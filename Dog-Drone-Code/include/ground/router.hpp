#pragma once

namespace DogDrone::Walk
{
    class Router
    {
    public:
        Router()
        {
        }

        int AngleToPulse(int angle, int motor_number)
        {
            double pulse;

            //Front Right Leg
            if (motor_number == 0)
            {
                pulse = angle;
            }
            else if (motor_number == 1)
            {
                pulse = angle;
            }
            else if (motor_number == 2)
            {
                pulse = angle;
            }

            //Front Left Leg
            else if (motor_number == 3)
            {
                pulse = angle;
            }
            else if (motor_number == 4)
            {
                pulse = angle;
            }
            else if (motor_number == 5)
            {
                pulse = angle;
            }

            //Back Right Leg
            else if (motor_number == 6)
            {
                pulse = angle;
            }
            else if (motor_number == 7)
            {
                pulse = angle;
            }
            else if (motor_number == 8)
            {
                pulse = angle;
            }

            //Back Left Leg
            else if (motor_number == 9)
            {
                pulse = angle;
            }
            else if (motor_number == 10)
            {
                pulse = angle;
            }
            else if (motor_number == 11)
            {
                pulse = angle;
            }
            return pulse;
        }
    };
}