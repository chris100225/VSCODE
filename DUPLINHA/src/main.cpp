#include <Arduino.h>
#include <BluetoothSerial.h>
#define pinled 2

BluetoothSerial SerialBT;
// espslave
void setup()
{
  Serial.begin(9600);
  SerialBT.begin("ESPdochris");
  Serial.println("Esperando uma conexao bluetooth");
  pinMode(pinled, OUTPUT);
}

void loop()
{
  if (SerialBT.available())
  {
    String mensagem = SerialBT.readStringUntil('\r');
    Serial.printf("Mensagem recebida: %s\n\r", mensagem);
    if (mensagem.equalsIgnoreCase("liga"))
    {
      SerialBT.print("Led ligado\n\r");
      digitalWrite(pinled, HIGH);

    }else if (mensagem.equalsIgnoreCase("desliga"))
    {
      SerialBT.print("Led desligado\n\r");
      digitalWrite(pinled, LOW);
    }
    
  }
}
