//
// Created by anton on 04.02.22.
//

#ifndef IOT_SOLAR_PANEL_LOGGER_H_
#define IOT_SOLAR_PANEL_LOGGER_H_

#include <Arduino.h>

class Logger {
public:
    static Logger& Log();

    template<typename MessageType>
    Logger& operator<<(MessageType message) {
        Serial.write(String(message).c_str());
        return *this;
    }

    static void Start(unsigned long speed = 115200);

private:
    static Logger* instance_;

    Logger() = default;
};

#endif //IOT_SOLAR_PANEL_LOGGER_H_
