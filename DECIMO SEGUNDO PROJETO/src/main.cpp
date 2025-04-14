#include <Arduino.h>
#define pinled 2
void setup()
{
  pinMode(pinled, OUTPUT);
  Serial.begin(9600);
  Serial.print("comunicacao serial iniciada\n\r");
}

void loop()
{
  static bool piscaled = false;
  static bool estadoled = 0;
  static int velocidade = 0;
  if (Serial.available())
  {
    String Msg = Serial.readStringUntil('\n');
    Msg.trim();

    if (Msg.equalsIgnoreCase("liga"))
    {
      piscaled = false;
      estadoled = true;
    }
    else if (Msg.equalsIgnoreCase("desliga"))
    {
      estadoled = false;
      piscaled = false;
    }
    else if (Msg.equalsIgnoreCase("pisca"))
    {
      piscaled = true;
    }

    else if (Msg.equalsIgnoreCase("mais rapido") && piscaled)
    {
      velocidade += 200;
    }
    else if (Msg.equalsIgnoreCase("mais devagar")&&piscaled)
    {
      velocidade -= 200;
    }
    if (Msg.startsWith("velocidade = "))
    {
      int tamanho = Msg.length();
      String extracao = Msg.substring(13, tamanho);
      Serial.println(extracao);
    }
    
  }
  unsigned long tempoatual = millis();
  static unsigned long tempoinicial = 0;

  if (piscaled)
  {
    if (tempoatual - tempoinicial > velocidade)
    {
      estadoled = !estadoled;
      tempoinicial = tempoatual;
    }
  }

  digitalWrite(pinled, estadoled);
}
