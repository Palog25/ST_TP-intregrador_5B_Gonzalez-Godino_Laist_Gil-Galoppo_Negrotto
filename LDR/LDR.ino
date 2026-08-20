//G1, Laist, Negrotto, Gil, Godino

int LDR = 35;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lectura = analogRead(LDR);
  int porcentaje = map(lectura, 0, 4095, 0, 100); //4095 si es esp, 1023 si es arduino

  Serial.println(porcentaje);

  if (porcentaje <= 50) {
    Serial.println("menor de 50");
  } else {
    Serial.println("mayor de 50");
  }

  delay(100);
}
