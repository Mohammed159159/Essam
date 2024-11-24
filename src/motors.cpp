#include "motors.h"
#include "bt_serial.h"
#include "commands.h"

void Motors::useMotors(char cmd)
{
    if (cmd == MOVE)
    {
        setSpeed();

        setAngle();

        if (isDirection(FORWARD))
            isReversed ? backward() : forward();
        else if (isDirection(BACKWARD))
            isReversed ? forward() : backward();
        else if (isDirection(FWD_RIGHT))
        {
            changeDifferential(FWD_RIGHT);
            isReversed ? bwdLeft() : fwdRight();
        }
        else if (isDirection(BWD_RIGHT))
        {
            changeDifferential(BWD_RIGHT);
            isReversed ? fwdLeft() : bwdRight();
        }
        else if (isDirection(SPIN_RIGHT))
            spinRight();
        else if (isDirection(FWD_LEFT))
        {
            changeDifferential(FWD_LEFT);
            isReversed ? bwdRight() : fwdLeft();
        }
        else if (isDirection(BWD_LEFT))
        {
            changeDifferential(BWD_LEFT);
            isReversed ? fwdRight() : bwdLeft();
        }
        else if (isDirection(SPIN_LEFT))
            spinLeft();
    }
    else if (cmd == FREEZE)
        freeze();
    else if (cmd == CHANGE_MAX_SPEED)
        changeMaxSpeed();
    else if (cmd == CHANGE_FACE)
        changeFace();
}

void Motors::setSpeed(int sp)
{
    if (sp)
    {
        speed = sp;
    }
    else
    {
        BTSerial.read();
        speed = (BTSerial.parseInt() / 255.0) * maxSpeed;
    }
}

void Motors::setAngle()
{
    BTSerial.read();
    angle = BTSerial.parseInt();
}

bool Motors::isDirection(int dir)
{
    // BTSerial.print("Direction: ");
    // BTSerial.println(dir);
    // BTSerial.print("Angle: ");
    // BTSerial.print(angle);
    // BTSerial.print(" ");
    // BTSerial.print("Speed: ");
    // BTSerial.println(speed);
    // BTSerial.print("Diff: ");
    // BTSerial.print(differential);
    // BTSerial.print(" ");
    // BTSerial.print("Max Speed: ");
    // BTSerial.println(maxSpeed);

    if (dir == 360)
        return (angle > 360 - MARGIN && angle <= 360) || (angle >= 0 && angle < 45 - MARGIN);
    return angle > dir - MARGIN && angle < dir + MARGIN;
}

void Motors::forward()
{
    BTSerial.println('F');
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
}

void Motors::backward()
{
    BTSerial.println('B');
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
}

void Motors::fwdRight()
{
    BTSerial.println("FR");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, speed);
    analogWrite(ENB, speed - differential);
}

void Motors::bwdRight()
{
    BTSerial.println("BR");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, speed);
    analogWrite(ENB, speed - differential);
}

void Motors::spinRight()
{
    BTSerial.println('R');
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
}



void Motors::fwdLeft()
{
    BTSerial.println("FL");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, speed - differential);
    analogWrite(ENB, speed);
}

void Motors::bwdLeft()
{
    BTSerial.println("BL");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, speed - differential);
    analogWrite(ENB, speed);
}
void Motors::spinLeft()
{
    BTSerial.println('L');
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
}



void Motors::pid(int pid)
{
    // BTSerial.print('PID: ');
    // BTSerial.println(pid);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, speed + pid);
    analogWrite(ENB, speed - pid);
}

void Motors::freeze()
{
    BTSerial.println("Freeze");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
}

void Motors::changeDifferential(int dir)
{
    if (dir == FWD_RIGHT || dir == BWD_LEFT)
        differential = (maxSpeed / 45.0) * (angle - (dir - MARGIN));
    if (dir == FWD_LEFT || dir == BWD_RIGHT)
        differential = (maxSpeed / 45.0) * (dir + MARGIN - angle);
}

void Motors::changeMaxSpeed()
{
    cmd = BTSerial.parseInt();
    maxSpeed = cmd;
    cmd = '\0';
}

void Motors::changeFace()
{
    isReversed = !isReversed;
}

