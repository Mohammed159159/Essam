#include "Arduino.h"
#include "pins.h"
#include "motors.h"

#define THRESHOLD 500
#define SENSORS_NUM 3


class LineFollower
{
private:
    int sensorPins[SENSORS_NUM] = {S1, S2, S3};
    int sensorReadings[SENSORS_NUM];
    void debugReadings();
    Motors motors;
    char cmd = '\0';

public:
    LineFollower(Motors motors)
    {
        this->motors = motors;

        for (int i = 0; i < SENSORS_NUM; i++)
            pinMode(sensorPins[i], INPUT);
    }
    void useLineFollower(char cmd);
};