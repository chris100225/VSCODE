#include <Arduino.h>

char nome [20];
char nome2[20];

void setup() {
Serial.begin(9600);
strcpy(nome, "thiago");

Serial.println(nome);
strcat (nome, "Oliveiria");
Serial.println(nome);

int tamanho = strlen(nome);
Serial.println(tamanho);
if (strcmp("thiago Oliveiria", nome)==0) Serial.println ("iguais");
else Serial.println("diferentes");
if (strcmp("thiago Oliveiria", nome)==0) Serial.println ("iguais");
else Serial.println("diferentes");

if (strncmp(nome2, nome, 6)==0)
Serial.println("os 6 primeiros sao iguais");
else Serial.println("o comeco nao e igual");

char buffer [50];
int temperatura=25;
sprintf(buffer, "temperatura: %d°C", temperatura);
Serial.println(buffer);
}

void loop() {
}
