#pragma once

#include <Arduino.h>
#include "configuration.h"
#include "display_task.h"
#include "motor_foc/motor_task.h"
// #include "serial/serial_protocol_plaintext.h"
// #include "serial/serial_protocol_protobuf.h"
// #include "serial/uart_stream.h"
#include <logging.h>
#include <logging/adapters/freertos/free_rtos_adapter.h>
#include "proto/serial_protocol_protobuf.h"
#include "task.h"
#include "app_config.h"
#include "network/wifi_task.h"
#include "network/mqtt_task.h"
#include "network/spotify/spotify_task.h"
#include "led_ring/led_ring_task.h"
#include "sensors/sensors_task.h"
#include "error_handling_flow/reset_task.h"

#include "notify/motor_notifier/motor_notifier.h"
#include "notify/os_config_notifier/os_config_notifier.h"

#include "navigation/navigation.h"

void delete_me_TriggerMotorCalibration();

class RootTask : public Task<RootTask>
{

    friend class Task<RootTask>; // Allow base Task to invoke protected run()

public:
    RootTask(const uint8_t task_core, Configuration *configuration, MotorTask &motor_task, DisplayTask *display_task, WifiTask *wifi_task, MqttTask *mqtt_task, SpotifyTask *spotify_task, LedRingTask *led_ring_task, SensorsTask *sensors_task, ResetTask *reset_task, FreeRTOSAdapter *free_rtos_adapter, SerialProtocolPlaintext *serial_protocol_plaintext, SerialProtocolProtobuf *serial_protocol_protobuf);
    virtual ~RootTask();
    void loadConfiguration();

    void addListener(QueueHandle_t queue);

    QueueHandle_t getConnectivityStateQueue();
    QueueHandle_t getMqttStateQueue();
    QueueHandle_t getSensorsStateQueue();
    QueueHandle_t getAppSyncQueue();
    QueueHandle_t getSettingsSyncQueue();

protected:
    void run();

private:
    MotorTask &motor_task_;
    DisplayTask *display_task_;
    WifiTask *wifi_task_;
    MqttTask *mqtt_task_;
    SpotifyTask *spotify_task_;
    LedRingTask *led_ring_task_;
    SensorsTask *sensors_task_;
    ResetTask *reset_task_;

    FreeRTOSAdapter *free_rtos_adapter_;

    SerialProtocolPlaintext *serial_protocol_plaintext_;
    SerialProtocolProtobuf *serial_protocol_protobuf_;

    char buf_[128];

    std::vector<QueueHandle_t> listeners_;

    SemaphoreHandle_t mutex_;
    Configuration *configuration_ = nullptr; // protected by mutex_

    PB_PersistentConfiguration configuration_value_;
    SETTINGS_Settings settings_;
    bool configuration_loaded_ = false;

    uint8_t factory_strain_calibration_step_ = 0;
    uint8_t strain_calibration_step_ = 0;
    int32_t strain_reading_ = 0;

    SerialProtocol *current_protocol_ = nullptr;
    bool remote_controlled_ = false;
    int current_config_ = 0;
    uint8_t press_count_ = 1;

    uint16_t brightness = UINT16_MAX;

    uint8_t last_strain_pressed_played_ = VIRTUAL_BUTTON_IDLE;

    PB_SmartKnobState latest_state_ = {};
    PB_SmartKnobConfig latest_config_ = {};

    ConnectivityState latest_connectivity_state_ = {};
    MqttState latest_mqtt_state_ = {};
    SensorsState latest_sensors_state_ = {};

    cJSON *apps_ = NULL;

    QueueHandle_t knob_state_queue_;

    QueueHandle_t connectivity_status_queue_;
    QueueHandle_t mqtt_status_queue_;
    QueueHandle_t sensors_status_queue_;

    QueueHandle_t app_sync_queue_;

    OSConfigNotifier os_config_notifier_;

    // SerialProtocolPlaintext plaintext_protocol_;
    // SerialProtocolProtobuf proto_protocol_;

    uint32_t last_calib_state_sent_ = 0;

    void updateHardware(AppState *app_state);
    void publishState();
    void applyConfig(PB_SmartKnobConfig config, bool from_remote);
    void publish(const AppState &state);
};
