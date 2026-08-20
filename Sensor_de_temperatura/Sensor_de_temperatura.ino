//G1, Laist, Negrotto, Gil, Godino

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BMP280 bmp;  

unsigned long delayTime;

void setup() {
  Serial.begin(115200);
  Serial.println(F("BMP280 test"));

  bool status;

  Wire.begin(21, 22);
  status = bmp.begin(0x76);
  if (!status) {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1)
      ;
  }
  Serial.println("-- Default Test --");
  delayTime = 1000;
  Serial.println();
}

void loop() {
  printValues();
  delay(delayTime);
}

void printValues() {
  Serial.print("Temperature = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(bmp.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Approx. Altitude = ");
  Serial.print(bmp.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");
  
  Serial.println();
}
