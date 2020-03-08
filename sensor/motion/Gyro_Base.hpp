#pragma once

#include <frc/interfaces/Gyro.h>
#include <math.h>

#include "StarDust/core/StarDustComponent.hpp"

/*
Wrapper class for the Gyro base class

Original class has no built-in rotation mod functions, or closest path functions
This class basically adds some more usefull functions
*/

class Gyro_Base : public StarDustComponent {
public:
    Gyro_Base(frc::Gyro* const gyro);

    void __RobotInit__() override;
    void __RobotPeriodic__() override;
    void __AutonomousInit__() override;
    void __AutonomousPeriodic__() override;
    void __TeleopInit__() override;
    void __TeleopPeriodic__() override;
    void __TestPeriodic__() override;

    double GetAngle() const;

    //get angle with a modulous applied
    double GetAngleMod() const;
    double GetAngleMod(const double deg) const;

    //returns the fastest way to turn to get to the desired degree
    double FastestToZero() const;
    double FastestTo(const double deg) const;

private:
    frc::Gyro* const gyro;

    void update();

    double cached_degree=0;

    //flag is set when teleop/auto is ran
    bool started=false;
};