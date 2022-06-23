#pragma once
#include "router.hpp"
#include <Arduino.h>
#include "../dtos/dog-dto.hpp"

namespace DogDrone::Walk
{
    class Run
    {

    public:
        Run(){

        };

        // put your main code here, to run repeatedly
        void LoopWalk(coordinates coordFR_, coordinates coordFL_, coordinates coordBR_, coordinates coordBL_)
        {
            for (double i = 0; i <= 0.99; i = i + increment)
            { // BR leg up
                unsigned long currentMillis = millis();
                if (currentMillis - previousMillis >= interval)
                {
                    // save the last time you blinked the LED
                    previousMillis = currentMillis;
                    t = float(currentMillis) / 1000;
                    /////////cuenta el tiempo que tarda el bucle en ejecutarse
                    loopTime = currentMillis - previousLooptime;
                    Serial.print("Time: ");
                    Serial.print(t);
                    Serial.print("s <");
                    Serial.print(loopTime);
                    Serial.print("#");
                    Serial.print("\t");
                    previousLooptime = currentMillis;
                    Serial.print(i);
                    Serial.println("\t");

                    step_coord_ = _step(i, 'u'); // BR
                    coordBR_.x4 = coord0_.x4 + step_coord_.x4;
                    coordBR_.y4 = coord0_.y4 + lateralGain * i;
                    coordBR_.z4 = coord0_.z4 + step_coord_.z4;

                    step_coord_ = _step(i + 2, 'd'); // FR
                    coordFR_.x4 = coord0_.x4 + step_coord_.x4;
                    coordFR_.y4 = coord0_.y4 + lateralGain * i;
                    coordFR_.z4 = coord0_.z4 + step_coord_.z4;

                    step_coord_ = _step(i + 1, 'd'); // BL
                    coordBL_.x4 = coord0_.x4 + step_coord_.x4;
                    coordBL_.y4 = coord0_.y4 - lateralGain * i;
                    coordBL_.z4 = coord0_.z4 + step_coord_.z4;

                    step_coord_ = _step(i, 'd'); // FL
                    coordFL_.x4 = coord0_.x4 + step_coord_.x4;
                    coordFL_.y4 = coord0_.y4 - lateralGain * i;
                    coordFL_.z4 = coord0_.z4 + step_coord_.z4;

                    router.moveServos(coordFR_, coordFL_, coordBR_, coordBL_);
                }
            }
            for (double i = 0; i <= 0.99; i = i + increment)
            { // FR leg up
                unsigned long currentMillis = millis();
                if (currentMillis - previousMillis >= interval)
                {
                    // save the last time you blinked the LED
                    previousMillis = currentMillis;
                    t = float(currentMillis) / 1000;
                    /////////cuenta el tiempo que tarda el bucle en ejecutarse
                    loopTime = currentMillis - previousLooptime;
                    Serial.print("Time: ");
                    Serial.print(t);
                    Serial.print("s <");
                    Serial.print(loopTime);
                    Serial.print("#");
                    Serial.print("\t");
                    previousLooptime = currentMillis;
                    Serial.print(i);
                    Serial.println("\t");

                    step_coord_ = _step(i, 'd'); // BR
                    coordBR_.x4 = coord0_.x4 + step_coord_.x4;
                    coordBR_.y4 = coord0_.y4 + lateralGain * (1 - i);
                    coordBR_.z4 = coord0_.z4 + step_coord_.z4;

                    step_coord_ = _step(i, 'u'); // FR
                    coordFR_.x4 = coord0_.x4 + step_coord_.x4;
                    coordFR_.y4 = coord0_.y4 + lateralGain * (1 - i);
                    coordFR_.z4 = coord0_.z4 + step_coord_.z4;

                    step_coord_ = _step(i + 2, 'd'); // BL
                    coordBL_.x4 = coord0_.x4 + step_coord_.x4;
                    coordBL_.y4 = coord0_.y4 - lateralGain * (1 - i);
                    coordBL_.z4 = coord0_.z4 + step_coord_.z4;

                    step_coord_ = _step(i + 1, 'd'); // FL
                    coordFL_.x4 = coord0_.x4 + step_coord_.x4;
                    coordFL_.y4 = coord0_.y4 - lateralGain * (1 - i);
                    coordFL_.z4 = coord0_.z4 + step_coord_.z4;

                    router.moveServos(coordFR_, coordFL_, coordBR_, coordBL_);
                }
            }
            for (double i = 0; i <= 0.99; i = i + increment)
            { // BL leg up
                unsigned long currentMillis = millis();
                if (currentMillis - previousMillis >= interval)
                {
                    // save the last time you blinked the LED
                    previousMillis = currentMillis;
                    t = float(currentMillis) / 1000;
                    /////////cuenta el tiempo que tarda el bucle en ejecutarse
                    loopTime = currentMillis - previousLooptime;
                    Serial.print("Time: ");
                    Serial.print(t);
                    Serial.print("s <");
                    Serial.print(loopTime);
                    Serial.print("#");
                    Serial.print("\t");
                    previousLooptime = currentMillis;
                    Serial.print(i);
                    Serial.println("\t");

                    step_coord_ = _step(i + 1, 'd'); // BR
                    coordBR_.x4 = coord0_.x4 + step_coord_.x4;
                    coordBR_.y4 = coord0_.y4 - lateralGain * i;
                    coordBR_.z4 = coord0_.z4 + step_coord_.z4;

                    step_coord_ = _step(i, 'd'); // FR
                    coordFR_.x4 = coord0_.x4 + step_coord_.x4;
                    coordFR_.y4 = coord0_.y4 - lateralGain * i;
                    coordFR_.z4 = coord0_.z4 + step_coord_.z4;

                    step_coord_ = _step(i, 'u'); // BL
                    coordBL_.x4 = coord0_.x4 + step_coord_.x4;
                    coordBL_.y4 = coord0_.y4 + lateralGain * i;
                    coordBL_.z4 = coord0_.z4 + step_coord_.z4;

                    step_coord_ = _step(i + 2, 'd'); // FL
                    coordFL_.x4 = coord0_.x4 + step_coord_.x4;
                    coordFL_.y4 = coord0_.y4 + lateralGain * i;
                    coordFL_.z4 = coord0_.z4 + step_coord_.z4;

                    router.moveServos(coordFR_, coordFL_, coordBR_, coordBL_);
                }
            }
            for (double i = 0; i <= 0.99; i = i + increment)
            { // FL leg up
                unsigned long currentMillis = millis();
                if (currentMillis - previousMillis >= interval)
                {
                    // save the last time you blinked the LED
                    previousMillis = currentMillis;
                    t = float(currentMillis) / 1000;
                    /////////cuenta el tiempo que tarda el bucle en ejecutarse
                    loopTime = currentMillis - previousLooptime;
                    Serial.print("Time: ");
                    Serial.print(t);
                    Serial.print("s <");
                    Serial.print(loopTime);
                    Serial.print("#");
                    Serial.print("\t");
                    previousLooptime = currentMillis;
                    Serial.print(i);
                    Serial.println("\t");

                    step_coord_ = _step(i + 2, 'd'); // BR
                    coordBR_.x4 = coord0_.x4 + step_coord_.x4;
                    coordBR_.y4 = coord0_.y4 - lateralGain * (1 - i);
                    coordBR_.z4 = coord0_.z4 + step_coord_.z4;

                    step_coord_ = _step(i + 1, 'd'); // FR
                    coordFR_.x4 = coord0_.x4 + step_coord_.x4;
                    coordFR_.y4 = coord0_.y4 - lateralGain * (1 - i);
                    coordFR_.z4 = coord0_.z4 + step_coord_.z4;

                    step_coord_ = _step(i, 'd'); // BL
                    coordBL_.x4 = coord0_.x4 + step_coord_.x4;
                    coordBL_.y4 = coord0_.y4 + lateralGain * (1 - i);
                    coordBL_.z4 = coord0_.z4 + step_coord_.z4;

                    step_coord_ = _step(i, 'u'); // FL
                    coordFL_.x4 = coord0_.x4 + step_coord_.x4;
                    coordFL_.y4 = coord0_.y4 + lateralGain * (1 - i);
                    coordFL_.z4 = coord0_.z4 + step_coord_.z4;

                    router.moveServos(coordFR_, coordFL_, coordBR_, coordBL_);
                }
            }
        }

        struct coordinates _step(double t, char sig)
        {
            float x0, x1, x2, x3, y0, y1, y2, y3;
            float L;
            coordinates coord;

            L = 80;
            if (sig == 'u')
            {
                // BEZIER CURVE WITH 4 POINTS
                x0 = 0;
                y0 = 0;

                x1 = -40;
                y1 = 20;

                x2 = 120;
                y2 = 20;

                x3 = 80;
                y3 = 0;

                coord.z4 = (1 - t) * ((1 - t) * ((1 - t) * x0 + t * x1) + t * ((1 - t) * x1 + t * x2)) +
                           t * ((1 - t) * ((1 - t) * x1 + t * x2) + t * ((1 - t) * x2 + t * x3));
                coord.y4 = 0;
                coord.x4 = (1 - t) * ((1 - t) * ((1 - t) * y0 + t * y1) + t * ((1 - t) * y1 + t * y2)) +
                           t * ((1 - t) * ((1 - t) * y1 + t * y2) + t * ((1 - t) * y2 + t * y3));
                return coord;
            }
            else if (sig == 'd')
            {

                coord.z4 = L - L * t / 3;
                coord.y4 = 0;
                coord.x4 = 0;
                return coord;
            }
        }

    private:
        char a;
        int pulse;
        float angle = 0;
        float lateralGain = 20;
        double increment = 0.0001;

        unsigned long previousMillis = 0;
        const long interval = 20;
        unsigned long loopTime;
        unsigned long previousLooptime;
        double t;

        leg_arguments front_right;
        leg_arguments front_left;
        leg_arguments back_right;
        leg_arguments back_left;
        Router router;
        coordinates coord0_;
        coordinates step_coord_;
        int pulse0, pulse1, pulse2, pulse3, pulse4, pulse5, pulse6, pulse7, pulse8, pulse9, pulse10, pulse11;
    };
} // namespace