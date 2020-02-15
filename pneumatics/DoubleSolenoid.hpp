#pragma once

#include <frc/DoubleSolenoid.h>

#include "StarDust/core/StarDustComponent.hpp"

class DoubleSolenoid : public StarDustComponent, public frc::DoubleSolenoid {
public:
    DoubleSolenoid(int port1, int port2) :
        frc::DoubleSolenoid(port1, port2, false)
        {}

    DoubleSolenoid(int port1, int port2, bool invert) :
        frc::DoubleSolenoid(port1, port2),
        inverted(invert)
        {}

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