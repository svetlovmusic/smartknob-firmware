#pragma once
#include "../app.h"

class SpotifyVolumeApp : public App {
public:
    SpotifyVolumeApp(SemaphoreHandle_t mutex, char *app_id, char *friendly_name, char *entity_id);
    EntityStateUpdate updateStateFromKnob(PB_SmartKnobState state) override;
    void updateStateFromHASS(MQTTStateUpdate mqtt_state_update) override;
    void handleNavigation(NavigationEvent event) override {}

private:
    void initScreen();
    lv_obj_t *arc_ = nullptr;
    lv_obj_t *label_ = nullptr;
    uint8_t last_position_ = 0;
};
