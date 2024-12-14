#include <Arduino.h>
#include "line_follower.h"
#include "motors.h"

LineFollower lineFollower;
Motors motors;

char cmd;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    if (Serial.available())
    {
        cmd = Serial.read();

        lineFollower.toggle_on_off(cmd);

        motors.move(cmd);
    }

    if (lineFollower.isOn)
    {
        motors.move(lineFollower.solve());
    }
}