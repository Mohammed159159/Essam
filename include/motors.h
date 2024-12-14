#ifndef MOTORS_H
#define MOTORS_H
#include <Arduino.h>
#include "pins.h"
#include "commands.h"

class Motors
{
private:
    int speed = 100;
    void spin_left();
    void left();
    void forward();
    void right();
    void spin_right();
    void backward();
    void stop();

public:
    Motors()
    {
        pinMode(RIGHT_MOTOR_SPEED, OUTPUT);
        pinMode(LEFT_MOTOR_SPEED, OUTPUT);
        pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
        pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
        pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);
        pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
    }
    void move(char cmd);
};

#endif