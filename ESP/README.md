# Sistema Interativo de Holograma Controlado por Gestos

## 📌 Descrição
Projeto de um sistema embarcado que utiliza o sensor de gestos PAJ7620 e um ESP32 para controlar a exibição de imagens em um dispositivo externo (iPad), criando um efeito de holograma.

## 🧠 Funcionamento
1. O sensor PAJ7620 detecta gestos do usuário
2. O ESP32 processa os dados via I2C
3. O sistema envia comandos via Wi-Fi/Bluetooth
4. O iPad exibe as imagens correspondentes

## 🔧 Hardware Utilizado
- ESP32-C3 DevKit
- Sensor de gestos PAJ7620
- Resistores de pull-up (4.7kΩ)
- Capacitor de desacoplamento (100nF)
- Conectores (2.54mm)

## 🖥️ PCB
O layout da placa foi desenvolvido no KiCad, contendo:
- plano de GND
- roteamento das trilhas principais
- organização dos blocos (alimentação, sensor, processamento)

## 📁 Estrutura
- `/kicad`: arquivos do projeto eletrônico
- `/docs`: relatório e imagens
- `/firmware`: código do ESP32

## 👨‍💻 Autor
Seu nome aqui
