/*
 * THIS FILE IS AUTOMATICALLY GENERATED
 *
 * Generator:     sensirion-driver-generator 0.23.0
 * Product:       sfx6xxx
 * Model-Version: 2.0.0
 */
/*
 * Copyright (c) 2023, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SFX6XXX_UART_H
#define SFX6XXX_UART_H

#ifdef __cplusplus
extern "C" {
#endif

#include "sensirion_config.h"
#define SFX6XXX_SHDLC_ADDR 0x00

typedef enum {
    SET_SETPOINT_CMD_ID = 0x0,
    GET_SETPOINT_CMD_ID = 0x0,
    READ_MEASURED_VALUE_CMD_ID = 0x8,
    READ_AVERAGED_MEASURED_VALUE_CMD_ID = 0x8,
    SET_SETPOINT_AND_READ_MEASURED_VALUE_CMD_ID = 0x3,
    SET_USER_CONTROLLER_GAIN_CMD_ID = 0x22,
    GET_USER_CONTROLLER_GAIN_CMD_ID = 0x22,
    SET_USER_INIT_STEP_CMD_ID = 0x22,
    GET_USER_INIT_STEP_CMD_ID = 0x22,
    MEASURE_RAW_FLOW_CMD_ID = 0x30,
    MEASURE_RAW_THERMAL_CONDUCTIVITY_WITH_CLOSED_VALVE_CMD_ID = 0x30,
    MEASURE_TEMPERATURE_CMD_ID = 0x30,
    GET_NUMBER_OF_CALIBRATIONS_CMD_ID = 0x40,
    GET_CALIBRATION_VALIDITY_CMD_ID = 0x40,
    GET_CALIBRATION_GAS_ID_CMD_ID = 0x40,
    GET_CALIBRATION_GAS_UNIT_CMD_ID = 0x40,
    GET_CALIBRATION_FULLSCALE_CMD_ID = 0x40,
    GET_CURRENT_GAS_ID_CMD_ID = 0x44,
    GET_CURRENT_GAS_UNIT_CMD_ID = 0x44,
    GET_CURRENT_FULLSCALE_CMD_ID = 0x44,
    SET_CALIBRATION_CMD_ID = 0x45,
    GET_CALIBRATION_CMD_ID = 0x45,
    SET_CALIBRATION_VOLATILE_CMD_ID = 0x46,
    SET_SLAVE_ADDRESS_CMD_ID = 0x90,
    GET_SLAVE_ADDRESS_CMD_ID = 0x90,
    SET_BAUDRATE_CMD_ID = 0x91,
    GET_BAUDRATE_CMD_ID = 0x91,
    GET_PRODUCT_TYPE_CMD_ID = 0xd0,
    GET_PRODUCT_NAME_CMD_ID = 0xd0,
    GET_ARTICLE_CODE_CMD_ID = 0xd0,
    GET_SERIAL_NUMBER_CMD_ID = 0xd0,
    GET_VERSION_CMD_ID = 0xd1,
    DEVICE_RESET_CMD_ID = 0xd3,
} cmd_id_t;

typedef enum {
    STATUS_CODE_SUCCESS = 0,
    STATUS_CODE_DATA_SIZE_ERROR = 1,
    STATUS_CODE_UNKNOWN_COMMAND_ERROR = 2,
    STATUS_CODE_PARAMETER_ERROR = 4,
    STATUS_CODE_I2C_NACK_ERROR = 41,
    STATUS_CODE_I2C_MASTER_HOLD_ERROR = 42,
    STATUS_CODE_I2C_CRC_ERROR = 43,
    STATUS_CODE_SENSOR_DATA_WRITE_ERROR = 44,
    STATUS_CODE_SENSOR_MEASURE_LOOP_NOT_RUNNING_ERROR = 45,
    STATUS_CODE_INVALID_CALIBRATION_INDEX_ERROR = 51,
    STATUS_CODE_SENSOR_BUSY_ERROR = 66,
    STATUS_CODE_COMMAND_NOT_ALLOWED_IN_CURRENT_STATE = 67,
    STATUS_CODE_FATAL_ERROR = 127,
} status_code;

/**
 * @brief Switch device off (close the valve by setting setpoint to 0)
 *
 * @note Only applicable for SFC6xxx mass flow controllers.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_close_valve();

/**
 * @brief sfx6xxx_set_setpoint
 *
 * Set the flow setpoint as a physical value which is used by the flow
 * controller as reference input.
 *
 * @param[in] setpoint The new setpoint.
 *
 * @note
 * * The setpoint is set to 0 if calibration is changed.
 * * Only applicable for SFC6xxx mass flow controllers.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_set_setpoint(float setpoint);

/**
 * @brief sfx6xxx_get_setpoint
 *
 * Get the current flow setpoint as a physical value.
 *
 * @param[out] setpoint The current setpoint.
 *
 * @note Only applicable for SFC6xxx mass flow controllers.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_get_setpoint(float* setpoint);

/**
 * @brief sfx6xxx_read_measured_value
 *
 * The command returns the latest measured flow as physical value.
 *
 * @param[out] measured_value The latest measured flow.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_read_measured_value(float* measured_value);

/**
 * @brief sfx6xxx_read_averaged_measured_value
 *
 * The command returns the average of given number of flow measurement as
 * physical value. A single measurement has a duration of 1ms, so the command
 * response time depends on the given number of measurements to average.
 *
 * @param[in] measurements number of measurements to average (1..100)
 * @param[out] averaged_measured_value The averaged flow measurement.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_read_averaged_measured_value(uint8_t measurements,
                                             float* averaged_measured_value);

/**
 * @brief sfx6xxx_set_setpoint_and_read_measured_value
 *
 * This command is a combination of the two commands set_setpoint (0x00) and
 * read_measured_value (0x08). It is intended for process data exchange
 * (setpoint and flow) and saves a lot of protocol overhead compared to separate
 * command usage.
 *
 * @param[in] setpoint The new setpoint as physical value.
 * @param[out] measured_value The latest measured flow as physical value.
 *
 * @note Only applicable for SFC6xxx mass flow controllers.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_set_setpoint_and_read_measured_value(float setpoint,
                                                     float* measured_value);

/**
 * @brief sfx6xxx_set_user_controller_gain
 *
 * Set the user controller gain.
 *
 * @param[in] gain The user controller gain to set.
 *
 * @note
 * * This configuration is not stored in non-volatile memory of the device and
 *   thus not persists after a device reset.
 * * Only applicable for SFC6xxx mass flow controllers.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_set_user_controller_gain(float gain);

/**
 * @brief sfx6xxx_get_user_controller_gain
 *
 * Get the user controller gain.
 *
 * @param[out] gain The current user controller gain.
 *
 * @note Only applicable for SFC6xxx mass flow controllers.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_get_user_controller_gain(float* gain);

/**
 * @brief sfx6xxx_set_user_init_step
 *
 * Set the init step of flow controller.
 *
 * @param[in] init_step the user init step to set.
 *
 * @note
 * * This configuration is not stored in non-volatile memory of the device and
 *   thus not persists after a device reset.
 * * Only applicable for SFC6xxx mass flow controllers.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_set_user_init_step(float init_step);

/**
 * @brief sfx6xxx_get_user_init_step
 *
 * Get the user init step of flow controller.
 *
 * @param[out] init_step The current user init step.
 *
 * @note Only applicable for SFC6xxx mass flow controllers.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_get_user_init_step(float* init_step);

/**
 * @brief sfx6xxx_measure_raw_flow
 *
 * Return the measured raw flow ticks from the sensor.
 *
 * @param[out] flow Measured raw flow in ticks.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_measure_raw_flow(uint16_t* flow);

/**
 * @brief sfx6xxx_measure_raw_thermal_conductivity_with_closed_valve
 *
 * Perform a thermal conductivity measurement and return the measured raw tick
 * value. The valve is automatically closed during the measurement.
 *
 * @param[out] thermal_conductivity Measured raw thermal conductivity in ticks.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_measure_raw_thermal_conductivity_with_closed_valve(
    uint16_t* thermal_conductivity);

/**
 * @brief sfx6xxx_measure_temperature
 *
 * Return the temperature of flow sensor.
 *
 * @param[out] temperature Measured temperature [°C].
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_measure_temperature(float* temperature);

/**
 * @brief sfx6xxx_get_number_of_calibrations
 *
 * Get the number of calibrations, i.e. how many calibration the device memory
 * is able to hold.
 *
 * @param[out] number_of_calibrations Number of calibrations.
 *
 * @note Not all calibration actually contain a valid gas calibration. Use the
 * command get_calibration_validity to check which calibrations are valid and
 * thus can be activated.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_get_number_of_calibrations(uint32_t* number_of_calibrations);

/**
 * @brief sfx6xxx_get_calibration_validity
 *
 * Check whether there exists a valid calibration at a specific index or not.
 *
 * @param[in] index The index to check whether there is a valid calibration or
 * not.
 * @param[out] validity Whether there exists a valid calibration at the
 * specified index or not.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_get_calibration_validity(uint32_t index, bool* validity);

/**
 * @brief sfx6xxx_get_calibration_gas_id
 *
 * Get the gas ID of a specific calibration index.
 *
 * @param[in] index The calibration index to read the requested information
 * from.
 * @param[out] gas_id The read gas ID.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_get_calibration_gas_id(uint32_t index, uint32_t* gas_id);

/**
 * @brief sfx6xxx_get_calibration_gas_unit
 *
 * Get the gas unit of a specific calibration index.
 *
 * @param[in] index The calibration index to read the requested information
 * from.
 * @param[out] prefix Medium unit prefix, see datasheet for encoding.
 * @param[out] unit Medium unit, see datasheet for encoding.
 * @param[out] timebase Timebase, see datasheet for encoding.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_get_calibration_gas_unit(uint32_t index, int8_t* prefix,
                                         uint8_t* unit, uint8_t* timebase);

/**
 * @brief sfx6xxx_get_calibration_fullscale
 *
 * Get the fullscale flow of a specific calibration index.
 *
 * @param[in] index The calibration index to read the requested information
 * from.
 * @param[out] fullscale The read fullscale flow in the unit of the
 * corresponding calibration.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_get_calibration_fullscale(uint32_t index, float* fullscale);

/**
 * @brief sfx6xxx_get_current_gas_id
 *
 * Get the gas ID of the currently active calibration.
 *
 * @param[out] gas_id The read gas ID.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_get_current_gas_id(uint32_t* gas_id);

/**
 * @brief sfx6xxx_get_current_gas_unit
 *
 * Get the gas unit of the currently active calibration.
 *
 * @param[out] prefix Medium unit prefix, see datasheet for encoding.
 * @param[out] unit Medium unit, see datasheet for encoding.
 * @param[out] timebase Timebase, see datasheet for encoding.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_get_current_gas_unit(int8_t* prefix, uint8_t* unit,
                                     uint8_t* timebase);

/**
 * @brief sfx6xxx_get_current_fullscale
 *
 * Get the fullscale flow of the currently active calibration.
 *
 * @param[out] fullscale The read fullscale flow in the unit of the
 * corresponding calibration.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_get_current_fullscale(float* fullscale);

/**
 * @brief sfx6xxx_set_calibration
 *
 * This command stops the controller, changes the used calibration of the flow
 * controller and starts the controller. The selected calibration is stored and
 * also used after a power-on or reset.
 *
 * @param[in] calibration_number The calibration number to activate.
 *
 * @note This command will cause a write operation in a flash. Because of the
 * limited write cycles of the flash, this command should not be called
 * periodically with new calibration (max. 50’000 times). If calibration is
 * already selected the function will not do a write cycle to flash.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_set_calibration(uint32_t calibration_number);

/**
 * @brief sfx6xxx_get_calibration
 *
 * Get the actual set calibration number of flow controller.
 *
 * @param[out] calibration_number The current activated calibration number.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_get_calibration(uint32_t* calibration_number);

/**
 * @brief sfx6xxx_set_calibration_volatile
 *
 * This command stops the controller, changes the used calibration of the flow
 * controller and starts the controller. The selected calibration is not stored
 * to a non volatile memory.
 *
 * @param[in] calibration_number The calibration number to activate.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_set_calibration_volatile(uint32_t calibration_number);

/**
 * @brief sfx6xxx_set_slave_address
 *
 * Sets the SHDLC slave address of the device.
 *
 * @param[in] slave_address The new slave address to set.
 *
 * @note The slave address is stored in non-volatile memory of the device and
 * thus persists after a device reset. So the next time connecting to the
 * device, you have to use the new address. When changing the address of a
 * slave, make sure there isn't already a slave with that address on the same
 * bus! In that case you would get communication issues which can only be fixed
 * by disconnecting one of the slaves.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_set_slave_address(uint8_t slave_address);

/**
 * @brief sfx6xxx_get_slave_address
 *
 * Gets the SHDLC slave address of the device.
 *
 * @param[out] slave_address The current slave address of the device.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_get_slave_address(uint8_t* slave_address);

/**
 * @brief sfx6xxx_set_baudrate
 *
 * Sets the SHDLC baudrate of the device.
 *
 * @param[in] baudrate The new baudrate in bit/s. Allowed values are 9600,
 * 19200, 38400, 57600 and 115200 (default)
 *
 * @note The baudrate is stored in non-volatile memory of the device and thus
 * persists after a device reset. So the next time connecting to the device, you
 * have to use the new baudrate.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_set_baudrate(uint32_t baudrate);

/**
 * @brief sfx6xxx_get_baudrate
 *
 * Gets the SHDLC baudrate of the device.
 *
 * @param[out] baudrate Current baudrate in bit/s.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_get_baudrate(uint32_t* baudrate);

/**
 * @brief sfx6xxx_get_product_type
 *
 * Gets the product type from the device.
 *
 * @param[out] product_type String containing the product type.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_get_product_type(int8_t* product_type,
                                 uint16_t product_type_size);

/**
 * @brief sfx6xxx_get_product_name
 *
 * Gets the product name from the device.
 *
 * @param[out] product_name String containing the product name.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_get_product_name(int8_t* product_name,
                                 uint16_t product_name_size);

/**
 * @brief sfx6xxx_get_article_code
 *
 * Get the article code of the device. This information is also contained on the
 * product label.
 *
 * @param[out] article_code The article code as an ASCII string.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_get_article_code(int8_t* article_code,
                                 uint16_t article_code_size);

/**
 * @brief sfx6xxx_get_serial_number
 *
 * Gets the serial number of the SFx6xxx sensor.
 *
 * @param[out] serial_number String containing the serial number of the SFx6xxx
 * sensor.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_get_serial_number(int8_t* serial_number,
                                  uint16_t serial_number_size);

/**
 * @brief sfx6xxx_get_version
 *
 * Gets the version information for the hardware, firmware and SHDLC protocol.
 *
 * @param[out] firmware_major Firmware major version number.
 * @param[out] firmware_minor Firmware minor version number.
 * @param[out] firmware_debug Firmware debug state. If the debug state is set,
 * the firmware is in development.
 * @param[out] hardware_major Hardware major version number.
 * @param[out] hardware_minor Hardware minor version number.
 * @param[out] protocol_major Protocol major version number.
 * @param[out] protocol_minor Protocol minor version number.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_get_version(uint8_t* firmware_major, uint8_t* firmware_minor,
                            bool* firmware_debug, uint8_t* hardware_major,
                            uint8_t* hardware_minor, uint8_t* protocol_major,
                            uint8_t* protocol_minor);

/**
 * @brief sfx6xxx_device_reset
 *
 * Executes a reset on the device. This has the same effect as a power cycle.
 *
 * @note The device will reply before excecuting the reset.
 *
 * @return error_code 0 on success, an error code otherwise.
 */
int16_t sfx6xxx_device_reset();

#ifdef __cplusplus
}
#endif
#endif  // SFX6XXX_UART_H