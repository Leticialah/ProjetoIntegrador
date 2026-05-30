# Sistema Interativo de Holograma Controlado por Gestos

Projeto desenvolvido para a disciplina de Projeto Integrador, com foco em sistemas embarcados, interfaces touchless e interação holográfica utilizando reconhecimento de gestos.

## 📌 Objetivo

O projeto tem como objetivo desenvolver um sistema holográfico interativo capaz de reconhecer gestos manuais sem contato físico e controlar conteúdos multimídia em tempo real.

A proposta busca reduzir a necessidade de interação direta com telas touchscreen, contribuindo para:

* redução de possíveis riscos de contaminação;
* maior acessibilidade;
* interfaces mais modernas e intuitivas;
* aplicações touchless em ambientes compartilhados.

---

# 🧠 Tecnologias Utilizadas

## Hardware

* ESP32-C3 SuperMini
* Sensor gestual PAJ7620
* iPad para reprodução holográfica
* PCB desenvolvida no KiCad
* Estrutura holográfica baseada em Pepper's Ghost

---

## Software

* Arduino IDE
* Visual Studio Code
* KiCad
* GitHub

---

# 📡 Funcionalidades Implementadas

✅ Reconhecimento de gestos em tempo real
✅ Comunicação I2C entre ESP32 e PAJ7620
✅ Comunicação Bluetooth BLE
✅ Integração com iPad
✅ Controle touchless da reprodução holográfica
✅ Firmware modular em C++
✅ PCB preliminar desenvolvida no KiCad
✅ Modelagem 3D da PCB

---

# 🖐️ Gestos Reconhecidos

| Gesto                |
| -------------------- |
| Direita              |
| Esquerda             |
| Cima                 |
| Baixo                |
| Aproximar            |
| Afastar              |
| Rotação horária      |
| Rotação anti-horária |

---

# 🔌 Arquitetura do Sistema

O sistema é dividido em três blocos principais:

## Entrada

Sensor PAJ7620 responsável pela captura dos gestos.

## Processamento

ESP32-C3 SuperMini responsável pela leitura do sensor, interpretação dos comandos e comunicação BLE.

## Saída Holográfica

iPad responsável pela reprodução das animações holográficas.

---

# 🔄 Fluxo do Sistema

1. Usuário realiza gesto próximo ao sensor;
2. PAJ7620 detecta o movimento;
3. ESP32-C3 realiza leitura via I2C;
4. Firmware interpreta o gesto;
5. Comando é enviado via Bluetooth BLE;
6. iPad recebe o comando;
7. Reprodução holográfica é acionada.

---

# ⚡ Alimentação

O sistema opera em:

| Bloco          | Tensão |
| -------------- | ------ |
| Entrada USB    | 5V     |
| ESP32-C3       | 3.3V   |
| PAJ7620        | 3.3V   |
| Barramento I2C | 3.3V   |

A alimentação ocorre através da USB-C do ESP32-C3 SuperMini.

---

# 🧩 Bibliotecas Utilizadas

```cpp
#include <Wire.h>
#include "paj7620.h"
#include <BleKeyboard.h>
```

## Bibliotecas

| Biblioteca    | Função                    |
| ------------- | ------------------------- |
| Wire.h        | Comunicação I2C           |
| paj7620.h     | Leitura dos gestos        |
| BleKeyboard.h | Comunicação Bluetooth BLE |

---

# 📁 Estrutura do Repositório

```bash
ProjetoIntegrador/
│
├── firmware/
│   ├── main.ino
│   ├── ble_control/
│   ├── gesture_read/
│   └── libraries/
│
├── hardware/
│   ├── esquematico/
│   ├── pcb/
│   ├── pcb_3d/
│   └── kicad/
│
├── docs/
│   ├── PC1/
│   ├── PC2/
│   ├── PC3/
│   └── referencias/
│
├── imagens/
│   ├── pcb/
│   ├── testes/
│   ├── bluetooth/
│   └── holograma/
│
└── README.md
```

---

# 🖥️ Firmware

O firmware foi desenvolvido em C++ utilizando Arduino IDE.

## Estrutura Modular

* Inicialização do sensor;
* Comunicação I2C;
* Interpretação dos gestos;
* Comunicação Bluetooth BLE;
* Envio dos comandos;
* Monitoramento serial.

---

# 📶 Comunicação BLE

O ESP32-C3 opera utilizando o perfil:

## BLE Keyboard

Nome Bluetooth utilizado nos testes:

```txt
Controle Gestos ESP32
```

---

# 🧪 Resultados Obtidos

Até o PC3, o sistema já apresenta:

✅ Detecção funcional de gestos
✅ Comunicação BLE operacional
✅ Integração com iPad
✅ Reprodução holográfica em desenvolvimento
✅ PCB preliminar funcional
✅ Modelagem 3D da placa

---

# ⚠️ Limitações Atuais

* refinamento da sincronização holográfica;
* influência parcial da iluminação ambiente;
* compactação futura da PCB;
* melhorias na integração física definitiva.

---

# 🚀 Próximas Etapas (PC4)

* otimização do firmware;
* refinamento da PCB;
* integração física definitiva;
* otimização da reprodução holográfica;
* validação experimental final.

---

# 📷 Imagens do Projeto

## PCB desenvolvida no KiCad

Adicionar:

* layout da PCB;
* visualização 3D frontal;
* visualização 3D traseira.

---

# 👨‍💻 Equipe

* Letícia Lavigne Guedes Germano
* Pedro Henrique Alves Castello Branco
* Kauã da Silva Araújo
* Iuri Costa Mariante
* João Gabriel de Souza
* Cauê Lovis Santana

---

# 📚 Referências

* ESP32-C3 Datasheet
* PAJ7620 Datasheet
* Arduino IDE Documentation
* Bluetooth BLE Documentation
* I2C Bus Specification
* KiCad Documentation

---

# 🔗 Repositório

GitHub do projeto:

```txt
https://github.com/Leticialah/ProjetoIntegrador
```

---

# 📄 Licença

Projeto acadêmico desenvolvido para fins educacionais.
