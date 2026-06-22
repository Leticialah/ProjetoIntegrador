# Sistema de Autoatendimento Sem Toque com Reconhecimento de Gestos

Projeto acadêmico desenvolvido na disciplina de Projeto Integrador com o objetivo de implementar um sistema de autoatendimento sem contato físico utilizando visão computacional, comunicação serial, sistemas embarcados e Bluetooth Low Energy (BLE).

O sistema permite que o usuário navegue por uma interface gráfica utilizando apenas gestos das mãos detectados por câmera, eliminando a necessidade de interação direta com telas ou botões físicos.

---

## Objetivo

Desenvolver um sistema de autoatendimento touchless capaz de reconhecer gestos manuais em tempo real para seleção e confirmação de senhas, integrando visão computacional, interface gráfica e comunicação embarcada.

A proposta busca:

* reduzir o contato com superfícies compartilhadas;
* tornar o processo de atendimento mais acessível e intuitivo;
* demonstrar a integração entre software e hardware;
* aplicar conceitos de visão computacional e sistemas embarcados;
* validar a comunicação entre aplicação desktop, ESP32 e dispositivos móveis.

---

## Arquitetura do Sistema

O projeto é dividido em quatro blocos principais:

| Bloco         | Componente                | Função                                             |
| ------------- | ------------------------- | -------------------------------------------------- |
| Entrada       | Webcam + MediaPipe        | Detecta e interpreta os gestos da mão              |
| Processamento | Aplicação Python          | Processa os landmarks e identifica os comandos     |
| Interface     | Qt                        | Gerencia a interface gráfica e a geração de senhas |
| Comunicação   | ESP32-C3 Super Mini + BLE | Recebe a senha e a transmite para o celular        |

### Fluxo de Funcionamento

1. O usuário posiciona a mão diante da câmera.
2. O MediaPipe realiza o rastreamento dos landmarks da mão.
3. O sistema interpreta os gestos definidos.
4. A aplicação Qt atualiza a interface conforme a interação.
5. Uma senha é gerada e enviada ao ESP32-C3 pela comunicação serial.
6. O ESP32-C3 transmite a senha via Bluetooth Low Energy.
7. O smartphone recebe a senha para exibição à equipe de atendimento.

---

## Tecnologias Utilizadas

### Software

* Python
* MediaPipe
* OpenCV
* PyAutoGUI
* Qt Creator
* Qt Widgets
* Qt Serial Port
* CMake
* PlatformIO
* Visual Studio Code

### Hardware

* ESP32-C3 Super Mini
* Cabo USB-C
* Smartphone com BLE
* Webcam

---

## Estrutura do Projeto

```text
ProjetoIntegrador/
│
├── qt/
│   ├── main.cpp
│   ├── mainwindow.cpp
│   ├── mainwindow.h
│   ├── mainwindow.ui
│   ├── ESP32Manager.cpp
│   └── ESP32Manager.h
│
├── visao_computacional/
│   └── sensormao.py
│
├── firmware/
│   └── main.cpp
│
├── docs/
│   ├── PC1
│   ├── PC2
│   ├── PC3
│   └── PC4
│
├── imagens/
│
├── CMakeLists.txt
├── platformio.ini
└── README.md
```

---

## Como Executar o Sistema

### 1. Aplicação de Visão Computacional

Instale as dependências:

```bash
pip install mediapipe opencv-python pyautogui
```

Execute:

```bash
python sensormao.py
```

---

### 2. Aplicação Qt

Abra o projeto no Qt Creator.

Compile utilizando:

```bash
CMake
Qt 6
```

Execute a aplicação.

---

### 3. Firmware ESP32-C3

Abra o projeto no PlatformIO.

Configure a porta correta no arquivo:

```ini
upload_port = COMx
monitor_port = COMx
```

Compile e envie o firmware:

```bash
PlatformIO: Upload
```

Abra o Monitor Serial:

```text
115200 baud
```

---

## Comunicação Bluetooth

O ESP32-C3 opera como dispositivo BLE.

Nome do dispositivo:

```text
Painel_Equipe_ESP32
```

As senhas recebidas pela aplicação Qt são retransmitidas para o smartphone através do BLE.

---

## Resultados Obtidos

O sistema atualmente apresenta:

* reconhecimento de gestos utilizando MediaPipe;
* rastreamento da mão em tempo real;
* navegação sem contato físico;
* geração automática de senhas;
* interface gráfica funcional em Qt;
* comunicação serial entre Qt e ESP32;
* transmissão das senhas via Bluetooth Low Energy;
* recebimento correto das informações no smartphone.

---

## Evidências

O repositório contém registros de:

* funcionamento do MediaPipe;
* integração com Qt;
* monitor serial do ESP32-C3;
* comunicação BLE;
* testes experimentais realizados durante o desenvolvimento.

---

## Equipe

* Letícia Lavigne Guedes Germano
* Pedro Henrique Alves Castello Branco
* Kauã da Silva Araújo
* Iuri Costa Mariante
* João Gabriel de Souza
* Cauê Lovis Santana

---

## Licença

Projeto acadêmico desenvolvido exclusivamente para fins educacionais e de pesquisa.
