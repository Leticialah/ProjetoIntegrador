# Leitura do sensor PAJ7620

O sensor PAJ7620 é lido via barramento I2C.

Conexões usadas no protótipo:

| PAJ7620 | ESP32-C3 SuperMini |
|---|---|
| VCC | 3V3 |
| GND | GND |
| SDA | GPIO 6 |
| SCL | GPIO 7 |

O registrador principal de gesto lido no firmware é `0x43`.
