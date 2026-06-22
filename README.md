# Sistema de Autoatendimento Sem Toque com Reconhecimento de Gestos

Projeto desenvolvido na disciplina de Projeto Integrador com o objetivo de implementar um sistema de autoatendimento touchless utilizando visão computacional, interface gráfica e comunicação embarcada.

O sistema permite que usuários realizem a seleção de opções e a geração de senhas através de gestos manuais detectados por uma câmera, eliminando a necessidade de contato físico com telas ou botões.

---

# Objetivo

Desenvolver um sistema de autoatendimento sem toque capaz de:

- reconhecer gestos da mão em tempo real;
- permitir navegação em uma interface gráfica;
- gerar senhas automaticamente;
- transmitir as senhas para um painel de atendimento;
- integrar visão computacional, software desktop e sistemas embarcados.

---

# Arquitetura do Sistema

O sistema é composto pelos seguintes módulos:

| Módulo | Tecnologia |
|----------|----------|
| Reconhecimento de Gestos | MediaPipe + OpenCV |
| Interface Gráfica | Qt |
| Comunicação Serial | Qt Serial Port |
| Sistema Embarcado | ESP32-C3 Super Mini |
| Comunicação Sem Fio | Bluetooth Low Energy (BLE) |
| Painel da Equipe | Smartphone |

## Fluxo de Funcionamento

1. A câmera captura a mão do usuário.
2. O MediaPipe realiza o rastreamento dos landmarks.
3. Os gestos são interpretados pelo software.
4. A interface Qt atualiza as opções exibidas.
5. O usuário confirma a seleção através de gestos.
6. A aplicação gera uma senha.
7. A senha é enviada ao ESP32-C3 via comunicação serial.
8. O ESP32-C3 transmite a senha utilizando BLE.
9. O smartphone recebe a senha para atendimento.

---

# Tecnologias Utilizadas

## Visão Computacional

- Python
- MediaPipe
- OpenCV
- PyAutoGUI

## Interface Gráfica

- Qt Creator
- Qt Widgets
- Qt Serial Port
- CMake
- C++

## Sistemas Embarcados

- ESP32-C3 Super Mini
- Bluetooth Low Energy (BLE)
- PlatformIO
- Arduino Framework

## Ferramentas de Desenvolvimento

- Visual Studio Code
- GitHub

---

# Estrutura do Projeto

```text
ProjetoIntegrador/
│
├── Qt/
│   ├── ESP32Manager.cpp
│   ├── ESP32Manager.h
│   ├── main.cpp
│   ├── mainwindow.cpp
│   ├── mainwindow.h
│   └── mainwindow.ui
│
├── visao_computacional/
│   └── sensormao.py
│
├── firmwaremacos/
│   └── main.cpp
│
├── firmwarewindows/
│   └── main.cpp
│
├── docs/
│   ├── PC1/
│   ├── PC2/
│   ├── PC3/
│   ├── PC4/
│   └── referencias/
│
├── imagens/
│
├── CMakeLists.txt
├── platformio.ini
└── README.md
```

---

# Descrição dos Diretórios

## Qt

Contém toda a aplicação gráfica desenvolvida em Qt, incluindo a interface principal, gerenciamento da comunicação serial com o ESP32-C3 e a lógica de geração de senhas.

## visao_computacional

Implementação do reconhecimento de gestos utilizando MediaPipe e OpenCV através do arquivo `sensormao.py`.

## firmwaremacos

Firmware utilizado para integração do ESP32-C3 em ambiente macOS.

## firmwarewindows

Firmware utilizado para integração do ESP32-C3 em ambiente Windows.

## docs

Documentação produzida ao longo do Projeto Integrador, incluindo as entregas PC1, PC2, PC3 e PC4, além das referências bibliográficas.

## imagens

Capturas de tela, registros experimentais e evidências de funcionamento utilizadas na documentação do projeto.

---

# Componentes Utilizados

| Componente | Função |
|------------|---------|
| ESP32-C3 Super Mini | Comunicação embarcada e BLE |
| Webcam | Captura dos gestos |
| Smartphone | Recebimento das senhas |
| Cabo USB-C | Alimentação e comunicação serial |
| Computador | Execução da interface Qt e visão computacional |

---

# Como Executar

## 1. Aplicação de Visão Computacional

Instale as dependências:

```bash
pip install mediapipe opencv-python pyautogui
```

Execute:

```bash
python sensormao.py
```

---

## 2. Aplicação Qt

Abra o projeto no Qt Creator.

Compile utilizando:

```text
Qt 6
CMake
```

Execute a aplicação principal.

---

## 3. Firmware ESP32-C3

Abra o projeto utilizando PlatformIO.

Configure a porta serial correta no arquivo `platformio.ini`.

Compile e envie o firmware:

```bash
PlatformIO: Upload
```

Abra o Monitor Serial:

```text
115200 baud
```

---

# Comunicação Bluetooth

O ESP32-C3 opera como dispositivo Bluetooth Low Energy.

Nome do dispositivo:

```text
Painel_Equipe_ESP32
```

A aplicação Qt envia a senha ao ESP32-C3 através da porta serial.

O ESP32-C3 retransmite a senha para o smartphone utilizando Bluetooth Low Energy.

---

# Resultados Obtidos

Durante os testes realizados, o sistema apresentou:

- reconhecimento de gestos utilizando MediaPipe;
- rastreamento da mão em tempo real;
- navegação sem contato físico;
- geração automática de senhas;
- interface gráfica funcional em Qt;
- comunicação serial entre Qt e ESP32;
- transmissão das senhas via BLE;
- recebimento correto das informações no smartphone;
- integração funcional entre software e hardware.

### Desempenho Experimental

| Parâmetro | Resultado |
|------------|------------|
| Taxa média de reconhecimento dos gestos | Superior a 90% |
| Tempo médio de resposta | 0,82 s |
| Menor tempo observado | 0,61 s |
| Maior tempo observado | 1,07 s |
| Distância máxima confiável de detecção | 80 cm |

---

# Evidências

O repositório contém registros de:

- detecção da mão utilizando MediaPipe;
- funcionamento da interface Qt;
- monitor serial do ESP32-C3;
- comunicação Bluetooth Low Energy;
- recebimento das senhas pelo smartphone;
- documentação técnica do projeto;
- relatórios PC1, PC2, PC3 e PC4.

---

# Repositório

O código-fonte e toda a documentação do projeto estão disponíveis em:

**https://github.com/Leticialah/ProjetoIntegrador**

---

# Equipe

- Letícia Lavigne Guedes Germano
- Pedro Henrique Alves Castello Branco
- Kauã da Silva Araújo
- Iuri Costa Mariante
- João Gabriel de Souza
- Cauê Lovis Santana

---

# Licença

Projeto acadêmico desenvolvido exclusivamente para fins educacionais e de pesquisa.
