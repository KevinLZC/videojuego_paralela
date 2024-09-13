#include "videojuego.h"
#include "Libraries.h"

LCD lcd;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  lcd.lcd_init();
  lcd.setCursor(0, 0);
  lcd.createCharacterTodos();
  lcd.printChar(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation
}
