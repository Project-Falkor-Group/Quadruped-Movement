#pragma once

namespace DogDrone::Walk
{
    struct movement_commands
    {
        int walk_speed;
        int walk_angle;
        char mode = 'W';
    };

    struct motor_arguments
    {
        int pin;
        int pulse;
    };

    struct leg_arguments
    {
        motor_arguments hip{motor_arguments{0, 0}};
        motor_arguments knee{motor_arguments{0, 0}};
        motor_arguments ankle{motor_arguments{0, 0}};
    };

    struct quadruped_router_arguments
    {
        leg_arguments front_right{leg_arguments{}};
        leg_arguments front_left{leg_arguments{}};
        leg_arguments back_right{leg_arguments{}};
        leg_arguments back_left{leg_arguments{}};
    };
}