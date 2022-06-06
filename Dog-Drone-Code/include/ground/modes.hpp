#pragma once
#include "../dtos/dog-dto.hpp"

namespace DogDrone::Walk    
{
    class Modes
    {
    public:
        Modes()
        {
        }
        quadruped_router_arguments WalkMode(movement_commands commands)
        {}
        quadruped_router_arguments TrotMode(movement_commands commands)
        {}
        quadruped_router_arguments RunMode(movement_commands commands)
        {}
    };
}