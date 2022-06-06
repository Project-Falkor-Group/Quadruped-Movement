#pragma once
#include "../dtos/dog-dto.hpp"
#include "../ground/modes.hpp"

namespace DogDrone::Walk    
{
    class ModeSelect
    {
    public:
        ModeSelect()
        {}

        quadruped_router_arguments SelectMode(movement_commands commands)
        {
            switch(commands.mode)
            {
                case 'W':
                {
                    return modes.WalkMode(commands);
                    break;
                }
                case 'T':
                {
                    return modes.TrotMode(commands);
                    break;
                }
                case 'R':
                {
                    return modes.RunMode(commands);
                    break;
                }
                default:
                {
                    return quadruped_router_arguments{};
                    break;
                }
            }
        }
        private:
        Modes modes;
    };
}