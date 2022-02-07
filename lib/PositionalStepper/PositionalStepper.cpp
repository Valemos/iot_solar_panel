#include <PositionalStepper.h>

#include <Logger.h>

PositionalStepper::PositionalStepper(int steps_per_revolution, int pin1, int pin2, int pin3, int pin4)
    : step_per_degree_(steps_per_revolution / MAX_ANGLE),
    // pin3 and pin2 must be swapped to fix backwards movement
      stepper_(steps_per_revolution, pin1, pin3, pin2, pin4) {
}

void PositionalStepper::SetAngle(int angle) {
    int shortest_angle = GetShortestAngle(angle);
    current_position_ = current_position_ + shortest_angle;
    int steps = ToSteps(shortest_angle);

    stepper_.step(steps);
}

int PositionalStepper::GetShortestAngle(int angle) const{
    int shortest_angle = angle - current_position_;

    if (abs(shortest_angle) > MAX_ANGLE) {
        shortest_angle = shortest_angle % MAX_ANGLE;
    }

    if (abs(shortest_angle) > HALF_ROTATION_ANGLE) {
        shortest_angle = shortest_angle - 360;
    }

    Logger::log() << "Position: " << current_position_
                 << " Angle: " << angle
                 << " Shortest turn: " << shortest_angle << "\n";

    return shortest_angle;
}

int PositionalStepper::ToSteps(int angle) const {
    return angle * step_per_degree_;
}

void PositionalStepper::SetSpeed(int speed) {
    stepper_.setSpeed(speed);
}
int PositionalStepper::GetAngle() const {
    return current_position_;
}
