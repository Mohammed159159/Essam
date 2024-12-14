#include "motors.h"

void Motors::move(char cmd)
{
    switch (cmd)
    {
    case SPIN_LEFT:
        spin_left();
        break;
    case LEFT:
        left();
        break;
    case FORWARD:
        forward();
        break;
    case RIGHT:
        right();
        break;
    case SPIN_RIGHT:
        spin_right();
        break;
    case BACKWARD:
        backward();
        break;
    case STOP:
        stop();
        break;
    }
}
void Motors::forward()
{
    analogWrite(RIGHT_MOTOR_SPEED, speed);
    digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
    digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);

    analogWrite(LEFT_MOTOR_SPEED, speed);
    digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
    digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
}
void Motors::backward()
{
    analogWrite(RIGHT_MOTOR_SPEED, speed);
    digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
    digitalWrite(RIGHT_MOTOR_BACKWARD, HIGH);

    analogWrite(LEFT_MOTOR_SPEED, speed);
    digitalWrite(LEFT_MOTOR_FORWARD, LOW);
    digitalWrite(LEFT_MOTOR_BACKWARD, HIGH);
}
void Motors::left()
{
    analogWrite(RIGHT_MOTOR_SPEED, 1.3 * speed);
    digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
    digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);

    analogWrite(LEFT_MOTOR_SPEED, 0);
    digitalWrite(LEFT_MOTOR_FORWARD, LOW);
    digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
}

void Motors::right()
{
    analogWrite(RIGHT_MOTOR_SPEED, 0);
    digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
    digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);

    analogWrite(LEFT_MOTOR_SPEED, 1.3 * speed);
    digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
    digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
}

void Motors::spin_right()
{
    analogWrite(RIGHT_MOTOR_SPEED, 1.5 * speed);
    digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
    digitalWrite(RIGHT_MOTOR_BACKWARD, HIGH);

    analogWrite(LEFT_MOTOR_SPEED, 1.5 * speed);
    digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
    digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
}

void Motors::spin_left()
{
    analogWrite(RIGHT_MOTOR_SPEED, 1.5 * speed);
    digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
    digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);

    analogWrite(LEFT_MOTOR_SPEED, 1.5 * speed);
    digitalWrite(LEFT_MOTOR_FORWARD, LOW);
    digitalWrite(LEFT_MOTOR_BACKWARD, HIGH);
}

void Motors::stop()
{

    analogWrite(RIGHT_MOTOR_SPEED, 0);
    digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
    digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);

    analogWrite(LEFT_MOTOR_SPEED, 0);
    digitalWrite(LEFT_MOTOR_FORWARD, LOW);
    digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
}
