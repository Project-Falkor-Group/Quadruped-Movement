#include <Arduino.h>
#include "../run.hpp"

void setup()
{
  Serial.begin(9600);
  connectServos();
  // initialize the servos to their starting positions
  coord0.x4 = -170;
  coord0.y4 = 30;
  coord0.z4 = -60;

  coordFR = coord0;
  coordFL = coord0;
  coordBR = coord0;
  coordBL = coord0;
}

void loop()
{
  Run(coordFR, coordFL, coordBR, coordBL);
}