

//G1, Laist, Negrotto, Gil, Godino
#include <ld2410.h>


#define RX_PIN 16
#define TX_PIN 17


HardwareSerial radarSerial(2);


ld2410 radar;


void setup() {


  Serial.begin(115200);


  delay(1000);


 
  // UART del radar
  radarSerial.begin(256000, SERIAL_8N1, RX_PIN, TX_PIN);


  delay(500);


  // Iniciar radar
  if (radar.begin(radarSerial)) {


    Serial.println("LD2410C DETECTADO");
    Serial.println("Esperando presencia...");
    Serial.println();


  } else {


    Serial.println("ERROR: no se pudo iniciar el LD2410C");
    Serial.println("Revisar TX/RX y baudrate");
  }
}


void loop() {


  if (radar.read()) {


    Serial.println("-----------------------------");


    // Presencia
    if (radar.presenceDetected()) {
      Serial.println("PRESENCIA: SI");
    } else {
      Serial.println("PRESENCIA: NO");
    }


    // Objetivo en movimiento
    if (radar.stationaryTargetDetected()) {
      Serial.println("OBJETIVO ESTATICO: SI");
    } else {
      Serial.println("OBJETIVO ESTATICO: NO");
    }


    // Distancia del objetivo estático
    Serial.print("Distancia estatica: ");
    Serial.print(radar.stationaryTargetDistance());
    Serial.println(" cm");


    // Energía del objetivo estático
    Serial.print("Energia estatica: ");
    Serial.println(radar.stationaryTargetEnergy());


    // Objetivo en movimiento
    if (radar.movingTargetDetected()) {


      Serial.print("Distancia movimiento: ");
      Serial.print(radar.movingTargetDistance());
      Serial.println(" cm");


      Serial.print("Energia movimiento: ");
      Serial.println(radar.movingTargetEnergy());


    } else {


      Serial.println("OBJETIVO EN MOVIMIENTO: NO");
    }
  }


  delay(100);
}

