#pragma once

#include "Arduino.h"

class Logger
{
public:
    enum Loglevel
    {
        ERROR,
        INFO,
        DEBUG
    };

    Logger(const char *name);

    template <typename... Args>
    void log(Loglevel loglevel, const char *buf, Args... args)
    {
        Serial.printf("[%.8lu][%s]: ", millis(), this->name);
        Serial.printf(buf, args...);
        Serial.printf("\n");
    };

private:
    HardwareSerial *serial;
    char name[20];
};