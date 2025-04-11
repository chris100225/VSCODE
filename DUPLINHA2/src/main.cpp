#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup()
{

  Serial.begin(9600);
  SerialBT.begin("ESPMASTER", true); //se torna visivel a outros dispositivos
  SerialBT.connect("ESPBatata");//conecta com outro esp

  if (SerialBT.connect("ESPBatata"))
  {
    Serial.println("conectado ao dispositivo");
  }
  else
  {
    Serial.println("Deu ruim");
    while (true)
      ;
  }
}

void loop()
{
  SerialBT.print("PING");
  Serial.println("Enviado mensagem");

  unsigned long timeout = millis() + 1000;
  while (millis() < timeout)
  {
    if (SerialBT.available())
    {
      String resposta = SerialBT.readStringUntil('\r');
      Serial.printf("resposta: %s", resposta);
      break;
    }
  }
}
