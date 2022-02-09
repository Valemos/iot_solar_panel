#pragma once

#include <Arduino.h>

class LedController {
public:
    explicit LedController(int led_pin);

    void init() const;
    void toggle_led();
    void blink() const;

private:
    int led_pin_;
    bool state_{false};
};
