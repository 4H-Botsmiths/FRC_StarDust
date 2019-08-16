#pragma once

#include <frc/PWMSpeedController.h>

#include "Stardust/core/StarDustComponent.hpp"

//wrapper class for inverting motors upon construction (if needed)
class BetterMotor : public StarDustComponent, public frc::PWMSpeedController {
public:
    //create PWM controler from only port
    BetterMotor(int n) : frc::PWMSpeedController(n) {}

    //create PWM controller from port and polarity
    BetterMotor(int n, bool invert) : frc::PWMSpeedController(n) {
        SetInverted(invert);
    }

    //required to be implemented by the drivebase to be considered a stardust component
    void __RobotInit__() {}
    void __RobotPeriodic__() {}
    void __AutonomousInit__() {}
    void __AutonomousPeriodic__() {}
    void __TeleopInit__() {}
    void __TeleopPeriodic__() {}
    void __TestPeriodic__() {}
};