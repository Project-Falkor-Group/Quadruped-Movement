#pragma once
#include "../../dtos/dog-dto.hpp"
// include <Servo.h>
#include <math.h>
#include <cmath>
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

        quadruped_router_arguments set_quadruped_router_arguments()
        {
            quadruped_router_arguments Quadruped;

            
            front_right = front_right;
            front_left = front_left;
            back_right = back_right;
            back_left = back_left;

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

        int moveServos( coordinates coordFR,  coordinates coordFL,  coordinates coordBR,  coordinates coordBL)
        { //  struct angles anglesFR;
            angles anglesFR;
            angles anglesFL;
            angles anglesBR;
            angles anglesBL;

            anglesFR = legFR(coordFR.x4, coordFR.y4, coordFR.z4);
            anglesFL = legFL(coordFL.x4, coordFL.y4, coordFL.z4);
            anglesBR = legBR(coordBR.x4, coordBR.y4, coordBR.z4);
            anglesBL = legBL(coordBL.x4, coordBL.y4, coordBL.z4);

            // Tell the servos to pulse with coresponsing motors in the array with angle
            front_right.hip.pulse = AngleToPulse(anglesFR.theta);
            front_right.knee.pulse = AngleToPulse(anglesFR.alpha);
            front_right.ankle.pulse = AngleToPulse(anglesFR.gamma);

            front_left.hip.pulse = AngleToPulse(anglesFL.theta);
            front_left.knee.pulse = AngleToPulse(anglesFL.alpha);
            front_left.ankle.pulse = AngleToPulse(anglesFL.gamma);

            back_right.hip.pulse = AngleToPulse(anglesBR.theta);
            back_right.knee.pulse = AngleToPulse(anglesBR.alpha);
            back_right.ankle.pulse = AngleToPulse(anglesBR.gamma);

            back_left.hip.pulse = AngleToPulse(anglesBL.theta);
            back_left.knee.pulse = AngleToPulse(anglesBL.alpha);
            back_left.ankle.pulse = AngleToPulse(anglesBL.gamma);

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

        int AngleToPulse(int angle)
        {
            double pulse;

            // Front Right Leg
            if (front_right.hip.pin == 0)
            {
                pulse = int(10.822 * angle) + 2350;
            }
            else if (front_right.knee.pin == 1)
            {
                pulse = int(10.822 * angle) + 1700;
            }
            else if (front_right.ankle.pin == 2)
            {
                pulse = int(10.822 * angle) + 1500;
            }

            // Front Left Leg
            else if (front_left.hip.pin == 3)
            {
                pulse = int(-10.822 * angle) + 800;
            }
            else if (front_left.knee.pin == 4)
            {
                pulse = int(-10.822 * angle) + 1500;
            }
            else if (front_left.ankle.pin == 5)
            {
                pulse = int(-10.822 * angle) + 1500;
            }

            // Back Right Leg
            else if (back_right.hip.pin == 6)
            {
                pulse = int(-10.822 * angle) + 900;
            }
            else if (back_right.knee.pin == 7)
            {
                pulse = int(10.822 * angle) + 1400;
            }
            else if (back_right.ankle.pin == 8)
            {
                pulse = int(10.822 * angle) + 1400;
            }

            // Back Left Leg
            else if (back_left.hip.pin == 9)
            {
                pulse = int(10.822 * angle) + 2000;
            }
            else if (back_left.knee.pin == 10)
            {
                pulse = int(-10.822 * angle) + 2600;
            }
            else if (back_left.ankle.pin == 11)
            {
                pulse = int(-10.822 * angle) + 1700;
            }
            return pulse;
        }

        // INVERSE KINEMATICS
        angles legFR(double x4, double y4, double z4)
        {

            angles ang;
            double D;

            D = ((x4)^2 + (-y4)^2 - (L1)^2 + (z4)^2 - (L2)^2 - (L3)^2) / (2 * L2 * L3);
            //  if (D >= 1){D=1;}
            //  else if (D <= 0){D=0;}
            /////////////////////////////////////////////DOMINIO
            ang.theta = -atan2(y4, x4) - atan2(sqrt((x4)^2 + (-y4)^2 - (L1)^2), -L1);
            ang.gamma = atan2(sqrt(1 - (D)^2), D);
            ang.alpha = atan2(z4, sqrt((x4)^2 + (-y4)^2 - (L1)^2)) - atan2(L3 * sin(ang.gamma), L2 + L3 * cos(ang.gamma));
            ang.theta = ang.theta * 360 / (2 * PI) + 270;
            ang.alpha = -ang.alpha * 360 / (2 * PI);
            ang.gamma = ang.gamma * 360 / (2 * PI) - 90;

            //  Serial.print("\t");Serial.print(ang.tetta);Serial.print(" - ");Serial.print(ang.alpha);Serial.print(" - ");Serial.println(ang.gamma);
            if (ang.gamma >= MAX_GAMMA)
            {
                ang.gamma = MAX_GAMMA;
            }
            return ang;
        }

        angles legFL(double x4, double y4, double z4)
        {

            angles ang;
            double D;

            D = ((x4)^2 + (-y4)^2 - (L1)^2 + (z4)^2 - (L2)^2 - (L3)^2) / (2 * L2 * L3);
            //  if (D >= 1){D=1;}
            //  else if (D <= 0){D=0;}
            /////////////////////////////////////////////DOMINIO
            ang.theta = -atan2(y4, x4) - atan2(sqrt((x4)^2 + (-y4)^2 - (L1)^2), -L1);
            ang.gamma = atan2(sqrt(1 - (D)^2), D);
            ang.alpha = atan2(z4, sqrt((x4)^2 + (-y4)^2 - (L1)^2)) - atan2(L3 * sin(ang.gamma), L2 + L3 * cos(ang.gamma));
            ang.theta = ang.theta * 360 / (2 * PI) + 270;
            ang.alpha = -ang.alpha * 360 / (2 * PI);
            ang.gamma = ang.gamma * 360 / (2 * PI) - 90;

            //  Serial.print("\t");Serial.print(ang.tetta);Serial.print(" - ");Serial.print(ang.alpha);Serial.print(" - ");Serial.println(ang.gamma);
            if (ang.gamma >= MAX_GAMMA)
            {
                ang.gamma = MAX_GAMMA;
            }
            return ang;
        }

        angles legBR(double x4, double y4, double z4)
        {

            angles ang;
            double D;

            D = ((x4)^2 + (-y4)^2 - (L1)^2 + (z4)^2 - (L2)^2 - (L3)^2) / (2 * L2 * L3);
            //  if (D >= 1){D=1;}
            //  else if (D <= 0){D=0;}
            /////////////////////////////////////////////DOMINIO
            ang.theta = -atan2(y4, x4) - atan2(sqrt((x4)^2 + (-y4)^2 - (L1)^2), -L1);
            ang.gamma = atan2(sqrt(1 - (D)^2), D);
            ang.alpha = atan2(z4, sqrt((x4)^2 + (-y4)^2 - (L1)^2)) - atan2(L3 * sin(ang.gamma), L2 + L3 * cos(ang.gamma));
            ang.theta = ang.theta * 360 / (2 * PI) + 270;
            ang.alpha = -ang.alpha * 360 / (2 * PI);
            ang.gamma = ang.gamma * 360 / (2 * PI) - 90;

            //  Serial.print("\t");Serial.print(ang.tetta);Serial.print(" - ");Serial.print(ang.alpha);Serial.print(" - ");Serial.println(ang.gamma);
            if (ang.gamma >= MAX_GAMMA)
            {
                ang.gamma = MAX_GAMMA;
            }

            return ang;
        }

        angles legBL(double x4, double y4, double z4)
        {

            angles ang;
            double D;

            D = ((x4)^2 + (-y4)^2 - (L1)^2 + (z4)^2 - (L2)^2 - (L3)^2) / (2 * L2 * L3);
            //  if (D >= 1){D=1;}
            //  else if (D <= 0){D=0;}
            /////////////////////////////////////////////DOMINIO
            ang.theta = -atan2(y4, x4) - atan2(sqrt((x4)^2 + (-y4)^2 - (L1)^2), -L1);
            ang.gamma = atan2(sqrt(1 - (D)^2), D);
            ang.alpha = atan2(z4, sqrt((x4)^2 + (-y4)^2 - (L1)^2)) - atan2(L3 * sin(ang.gamma), L2 + L3 * cos(ang.gamma));
            ang.theta = ang.theta * 360 / (2 * PI) + 270;
            ang.alpha = -ang.alpha * 360 / (2 * PI);
            ang.gamma = ang.gamma * 360 / (2 * PI) - 90;

            //  Serial.print("\t");Serial.print(ang.tetta);Serial.print(" - ");Serial.print(ang.alpha);Serial.print(" - ");Serial.println(ang.gamma);
            if (ang.gamma >= MAX_GAMMA)
            {
                ang.gamma = MAX_GAMMA;
            }
            return ang;
        }

    private:
        leg_arguments front_right;
        leg_arguments front_left;
        leg_arguments back_right;
        leg_arguments back_left;

        // int L1 = 40;
        // int L2 = 100;
        // int L3 = 100;
        int MAX_GAMMA = 50;
        // int MAX_SERVOS = 12;
        // int MAX_PULSE = 2500;
        // int MIN_PULSE = 560;
        int L1 = 40;
        int L2 = 100;
        int L3 = 100;

        Servo Servos[MAX_SERVOS];
    };
}