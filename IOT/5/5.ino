//Demonstration of Hello message on LCD Display

#include<LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("Hi im ");
  lcd.setCursor(1, 1);
  lcd.print("Yash Junagade");
  delay(2000);
}
