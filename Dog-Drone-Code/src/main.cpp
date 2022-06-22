#include <Arduino.h>
#include "..\include\ground\router.hpp"
#include "..\include\ground\run.hpp"

namespace DogDrone::Walk
{

  void setup()
  {
    Serial.begin(9600);
    // initialize the servos to their starting positions
    coordinates coord0.x4 = -170;
    coordinates coord0.y4 = 30;
    coordinates coord0.z4 = -60;

    coordinates coordFR = coord0;
    coordinates coordFL = coord0;
    coordinates coordBR = coord0;
    coordinates coordBL = coord0;

    Run runner();

  }

  void loop()
  {
    runner.Run(coordFR, coordFL, coordBR, coordBL);
  }
}