#include "BME680.h"

BME680::BME680() {

}

uint8_t BME680::write(uint8_t reg, uint8_t data) {
    Wire.beginTransmission(BME680_I2C_ADDRESS);             // START+SLA+W
    Wire.write(reg);                                        // REG
    Wire.write(data);                                       // DATA
    Wire.endTransmission(true);                             // STOP

    // read back the value of the register
    return read(reg);
}

uint8_t BME680::read(uint8_t reg){
    uint8_t chr = 0;
    Wire.beginTransmission(BME680_I2C_ADDRESS);             // START+SLA+W
    Wire.write(reg);                                        // REG
    Wire.endTransmission(false);                            // REP START
    Wire.requestFrom(BME680_I2C_ADDRESS, 1, true);          // SLA+R
    if(Wire.available()){
        chr = Wire.read();                                // DATA
    }

    return chr;
}

uint8_t BME680::status(void) {
    return read(BME680_STATUS);
}

bool BME680::reset(void) {
    write(BME680_RESET, 0xB6);
    return true;
}

uint8_t BME680::get_chipid(void) {
    return read(BME680_ID);
}

bool BME680::setHumidityOversampling(uint8_t osf){
    switch(osf){
        case 0:
            settings.humidity_oversampling = 0b000;
            break;
        case 1:
            settings.humidity_oversampling = 0b001;
            break;
        case 2:
            settings.humidity_oversampling = 0b010;
            break;
        case 4:
            settings.humidity_oversampling = 0b011;
            break;
        case 8:
            settings.humidity_oversampling = 0b100;
            break;
        case 16:
            settings.humidity_oversampling = 0b101;
            break;
        default:
            settings.humidity_oversampling = 0b001;
            break;
    }
}


bool BME680::setTemperatureOversampling(uint8_t osf){
    switch(osf){
        case 0:
            settings.temperature_oversampling = 0b000;
            break;
        case 1:
            settings.temperature_oversampling = 0b001;
            break;
        case 2:
            settings.temperature_oversampling = 0b010;
            break;
        case 4:
            settings.temperature_oversampling = 0b011;
            break;
        case 8:
            settings.temperature_oversampling = 0b100;
            break;
        case 16:
            settings.temperature_oversampling = 0b101;
            break;
        default:
            settings.temperature_oversampling = 0b001;
            break;
    }
}


bool BME680::setPressureOversampling(uint8_t osf){
    switch(osf){
        case 0:
            settings.pressure_oversampling = 0b000;
            break;
        case 1:
            settings.pressure_oversampling = 0b001;
            break;
        case 2:
            settings.pressure_oversampling = 0b010;
            break;
        case 4:
            settings.pressure_oversampling = 0b011;
            break;
        case 8:
            settings.pressure_oversampling = 0b100;
            break;
        case 16:
            settings.pressure_oversampling = 0b101;
            break;
        default:
            settings.pressure_oversampling = 0b001;
            break;
    }
}


bool BME680::setIIRFilter(uint8_t iir_coeff) {
    switch(iir_coeff){
        case 0:
            settings.IIR_coefficient = 0b000;
            break;
        case 1:
            settings.IIR_coefficient = 0b001;
            break;
        case 3:
            settings.IIR_coefficient = 0b010;
            break;
        case 7:
            settings.IIR_coefficient = 0b011;
            break;
        case 15:
            settings.IIR_coefficient = 0b100;
            break;
        case 31:
            settings.IIR_coefficient = 0b101;
            break;
        case 63:
            settings.IIR_coefficient = 0b110;
            break;
        case 127:
            settings.IIR_coefficient = 0b111;
            break;
        default:
            settings.IIR_coefficient = 0b000;
            break;
    }
}

bool BME680::setIDACHeater(uint8_t idac_heat[10]) {
    for( uint8_t i = 0; i < sizeof(idac_heat); i++) {
        write(BME680_IDAC_HEAT_0 + i, idac_heat[i]);
    }
}

bool BME680::setHeaterResistance(uint8_t heater_resistance[10]) {
    for( uint8_t i = 0; i < sizeof(heater_resistance); i++) {
        write(BME680_RES_HEAT_0 + i, heater_resistance[i]);
    }
}


bool BME680::setGasWaitTime(uint8_t gas_wait[10]) {
    for( uint8_t i = 0; i < sizeof(gas_wait); i++) {
        write(BME680_GAS_WAIT_0 + i, gas_wait[i]);
    }
}

bool BME680::heaterOff(void) {
    register_contents = read(BME680_CTRL_GAS_0)
    write(register_contents || 0x8);
}

bool BME680::heaterOn(void) {
    register_contents = read(BME680_CTRL_GAS_0)
    write(register_contents || 0x0);
}

bool BME680::selectHeaterProfile(uint8t heater_profile) {
    register_contents = read(BME680_CTRL_GAS_1);
    mask = 0xF0;
    write(register_contents && mask || heater_profile);
}

bool BME680::runGas(bool run_gas) {
    register_contents = read(BME680_CTRL_GAS_1);
    mask = 0xEF;
    write(register_contents && mask || run_gas);
}

uint8_t BME680::getGetRange(void) {
    return(read(BME680_GAS_R_LSB) && 0x0F);
}

bool BME680::newDataAvailable(void) {
    return(read(BME680_MEAS_STATUS_0) && 0x80 >>7);
}

bool BME680::gasMeasuringStatus(void) {
    return(read(BME680_MEAS_STATUS_0) && 0x40 >> 6);
}

bool BME680::MeasuringStatus(void) {
    return(read(BME680_MEAS_STATUS_0) && 0x20 >> 5);
}

uint8_t BME680::gasMeasurementIndex(void) {
    return(read(BME680_MEAS_STATUS_0) && 0x0F);
}

bool BME680::gasValidStatus(void) {
    return(read(BME680_GAS_R_LSB) && 0x10);
}

bool BME680::heaterStabilityStatus(void) {
    return(read(BME680_GAS_R_LSB) && 0x08 >> 3);
}

uint8_t BME680::readData(void) {
    /* Read Pressure Data

       Read Temperature Data

       Read Humidity Data

       Read Gas Resistance Data*/
}

/*
# START SENSOR
    # set oversampling for T, P, H all together
    # Get IIR filter
    # Enable gas
    # select index of heater set point
    # define heater on time
    # set heater Temperature
    # set forced mode
*/
