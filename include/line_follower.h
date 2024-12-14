#ifndef LINE_FOLLOWER_H
#define LINE_FOLLOWER_H
#include <Arduino.h>
#include "pins.h"
#include "commands.h"

class LineFollower
{
private:
    void get_readings();
    int read_left;
    int read_center;
    int read_right;
    int read_far_left;
    int read_far_right;
    bool ignore_right = false;
    bool ignore_left = false;
    const char spin_left = SPIN_LEFT;
    const char left = LEFT;
    const char forward = FORWARD;
    const char right = RIGHT;
    const char spin_right = SPIN_RIGHT;
    const char stop = STOP;

public:
    LineFollower()
    {
        pinMode(LL, INPUT);
        pinMode(L, INPUT);
        pinMode(C, INPUT);
        pinMode(R, INPUT);
        pinMode(RR, INPUT);
    }
    void debug_readings();
    char solve();
    bool isOn = false;
    void toggle_on_off(char cmd);
};

#endif