//G1, Laist, Negrotto, Gil, Godino
int pot = A0;

int led1 = 2;
int led2 = 3;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int lectura = analogRead(pot);

  int porcentaje = map(lectura, 0, 4095, 0, 100); //4095 si es esp, 1023 si es arduino

  Serial.println(porcentaje);

  if (porcentaje <= 50) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }
  delay(100);
}
