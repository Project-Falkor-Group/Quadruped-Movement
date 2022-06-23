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

    struct angles
    {
        double theta;
        double alpha;
        double gamma;
    }; ////vector

    struct coordinates
    {
        double x4;
        double y4;
        double z4;
    };

    struct leg_arguments
    {
        motor_arguments hip{0, 0};
        motor_arguments knee{0, 0};
        motor_arguments ankle{0, 0};
    };

    struct quadruped_router_arguments
    {
        leg_arguments front_right{leg_arguments{}};
        leg_arguments front_left{leg_arguments{}};
        leg_arguments back_right{leg_arguments{}};
        leg_arguments back_left{leg_arguments{}};
    };

    struct angles
    {
        double theta;
        double alpha;
        double gamma;
    }; ////vector
    struct coordinates
    {
        double x4;
        double y4;
        double z4;
    };
    struct coordinates coord0;
    struct coordinates step_coord;
    struct coordinates coordFR;
    struct coordinates coordFL;
    struct coordinates coordBR;
    struct coordinates coordBL;
}