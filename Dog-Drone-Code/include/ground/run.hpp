#pragma once
#include "router.hpp"
//#include <Arduino>

namespace DogDrone::Walk
{

    class Run
    {

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
        int pulse0, pulse1, pulse2, pulse3, pulse4, pulse5, pulse6, pulse7, pulse8, pulse9, pulse10, pulse11;

        Run(coordinates coordFR, coordinates coordFL, coordinates coordBR, coordinates coordBL){

        };

        // put your main code here, to run repeatedly
        void LoopWalk()
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

                    step_coord = _step(i, 'u'); // BR
                    coordBR.x4 = coord0.x4 + step_coord.x4;
                    coordBR.y4 = coord0.y4 + lateralGain * i;
                    coordBR.z4 = coord0.z4 + step_coord.z4;

                    step_coord = _step(i + 2, 'd'); // FR
                    coordFR.x4 = coord0.x4 + step_coord.x4;
                    coordFR.y4 = coord0.y4 + lateralGain * i;
                    coordFR.z4 = coord0.z4 + step_coord.z4;

                    step_coord = _step(i + 1, 'd'); // BL
                    coordBL.x4 = coord0.x4 + step_coord.x4;
                    coordBL.y4 = coord0.y4 - lateralGain * i;
                    coordBL.z4 = coord0.z4 + step_coord.z4;

                    step_coord = _step(i, 'd'); // FL
                    coordFL.x4 = coord0.x4 + step_coord.x4;
                    coordFL.y4 = coord0.y4 - lateralGain * i;
                    coordFL.z4 = coord0.z4 + step_coord.z4;

                    // moveServos(coordFR, coordFL, coordBR, coordBL);
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

                    step_coord = _step(i, 'd'); // BR
                    coordBR.x4 = coord0.x4 + step_coord.x4;
                    coordBR.y4 = coord0.y4 + lateralGain * (1 - i);
                    coordBR.z4 = coord0.z4 + step_coord.z4;

                    step_coord = _step(i, 'u'); // FR
                    coordFR.x4 = coord0.x4 + step_coord.x4;
                    coordFR.y4 = coord0.y4 + lateralGain * (1 - i);
                    coordFR.z4 = coord0.z4 + step_coord.z4;

                    step_coord = _step(i + 2, 'd'); // BL
                    coordBL.x4 = coord0.x4 + step_coord.x4;
                    coordBL.y4 = coord0.y4 - lateralGain * (1 - i);
                    coordBL.z4 = coord0.z4 + step_coord.z4;

                    step_coord = _step(i + 1, 'd'); // FL
                    coordFL.x4 = coord0.x4 + step_coord.x4;
                    coordFL.y4 = coord0.y4 - lateralGain * (1 - i);
                    coordFL.z4 = coord0.z4 + step_coord.z4;

                    // moveServos(coordFR, coordFL, coordBR, coordBL);
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

                    step_coord = _step(i + 1, 'd'); // BR
                    coordBR.x4 = coord0.x4 + step_coord.x4;
                    coordBR.y4 = coord0.y4 - lateralGain * i;
                    coordBR.z4 = coord0.z4 + step_coord.z4;

                    step_coord = _step(i, 'd'); // FR
                    coordFR.x4 = coord0.x4 + step_coord.x4;
                    coordFR.y4 = coord0.y4 - lateralGain * i;
                    coordFR.z4 = coord0.z4 + step_coord.z4;

                    step_coord = _step(i, 'u'); // BL
                    coordBL.x4 = coord0.x4 + step_coord.x4;
                    coordBL.y4 = coord0.y4 + lateralGain * i;
                    coordBL.z4 = coord0.z4 + step_coord.z4;

                    step_coord = _step(i + 2, 'd'); // FL
                    coordFL.x4 = coord0.x4 + step_coord.x4;
                    coordFL.y4 = coord0.y4 + lateralGain * i;
                    coordFL.z4 = coord0.z4 + step_coord.z4;

                    // moveServos(coordFR, coordFL, coordBR, coordBL);
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

                    step_coord = _step(i + 2, 'd'); // BR
                    coordBR.x4 = coord0.x4 + step_coord.x4;
                    coordBR.y4 = coord0.y4 - lateralGain * (1 - i);
                    coordBR.z4 = coord0.z4 + step_coord.z4;

                    step_coord = _step(i + 1, 'd'); // FR
                    coordFR.x4 = coord0.x4 + step_coord.x4;
                    coordFR.y4 = coord0.y4 - lateralGain * (1 - i);
                    coordFR.z4 = coord0.z4 + step_coord.z4;

                    step_coord = _step(i, 'd'); // BL
                    coordBL.x4 = coord0.x4 + step_coord.x4;
                    coordBL.y4 = coord0.y4 + lateralGain * (1 - i);
                    coordBL.z4 = coord0.z4 + step_coord.z4;

                    step_coord = _step(i, 'u'); // FL
                    coordFL.x4 = coord0.x4 + step_coord.x4;
                    coordFL.y4 = coord0.y4 + lateralGain * (1 - i);
                    coordFL.z4 = coord0.z4 + step_coord.z4;

                    // moveServos(coordFR, coordFL, coordBR, coordBL);
                }
            }
        }

        struct coordinates _step(double t, char sig)
        {
            double x, y;
            float x0, x1, x2, x3, y0, y1, y2, y3;
            float L;
            struct coordinates coord;

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
    };
} // namespace