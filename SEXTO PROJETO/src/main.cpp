#include <Arduino.h>
int valor = 0;
int pin51 = 4;
int pin52 = 5;

bool estadoatual51 = false;
bool estadoatual52 = false;
bool estadoanterior51 = false;
bool estadoanterior52 = false;
void setup()
{
  pinMode(pin51, INPUT);
  pinMode(pin52, INPUT);
  Serial.begin(9600);
}

void loop()
{
  estadoatual51 = digitalRead(pin51);
  estadoatual52 = digitalRead(pin52);

  if (estadoatual51 != estadoanterior51 || estadoatual52 != estadoanterior52)
  {
    estadoanterior51 = estadoatual51;
    estadoanterior52 = estadoatual52;

    Serial.print(estadoatual51);
    Serial.print(" ");
    Serial.println(estadoatual52);
    if (estadoatual51 && estadoatual52)
    {
      Serial.println("_____________________");
    }
  }
}
