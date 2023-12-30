#pragma once
#include "Arduino.h"
#include "Logger.h"
#include <vector>

#define DEBOUNCE_TIME 500 // Debounce time in ms to avoid unstable states while pressing the button

class Led
{

public:
    /// @brief Constructor of Led, sets button to input and led to output
    /// @param button Pin number of button
    /// @param led Pin number of led
    /// @param name Name for the logger (ONLY for the logger)
    Led(uint8_t button, uint8_t led, const char *name);

    /// @brief Sets the light level. If the
    /// Light level is too high its %#lighlevels
    /// @param lightLevel The Light Level to set
    void setLevel(uint8_t lightLevel);

    /// @brief Switchers to the next LightLevel
    /// if the light level is already on maximum it starts over aggain
    void nextLevel();

    /// @brief Updates the State of the Led. Use frequently in loop
    /// (otherwise light state might not be updated after ISR)
    void updateLight();

    void buttonISR();

private:
    Logger *logger;
    uint8_t button;
    uint8_t led;
    uint8_t lightLevel;
    char ledName[20];

    std::vector<uint8_t> lightLevels;

    unsigned long lastpress;

    bool stateChanged;
};
