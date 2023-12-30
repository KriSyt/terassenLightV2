#include "Led.h"

Led::Led(uint8_t button, uint8_t led, const char *name)
{
    this->logger = new Logger(name);
    this->button = button;
    this->led = led;
    this->lightLevel = 0; // TODO
    strcpy(this->ledName, name);

    pinMode(button, INPUT);
    pinMode(led, INPUT_PULLUP);

    this->lightLevel = 0;
    this->lightLevels = {0, 20, 50, 100, 255};

    this->lastpress = 0;
    this->updateLight();
    this->stateChanged = true;
};

void Led::setLevel(uint8_t lightLevel)
{
    this->lightLevel = lightLevel;
    this->lightLevel = this->lightLevel % this->lightLevels.size();
    this->stateChanged = true;
    this->updateLight();
};

void Led::nextLevel()
{
    this->lightLevel++;
    this->lightLevel = this->lightLevel % this->lightLevels.size();
    this->stateChanged = true;
    this->updateLight();
};

void Led::updateLight()
{
    if (!stateChanged)
        return;

    analogWrite(this->led, this->lightLevels.at(this->lightLevel));
    this->logger->log(Logger::INFO, "Light Level on Led(%s) set to %i -> %i", this->ledName, this->lightLevel, this->lightLevels.at(this->lightLevel));
    stateChanged = false;
};

void Led::buttonISR()
{
    if (millis() < this->lastpress + DEBOUNCE_TIME)
        return;

    this->lightLevel++;
    this->lightLevel = this->lightLevel % this->lightLevels.size();
    this->stateChanged = true;
    lastpress = millis();
};
