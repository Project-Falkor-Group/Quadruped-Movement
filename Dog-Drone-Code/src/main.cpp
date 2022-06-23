#include <Arduino.h>
#include "..\include\ground\router.hpp"
#include "..\include\ground\run.hpp"
#include "..\dtos\dog-dto.hpp"

using namespace DogDrone::Walk;

  Run runner;

  void setup()
  {
    Serial.begin(9600);
    // initialize the servos to their starting positions
    // coordinates coord0.x4 = -170;
    // coordinates coord0.y4 = 30;
    // coordinates coord0.z4 = -60;

    // connectServos();
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
        runner.LoopWalk(coordFR, coordFL, coordBR, coordBL);
  }
