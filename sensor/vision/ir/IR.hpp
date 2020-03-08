#pragma once

#include <frc/AnalogInput.h>

#include "StarDust/core/StarDustComponent.hpp"

//wrapper class for using an infa-red sensor

class IR : public StarDustComponent, frc::AnalogInput {
public:
    IR(int port) : frc::AnalogInput(port) {}

    double getV() const {
        return GetVoltage();
    }

    double getVV() const {
        return GetValue();
    }

    double getAV() const {
        return GetAverageVoltage();
    }
};