# Bibliotecas necessárias

## Arduino IDE

Instale pelo Gerenciador de Bibliotecas ou por ZIP/GitHub:

- ESP32 BLE Keyboard, de T-vK
- Gesture PAJ7620 / Grove Gesture PAJ7620
- Wire.h já vem com o core Arduino/ESP32

## PlatformIO

As bibliotecas são baixadas automaticamente pelo arquivo `platformio.ini`:

```ini
lib_deps =
    https://github.com/Seeed-Studio/Grove_Gesture.git
    https://github.com/T-vK/ESP32-BLE-Keyboard.git
```
