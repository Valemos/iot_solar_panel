#include <Arduino.h>

#include <Servo.h>
#include <PositionalStepper.h>

#include <RF24.h>
#include "../lib/LedController/LedController.h"

PositionalStepper azimuth_motor{2048, 7, 6, 5, 4};
Servo elevation_motor{};

LedController status_led{LED_BUILTIN};

RF24 radio{2, 3};
const byte address[6] = "00001";


void setup() {
    status_led.init();

    radio.begin();
    radio.openWritingPipe(address);
    radio.setPALevel(RF24_PA_MIN);
    radio.stopListening();

    delay(2000);
}

void loop() {
    const char text[] = "Hello World";
    radio.write(&text, sizeof(text));
    status_led.blink();
}
