#include <Wire.h>
#include "paj7620.h"
#include <BleKeyboard.h>

#define SDA_PIN 6
#define SCL_PIN 7

BleKeyboard bleKeyboard("Controle Gestos ESP32", "Projeto PI", 100);

void setup() {
  Serial.begin(115200);
  delay(1000);

  Wire.begin(SDA_PIN, SCL_PIN);

  Serial.println("Iniciando sensor PAJ7620...");

  uint8_t error = paj7620Init();

  if (error) {
    Serial.print("Erro ao iniciar PAJ7620. Codigo: ");
    Serial.println(error);
    while (1);
  }

  Serial.println("PAJ7620 iniciado com sucesso.");

  bleKeyboard.begin();

  Serial.println("Bluetooth iniciado.");
  Serial.println("Pareie no iPad com: Controle Gestos ESP32");
}

void loop() {
  uint8_t data = 0;

  paj7620ReadReg(0x43, 1, &data);

  if (data != 0) {
    if (bleKeyboard.isConnected()) {

      if (data == GES_RIGHT_FLAG) {
        Serial.println("Gesto: Direita");
        bleKeyboard.write('1');
      }

      else if (data == GES_LEFT_FLAG) {
        Serial.println("Gesto: Esquerda");
        bleKeyboard.write('2');
      }

      else if (data == GES_UP_FLAG) {
        Serial.println("Gesto: Cima");
        bleKeyboard.write('3');
      }

      else if (data == GES_DOWN_FLAG) {
        Serial.println("Gesto: Baixo");
        bleKeyboard.write('4');
      }

      else if (data == GES_FORWARD_FLAG) {
        Serial.println("Gesto: Aproximar");
        bleKeyboard.write('5');
      }

      else if (data == GES_BACKWARD_FLAG) {
        Serial.println("Gesto: Afastar");
        bleKeyboard.write('6');
      }

      else if (data == GES_CLOCKWISE_FLAG) {
        Serial.println("Gesto: Horario");
        bleKeyboard.write('7');
      }

      else if (data == GES_COUNT_CLOCKWISE_FLAG) {
        Serial.println("Gesto: Anti-horario");
        bleKeyboard.write('8');
      }

      delay(800);
    } else {
      Serial.println("Bluetooth ainda nao conectado.");
    }
  }

  delay(100);
}