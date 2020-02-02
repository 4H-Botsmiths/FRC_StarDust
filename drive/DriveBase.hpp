#pragma once

#include "StarDust/control/XboxController.hpp"
#include "StarDust/core/StarDustComponent.hpp"

class DriveBase : public StarDustComponent {
public:
    //constructor with default multipliers
    DriveBase()
        : x_mult(1), y_mult(1), rotation_mult(1) {}

    //constructor with custom multipliers
    DriveBase(double x, double y, double rot)
        : x_mult(x), y_mult(y), rotation_mult(rot) {}

    virtual void drive(double y) {}
    virtual void drive(double y, double rot) {}
    virtual void drive(double x, double y, double rot) {}

    virtual void drive(XboxController* controller) {}

    double getx() { return x_mult; }
    double gety() { return y_mult; }
    double getr() { return rotation_mult; }

private:
    double x_mult=0; //parallel to front face of bot
    double y_mult=0; //perpendicular to front face of bot
    double rotation_mult=0;
};