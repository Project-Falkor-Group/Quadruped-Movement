#pragma once
#include "../../dtos/dog-dto.hpp"
#include <Servo.h>


//This class is not in use right now. Will be used later when we have a working PCA driver.
namespace DogDrone::Walk
{
    class PCAServo
    {
    public:
        PCAServo(int &pin) : pin_(pin)
        {
            servo_.attach(pin_);
        };

    private:
        int &pin_;
        Servo servo_;
    };

}