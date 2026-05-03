# Sistema Interativo de Holograma Controlado por Gestos

## 📌 Visão Geral

Este projeto consiste no desenvolvimento de um sistema embarcado capaz de interpretar gestos manuais e convertê-los em comandos para controle de efeitos visuais, criando uma experiência de interação sem contato físico.

O sistema utiliza um sensor de gestos para capturar movimentos da mão, um microcontrolador para processar os dados e um dispositivo externo para exibir o efeito holográfico.

---

## 🧠 Arquitetura do Sistema

O sistema foi estruturado em três blocos principais:

### 🔹 1. Aquisição de Dados
- Sensor: **PAJ7620**
- Responsável pela detecção de gestos manuais

### 🔹 2. Processamento
- Microcontrolador: **ESP32**
- Executa leitura via I2C e interpreta os gestos

### 🔹 3. Saída / Atuação
- Dispositivo externo (ex: iPad)
- Responsável pela exibição dos efeitos visuais (holograma)

Essa arquitetura segue o modelo clássico de sistemas embarcados:  
**Entrada → Processamento → Saída** :contentReference[oaicite:1]{index=1}

---

## 🔄 Funcionamento do Sistema

1. O usuário realiza um gesto com a mão  
2. O sensor PAJ7620 detecta o movimento  
3. O ESP32 lê os dados via I2C  
4. O firmware interpreta o gesto  
5. Um comando é gerado  
6. O sistema ativa um efeito visual no holograma  

---

## ⚙️ Decisões de Projeto

### ✔ Substituição do Sensor
O sensor inicial (APDS-9960) foi substituído pelo **PAJ7620** devido a:
- maior precisão
- melhor estabilidade
- menor sensibilidade à iluminação :contentReference[oaicite:2]{index=2}

---

### ✔ Comunicação
- Protocolo: **I2C**
- Linhas: SDA e SCL  
- Vantagem: menos fios e integração simples :contentReference[oaicite:3]{index=3}

---

### ✔ Nível de Tensão
- Sistema opera em **3.3V**
- Compatibilidade direta entre ESP32 e PAJ7620  
- Sem necessidade de conversor de nível lógico :contentReference[oaicite:4]{index=4}

---

## 🔌 Hardware Utilizado

- ESP32-C3 DevKitM-1
- Sensor de gestos PAJ7620
- Resistores pull-up (4.7kΩ)
- Capacitor de desacoplamento (100nF)
- Conectores 2.54mm
- Fonte 5V (USB)

---

## 🖥️ PCB

A placa foi projetada no **KiCad** e inclui:

- plano de GND
- roteamento otimizado
- separação de blocos
- proteção da área da antena do ESP32

---

## 💻 Firmware

O firmware realiza:
- inicialização do barramento I2C
- configuração do sensor
- leitura contínua dos gestos
- interpretação dos dados

Exemplo de gestos detectados:
- Direita
- Esquerda
- Cima
- Baixo
- Aproximar
- Afastar
- Horário / Anti-horário
- Acenar

O código base encontra-se em:
