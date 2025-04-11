#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

String led = "";
void setup()
{
  Serial.begin(9600);
  SerialBT.begin("espdochris");
  SerialBT.println("Qual led voce deseja ligar? ");
  SerialBT.println("Led A \n\r Led B\n\rLed C\n\rLed D\n\r");
}

void loop()
{

  static int intensidadeLed[4] = {0, 0, 0, 0};
  static int ledselecionado = 0;
  if (SerialBT.available()) // identifica se algo nao foi lido
  {

    char leitura = SerialBT.read();
    if (leitura == '\n')
    {
      SerialBT.println(led);
      if (led.equals("led A"))
      {
        ledselecionado = 1;
        if (intensidadeLed[ledselecionado] > 100)
          intensidadeLed[ledselecionado] = 100;
        else if (intensidadeLed[ledselecionado] < 0)
          intensidadeLed[ledselecionado] = 0;

        SerialBT.println("O led A esta ligado");
      }
      else if (led.equals("led B"))
      {
        ledselecionado = 2;
        if (intensidadeLed[ledselecionado] > 100)
          intensidadeLed[ledselecionado] = 100;
        else if (intensidadeLed[ledselecionado] < 0)
          intensidadeLed[ledselecionado] = 0;

        SerialBT.println("O led B esta ligado");
      }
      else if (led.equals("led C"))
      {
        ledselecionado = 3;
        if (intensidadeLed[ledselecionado] > 100)
          intensidadeLed[ledselecionado] = 100;
        else if (intensidadeLed[ledselecionado] < 0)
          intensidadeLed[ledselecionado] = 0;

        SerialBT.println("O led C esta ligado");
      }
      else if (led.equals("led D"))
      {
        ledselecionado = 4;
        if (intensidadeLed[ledselecionado] > 100)
          intensidadeLed[ledselecionado] = 100;
        else if (intensidadeLed[ledselecionado] < 0)
          intensidadeLed[ledselecionado] = 0;

        SerialBT.println("O led D esta ligado");
      }
    }
  }
}