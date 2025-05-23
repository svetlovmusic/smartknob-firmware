#include "spotify_volume.h"
#include "cJSON.h"
#include "assets/images/icons.h"
#include <cstring>

SpotifyVolumeApp::SpotifyVolumeApp(SemaphoreHandle_t mutex, char *app_id_, char *friendly_name_, char *entity_id_)
    : App(mutex) {
    sprintf(app_id, "%s", app_id_);
    sprintf(friendly_name, "%s", friendly_name_);
    sprintf(entity_id, "%s", entity_id_);

    motor_config = PB_SmartKnobConfig{
        .position = 10,
        .sub_position_unit = 0,
        .position_nonce = 0,
        .min_position = 0,
        .max_position = 20,
        .position_width_radians = 9 * PI / 180,
        .detent_strength_unit = 1,
        .endstop_strength_unit = 1,
        .snap_point = 1.1,
        .detent_positions_count = 0,
        .detent_positions = {},
        .snap_point_bias = 0,
        .led_hue = 27,
    };
    strncpy(motor_config.id, app_id, sizeof(motor_config.id) - 1);

    // Icons not available for normal build

    initScreen();
}

void SpotifyVolumeApp::initScreen() {
    SemaphoreGuard lock(mutex_);
    arc_ = lv_arc_create(screen);
    lv_obj_set_size(arc_, 210, 210);
    lv_arc_set_rotation(arc_, 225);
    lv_arc_set_bg_angles(arc_, 0, 90);
    lv_arc_set_value(arc_, 50);
    lv_obj_center(arc_);
    lv_obj_set_style_arc_color(arc_, dark_arc_bg, LV_PART_MAIN);
    lv_obj_set_style_arc_width(arc_, 24, LV_PART_MAIN);
    lv_obj_set_style_arc_width(arc_, 24, LV_PART_INDICATOR);
    lv_obj_set_style_pad_all(arc_, -5, LV_PART_KNOB);

    label_ = lv_label_create(screen);
    lv_obj_align(label_, LV_ALIGN_BOTTOM_MID, 0, -48);
    lv_label_set_text_fmt(label_, "%s 50%%", friendly_name);
}

EntityStateUpdate SpotifyVolumeApp::updateStateFromKnob(PB_SmartKnobState state) {
    EntityStateUpdate update;
    if (state_sent_from_hass) {
        state_sent_from_hass = false;
        return update;
    }

    uint8_t position = CLAMP<uint8_t>(state.current_position, 0u, 20u);
    motor_config.position_nonce = position;
    motor_config.position = position;

    if (position != last_position_) {
        last_position_ = position;
        uint8_t volume = position * 5;
        {
            SemaphoreGuard lock(mutex_);
            lv_arc_set_value(arc_, volume);
            lv_label_set_text_fmt(label_, "%s %d%%", friendly_name, volume);
        }

        snprintf(update.app_id, sizeof(update.app_id), "%s", app_id);
        snprintf(update.entity_id, sizeof(update.entity_id), "%s", entity_id);

        cJSON *json = cJSON_CreateObject();
        cJSON_AddNumberToObject(json, "volume", volume);
        char *json_str = cJSON_PrintUnformatted(json);
        snprintf(update.state, sizeof(update.state), "%s", json_str);
        cJSON_free(json_str);
        cJSON_Delete(json);

        update.changed = true;
        snprintf(update.app_slug, sizeof(update.app_slug), "%s", APP_SLUG_MUSIC);
    }

    return update;
}

void SpotifyVolumeApp::updateStateFromHASS(MQTTStateUpdate mqtt_state_update) {
    cJSON *state = cJSON_Parse(mqtt_state_update.state);
    cJSON *volume = cJSON_GetObjectItem(state, "volume");
    if (volume != NULL) {
        uint8_t position = volume->valueint / 5;
        position = CLAMP<uint8_t>(position, 0u, 20u);
        motor_config.position = position;
        motor_config.position_nonce = position;
        last_position_ = position;
        state_sent_from_hass = true;

        SemaphoreGuard lock(mutex_);
        lv_arc_set_value(arc_, position * 5);
        lv_label_set_text_fmt(label_, "%s %d%%", friendly_name, position * 5);
    }
    cJSON_Delete(state);
}

