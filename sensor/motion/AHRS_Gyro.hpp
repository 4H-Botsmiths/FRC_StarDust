#pragma once

#include <frc/GyroBase.h>
#include <frc/I2C.h>
#include <AHRS.h>

#include "StarDust/sensor/motion/Gyro_Base.hpp"

//Wrapper class for the AHRS Gyro

class AHRS_Gyro : public AHRS, public Gyro_Base {
public:
    AHRS_Gyro() :
        AHRS(frc::I2C::Port::kOnboard),
        Gyro_Base(this)
        {}

    using Gyro_Base::GetAngle;
};