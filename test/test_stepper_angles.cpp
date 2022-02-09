#include <AUnit.h>
#include <PositionalStepper.h>

using namespace aunit;

class TestOnceAngle : public TestOnce {
public:
    PositionalStepper* stepper_ {nullptr};

    void setup() override {
        stepper_ = new PositionalStepper{2048, 1, 1, 1, 1};
        stepper_->SetSpeed(5);
    }

    void teardown() override {
        delete stepper_;
    }

};

testF(TestOnceAngle, ZeroToZero) {
    assertEqual(stepper_->GetShortestAngle(0), 0);
}

testF(TestOnceAngle, ToCurrentPositionStays) {
    stepper_->SetAngle(130);
    assertEqual(stepper_->GetShortestAngle(130), 0);
}

testF(TestOnceAngle, PositiveFromZero) {
    stepper_->SetAngle(20);
    assertEqual(stepper_->GetShortestAngle(80), 60);
}

testF(TestOnceAngle, PositiveWraps360Degrees) {
    assertEqual(stepper_->GetShortestAngle(450), 90);
}

testF(TestOnceAngle, NegativeWraps360Degrees) {
    assertEqual(stepper_->GetShortestAngle(270), -90);
}

testF(TestOnceAngle, NegativeWraps360DegreesNonZeroStart) {
    stepper_->SetAngle(100);
    assertEqual(stepper_->GetShortestAngle(300), -160);
}

testF(TestOnceAngle, NegativeDifferenceOnPositiveAngle) {
    stepper_->SetAngle(180);
    assertEqual(stepper_->GetAngle(), 180);
    assertEqual(stepper_->GetShortestAngle(80), -100);
}

void setup() {
    Serial.begin(115200);
    while (! Serial); // Wait until Serial is ready - Leonardo/Micro

    TestRunner::include("TestOnceAngle", "*");
}

void loop() {
    TestRunner::run();
}
