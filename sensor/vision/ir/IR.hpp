#pragma once

#include <frc/AnalogInput.h>

#include "StarDust/core/StarDustComponent.hpp"

//wrapper class for using an infa-red sensor

class IR : public StarDustComponent, frc::AnalogInput {
public:
    IR(int port) : frc::AnalogInput(port) {}

    double getV() { return GetVoltage(); }
    double getVV() { return GetValue(); }
    double getAV() { return GetAverageVoltage(); }
};