#pragma once

#include "StarDust/control/BetterController.hpp"
#include "StarDust/core/StarDustComponent.hpp"

class DriveBase : public StarDustComponent {
public:
    //constructor with default (1.0x speed)
    DriveBase() : xspeed(1), yspeed(1), rotation(1) {}
    //constructor with custom speeds
    DriveBase(float x, float y, float r) : xspeed(x), yspeed(y), rotation(r) {}

    virtual void drive(float y) {}
    virtual void drive(float x, float r) {}
    virtual void drive(float x, float y, float r) {}

    virtual void drive(BetterController* controller) {}

    float gety() { return yspeed; }
    float getx() { return xspeed; }
    float getr() { return rotation; }

private:
    //multipliers
    float xspeed=0; //parallel to front face of bot
    float yspeed=0; //perpendicular to front face of bot
    float rotation=0;
    float gyro=0;
};