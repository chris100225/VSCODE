#include <Arduino.h>
#define pinbutton 5
#define pinled 4

void setup()
{
  pinMode(pinled, OUTPUT);
  pinMode(pinbutton, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop()
{
  bool statebutton = digitalRead(pinbutton);
  static bool previousstate = 1;
  static bool action = 1;
  static unsigned long previoustimedebounce = 0;
  unsigned long timenow = millis();
  const unsigned long timebounce = 50;
  static int count = 0;

  // marca quando uma mudanca de estado acontece

  if (statebutton != previousstate)
  {
    previoustimedebounce = timenow;
  }
  // comeca o tratamento de ruido do botao

  // ve se a mudanca de estado esta ligado a bastante tempo
  if ((timenow - previoustimedebounce) > timebounce)
  {
    // houve uma alteracao proposital do botao?
    if (statebutton != action)
    {
      action = statebutton;
      if (!statebutton)
      {
        // botao foi pressionado
        count++;
        Serial.println(count);
      }
      else
      {
        // botao foi solto
      }
    }
  }
  previousstate = statebutton;
}
