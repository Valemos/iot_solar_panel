#include <Arduino.h>
#include <Servo.h>
#include <RF24.h>
#include <RF24Udp.h>
#include <PositionalStepper.h>


PositionalStepper azimuth_motor{2048, 7, 6, 5, 4};
Servo elevation_motor{};
RF24 radio{2, 3};

int position = 0;
int direction = 1;

void setup() {
    Serial.begin(9600);
    elevation_motor.attach(8, 0, 180);
    azimuth_motor.SetSpeed(5);
}

void loop() {
    azimuth_motor.SetAngle(0);
    elevation_motor.write(position = (position + 10) % 180);
    delay(500);

    azimuth_motor.SetAngle(90);
    elevation_motor.write(position = (position + 10) % 180);
    delay(500);

    azimuth_motor.SetAngle(180);
    elevation_motor.write(position = (position + 10) % 180);
    delay(500);

    azimuth_motor.SetAngle(90);
    elevation_motor.write(position = (position + 10) % 180);
    delay(500);
}

// TODO: create interrupt to send data periodically using UDP and nrf Network
