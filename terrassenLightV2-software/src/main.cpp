#include "main.h"
#include <Arduino.h>
#include <Logger.h>
#include "led/Led.h"

Logger logger("Main");

Led led1(BUTTON1, LED1, "LED1");
Led led2(BUTTON2, LED2, "LED1");
Led led3(BUTTON3, LED3, "LED1");

void setup()
{
  Serial.begin(9600);

  // SETUP Pins
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);

  // attach ISR
  attachInterrupt(BUTTON1, led1ISR, FALLING);
  attachInterrupt(BUTTON2, led2ISR, FALLING);
  attachInterrupt(BUTTON3, led3ISR, FALLING);
}

void loop()
{

  delay(200);
  led1.updateLight();
}

void ICACHE_RAM_ATTR led1ISR()
{
  led1.buttonISR();
}

void ICACHE_RAM_ATTR led2ISR()
{
  led2.buttonISR();
}

void ICACHE_RAM_ATTR led3ISR()
{
  led3.buttonISR();
}