#pragma once
#include "../dtos/dog-dto.hpp"
#include <Arduino.h>
#include <math.h>
//#include <cmath>

namespace DogDrone::Walk
{
    class InverseKin
    {
    public:
        static angles legFR(double x4, double y4, double z4)
        {

            angles ang;
            double D;

            D = (square(x4) + square(-y4) - square(L1) + square(z4) - square(L2) - square(L3)) / (2 * L2 * L3);
            //  if (D >= 1){D=1;}
            //  else if (D <= 0){D=0;}
            /////////////////////////////////////////////DOMINIO
            ang.theta = -atan2(y4, x4) - atan2(sqrt(square(x4) + square(-y4) - square(L1)), -L1);
            ang.gamma = atan2(sqrt(1 - square(D)), D);
            ang.alpha = atan2(z4, sqrt(square(x4) + square(-y4) - square(L1))) - atan2(L3 * sin(ang.gamma), L2 + L3 * cos(ang.gamma));
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

        static angles legFL(double x4, double y4, double z4)
        {

            angles ang;
            double D;

            D = (square(x4) + square(-y4) - square(L1) + square(z4) - square(L2) - square(L3)) / (2 * L2 * L3);
            //  if (D >= 1){D=1;}
            //  else if (D <= 0){D=0;}
            /////////////////////////////////////////////DOMINIO
            ang.theta = -atan2(y4, x4) - atan2(sqrt(square(x4) + square(-y4) - square(L1)), -L1);
            ang.gamma = atan2(sqrt(1 - square(D)), D);
            ang.alpha = atan2(z4, sqrt(square(x4) + square(-y4) - square(L1))) - atan2(L3 * sin(ang.gamma), L2 + L3 * cos(ang.gamma));
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

        static angles legBR(double x4, double y4, double z4)
        {

            angles ang;
            double D;

            D = (square(x4) + square(-y4) - square(L1) + square(z4) - square(L2) - square(L3)) / (2 * L2 * L3);
            //  if (D >= 1){D=1;}
            //  else if (D <= 0){D=0;}
            /////////////////////////////////////////////DOMINIO
            ang.theta = -atan2(y4, x4) - atan2(sqrt(square(x4) + square(-y4) - square(L1)), -L1);
            ang.gamma = atan2(sqrt(1 - square(D)), D);
            ang.alpha = atan2(z4, sqrt(square(x4) + square(-y4) - square(L1))) - atan2(L3 * sin(ang.gamma), L2 + L3 * cos(ang.gamma));
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

        static angles legBL(double x4, double y4, double z4)
        {

            angles ang;
            double D;

            D = (square(x4) + square(-y4) - square(L1) + square(z4) - square(L2) - square(L3)) / (2 * L2 * L3);
            //  if (D >= 1){D=1;}
            //  else if (D <= 0){D=0;}
            /////////////////////////////////////////////DOMINIO
            ang.theta = -atan2(y4, x4) - atan2(sqrt(square(x4) + square(-y4) - square(L1)), -L1);
            ang.gamma = atan2(sqrt(1 - square(D)), D);
            ang.alpha = atan2(z4, sqrt(square(x4) + square(-y4) - square(L1))) - atan2(L3 * sin(ang.gamma), L2 + L3 * cos(ang.gamma));
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
        static constexpr int MAX_GAMMA = 50;
        static constexpr int L1 = 40;
        static constexpr int L2 = 100;
        static constexpr int L3 = 100;
    };
}