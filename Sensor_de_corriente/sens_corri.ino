

//G1, Laist, Negrotto, Gil, Godino
#include <Wire.h>
#include <Adafruit_INA219.h>


Adafruit_INA219 ina219;


#define LED 32


void setup() {
  Serial.begin(115200);


  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);


  if (!ina219.begin()) {
    Serial.println("INA219 no encontrado");
    while (1);
  }


  Serial.println("INA219 encontrado");
}


void loop() {




  float corriente = ina219.getCurrent_mA();






  Serial.print("Corriente: ");
  Serial.print(corriente);
  Serial.println(" mA");






  Serial.println("----------------");


  // Prender LED
  digitalWrite(LED, HIGH);


  delay(1000);
}

