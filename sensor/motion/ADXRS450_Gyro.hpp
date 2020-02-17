#pragma once

#include <frc/ADXRS450_Gyro.h>

#include "StarDust/sensor/motion/Gyro_Base.hpp"

//Wrapper class for ADXRS450_Gyro

class ADXRS450_Gyro : public frc::ADXRS450_Gyro, public Gyro_Base {
public:
    //there will probably be only one gyro anyways, only use default (SPI 0)
    ADXRS450_Gyro() :
        frc::ADXRS450_Gyro(),
        Gyro_Base(this)
        {}

    using Gyro_Base::GetAngle;
};