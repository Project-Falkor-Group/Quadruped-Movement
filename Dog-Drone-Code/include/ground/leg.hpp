#pragma once
#include "../../dtos/dog-dto.hpp"
// include <Servo.h>

namespace DogDrone::Walk
{
    class Leg
    {
    public:
        Leg(int &hip_pulse, int &knee_pulse, int &ankle_pulse) : hip_pulse_(hip_pulse), knee_pulse_(knee_pulse), ankle_pulse_(ankle_pulse){};

        leg_arguments SetLeg()
        {
            leg_arguments leg_;
            //Attach them to a servo or just values???
            return leg_;
        }

    private:
        int &previous_hip_;
        int &previous_knee_;
        int &previous_ankle_;

        int &hip_pulse_;
        int &knee_pulse_;
        int &ankle_pulse_;

        
    };
}