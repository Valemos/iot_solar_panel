#include <Logger.h>

Logger* Logger::instance_ = nullptr;

void Logger::Start(unsigned long speed) {
    Serial.begin(speed);
}

Logger &Logger::Log() {
    if (instance_ == nullptr) {
        instance_ = new Logger();
    }
    return *instance_;
}

template<>
Logger& Logger::operator<<(char message) {
    Serial.write(message);
    return *this;
}
