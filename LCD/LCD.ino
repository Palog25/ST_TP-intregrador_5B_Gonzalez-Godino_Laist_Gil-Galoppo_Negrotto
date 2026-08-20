//G1, Laist, Negrotto, Gil, Godino

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SDA_PIN 21
#define SCL_PIN 22

int lcdColumns = 16;//(0,1,2…)
int lcdRows = 2; //(0,1)

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  //direccion, columnas y filas

String messageStatic = "Hola";
String messageToScroll = "  Chau";

void scrollText(int row, String message, int delayTime, int lcdColumns) {
  for (int i=0; i < lcdColumns; i++) {
    message = " " + message;  
  }
  message = message + " ";
  for (int pos = 0; pos < message.length(); pos++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(pos, pos + lcdColumns));
    delay(delayTime);
  }
}
void setup(){
Wire.begin(SDA_PIN, SCL_PIN);
  lcd.init();                    
  lcd.backlight();
}

void loop(){
  lcd.setCursor(0, 0); //poner cursor en columna 1 y fila 1
   lcd.print(messageStatic);//msj fijo
  scrollText(1, messageToScroll, 250, lcdColumns); //msj que se mueve
}
