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

uint8_t BME680::setTemperatureOversampling(uint8_t osf){
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

uint8_t BME680::setPressureOversampling(uint8_t osf){
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

uint8_t BME680::setHumidityOversampling(uint8_t osf){
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

uint8_t BME680::setIIRFilter(uint8_t iir_coeff){
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

uint8_t BME680::setGasEnable(uint8_t gas_en){
      setting.run_gas = gas_en;
      return 0;
}

uint8_t BME680::setHeaterIndex(uint8_t VAR){

}

uint8_t BME680::setHeaterOnTimeMs(uint8_t VAR){

}

uint8_t BME680::setHeaterTemperatureC(uint8_t VAR){

}

uint8_t BME680::setStandbyTimeMs(uint8_t VAR){

}

uint8_t BME680::setHeaterSetPoints(uint8_t VAR){

}

uint8_t BME680::setHeaterOnTimesMs(uint8_t VAR){

}

uint8_t BME680::setHeaterTemperaturesC(uint8_t VAR){

}

uint8_t BME680::setWaitTimeMs(uint8_t VAR){

}

uint8_t BME680::setMode(uint8_t VAR){

}


uint8_t BME680::begin(void) {
    //
    // Forced mode
    //

    // Set oversampling for T, P, RH

    // Set IIR filter for T, P

    // Enable Gas conversion

    // Select Index of Heater Set-Point

    // Define Heater On Time

    // Set Heater Temperature

    // Set Mode to Forced


    //
    // Sequential mode
    //

    // Set stand-by time between measurements

    // Set oversampling for T, P, RH

    // Set IIR filter for T, P

    // Enable Gas conversion

    // Set Heater Set Points Used

    // Define Heater On Times

    // Set Heater Temperatures

    // Set Mode to Sequential

    //
    // Parallel mode
    //

    // Set oversampling for T, P, RH

    // Set IIR filter for T, P

    // Enable Gas conversion

    // Set Heater Set Points Used

    // Set Wait Time Between TPHG Sub-Measurements

    // Define Heater On Times

    // Set Heater Temperatures

    // Set Mode to Parallel

}
