#include <Arduino.h>
/*struct pessoa
{
  char nome[40];
  int idade;
  float altura;
  bool calvice;
};

pessoa aluno;
pessoa professor;*/

struct rgb
{
int red;
int green;
int blue;
};

rgb roxo;
rgb rosa;
rgb amarelo;
rgb azul;
rgb preto;

void setup() {
  Serial.begin(9600);
  

  roxo.red =166;
  roxo.green =163;
  roxo.blue=225;

  Serial.printf("rgb para roxo: %d", roxo.red);
  Serial.printf(",  %d", roxo.green);
  Serial.printf(",  %d\n\r", roxo.blue);

  rosa.red =219;
  rosa.green =140;
  rosa.blue=199;

  Serial.printf("rgb para rosa: %d", rosa.red);
  Serial.printf(",  %d", rosa.green);
  Serial.printf(",  %d\n\r", rosa.blue);

  amarelo.red =255;
  amarelo.green =240;
  amarelo.blue=166;

  Serial.printf("rgb para amarelo: %d", amarelo.red);
  Serial.printf(",  %d", amarelo.green);
  Serial.printf(",  %d\n\r", amarelo.blue);
  
  preto.red =0;
  preto.green =0;
  preto.blue=0;

  Serial.printf("rgb para preto: %d", preto.red);
  Serial.printf(",  %d", preto.green);
  Serial.printf(",  %d\n\r", preto.blue);

  azul.red =92;
  azul.green =130;
  azul.blue=255;

  Serial.printf("rgb para azul: %d", azul.red);
  Serial.printf(",  %d", azul.green);
  Serial.printf(",  %d\n\r", azul.blue);

/*  strcpy(aluno.nome, "Chris");
  aluno.idade = 18;
  aluno.altura = 1.70;
  aluno.calvice=true;

strcpy(professor.nome, "Thigas");
professor.idade = 47;
professor.altura = 1.80;
professor.calvice= false;

  Serial.printf("meu nome eh: %s \n\r", aluno.nome);
  Serial.printf("E tenho %d anos\n\r", aluno.idade);
  Serial.printf("tenho %.2f metros de altura\n\r", aluno.altura, aluno.calvice);
  Serial.printf("e %s calvo", aluno.calvice ? "sou" : "ainda nao sou");

  Serial.printf("meu nome eh: %s \n\r", professor.nome);
  Serial.printf("E tenho %d anos\n\r", professor.idade);
  Serial.printf("tenho %.2f metros de altura\n\r", professor.altura, professor.calvice);
  Serial.printf("e %s calvo", professor.calvice ? "sou" : "ainda nao sou");
*/
}
void loop() {

}
