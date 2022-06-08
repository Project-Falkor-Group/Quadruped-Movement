#pragma once
#include "../../dtos/dog-dto.hpp"
// include <Servo.h>
#include <math.h>
#include "leg.hpp"

namespace DogDrone::Walk
{
    class Router
    {
    public:
        Router(leg_arguments &front_right_, leg_arguments &front_left_, leg_arguments &back_right_, leg_arguments &back_left_)
        {
            front_right = front_right_;
            front_left = front_left_;
            back_right = back_right_;
            back_left = back_left_;
        };
        
        leg_arguments front_right;
        leg_arguments front_left;
        leg_arguments back_right;
        leg_arguments back_left;

        quadruped_router_arguments set_quadruped_router_arguments(quadruped_router_arguments &Quadruped)
        {
            Quadruped.front_right = front_right;
            Quadruped.front_left = front_left;
            Quadruped.back_right = back_right;
            Quadruped.back_left = back_left;

            return Quadruped;
        }

        void connectServos()
        {
            Servos[0].attach(front_right.hip.pin);
            Servos[1].attach(front_right.knee.pin); // 0=2500
            Servos[2].attach(front_right.ankle.pin);

            Servos[3].attach(front_left.hip.pin);  // FL
            Servos[4].attach(front_left.knee.pin); // 0=550
            Servos[5].attach(front_left.ankle.pin);

            Servos[6].attach(back_right.hip.pin);  // BR
            Servos[7].attach(back_right.knee.pin); // 0=2500
            Servos[8].attach(back_right.ankle.pin);

            Servos[9].attach(back_left.hip.pin);   // BL
            Servos[10].attach(back_left.knee.pin); // 0=550
            Servos[11].attach(back_left.ankle.pin);
        }

#define L1 40
#define L2 100
#define L3 100
#define MAX_GAMMA 50
/// VARIABLES SERVOMOTORES
#define MAX_SERVOS 12
#define MAX_PULSE 2500
#define MIN_PULSE 560
        Servo Servos[MAX_SERVOS];

        unsigned long previousMillis = 0;
        const long interval = 20;
        unsigned long loopTime;
        unsigned long previousLooptime;
        double t;

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

        char a;
        float angle = 0;
        float lateralGain;
        double incremento;

        int moveServos(struct coordinates coordFR, struct coordinates coordFL, struct coordinates coordBR, struct coordinates coordBL)
        { //  struct angles anglesFR;
            struct angles anglesFR;
            struct angles anglesFL;
            struct angles anglesBR;
            struct angles anglesBL;

            anglesFR = legFR(coordFR.x4, coordFR.y4, coordFR.z4);
            anglesFL = legFL(coordFL.x4, coordFL.y4, coordFL.z4);
            anglesBR = legBR(coordBR.x4, coordBR.y4, coordBR.z4);
            anglesBL = legBL(coordBL.x4, coordBL.y4, coordBL.z4);

            // Tell the servos to pulse with coresponsing motors in the array with angle
            front_right.hip.pulse = AngleToPulse(anglesFR.theta, Quadruped);
            front_right.knee.pulse = AngleToPulse(anglesFR.alpha, Quadruped);
            front_right.ankle.pulse = AngleToPulse(anglesFR.gamma, Quadruped);

            front_left.hip.pulse = AngleToPulse(anglesFL.theta, Quadruped);
            front_left.knee.pulse = AngleToPulse(anglesFL.alpha, Quadruped);
            front_left.ankle.pulse = AngleToPulse(anglesFL.gamma, Quadruped);

            back_right.hip.pulse = AngleToPulse(anglesBR.theta, Quadruped);
            back_right.knee.pulse = AngleToPulse(anglesBR.alpha, Quadruped);
            back_right.ankle.pulse = AngleToPulse(anglesBR.gamma, Quadruped);

            back_left.hip.pulse = AngleToPulse(anglesBL.theta, Quadruped);
            back_left.knee.pulse = AngleToPulse(anglesBL.alpha, Quadruped);
            back_left.ankle.pulse = AngleToPulse(anglesBL.gamma, Quadruped);

            // Writing pulse command to motors
            Servos[0].writeMicroseconds(front_right.hip.pulse); // initial pos
            Servos[1].writeMicroseconds(front_right.knee.pulse);
            Servos[2].writeMicroseconds(front_right.ankle.pulse);

            Servos[3].writeMicroseconds(front_left.hip.pulse);
            Servos[4].writeMicroseconds(front_left.knee.pulse);
            Servos[5].writeMicroseconds(front_left.ankle.pulse);

            Servos[6].writeMicroseconds(back_right.hip.pulse);
            Servos[7].writeMicroseconds(back_right.knee.pulse);
            Servos[8].writeMicroseconds(back_right.ankle.pulse);

            Servos[9].writeMicroseconds(back_left.hip.pulse);
            Servos[10].writeMicroseconds(back_left.knee.pulse);
            Servos[11].writeMicroseconds(back_left.ankle.pulse);
        }

        int AngleToPulse(int angle, quadruped_router_arguments &quadruped_legs)
        {
            double pulse;

            // Front Right Leg
            if (quadruped_legs.front_right.hip.pin == 0)
            {
                pulse = angle;
            }
            else if (quadruped_legs.front_right.knee.pin == 1)
            {
                pulse = angle;
            }
            else if (quadruped_legs.front_right.ankle.pin == 2)
            {
                pulse = angle;
            }

            // Front Left Leg
            else if (quadruped_legs.front_left.hip.pin == 3)
            {
                pulse = angle;
            }
            else if (quadruped_legs.front_left.knee.pin == 4)
            {
                pulse = angle;
            }
            else if (quadruped_legs.front_left.ankle.pin == 5)
            {
                pulse = angle;
            }

            // Back Right Leg
            else if (quadruped_legs.back_right.hip.pin == 6)
            {
                pulse = angle;
            }
            else if (quadruped_legs.back_right.knee.pin == 7)
            {
                pulse = angle;
            }
            else if (quadruped_legs.back_right.ankle.pin == 8)
            {
                pulse = angle;
            }

            // Back Left Leg
            else if (quadruped_legs.back_left.hip.pin == 9)
            {
                pulse = angle;
            }
            else if (quadruped_legs.back_left.knee.pin == 10)
            {
                pulse = angle;
            }
            else if (quadruped_legs.back_left.ankle.pin == 11)
            {
                pulse = angle;
            }
            return pulse;
        }
    };
}