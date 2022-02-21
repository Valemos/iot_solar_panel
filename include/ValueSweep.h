
#ifndef IOT_SOLAR_PANEL_INCLUDE_VALUESWEEP_H_
#define IOT_SOLAR_PANEL_INCLUDE_VALUESWEEP_H_

#include "Logger.h"

template<int min, int max>
class ValueSweep {
public:
    ValueSweep() = default;

    explicit ValueSweep(int position, int increment = 1);

    void step();
    int Next();

private:
    int position_{0};
    int increment_{1};
};

template<int min, int max>
ValueSweep<min, max>::ValueSweep(int position, int increment) : position_(position), increment_(increment) {}

template<int min, int max>
void ValueSweep<min, max>::step() {
    position_ += increment_;

    if (position_ <= min) {
        position_ = min;
        increment_ = -increment_;
    } else if (position_ >= max) {
        position_ = max;
        increment_ = -increment_;
    }

    Logger::Log() << "Position: " << position_ << '\n';
}

template<int min, int max>
int ValueSweep<min, max>::Next() {
    step();
    return position_;
}
#endif //IOT_SOLAR_PANEL_INCLUDE_VALUESWEEP_H_
