#pragma once

#include "StarDust/control/BetterController.hpp"
#include "StarDust/core/StarDustComponent.hpp"

class DriveBase : public StarDustComponent {
public:
    //constructor with default multipliers
    DriveBase()
        : x_mult(1), y_mult(1), rotation_mult(1) {}

    //constructor with custom multipliers
    DriveBase(float x, float y, float rot)
        : x_mult(x), y_mult(y), rotation_mult(rot) {}

    virtual void drive(float y) {}
    virtual void drive(float y, float rot) {}
    virtual void drive(float x, float y, float rot) {}

    virtual void drive(BetterController* controller) {}

    float getx() { return x_mult; }
    float gety() { return y_mult; }
    float getr() { return rotation_mult; }

private:
    float x_mult=0; //parallel to front face of bot
    float y_mult=0; //perpendicular to front face of bot
    float rotation_mult=0;
};