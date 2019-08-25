#pragma once

#include <frc/ADXRS450_Gyro.h>
#include <math.h>

#include "Stardust/core/StarDustComponent.hpp"

/*
Wrapper class for gyro

Original class has no built-in rotation mod functions, or closest path functions
This class basically adds some more usefull functions
*/

class BetterGyro : public StarDustComponent, public frc::ADXRS450_Gyro {
public:
    //there will probably be only one gyro anyways, only use default (SPI 0)
    BetterGyro() : frc::ADXRS450_Gyro() {}

    //overriden in the cpp file
    void __RobotInit__() override;
    void __RobotPeriodic__() override;
    void __AutonomousInit__() override;
    void __AutonomousPeriodic__() override;
    void __TeleopInit__() override;
    void __TeleopPeriodic__() override;
    void __TestPeriodic__() override;

    //override original function to return cached degree not base class's degree
    double GetAngle() { return degree; }

    double GetAngleMod() { return GetAngleMod(360); }
    double GetAngleMod(double deg) { return fmod(GetAngle(), deg); }

    double FastestTo(double deg);
    double FastestToZero();

private:

    //only called by this class, all other getangle methods will pull from internal "degree"
    void update() { degree=ADXRS450_Gyro::GetAngle(); }
    double degree=0; //cache the degree the gyro is at so that it is consistent when called
};