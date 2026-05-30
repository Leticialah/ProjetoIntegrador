#include <Arduino.h>
#include <Wire.h>
#include "paj7620.h"
#include <BleKeyboard.h>

// =============================
// CONFIGURACAO DOS PINOS I2C
// =============================
// ESP32-C3 SuperMini utilizado no projeto:
// SDA -> GPIO 6
// SCL -> GPIO 7
// Se sua placa usar outros pinos, altere aqui.
#define SDA_PIN 6
#define SCL_PIN 7

// Nome que aparece no Bluetooth do iPad
BleKeyboard bleKeyboard("Controle Gestos ESP32", "Projeto PI", 100);

// Tempo para evitar varias leituras repetidas do mesmo gesto
const unsigned long TEMPO_ENTRE_GESTOS_MS = 800;
unsigned long ultimoGesto = 0;

void enviarTecla(char tecla, const char* nomeGesto) {
  if (!bleKeyboard.isConnected()) {
    Serial.println("Bluetooth ainda nao conectado ao iPad.");
    return;
  }

  unsigned long agora = millis();
  if (agora - ultimoGesto < TEMPO_ENTRE_GESTOS_MS) {
    return;
  }

  ultimoGesto = agora;

  Serial.print("Gesto detectado: ");
  Serial.print(nomeGesto);
  Serial.print(" -> enviando tecla: ");
  Serial.println(tecla);

  bleKeyboard.write(tecla);
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("====================================");
  Serial.println(" ESP32-C3 Mini + PAJ7620 + BLE Keyboard");
  Serial.println("====================================");

  Wire.begin(SDA_PIN, SCL_PIN);

  Serial.println("Iniciando sensor PAJ7620...");
  uint8_t erro = paj7620Init();

  if (erro) {
    Serial.print("Erro ao iniciar o PAJ7620. Codigo: ");
    Serial.println(erro);
    Serial.println("Verifique VCC, GND, SDA e SCL.");
    while (true) {
      delay(1000);
    }
  }

  Serial.println("PAJ7620 iniciado com sucesso.");

  bleKeyboard.begin();
  Serial.println("Bluetooth BLE iniciado.");
  Serial.println("No iPad, pareie com: Controle Gestos ESP32");
}

void loop() {
  uint8_t gesto = 0;

  // Registro 0x43 contem os gestos principais
  paj7620ReadReg(0x43, 1, &gesto);

  if (gesto != 0) {
    switch (gesto) {
      case GES_RIGHT_FLAG:
        enviarTecla('1', "Direita");
        break;

      case GES_LEFT_FLAG:
        enviarTecla('2', "Esquerda");
        break;

      case GES_UP_FLAG:
        enviarTecla('3', "Cima");
        break;

      case GES_DOWN_FLAG:
        enviarTecla('4', "Baixo");
        break;

      case GES_FORWARD_FLAG:
        enviarTecla('5', "Aproximar");
        break;

      case GES_BACKWARD_FLAG:
        enviarTecla('6', "Afastar");
        break;

      case GES_CLOCKWISE_FLAG:
        enviarTecla('7', "Horario");
        break;

      case GES_COUNT_CLOCKWISE_FLAG:
        enviarTecla('8', "Anti-horario");
        break;

      default:
        Serial.print("Gesto nao mapeado. Valor lido: ");
        Serial.println(gesto, HEX);
        break;
    }
  }

  delay(100);
}
