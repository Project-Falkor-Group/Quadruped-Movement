#pragma once

namespace DogDrone::Walk    
{
    struct mpu_data
    {
        double ax;
        double ay;
        double az;
    };

    struct sensory_commands
    {
        int ultrasound_distance_right;
        int ultrasound_distance_left;
    };

    struct obstacle_arguments
    {
        bool obstacle_detected;
    };
}