#pragma once

namespace DogDrone::Walk
{
    struct movement_commands
    {
        int walk_speed;
        int walk_angle;
        char mode = 'W';
    };

    // struct motor_arguments
    // {
    //     // int pin;
    //     int pulse;
    // };

    typedef int motor_pulse;

    struct leg_arguments
    {
        motor_pulse hip{0};
        motor_pulse knee{0};
        motor_pulse ankle{0};
    };

    struct quadruped_router_arguments
    {
        leg_arguments front_right{leg_arguments{}};
        leg_arguments front_left{leg_arguments{}};
        leg_arguments back_right{leg_arguments{}};
        leg_arguments back_left{leg_arguments{}};
    };
}