#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

// coracao
byte gardenia[8] = {
    0b00000,
    0b00000,
    0b01010,
    0b11111,
    0b01110,
    0b00100,
    0b00000,
    0b00000};

// pedra
byte pedrito[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b01110,
    0b11111,
    0b11111,
    0b11111};

// casa
byte casita[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b00100,
    0b01110,
    0b11111,
    0b01010,
    0b01010};

// brilho de conclusa
byte brilho[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00100,
    0b01110,
    0b00100};

// nuvem
byte nuvem[8] = {
    0b00000,
    0b00000,
    0b01110,
    0b11111,
    0b00000,
    0b00000,
    0b00000,
    0b00000};

// lua
byte lua[8] = {
    0b00000,
    0b00000,
    0b01110,
    0b11001,
    0b11000,
    0b11001,
    0b01110,
    0b00000};

// nuvem baixa
byte nuvemBaixa[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b01110,
    0b11111};

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define pinLed 4
#define botaoDireita 5
#define botaoPula 18

static int posicaoGardeniaAtualX = 0;
int posicaoGardeniaAnteriorX = 0;
int posicaoGardeniaAtualY = 3;
int posicaoGardeniaAnteriorY = 3;

int posicaoApagar1[2] = {5, 3};
int posicaoApagar2[2] = {11, 3};
int posicaoApagar3[2] = {6, 2};
int posicaoApagar4[2] = {12, 2};
int posicaoApagar5[2] = {18, 3};
int posicaoPedra1[2] = {0, 3};
int posicaoPedra2[2] = {0, 3};

void pula();
void anda();

void setup()
{
  pinMode(pinLed, OUTPUT);
  pinMode(botaoDireita, INPUT_PULLUP);
  pinMode(botaoPula, INPUT_PULLUP);

  Serial.begin(115200);

  randomSeed(analogRead(1));
  lcd.init();
  lcd.backlight();

  posicaoPedra1[0] = random(3,9);
  posicaoPedra2[0] = random(11,18);

  // cria os caracteres especiais (elementos)
  lcd.createChar(0, gardenia);
  lcd.createChar(1, pedrito);
  lcd.createChar(2, casita);
  lcd.createChar(3, brilho);
  lcd.createChar(4, nuvem);
  lcd.createChar(5, lua);
  lcd.createChar(6, nuvemBaixa);

  // imprime o coracao
  lcd.setCursor(0, 3);
  lcd.write(0);

  // imprime a primeira pedra
  lcd.setCursor(posicaoPedra1[0], 3);
  lcd.write(1);

  // imprime a segunda pedra
  lcd.setCursor(posicaoPedra2[0], 3);
  if(posicaoGardeniaAtualY == 3){
    posicaoGardeniaAtualY--;
  }
  lcd.setCursor(posicaoGardeniaAtualX, posicaoGardeniaAtualY);
  lcd.write(0);
  if (posicaoGardeniaAtualX >= 19)
  {
    lcd.setCursor(19, 2);
    lcd.write(2);
    digitalWrite(pinLed, HIGH);
    posicaoGardeniaAtualX = 0;
    lcd.setCursor(19, 1);
    lcd.write(3);
  }
}

// faz o coracao andar para direita
void anda()
{
  posicaoGardeniaAnteriorX = posicaoGardeniaAtualX;
  posicaoGardeniaAnteriorY = posicaoGardeniaAtualY;
  posicaoGardeniaAtualX++;
  Serial.print(posicaoGardeniaAtualX);
  if(posicaoGardeniaAtualY == 2){
    posicaoGardeniaAtualY = 3;
  }
  if (posicaoGardeniaAtualX != posicaoPedra1[0] && posicaoGardeniaAtualX != posicaoPedra2[0])
  {
    lcd.setCursor(posicaoGardeniaAtualX - 1, posicaoGardeniaAnteriorY);
    lcd.print(" ");
    lcd.setCursor(posicaoGardeniaAtualX, posicaoGardeniaAtualY);
    lcd.write(0);
  }
  else
  {
    lcd.setCursor(4, 2);
    lcd.print("VOCE PERDEU!");
  }
  if (posicaoGardeniaAtualX >= 19)
  {
    posicaoGardeniaAtualX = 0;
  }
}