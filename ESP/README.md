# ESP32 + APDS-9960 - Detecção de Gestos

Projeto simples para testar detecção de gestos com ESP32 e sensor APDS-9960 usando a biblioteca da SparkFun.

## Ligações

APDS9960 -> ESP32

- VCC -> 3V3
- GND -> GND
- SDA -> GPIO 21
- SCL -> GPIO 22
- INT -> GPIO 25

## Requisitos

- ESP32 Dev Module
- Sensor APDS-9960
- PlatformIO ou Arduino IDE
- Biblioteca SparkFun APDS-9960

## Configuração

No PlatformIO, use:

- Board: `esp32dev`
- Framework: `arduino`
- Porta: `COM8`

## Funcionamento

O sensor usa o pino `INT` para avisar quando um gesto foi detectado.  
O ESP32 lê esse evento e imprime no monitor serial:

- UP
- DOWN
- LEFT
- RIGHT
- NEAR
- FAR

## Monitor Serial

Velocidade:
115200

## Observação importante

Se aparecer erro na inicialização do sensor, o problema pode estar em:
- alimentação
- fiação I2C
- incompatibilidade do módulo com a biblioteca