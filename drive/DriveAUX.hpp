#pragma once

#include "StarDust/sensor/motion/Gyro.hpp"
#include "StarDust/core/StarDustComponent.hpp"
#include "StarDust/drive/DriveBase.hpp"

class DriveAUX : public StarDustComponent {
public:
    DriveAUX(DriveBase* driveBase, Gyro* gyro, double threshold) {
        this->driveBase=driveBase;
        this->gyro=gyro;
        this->threshold=threshold;
    }

    void GyroRotateToZero(double range);
    void GyroRotateTo(double degree, double range);
    void GyroRotateTo(double degree, double range, double y_mult);

    void drive(double x, double y, double z);
    void drive(double x, double y, double z, double deg);

private:
    DriveBase* driveBase;
    Gyro* gyro;

    //minimum amount needed to move drivetrain
    double threshold;
};