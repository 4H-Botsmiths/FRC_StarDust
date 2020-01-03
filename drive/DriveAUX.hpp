#pragma once

#include "StarDust/sensor/motion/BetterGyro.hpp"
#include "StarDust/core/StarDustComponent.hpp"
#include "StarDust/drive/DriveBase.hpp"

class DriveAUX : public StarDustComponent {
public:
    DriveAUX(DriveBase* driveBase, double threshold) {
        this->driveBase=driveBase;
        this->threshold=threshold;
    }
    DriveAUX(DriveBase* driveBase, BetterGyro* gyro, double threshold) {
        this->driveBase=driveBase;
        this->gyro=gyro;
        this->threshold=threshold;
    }

    void __RobotInit__() override;
    void __RobotPeriodic__() override;
    void __AutonomousInit__() override;
    void __AutonomousPeriodic__() override;
    void __TeleopInit__() override;
    void __TeleopPeriodic__() override;
    void __TestPeriodic__() override;

    void GyroRotate(double range);
    void GyroRotateTo(double degree, double range);
    void GyroRotateTo(double degree, double range, double y_mult);

private:
    DriveBase* driveBase;
    BetterGyro* gyro;

    //minimum amount needed to move drivetrain
    double threshold;
};