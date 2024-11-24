/**
 * main.cpp - main file for integrating robot functionalities
 */
#include <Arduino.h>
#include "bt_serial.h"
#include "motors.h"
#include "line_follower.h"

char cmd;

Motors motors;
LineFollower lineFollower(motors);

void setup()
{
  BTSerial.begin(9600);
}

void loop()
{
  delay(10);
  if (BTSerial.available())
  {
    cmd = BTSerial.read();
    lineFollower.useLineFollower(cmd);
    motors.useMotors(cmd);
  }
}
