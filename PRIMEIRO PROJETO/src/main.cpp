#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

//instancia objetos
LiquidCrystal_I2C lcd(0x27,20,4);
void setup()
{
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.print("perdao por mexer no ar condicionado");
}

void loop()
{
}