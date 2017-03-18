#ifndef BME680_H
#define BME680_H

#if defined(ARDUINO) && ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <Wire.h>

#define BME680_I2C_ADDRESS          (0x77)   /* Device Address (default) */
#define BME680_ID                   (0xD0)   /* Chip ID of device */
#define BME680_STATUS               (0x73)   /* Status of the BME680 */
#define BME680_RESET                (0xE0)   /* Reset the sensor */
#define BME680_CONFIG               (0x75)   /*  General config register */

// Pressure Data - Field 0
#define BME680_FIELD0_PRESS_MSB     (0x1F)    /* MSB of raw pressure measurement */
#define BME680_FIELD0_PRESS_LSB     (0x20)    /* LSB of raw pressure measurement */
#define BME680_FIELD0_PRESS_XLSB    (0x21)    /* XLSB of raw pressure measurement */

// Temperature Data
#define BME680_TEMP_MSB     (0x22)    /* MSB of raw temperature measurement */
#define BME680_TEMP_LSB     (0x23)    /* LSB of raw temperature measurement */
#define BME680_TEMP_XLSB    (0x24)    /* XLSB of raw temperature measurement */

// Humidity Data
#define BME680_HUM_MSB       (0x25)    /* MSB of raw humidity measurement */
#define BME680_HUM_LSB       (0x26)    /* LSB of raw humidity measurement */

// Gas data and range
#define BME680_GAS_R_MSB       (0x2A)    /* MSB of raw gas measurement */
#define BME680_GAS_R_LSB       (0x2B)    /* LSB of raw gas measurement */

// New Data Status
#define BME680_MEAS_STATUS_0 (0x1D)    /* New data flag for field 0 */

// Gas Control Registers
#define BME680_IDAC_HEAT_0          (0x50)    /* idac_heat of particular heater set point */
#define BME680_IDAC_HEAT_1          (0x51)    /* idac_heat of particular heater set point */
#define BME680_IDAC_HEAT_2          (0x52)    /* idac_heat of particular heater set point */
#define BME680_IDAC_HEAT_3          (0x53)    /* idac_heat of particular heater set point */
#define BME680_IDAC_HEAT_4          (0x54)    /* idac_heat of particular heater set point */
#define BME680_IDAC_HEAT_5          (0x55)    /* idac_heat of particular heater set point */
#define BME680_IDAC_HEAT_6          (0x56)    /* idac_heat of particular heater set point */
#define BME680_IDAC_HEAT_7          (0x57)    /* idac_heat of particular heater set point */
#define BME680_IDAC_HEAT_8          (0x58)    /* idac_heat of particular heater set point */
#define BME680_IDAC_HEAT_9          (0x59)    /* idac_heat of particular heater set point */

#define BME680_RES_HEAT_0           (0x5A)    /* Decimal value for achieving target heater resistance */
#define BME680_RES_HEAT_1           (0x5B)    /* Decimal value for achieving target heater resistance */
#define BME680_RES_HEAT_2           (0x5C)    /* Decimal value for achieving target heater resistance */
#define BME680_RES_HEAT_3           (0x5D)    /* Decimal value for achieving target heater resistance */
#define BME680_RES_HEAT_4           (0x5E)    /* Decimal value for achieving target heater resistance */
#define BME680_RES_HEAT_5           (0x5F)    /* Decimal value for achieving target heater resistance */
#define BME680_RES_HEAT_6           (0x60)    /* Decimal value for achieving target heater resistance */
#define BME680_RES_HEAT_7           (0x61)    /* Decimal value for achieving target heater resistance */
#define BME680_RES_HEAT_8           (0x62)    /* Decimal value for achieving target heater resistance */
#define BME680_RES_HEAT_9           (0x63)    /* Decimal value for achieving target heater resistance */

#define BME680_GAS_WAIT_0           (0x64)    /* Controls heater timing of the gas sensor */
#define BME680_GAS_WAIT_1           (0x65)    /* Controls heater timing of the gas sensor */
#define BME680_GAS_WAIT_2           (0x66)    /* Controls heater timing of the gas sensor */
#define BME680_GAS_WAIT_3           (0x67)    /* Controls heater timing of the gas sensor */
#define BME680_GAS_WAIT_4           (0x68)    /* Controls heater timing of the gas sensor */
#define BME680_GAS_WAIT_5           (0x69)    /* Controls heater timing of the gas sensor */
#define BME680_GAS_WAIT_6           (0x6A)    /* Controls heater timing of the gas sensor */
#define BME680_GAS_WAIT_7           (0x6B)    /* Controls heater timing of the gas sensor */
#define BME680_GAS_WAIT_8           (0x6C)    /* Controls heater timing of the gas sensor */
#define BME680_GAS_WAIT_9           (0x6D)    /* Controls heater timing of the gas sensor */

#define BME680_CTRL_GAS_0           (0x70)    /* Gas sensor control settings */
#define BME680_CTRL_GAS_1           (0x71)    /* Gas sensor control settings */

// Pressure, Temperature, and Relative Humidity Control Registers
#define BME680_CTRL_HUM             (0x72)    /* Controls humidity sensor settings */
#define BME680_CTRL_MEAS            (0x74)    /* Controls measurement settings */

class BME680 {

public:
      BME680();
      uint8_t status(void);
      uint8_t write(uint8_t reg, uint8_t data);
      uint8_t read(uint8_t reg);
private:
};

#endif
