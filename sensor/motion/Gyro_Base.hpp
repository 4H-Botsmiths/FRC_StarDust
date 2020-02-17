#pragma once

#include <frc/GyroBase.h>
#include <math.h>

#include "StarDust/core/StarDustComponent.hpp"

/*
Wrapper class for the Gyro base class

Original class has no built-in rotation mod functions, or closest path functions
This class basically adds some more usefull functions
*/

class Gyro_Base : public StarDustComponent {
public:
    Gyro_Base(frc::GyroBase* gyro) :
        gyro(gyro)
        {}

    void __RobotInit__() override;
    void __RobotPeriodic__() override;
    void __AutonomousInit__() override;
    void __AutonomousPeriodic__() override;
    void __TeleopInit__() override;
    void __TeleopPeriodic__() override;
    void __TestPeriodic__() override;

    double GetAngle();

    //get angle with a modulous applied
    double GetAngleMod();
    double GetAngleMod(double deg);

    //returns the fastest way to turn to get to the desired degree
    double FastestToZero();
    double FastestTo(double deg);

private:
    frc::GyroBase* gyro;

    void update();

    double cached_degree=0;

    //flag is set when teleop/auto is ran
    bool started=false;
};