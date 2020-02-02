#pragma once

#include <frc/ADXRS450_Gyro.h>
#include <math.h>

#include "StarDust/core/StarDustComponent.hpp"

/*
Wrapper class for ADXRS450_Gyro

Original class has no built-in rotation mod functions, or closest path functions
This class basically adds some more usefull functions
*/

class Gyro : public StarDustComponent, public frc::ADXRS450_Gyro {
public:
    //there will probably be only one gyro anyways, only use default (SPI 0)
    Gyro() : frc::ADXRS450_Gyro() {}

    void __RobotInit__() override;
    void __RobotPeriodic__() override;
    void __AutonomousInit__() override;
    void __AutonomousPeriodic__() override;
    void __TeleopInit__() override;
    void __TeleopPeriodic__() override;
    void __TestPeriodic__() override;

    //override original function to return cached degree not base class's degree
    double GetAngle() {
        return cached_degree;
    }

    double GetAngleMod() {
        return GetAngleMod(360);
    }
    double GetAngleMod(double deg) {
        return fmod(GetAngle(), deg);
    }

    double FastestToZero();
    double FastestTo(double deg);

private:
    void update() {
        cached_degree=ADXRS450_Gyro::GetAngle();
    }

    double cached_degree=0;

    //flag is set when teleop/auto is ran
    bool started=false;
};