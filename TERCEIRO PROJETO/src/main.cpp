#include <Arduino.h>
#define pinled 4

void piscaled(uint8_t);
void setup()
{
  pinMode(pinled, OUTPUT);
}

void loop()
{
  piscaled(pinled);
}
void piscaled(uint8_t pin)
{
  digitalWrite(pin, 1);
  delay(300);
  digitalWrite(pin, 0);
  delay(300);
}