#ifndef MOTORS_H
#define MOTORS_H

#define FORWARD 360
#define BACKWARD 180
#define FWD_RIGHT 45
#define BWD_RIGHT 135
#define SPIN_RIGHT 90
#define FWD_LEFT 315
#define BWD_LEFT 225
#define SPIN_LEFT 270
#define MARGIN 22.5

#include <Arduino.h>
#include "pins.h"
class Motors
{
private:
    int motorPins[6] = {IN1, IN2, IN3, IN4, ENA, ENB};
    int speed = 200;
    int maxSpeed = 255;
    int angle = 90;
    int differential = 0;
    char cmd = '\0';
    void fwdRight();
    void bwdRight();
    void fwdLeft();
    void bwdLeft();
    bool isDirection(int dir);
    void changeDifferential(int dir);
    void setAngle();
    void changeFace();
    //different types of speeds? turning, forward, backward?
    //use extra output of 2nd h bridge for controlling motors and enable gliding?

public:
    Motors()
    {
        for (int i = 0; i < sizeof(motorPins) / sizeof(motorPins[0]); i++)
            pinMode(motorPins[i], OUTPUT);
    }
    bool isReversed = false;
    void useMotors(char cmd);
    void forward();
    void backward();
    void spinRight();
    void spinLeft();
    void pid(int pid);
    void setSpeed(int sp = 0);
    void changeMaxSpeed();
    void freeze();
};
#endif