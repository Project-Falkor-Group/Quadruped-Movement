#include <Arduino.h>
#include "../include/ground/run.hpp"
#include "../include/ground/router.hpp"

using namespace DogDrone::Walk;
Run run;
Router router;

void setup()
{
  Serial.begin(9600);
  router.connectServos();
  // initialize the servos to their starting positions
  coordinates coord0.x4 = -170;
  coordinates coord0.y4 = 30;
  coordinates coord0.z4 = -60;

  coordinates coordFR = coord0;
  coordinates coordFL = coord0;
  coordinates coordBR = coord0;
  coordinates coordBL = coord0;
}

void loop()
{
  run.Run(coordFR, coordFL, coordBR, coordBL);
}