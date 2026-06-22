#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define LED_STATUS 8

#define SERVICE_UUID        "12345678-1234-1234-1234-1234567890ab"
#define CHARACTERISTIC_UUID "abcd1234-5678-90ab-cdef-1234567890ab"

String comando = "";
String ultimaSenha = "";

BLECharacteristic *senhaCharacteristic;
bool dispositivoConectado = false;

class ServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer *server) override {
    dispositivoConectado = true;
    Serial.println("Celular conectado ao BLE");
  }

  void onDisconnect(BLEServer *server) override {
    dispositivoConectado = false;
    Serial.println("Celular desconectado do BLE");
    BLEDevice::startAdvertising();
  }
};

void piscarLed(int vezes, int tempoMs) {
  for (int i = 0; i < vezes; i++) {
    digitalWrite(LED_STATUS, HIGH);
    delay(tempoMs);
    digitalWrite(LED_STATUS, LOW);
    delay(tempoMs);
  }
}

bool senhaValida(const String& senha) {
  if (senha.length() != 4) return false;
  if (senha.charAt(0) != 'A') return false;

  for (int i = 1; i < 4; i++) {
    if (!isDigit(senha.charAt(i))) return false;
  }

  return true;
}

void enviarBluetooth(const String& senha) {
  senhaCharacteristic->setValue(senha.c_str());

  if (dispositivoConectado) {
    senhaCharacteristic->notify();
    Serial.println("BLE enviado: " + senha);
  } else {
    Serial.println("BLE aguardando celular. Valor atualizado: " + senha);
  }
}

void processarComando(String cmd) {
  cmd.trim();

  if (cmd.startsWith("SENHA:")) {
    String senha = cmd.substring(6);
    senha.trim();

    if (senhaValida(senha)) {
      ultimaSenha = senha;

      digitalWrite(LED_STATUS, HIGH);
      delay(500);
      digitalWrite(LED_STATUS, LOW);

      enviarBluetooth(senha);

      Serial.println("OK:" + senha);
    } else {
      Serial.println("ERRO:SENHA_INVALIDA");
      piscarLed(3, 150);
    }
  }
  else if (cmd == "PING") {
    Serial.println("PONG");
  }
  else if (cmd == "ULTIMA") {
    if (ultimaSenha == "") {
      Serial.println("ULTIMA:---");
    } else {
      Serial.println("ULTIMA:" + ultimaSenha);
    }
  }
  else {
    Serial.println("ERRO:COMANDO_DESCONHECIDO");
    piscarLed(2, 150);
  }
}

void iniciarBLE() {
  BLEDevice::init("Painel_Equipe_ESP32");

  BLEServer *server = BLEDevice::createServer();
  server->setCallbacks(new ServerCallbacks());

  BLEService *service = server->createService(SERVICE_UUID);

  senhaCharacteristic = service->createCharacteristic(
    CHARACTERISTIC_UUID,
    BLECharacteristic::PROPERTY_READ |
    BLECharacteristic::PROPERTY_NOTIFY
  );

  senhaCharacteristic->addDescriptor(new BLE2902());
  senhaCharacteristic->setValue("Aguardando senha");

  service->start();

  BLEAdvertising *advertising = BLEDevice::getAdvertising();
  advertising->addServiceUUID(SERVICE_UUID);
  advertising->setScanResponse(true);
  advertising->setMinPreferred(0x06);
  advertising->setMinPreferred(0x12);

  BLEDevice::startAdvertising();
}

void setup() {
  pinMode(LED_STATUS, OUTPUT);
  digitalWrite(LED_STATUS, LOW);

  Serial.begin(115200);
  delay(1000);

  iniciarBLE();

  Serial.println("ESP32-C3 pronto");
  Serial.println("BLE nativo: Painel_Equipe_ESP32");
  Serial.println("Aguardando comandos...");
  Serial.println("Formato esperado: SENHA:A001");

  piscarLed(2, 200);
}

void loop() {
  while (Serial.available() > 0) {
    char c = Serial.read();

    if (c == '\n') {
      processarComando(comando);
      comando = "";
    } else {
      comando += c;
    }
  }
}
