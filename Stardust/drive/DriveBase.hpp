#pragma once

#include "Stardust/control/BetterController.hpp"
#include "Stardust/core/StarDustComponent.hpp"

class DriveBase : public StarDustComponent {
public:
    DriveBase() {}

    virtual void drive(float y) {}
    virtual void drive(float x, float r) {}
    virtual void drive(float x, float y, float r) {}

    virtual void drive(BetterController* x) {}

private:
    //multipliers
    float xspeed=0; //parallel to front face of bot
    float yspeed=0; //perpendicular to front face of bot
    float rotation=0;
    float gyro=0;
};