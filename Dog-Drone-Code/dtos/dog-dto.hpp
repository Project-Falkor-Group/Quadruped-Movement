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
        int motor_speed;
        int motor_angle;
    };

    struct leg_arguments
    {
        motor_arguments hip{motor_arguments{0, 0}};
        motor_arguments knee{motor_arguments{0, 0}};
        motor_arguments ankle{motor_arguments{0, 0}};
    };

    struct quadruped_router_arguments
    {
        leg_arguments left_front{leg_arguments{}};
        leg_arguments left_rear{leg_arguments{}};
        leg_arguments right_front{leg_arguments{}};
        leg_arguments right_rear{leg_arguments{}};
    };
}