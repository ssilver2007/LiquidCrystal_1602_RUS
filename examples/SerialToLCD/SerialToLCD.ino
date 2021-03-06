#include <LiquidCrystal_1602_RUS.h>

LiquidCrystal_1602_RUS lcd(8, 9, 4, 5, 6, 7 );//For LCD Keypad Shield

void setup()
{
  lcd.begin(16, 2);
  lcd.print(L"Ввод с монитора");
  lcd.setCursor(0,1);
  lcd.print(L"порта");
  // initialize the serial communications:
  Serial.begin(9600);
}

void loop() {
  unsigned char str;
  
  // when characters arrive over the serial port...
  if (Serial.available())
  {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    lcd.setCursor(0,0);
    // read all the available characters
    while (Serial.available() > 0)
    {
      // display each character to the LCD
      str = Serial.read();
      lcd.print(lcd.asciiutf8(str));//Вывод на экран LCD, в т.ч. по-русски. Перевод из ASCII в UTF-8.
    }
    Serial.println();
  }
}
