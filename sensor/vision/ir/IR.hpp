#pragma once

#include <frc/AnalogInput.h>

#include "StarDust/core/StarDustComponent.hpp"

//wrapper class for using an infa-red sensor

class IR : public StarDustComponent, frc::AnalogInput {
public:
    IR(int port) : frc::AnalogInput(port) {}

    //in the future, these functions will cache all the data from the sensor each frame
    void __RobotInit__() {};
    void __RobotPeriodic__() {};
    void __AutonomousInit__() {};
    void __AutonomousPeriodic__() {};
    void __TeleopInit__() {};
    void __TeleopPeriodic__() {};
    void __TestPeriodic__() {};

    double getV() { return GetVoltage(); }
    double getVV() { return GetValue(); }
    double getAV() { return GetAverageVoltage(); }
};