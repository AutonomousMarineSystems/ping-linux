/*
* ping1d.h
* A device API for the Blue Robotics Ping1D echosounder
*
*~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!
* THIS IS AN AUTOGENERATED FILE
* DO NOT EDIT
*~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!~!
*
*/

#pragma once


#include <stdint.h>
#include <cstring>

#include "pingmessage.h"
#include "ping_parser.h"

#include "stream.h"
class Ping1D
{
public:

    /**
     *  @brief Constructor
     *
     *  @param ser: The device I/O
     */
    Ping1D(Stream& ser);

    /**
     * @brief Destructor
     */
    ~Ping1D();

    /**
     *  @brief Establish communications with the device, and initialize the update interval
     *
     *  @param ping_interval_ms: The interval (in milliseconds) between acoustic measurements
     *
     *  @return true if the device was initialized successfully
     */
    bool initialize(uint16_t ping_interval_ms = 50);

    /**
     *  @brief Request a PingMessage from the device
     *
     *  @param id: The message ID to request
     *  @param timeout_ms: The timeout period to wait for the requested PingMessage to be received
     *
     *  @return The PingMessage that was requested
     *  @return null if the device did not reply with the requested message before the timeout period expired
     *
     *  @par ex.
     *  @code
     *  ping_msg_ping1D_voltage_5 msg(*pd.request(Ping1DNamespace::Voltage_5));
     *  @endcode
     */
    PingMessage* request(enum Ping1DNamespace::msg_ping1D_id id, uint16_t timeout_ms = 500);


    /**
     *  @brief Request a PingMessage of type T from the device
     *
     *  @param timeout_ms: The timeout period to wait for the requested PingMessage to be received
     *
     *  @return The PingMessage that was requested
     *  @return null if the device did not reply with the requested message before the timeout period expired
     *
     *  @par ex.
     *  @code
     *  auto msg = pd.request<ping_msg_ping1D_voltage_5>();
     *  @endcode
     */
    template <typename T>
    T* request();

    /**
     *  @brief Helper to request distance and confidence
     *
     *  @return true if the distance and confidence have been updated successfully
     */
    bool update() {
        return request(Ping1DNamespace::Distance_simple);
    }

    /**
     * @brief Set the device ID.
     *
     * @param device_id - Device ID (0-254). 255 is reserved for broadcast messages.
     *
     * @return when verify = false: true if a valid reply is received from the device.
     * @return when verify = true: true if a valid reply is received from the
     * device, and the values in the reply match the values that we applied
     */
    bool set_device_id(uint8_t device_id, bool verify = true);

    /**
     * @brief Set the scan range for acoustic measurements.
     *
     * @param scan_start - Units: mm; 
     * @param scan_length - Units: mm; The length of the scan range.
     *
     * @return when verify = false: true if a valid reply is received from the device.
     * @return when verify = true: true if a valid reply is received from the
     * device, and the values in the reply match the values that we applied
     */
    bool set_range(uint32_t scan_start, uint32_t scan_length, bool verify = true);

    /**
     * @brief Set the speed of sound used for distance calculations.
     *
     * @param speed_of_sound - Units: mm/s; The speed of sound in the measurement medium. ~1,500,000 mm/s for water.
     *
     * @return when verify = false: true if a valid reply is received from the device.
     * @return when verify = true: true if a valid reply is received from the
     * device, and the values in the reply match the values that we applied
     */
    bool set_speed_of_sound(uint32_t speed_of_sound, bool verify = true);

    /**
     * @brief Set automatic or manual mode. Manual mode allows for manual selection of the gain and scan range.
     *
     * @param mode_auto - 0: manual mode. 1: auto mode.
     *
     * @return when verify = false: true if a valid reply is received from the device.
     * @return when verify = true: true if a valid reply is received from the
     * device, and the values in the reply match the values that we applied
     */
    bool set_mode_auto(uint8_t mode_auto, bool verify = true);

    /**
     * @brief The interval between acoustic measurements.
     *
     * @param ping_interval - Units: ms; The interval between acoustic measurements.
     *
     * @return when verify = false: true if a valid reply is received from the device.
     * @return when verify = true: true if a valid reply is received from the
     * device, and the values in the reply match the values that we applied
     */
    bool set_ping_interval(uint16_t ping_interval, bool verify = true);

    /**
     * @brief Set the current gain setting.
     *
     * @param gain_index - The current gain setting. 0: 0.6, 1: 1.8, 2: 5.5, 3: 12.9, 4: 30.2, 5: 66.1, 6: 144
     *
     * @return when verify = false: true if a valid reply is received from the device.
     * @return when verify = true: true if a valid reply is received from the
     * device, and the values in the reply match the values that we applied
     */
    bool set_gain_index(uint8_t gain_index, bool verify = true);

    /**
     * @brief Enable or disable acoustic measurements.
     *
     * @param ping_enabled - 0: Disable, 1: Enable.
     *
     * @return when verify = false: true if a valid reply is received from the device.
     * @return when verify = true: true if a valid reply is received from the
     * device, and the values in the reply match the values that we applied
     */
    bool set_ping_enable(uint8_t ping_enabled, bool verify = true);


    /**
     * Return the latest value received
     */
    uint8_t device_type() { return _device_type; }

    /**
     * Return the latest value received
     */
    uint8_t device_model() { return _device_model; }

    /**
     * Return the latest value received
     */
    uint16_t firmware_version_major() { return _firmware_version_major; }

    /**
     * Return the latest value received
     */
    uint16_t firmware_version_minor() { return _firmware_version_minor; }

    /**
     * Return the latest value received
     */
    uint8_t device_id() { return _device_id; }

    /**
     * Return the latest value received
     */
    uint16_t voltage_5() { return _voltage_5; }

    /**
     * Return the latest value received
     */
    uint32_t speed_of_sound() { return _speed_of_sound; }

    /**
     * Return the latest value received
     */
    uint32_t scan_start() { return _scan_start; }

    /**
     * Return the latest value received
     */
    uint32_t scan_length() { return _scan_length; }

    /**
     * Return the latest value received
     */
    uint8_t mode_auto() { return _mode_auto; }

    /**
     * Return the latest value received
     */
    uint16_t ping_interval() { return _ping_interval; }

    /**
     * Return the latest value received
     */
    uint32_t gain_index() { return _gain_index; }

    /**
     * Return the latest value received
     */
    uint16_t pulse_duration() { return _pulse_duration; }

    /**
     * Return the latest value received
     */
    uint32_t distance() { return _distance; }

    /**
     * Return the latest value received
     */
    uint16_t confidence() { return _confidence; }

    /**
     * Return the latest value received
     */
    uint32_t ping_number() { return _ping_number; }

    /**
     * Return the latest value received
     */
    uint16_t processor_temperature() { return _processor_temperature; }

    /**
     * Return the latest value received
     */
    uint16_t pcb_temperature() { return _pcb_temperature; }

    /**
     * Return the latest value received
     */
    uint8_t ping_enabled() { return _ping_enabled; }

    /**
     * Return the latest value received
     */
    uint16_t profile_data_length() { return _profile_data_length; }
    /**
     * Return the latest value received
     */
    uint8_t* profile_data() { return _profile_data; }

    /**
     * Return the latest value received
     */
    uint32_t protocol_version() { return _protocol_version; }


private:
    // Device I/O
    Stream& _stream;

    // For decoding PingMessages from the device
    PingParser _parser;

    // Device type. 0: Unknown; 1: Echosounder
    uint8_t _device_type = 0;

    // Device model. 0: Unknown; 1: Ping1D
    uint8_t _device_model = 0;

    // Firmware major version.
    uint16_t _firmware_version_major = 0;

    // Firmware minor version.
    uint16_t _firmware_version_minor = 0;

    // The device ID (0-254). 255 is reserved for broadcast messages.
    uint8_t _device_id = 0;

    // Device supply voltage.
    uint16_t _voltage_5 = 0;

    // The speed of sound in the measurement medium. ~1,500,000 mm/s for water.
    uint32_t _speed_of_sound = 0;

    // The beginning of the scan region in mm from the transducer.
    uint32_t _scan_start = 0;

    // The length of the scan region.
    uint32_t _scan_length = 0;

    // The current operating mode of the device. 0: manual mode, 1: auto mode
    uint8_t _mode_auto = 0;

    // The interval between acoustic measurements.
    uint16_t _ping_interval = 0;

    // The current gain setting. 0: 0.6, 1: 1.8, 2: 5.5, 3: 12.9, 4: 30.2, 5: 66.1, 6: 144
    uint32_t _gain_index = 0;

    // The acoustic pulse length during acoustic transmission/activation.
    uint16_t _pulse_duration = 0;

    // The current return distance determined for the most recent acoustic measurement.
    uint32_t _distance = 0;

    // Confidence in the most recent range measurement.
    uint16_t _confidence = 0;

    // The pulse/measurement count since boot.
    uint32_t _ping_number = 0;

    // The temperature in centi-degrees Centigrade (100 * degrees C).
    uint16_t _processor_temperature = 0;

    // The temperature in centi-degrees Centigrade (100 * degrees C).
    uint16_t _pcb_temperature = 0;

    // The state of the acoustic output. 0: disabled, 1:enabled
    uint8_t _ping_enabled = 0;

    // An array of return strength measurements taken at regular intervals across the scan region.
    uint16_t _profile_data_length = 0;
    uint8_t* _profile_data = 0;

    // The protocol version
    uint32_t _protocol_version = 0;


    /**
     *  @brief Read in data from device, return a PingMessage if available.
     *  Data will be read in from device until there is no data left in the RX buffer,
     *  or a valid PingMessage is successfully decoded.
     *  Note that there may still be data available in the RX buffer for decoding when
     *  this function returns a PingMessage.
     *
     *  @return: The next PingMessage from the device
     *  @return: null if the RX buffer is empty and no PingMessage has been decoded
     */
    PingMessage* read();

    /**
     *  @brief Write data to device
     *
     *  @param data: pointer to buffer to write
     *  @param length: buffer length to write
     *
     *  @return: size of data buffer written to the device
     */
    size_t write(uint8_t* data, uint16_t length);

    /**
     *  @brief Wait for receipt of a message with a particular message id from device
     *
     *  @param id: The message id to wait for
     *  @param timeout_ms: The timeout period to wait for a matching PingMessage to be received
     *
     *  @return The PingMessage received with matching id
     *  @return null if the timeout expires and no PingMessage was received with a matching id
     */
    PingMessage* waitMessage(enum Ping1DNamespace::msg_ping1D_id id, uint16_t timeout_ms = 500);

    /**
     *  @brief Handle an incoming message from the device. Internal values are updated according to the device data.
     *
     *  @param pmsg: The message received from the device
     */
    void handleMessage(PingMessage* pmsg);

};
