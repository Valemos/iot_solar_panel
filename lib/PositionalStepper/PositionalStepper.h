#pragma once

#include <Arduino.h>
#include <Stepper.h>

class PositionalStepper {
public:
    PositionalStepper(int steps_per_revolution, int pin1, int pin2, int pin3, int pin4);

    void SetAngle(int angle);
    int GetAngle() const;

    int GetShortestAngle(int angle) const;

    void SetSpeed(int speed);

private:
    int current_position_ {0};
    const int step_per_degree_;
    Stepper stepper_;

    static constexpr int MAX_ANGLE = 360;
    static constexpr int HALF_ROTATION_ANGLE = MAX_ANGLE / 2;

    inline int ToSteps(int angle) const;
};


