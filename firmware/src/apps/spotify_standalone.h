#pragma once
#include "apps.h"
#include "../util.h"
#include "../events/events.h"

class SpotifyStandalone : public Apps
{
public:
    SpotifyStandalone(SemaphoreHandle_t mutex);

    // void sync(cJSON *json_apps);
    void handleEvent(WiFiEvent event);
    void handleNavigationEvent(NavigationEvent event);
    // void render();

private:
    // lv_obj_t *waiting_for_hass = lv_obj_create(NULL);
};