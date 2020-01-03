#pragma once

#include <frc/DoubleSolenoid.h>

#include "StarDust/core/StarDustComponent.hpp"

class BetterDoubleSolenoid : public StarDustComponent, public frc::DoubleSolenoid {
public:
    BetterDoubleSolenoid(int port1, int port2)
        : DoubleSolenoid(port1, port2), inverted(false) {}

    BetterDoubleSolenoid(int port1, int port2, bool invert)
        : DoubleSolenoid(port1, port2), inverted(invert) {}

    void __RobotInit__() {}
    void __RobotPeriodic__() {}
    void __AutonomousInit__() {}
    void __AutonomousPeriodic__() {}
    void __TeleopInit__() {}
    void __TeleopPeriodic__() {}
    void __TestPeriodic__() {}

    void Extend() {
        if (!inverted) Set(frc::DoubleSolenoid::Value::kForward);
        else Set(frc::DoubleSolenoid::Value::kReverse);
    }

    void Retract() {
        if (inverted) Set(frc::DoubleSolenoid::Value::kForward);
        else Set(frc::DoubleSolenoid::Value::kReverse);
    }

    void Off() {
        Set(frc::DoubleSolenoid::Value::kOff);
    }

    void Invert() {
        if (inverted==(Get()==frc::DoubleSolenoid::Value::kForward)) {
            Extend();
        }
        else {
            Retract();
        }
    }

private:
    bool inverted;
};