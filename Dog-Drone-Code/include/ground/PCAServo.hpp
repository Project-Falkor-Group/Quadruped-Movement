#pragma once
#include "../../dtos/dog-dto.hpp"
#include <Servo.h>

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