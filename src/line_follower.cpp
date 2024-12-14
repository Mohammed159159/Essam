#include "line_follower.h"

void LineFollower::get_readings()
{
    read_left = digitalRead(L);
    read_center = digitalRead(C);
    read_right = digitalRead(R);
    read_far_left = !digitalRead(LL);
    read_far_right = !digitalRead(RR);
}

void LineFollower::debug_readings()
{
    get_readings();
    Serial.print("LINE_FOLLOWING_MODE: ");
    Serial.println(isOn);
    Serial.print("far left: ");
    Serial.print(read_far_left);
    Serial.print(" ");
    Serial.print("left: ");
    Serial.print(read_left);
    Serial.print(" ");
    Serial.print("center: ");
    Serial.print(read_center);
    Serial.print(" ");
    Serial.print("right: ");
    Serial.print(read_right);
    Serial.print(" ");
    Serial.print("far right: ");
    Serial.println(read_far_right);
    Serial.println(solve());
    delay(2000);
}

char LineFollower::solve()
{
    get_readings();

    if (read_far_left == 0 && read_center == 0 && read_far_right == 0)
    {
        return stop;
    }
    else if (read_far_left == 0 && !ignore_left)
    {
        ignore_right = true;
        return spin_left;
    }
    else if (read_left == 0 && !ignore_left)
    {
        ignore_left = false;
        ignore_right = false;

        return left;
    }
    else if (read_center == 0)
    {
        ignore_left = false;
        ignore_right = false;
        
        return forward;
    }
    else if (read_right == 0 && !ignore_right)
    {
        ignore_left = false;
        ignore_right = false;

        return right;
    }
    else if (read_far_right == 0 && !ignore_right)
    {
        ignore_left = true;
        return spin_right;
    }
    return '\0';
}


void LineFollower::toggle_on_off(char cmd)
{
    if (cmd == TOGGLE_LINE_FOLLOWING_MODE)
        isOn = !isOn;
}