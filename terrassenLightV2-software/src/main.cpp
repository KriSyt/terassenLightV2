#include <Arduino.h>
#include <Logger.h>

Logger logger("Main");

void setup()
{
  Serial.begin(9600);
}

void loop()
{

  delay(1000);
  logger.log(Logger::DEBUG, "Test");
}
