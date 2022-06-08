#pragma once
#include "../../dtos/dog-dto.hpp"

namespace DogDrone::Walk
{
    class Leg
    {
    public:
        Leg(motor_arguments &hip_, motor_arguments &knee_, motor_arguments &ankle_)
        {
            hip = hip_;
            knee = knee_;
            ankle = ankle_;
        };

    private:
        motor_arguments hip;
        motor_arguments knee;
        motor_arguments ankle;
    };
}