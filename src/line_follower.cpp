#include "line_follower.h"
#include "bt_serial.h"
#include "commands.h"

void LineFollower::useLineFollower(char cmd)
{
    switch (cmd)
    {
    case DEBUG_READINGS:
        debugReadings();
        break;
    case FOLLOW_LINE:
        while (1)
        {
            if ((analogRead(S1) < THRESHOLD && analogRead(S2) < THRESHOLD) || (analogRead(S1) > THRESHOLD && analogRead(S2) > THRESHOLD))
               motors.isReversed ? motors.backward() : motors.forward();
            else if (analogRead(S1) < THRESHOLD && analogRead(S2) > THRESHOLD)
                motors.spinRight();
            else if (analogRead(S2) < THRESHOLD && analogRead(S1) > THRESHOLD)
                motors.spinLeft();
            else
                motors.freeze();

            if (BTSerial.available())
            {
                cmd = BTSerial.read();
                if (cmd == STOP_LINE_FOLLOWING)
                {
                    motors.freeze();
                    break;
                }
                else if (cmd == CHANGE_MAX_SPEED)
                    motors.changeMaxSpeed();
            }
        }
    }
}

void LineFollower::debugReadings()
{
    for (int i = 0; i < SENSORS_NUM; i++)
    {
        sensorReadings[i] = analogRead(sensorPins[i]);
        BTSerial.print("S");
        BTSerial.print(i + 1);
        BTSerial.print(": ");
        BTSerial.print(sensorReadings[i]);
        BTSerial.print(" ");
        if (i == SENSORS_NUM - 1)
            BTSerial.println("");
    }
}
