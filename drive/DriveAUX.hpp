#pragma once

#include "StarDust/sensor/motion/ADXRS450_Gyro.hpp"
#include "StarDust/core/StarDustComponent.hpp"
#include "StarDust/drive/DriveBase.hpp"

class DriveAUX : public StarDustComponent {
public:
    DriveAUX(DriveBase driveBase, ADXRS450_Gyro* gyro, double threshold);

    void GyroRotateToZero(double range);
    void GyroRotateTo(double degree, double range);
    void GyroRotateTo(double degree, double range, double y_mult);

    void drive(double x, double y, double z);
    void drive(double x, double y, double z, double deg);

private:
    DriveBase driveBase;
    ADXRS450_Gyro* gyro;

    //minimum amount needed to move drivetrain
    double threshold;
};