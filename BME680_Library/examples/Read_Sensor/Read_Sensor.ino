#include <BME680_Library.h>
#include <Wire.h>

BME680_Library bme680;

void setup(void){
  Wire.begin();
  Serial.begin(9600);

  Serial.print("BME Initialization...");
  if(bme680.begin()){
     Serial.println("Succeeded!");
     Serial.print("Config");
     Serial.println(bme680.set_config());
     Serial.println("Reading Sensor");
     Serial.println(bme680.read_sensor());
  }
  else {
    Serial.print("Failed!");
    for(;;); // spin forever
  }
}

void loop(void){
  bme680.read_sensor();
  delay(1000);
  Serial.print(bme680.gettemp());
  Serial.print(",");
  Serial.print(bme680.getpres());
  Serial.print(",");
  Serial.print(bme680.gethumidity());
  Serial.print(",");
  Serial.println(bme680.getgas());
}
