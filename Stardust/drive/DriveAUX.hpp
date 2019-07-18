#pragma once

#include "Stardust/sensor/motion/BetterGyro.hpp"
#include "Stardust/drive/DriveBase.hpp"

class DriveAUX {
public:
    DriveAUX(DriveBase* db, double t) {
        base=db;
        threshold=t;
    }
    DriveAUX(DriveBase* db, BetterGyro* bg, double t) {
        base=db;
        gyro=bg;
        threshold=t;
    }

    void GyroRotate(double r);
    void GyroRotateTo(double g, double r);

private:
    DriveBase* base;
    BetterGyro* gyro;

    double threshold; //minimum amount needed to move drivetrain
};