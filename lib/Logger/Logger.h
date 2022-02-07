//
// Created by anton on 04.02.22.
//

#ifndef IOT_SOLAR_PANEL_INCLUDE_LOGGER_H_
#define IOT_SOLAR_PANEL_INCLUDE_LOGGER_H_

#include <Arduino.h>

class Logger {
public:
    static Logger& log() {
        if (instance_ == nullptr) {
            instance_ = new Logger();
        }
        return *instance_;
    }

    template<typename MessageType>
    Logger& operator<<(MessageType message) {
        Serial.write(message);
        return *this;
    }

    static void Start() {
        Serial.begin(9600);
    };

private:
    static Logger* instance_;

    Logger() = default;
};

Logger* Logger::instance_ = nullptr;

template<>
Logger& Logger::operator<<(int message) {
    Serial.write(String(message).c_str());
    return *this;
}

#endif //IOT_SOLAR_PANEL_INCLUDE_LOGGER_H_
