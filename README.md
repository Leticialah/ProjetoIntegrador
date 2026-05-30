# Sistema Interativo de Holograma Controlado por Gestos

Projeto acadêmico de um sistema **touchless** para controle de uma interface holográfica por gestos manuais.

O sistema utiliza um **ESP32-C3 SuperMini**, um sensor gestual **PAJ7620** e comunicação **Bluetooth BLE**. O ESP32-C3 funciona como um teclado Bluetooth e envia comandos para um iPad, que reproduz vídeos ou animações de acordo com o gesto detectado.

---

## Objetivo

Desenvolver um sistema holográfico interativo capaz de reconhecer gestos manuais e controlar conteúdos multimídia em tempo real, evitando contato físico direto com telas.

A proposta busca:

- reduzir o contato com superfícies compartilhadas;
- criar uma interface mais intuitiva;
- demonstrar integração entre hardware, firmware, BLE e interface visual;
- aplicar conceitos de sistemas embarcados e comunicação I2C.

---

## Arquitetura do sistema

O projeto é dividido em três blocos principais:

| Bloco | Componente | Função |
|---|---|---|
| Entrada | PAJ7620 | Detecta os gestos da mão |
| Processamento | ESP32-C3 SuperMini | Lê o sensor, interpreta o gesto e envia comando BLE |
| Saída | iPad | Reproduz o vídeo/animação holográfica |

Fluxo de funcionamento:

1. O usuário realiza um gesto próximo ao sensor.
2. O PAJ7620 identifica o movimento.
3. O ESP32-C3 lê o gesto via I2C.
4. O firmware interpreta o comando.
5. O ESP32-C3 envia uma tecla via BLE Keyboard.
6. O iPad recebe a tecla.
7. A interface HTML reproduz o vídeo correspondente.

---

## Componentes utilizados

| Componente | Função |
|---|---|
| ESP32-C3 SuperMini | Microcontrolador principal |
| PAJ7620 | Sensor de reconhecimento de gestos |
| iPad | Reprodução holográfica |
| Protoboard | Montagem experimental |
| PCB preliminar | Organização física da arquitetura eletrônica |
| Cabo USB-C | Alimentação e gravação |

---

## Ligações elétricas

| PAJ7620 | ESP32-C3 SuperMini |
|---|---|
| VCC | 3V3 |
| GND | GND |
| SDA | GPIO 6 |
| SCL | GPIO 7 |

O sistema utiliza alimentação via USB-C. O ESP32-C3 recebe 5V pela porta USB e fornece 3.3V para o sensor.

---

## Bibliotecas utilizadas

No firmware foram usadas as seguintes bibliotecas:

```cpp
#include <Wire.h>
#include "paj7620.h"
#include <BleKeyboard.h>
```

| Biblioteca | Função |
|---|---|
| Wire.h | Comunicação I2C |
| paj7620.h | Inicialização e leitura do sensor PAJ7620 |
| BleKeyboard.h | Comunicação Bluetooth BLE como teclado |

---

## Mapeamento dos gestos

| Gesto detectado | Tecla enviada |
|---|---|
| Direita | 1 |
| Esquerda | 2 |
| Cima | 3 |
| Baixo | 4 |
| Aproximar | 5 |
| Afastar | 6 |
| Rotação horária | 7 |
| Rotação anti-horária | 8 |

---

## Como usar com PlatformIO no VS Code

1. Instale o **VS Code**.
2. Instale a extensão **PlatformIO IDE**.
3. Abra a pasta raiz deste repositório.
4. Conecte o ESP32-C3 SuperMini ao computador.
5. Confira o arquivo `platformio.ini`.
6. Faça upload do firmware.
7. Abra o Monitor Serial em `115200 baud`.
8. No iPad, pareie com o dispositivo Bluetooth:

```txt
Controle Gestos ESP32
```

---

## Como usar com Arduino IDE

1. Abra o arquivo:

```txt
firmware/main.ino
```

2. Instale as bibliotecas necessárias.
3. Selecione a placa **ESP32C3 Dev Module**.
4. Selecione a porta COM correta.
5. Faça upload.
6. Abra o Monitor Serial em `115200 baud`.

---

## Interface no iPad

A interface de vídeo está em:

```txt
interface_holografica/videos_ipad.html
```

Ela escuta as teclas `1` a `8` e troca o vídeo conforme o gesto recebido.

Os vídeos devem ser colocados na pasta:

```txt
interface_holografica/videos/
```

com os nomes:

```txt
video1.mp4
video2.mp4
video3.mp4
video4.mp4
video5.mp4
video6.mp4
video7.mp4
video8.mp4
```

---

## Estrutura do repositório

```txt
ProjetoIntegrador/
│
├── firmware/
│   ├── main.ino
│   ├── ble_control/
│   ├── gesture_read/
│   ├── libraries/
│   └── src/
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
├── interface_holografica/
│   ├── videos_ipad.html
│   └── videos/
│
├── src/
│   └── main.cpp
│
├── platformio.ini
├── .gitignore
└── README.md
```

---

## Resultados atuais

Até o PC3, o sistema apresenta:

- leitura funcional do sensor PAJ7620;
- comunicação I2C validada;
- comunicação Bluetooth BLE funcional;
- reconhecimento de múltiplos gestos;
- envio de comandos para o iPad;
- início da reprodução holográfica controlada por gestos;
- PCB preliminar desenvolvida no KiCad;
- modelagem 3D frontal e traseira da PCB.

---

## Limitações atuais

- reprodução holográfica ainda em refinamento;
- PCB em evolução incremental;
- sensibilidade parcial à iluminação ambiente;
- necessidade de sincronização final entre gesto e vídeo;
- validação final prevista para o PC4.

---

## Equipe

- Letícia Lavigne Guedes Germano
- Pedro Henrique Alves Castello Branco
- Kauã da Silva Araújo
- Iuri Costa Mariante
- João Gabriel de Souza
- Cauê Lovis Santana

---

## Licença

Projeto acadêmico desenvolvido para fins educacionais.
