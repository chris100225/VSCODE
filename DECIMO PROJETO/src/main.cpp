#include <Arduino.h>
#include "BluetoothSerial.h"
#define pinled 2
String palavra = "";











BluetoothSerial SerialBT;

void setup()
{
  Serial.begin(9600);
  SerialBT.begin("espdochris");
  SerialBT.println("digite algo no monitor: ");
  pinMode(pinled, OUTPUT);
  
}

void loop()
{
  if (SerialBT.available())
  {
    
char caractere = SerialBT.read();
if (caractere=='\n'){
  SerialBT.println(palavra);
  if (palavra.equals("liga"))
  {
    digitalWrite(pinled, HIGH);
  }else if (palavra.equals("desliga"))
  {
    digitalWrite(pinled, LOW);
  }else
  {
    Serial.println("comando nao identificado");
  }
palavra="";
}else if (caractere!='\r')
{
  palavra+=caractere;
}


/*if (caractere=='L')
{
digitalWrite(pinled, HIGH);
Serial.println("led ligado");}else if (caractere=='D')
{
  digitalWrite(pinled, LOW);
  Serial.println("led desligado");
}else
{
  Serial.println ("so funciona se for L ou D bobao");
  Serial.printf("voce colocou %c\n\r", caractere);
}*/



  }
}