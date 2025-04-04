#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

byte  led[8] = {
	0b10001,
	0b00100,
	0b01010,
	0b10001,
	0b01010,
	0b00100,
	0b10001,
	0b00000
};byte led2[8] = {
	0b10001,
	0b00100,
	0b01110,
	0b11011,
	0b01110,
	0b00100,
	0b10001,
	0b00000
};byte led3[8] = {
	0b10001,
	0b00100,
	0b01110,
	0b11111,
	0b01110,
	0b00100,
	0b10001,
	0b00000
};byte select[8] = {
	0b00000,
	0b00000,
	0b00100,
	0b01000,
	0b11111,
	0b01000,
	0b00100,
	0b00000
};

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define botao 2
#define entradaA 5
#define entradaB 23

const int8_t tabelaTransicao[4][4] = {
// +1 horario 
// 0 parado 
// - 1 antihorario

// 0   1  2  3 ATUAL
  {0, 1, -1, 0}, // 0 anterior
  {-1, 0, 0, 1}, // 1 anterior
  {1, 0, 0, -1}, // 2 anterior
  {0, -1, 1, 0} // 3 anterior
  };

//* 32013201 HORARIO 
//* 10231023 ANTIHORARIO

void setup() {
  
  pinMode(entradaA, INPUT);
  pinMode(entradaB, INPUT);
  pinMode(botao, INPUT);

  Serial.begin(115200);

  lcd.init();
  lcd.backlight();

}

void loop() {
  
  bool leituraEntradaA = digitalRead(entradaA);
  bool leituraEntradaB = digitalRead(entradaB);
  int estadoAtualEncoder = ((leituraEntradaA << 1) | leituraEntradaB);
  static int estadoAnteriorEncoder = 3;

  static int posicao = 0;

  posicao = posicao + tabelaTransicao[estadoAnteriorEncoder][estadoAtualEncoder];

  Serial.println(posicao/4);
  lcd.print(posicao/4);



  estadoAnteriorEncoder = estadoAtualEncoder;
}