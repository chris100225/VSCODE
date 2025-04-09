#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup()
{
  Serial.begin(9600);
  SerialBT.begin("espdochris");
  SerialBT.println("Qual led voce deseja ligar? ");
  SerialBT.println("Led A \n\r Led B\n\rLed C\n\rLed D\n\r");
}

void loop()
{
  if (SerialBT.available()) //identifica se algo nao foi lido
  {
    
  char led = SerialBT.read();
}
}