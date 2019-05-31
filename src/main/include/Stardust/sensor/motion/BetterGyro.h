#pragma once

#include <frc/ADXRS450_Gyro.h>
#include <math.h>

/*
Wrapper class for gyro

Original class has no built-in rotation mod functions, or closest path functions
This class basically adds some more usefull functions
*/

class BetterGyro : public frc::ADXRS450_Gyro {
public:
    //there will probably be only one gyro anyways, only use default (SPI 0)
    BetterGyro() : frc::ADXRS450_Gyro() {}

    double GetAngleMod() { return GetAngleMod(360); }
    double GetAngleMod(double deg) { return fmod(GetAngle(), deg); }

    double FastestTo(double deg);
    double FastestToZero();
};