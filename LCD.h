#ifndef LCD_H
#define LCD_H
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

class LCD
{
private:
  byte Icon2[8] = {
      B11111,
      B11111,
      B11111,
      B11111,
      B11111,
      B11111,
      B11111,
      B11111};

public:
  void lcd_init(void);
  void print(int, uint8_t, bool);
  void lcd_clear(void);
  // void createCharacter ( int , byte );
  void printChar(int);
  void setCursor(int, int);
  void createCharacterTodos(void);
};
void LCD ::lcd_init(void)
{

  lcd.init();
  lcd.backlight();
}

void LCD ::print(int posicionChar, uint8_t columna, bool fila)
{
  lcd.setCursor(columna, fila);
  printChar(posicionChar);
}

void LCD ::lcd_clear(void)
{
  lcd.clear();
}

// void Actuador :: createCharacter( int posicion, byte caracter){
//   lcd.createChar( posicion, caracter );
// }

void LCD ::createCharacterTodos(void)
{
  lcd.createChar(0, Icon2);
}
void LCD ::printChar(int posicionChar)
{
  lcd.write(posicionChar);
}
void LCD ::setCursor(int columna, int fila)
{
  lcd.setCursor(columna, fila);
}

void LCD :: moveObjToRight(  ){

}
#endif