#include <Wire.h>
#include <BME680.h>

BME680 bme680;

void setup(void){

  // Start serial and Wire
  Serial.begin(115200);
  Serial.println("BME680 Demonstration");
  Wire.begin();

  // Setup the sensor
  // Magic Happens Here

  // Print header for sensor output
  Serial.println("Temperature[C], Temperature[F], Humidity[%], Dewpoint[C], \
                  Dewpoint[F], Pressure[hPa], Altitude[m], Altitude[ft], VOC");
}

void loop(void){

  // Print sensor readings in a CSV format.
  // Output can easily be read into Excel or other data anaalysis tools.
  //Serial.print(bmp680.readTemperatureC(), 2);
  Serial.print(",");
  //Serial.print(bmp680.readTemperatureF(), 2);
  Serial.print(",");
  //Serial.print(bmp680.readHumidity(), 2);
  Serial.print(",");
  //Serial.print(bmp680.readDewpointC(), 2);
  Serial.print(",");
  //Serial.print(bmp680.readDewpointF(), 2);
  Serial.print(",");
  //Serial.print(bmp680.readPressure(), 2);
  Serial.print(",");
  //Serial.print(bmp680.readAltitudem(), 2);
  Serial.print(",");
  //Serial.print(bmp680.readAltitudeft(), 2);
  Serial.print(",");
  //Serial.println(bmp680.readVOC(), 2);

  delay(1000);

}
