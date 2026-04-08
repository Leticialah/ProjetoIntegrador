#include <Wire.h>
#include <SparkFun_APDS9960.h>

#define APDS9960_INT 25

SparkFun_APDS9960 apds;
volatile bool isr_flag = false;

void IRAM_ATTR interruptRoutine() {
  isr_flag = true;
}

void setup() {
  Serial.begin(115200);
  delay(2000);

  Wire.begin(21, 22);

  pinMode(APDS9960_INT, INPUT_PULLUP);

  Serial.println();
  Serial.println("--------------------------------");
  Serial.println("ESP32 + APDS-9960 - Gesture Test");
  Serial.println("--------------------------------");

  attachInterrupt(digitalPinToInterrupt(APDS9960_INT), interruptRoutine, FALLING);

  if (apds.init()) {
    Serial.println("APDS-9960 initialization complete");
  } else {
    Serial.println("Something went wrong during APDS-9960 init!");
    while (1) {
      delay(1000);
    }
  }

  if (apds.enableGestureSensor(true)) {
    Serial.println("Gesture sensor is now running");
    if (apds.setGestureGain(GGAIN_2X)) {
      Serial.println("Gesture Gain Set");
    }
  } else {
    Serial.println("Something went wrong during gesture sensor init!");
    while (1) {
      delay(1000);
    }
  }

  Serial.println("Passe a mao na frente do sensor.");
}

void loop() {
  if (isr_flag) {
    detachInterrupt(digitalPinToInterrupt(APDS9960_INT));
    isr_flag = false;

    if (apds.isGestureAvailable()) {
      int gesture = apds.readGesture();

      switch (gesture) {
        case DIR_UP:
          Serial.println("UP");
          break;
        case DIR_DOWN:
          Serial.println("DOWN");
          break;
        case DIR_LEFT:
          Serial.println("LEFT");
          break;
        case DIR_RIGHT:
          Serial.println("RIGHT");
          break;
        case DIR_NEAR:
          Serial.println("NEAR");
          break;
        case DIR_FAR:
          Serial.println("FAR");
          break;
        default:
          Serial.println("NONE");
          break;
      }
    }

    attachInterrupt(digitalPinToInterrupt(APDS9960_INT), interruptRoutine, FALLING);
  }
}