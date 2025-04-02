#include <Arduino.h>

int calculasegundograu(int, int, int);

void setup()
{
  Serial.begin(9600);
  int raizdafuncao;

  raizdafuncao=calculasegundograu(1,6,9);
  Serial.println(raizdafuncao);
  raizdafuncao=calculasegundograu(1,5,7);
  Serial.println(raizdafuncao);
}

void loop()
{
}
  int calculasegundograu(int a, int b, int c)
  {
    int resultado;

    resultado = -b + sqrt((b + b) - (4 * a * c)) / (2 * a);
    return resultado;
  }