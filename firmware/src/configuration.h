#pragma once

#include <logging.h>
#include <FFat.h>
#include <PacketSerial.h>

#include <WiFi.h>

#include "proto/proto_gen/smartknob.pb.h"

#include "EEPROM.h"
#include "./events/events.h"

static const char *CONFIG_PATH = "/config.pb";
static const char *SETTINGS_PATH = "/settings.pb";
static const char *SPOTIFY_CONFIG_PATH = "/spotify.pb";

// TODO: should move these consts to wifi?
static const uint16_t WIFI_SSID_LENGTH = 128;
static const uint16_t WIFI_PASSPHRASE_LENGTH = 128;
static const uint16_t WIFI_SET_LENGTH = 1;

static const uint16_t MQTT_HOST_LENGTH = 64;
static const uint16_t MQTT_PORT_LENGTH = sizeof(uint16_t);
static const uint16_t MQTT_USER_LENGTH = 64;
static const uint16_t MQTT_PASS_LENGTH = 64;
static const uint16_t MQTT_SET_LENGTH = 1;

// OS configurations
static const uint16_t OS_MODE_LENGTH = 1;
static const uint16_t OS_CONFIG_TOTAL_LENGTH = 50;

// OS config EEPROM positions
static const uint16_t OS_MODE_EEPROM_POS = 0;

// WiFi EEPROM positions
static const uint16_t WIFI_SSID_EEPROM_POS = OS_MODE_EEPROM_POS + OS_CONFIG_TOTAL_LENGTH;
static const uint16_t WIFI_PASSPHRASE_EEPROM_POS = WIFI_SSID_EEPROM_POS + WIFI_SSID_LENGTH;
static const uint16_t WIFI_SET_EEPROM_POS = WIFI_PASSPHRASE_EEPROM_POS + WIFI_PASSPHRASE_LENGTH;

// MQTT EEPROM positions
static const uint16_t MQTT_HOST_EEPROM_POS = WIFI_SET_EEPROM_POS + WIFI_SET_LENGTH;
static const uint16_t MQTT_PORT_EEPROM_POS = MQTT_HOST_EEPROM_POS + MQTT_HOST_LENGTH;
static const uint16_t MQTT_USER_EEPROM_POS = MQTT_PORT_EEPROM_POS + MQTT_PORT_LENGTH;
static const uint16_t MQTT_PASS_EEPROM_POS = MQTT_USER_EEPROM_POS + MQTT_USER_LENGTH;
static const uint16_t MQTT_SET_EEPROM_POS = MQTT_PASS_EEPROM_POS + MQTT_PASS_LENGTH;

// EEPROM size, verify when adding new fiels that size is still big enough
static const uint16_t EEPROM_SIZE = 512;

const uint32_t PERSISTENT_CONFIGURATION_VERSION = 2;
const uint32_t SETTINGS_VERSION = 1;
const uint32_t SPOTIFY_CONFIG_VERSION = 1;

struct WiFiConfiguration
{
    char ssid[128];
    char passphrase[128];
    char knob_id[64];
};

enum OSMode
{
    ONBOARDING = 0,
    DEMO,
    HASS,
    SPOTIFY,
    UNSET
};

struct OSConfiguration
{
    OSMode mode = ONBOARDING;
};

static const SETTINGS_Settings default_settings =
    {
        .has_screen = true,
        .screen = {
            .dim = true,
            .max_bright = 65535,
            .min_bright = 19661,
            .timeout = 30000,
        },
        .has_led_ring = true,
        .led_ring = {
            .enabled = true,
            .dim = true,
            .max_bright = 65535,
            .min_bright = 19661,
            .color = 16754176,
            .has_beacon = true,
            .beacon = {
                .enabled = true,
                .brightness = 19661,
                .color = 16754176,
            },
        },
};

class Configuration
{
public:
    Configuration();
    ~Configuration();

    bool loadPersistantConfigFromDisk();
    bool savePersistantConfigToDisk();
    bool resetToDefaults();
    PB_PersistentConfiguration get();

    bool loadSettingsFromDisk();
    bool saveSettingsToDisk();

    bool loadSpotifyConfigFromDisk();
    bool saveSpotifyConfigToDisk();

    bool setSpotifyConfig(const PB_SpotifyConfig &spotify_config);
    PB_SpotifyConfig getSpotifyConfig();

    bool setSettings(SETTINGS_Settings &settings);
    // bool resetSettingsToDefaults();
    SETTINGS_Settings getSettings();

    bool setMotorCalibrationAndSave(PB_MotorCalibration &motor_calibration);
    bool saveWiFiConfiguration(WiFiConfiguration wifi_config);
    WiFiConfiguration getWiFiConfiguration();
    bool loadWiFiConfiguration();
    bool saveMQTTConfiguration(MQTTConfiguration mqtt_config);
    MQTTConfiguration getMQTTConfiguration();
    bool loadMQTTConfiguration();
    bool saveOSConfiguration(OSConfiguration os_config);
    bool saveOSConfigurationInMemory(OSConfiguration os_config);
    bool loadOSConfiguration();
    bool saveFactoryStrainCalibration(float strain_scale);
    OSConfiguration *getOSConfiguration();
    const char *getKnobId();

    void setSharedEventsQueue(QueueHandle_t shared_event_queue);
    void publishEvent(WiFiEvent event);

private:
    SemaphoreHandle_t mutex_;

    QueueHandle_t shared_events_queue;

    bool loaded_ = false;
    PB_PersistentConfiguration pb_buffer_ = {};

    bool settings_loaded_ = false;
    SETTINGS_Settings settings_buffer_ = default_settings;

    bool spotify_config_loaded_ = false;
    PB_SpotifyConfig spotify_config_buffer_ = {};

    WiFiConfiguration wifi_config;
    bool is_wifi_set = false;
    MQTTConfiguration mqtt_config;
    bool is_mqtt_set = false;
    OSConfiguration os_config;

    uint8_t pb_stream_buffer_[PB_PersistentConfiguration_size];
    uint8_t settings_stream_buffer_[SETTINGS_Settings_size];
    uint8_t spotify_config_stream_buffer_[PB_SpotifyConfig_size];

    std::string knob_id;

    pb_istream_t loadFromDisk(const char *path, uint8_t *buffer, size_t buffer_size);
    bool saveToDisk(const char *path, uint8_t *buffer, size_t buffer_size);
};
class FatGuard
{
public:
    FatGuard()
    {
        if (!FFat.begin(true))
        {
            LOGV(LOG_LEVEL_ERROR, "Failed to mount FFat");
            return;
        }
        LOGV(LOG_LEVEL_DEBUG, "Mounted FFat");
        mounted_ = true;
    }
    ~FatGuard()
    {
        if (mounted_)
        {
            FFat.end();
            LOGV(LOG_LEVEL_DEBUG, "Unmounted FFat");
        }
    }
    FatGuard(FatGuard const &) = delete;
    FatGuard &operator=(FatGuard const &) = delete;

    bool mounted_ = false;
};
