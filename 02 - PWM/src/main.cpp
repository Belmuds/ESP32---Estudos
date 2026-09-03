#include <Arduino.h>

const int led_gpio = 2;

int brightness = 0;
int fadeAmount = 5;

void setup() {
    ledcSetup(0, 5000, 8);//canal 0, 5kHz, 8 bits resolution
    ledcAttachPin(led_gpio, 0);//attach pin to channel 0
}

void loop() {

    ledcWrite(0, brightness);//set the brightness of the LED

    brightness = brightness + fadeAmount;

    if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
    }

    delay(30);
}