#include "LedController.h"

LedController::LedController(int led_pin) : led_pin_(led_pin) {}

void LedController::toggle_led() {
    if (state_) {
        digitalWrite(led_pin_, HIGH);
    } else {
        digitalWrite(led_pin_, LOW);
    }
    state_ = not state_;
}

void LedController::blink() const {
    digitalWrite(led_pin_, HIGH);
    delay(50);
    digitalWrite(led_pin_, LOW);
}

void LedController::init() const {
    pinMode(led_pin_, OUTPUT);
}
