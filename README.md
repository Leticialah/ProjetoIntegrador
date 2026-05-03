# Sistema Interativo de Holograma Controlado por Gestos

## Descrição
Projeto de um sistema embarcado que utiliza o sensor de gestos PAJ7620 e um ESP32-C3 DevKit para detectar movimentos da mão e controlar a exibição de imagens em um dispositivo externo, como um iPad, criando um efeito visual de holograma.

## Funcionamento
1. O sensor PAJ7620 detecta gestos do usuário.
2. O ESP32 recebe os dados do sensor por comunicação I2C.
3. O firmware interpreta os gestos detectados.
4. O ESP32 pode enviar comandos via Wi-Fi ou Bluetooth para o iPad.
5. O iPad exibe as imagens responsáveis pelo efeito holográfico.

## Gestos Detectados
- Direita
- Esquerda
- Cima
- Baixo
- Aproximar
- Afastar
- Horário
- Anti-horário
- Acenar

## Hardware Utilizado
- ESP32-C3 DevKitM-1
- Sensor de gestos PAJ7620
- Resistores pull-up de 4.7kΩ para SDA e SCL
- Capacitor de desacoplamento de 100nF
- Conector de alimentação 2 pinos
- Conector do sensor 4 pinos
- PCB desenvolvida no KiCad

## Comunicação
- PAJ7620 ↔ ESP32: I2C
- ESP32 ↔ iPad: Wi-Fi ou Bluetooth
- Alimentação: 5V na entrada do ESP32 DevKit
- Lógica: 3.3V fornecidos pelo regulador interno do ESP32 DevKit

## Como Usar o Firmware
1. Abrir o arquivo `firmware/paj7620_gestos.ino` na Arduino IDE.
2. Instalar a biblioteca `DFRobot_PAJ7620U2`.
3. Selecionar a placa ESP32 correta.
4. Ajustar os pinos SDA e SCL no código, caso necessário.
5. Fazer upload para o ESP32.
6. Abrir o Monitor Serial em 115200 baud.
