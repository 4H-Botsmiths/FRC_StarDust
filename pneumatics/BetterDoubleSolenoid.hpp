#include <frc/DoubleSolenoid.h>

#include "Stardust/core/StarDustComponent.hpp"

class BetterDoubleSolenoid : public StarDustComponent, public frc::DoubleSolenoid {
public:
    BetterDoubleSolenoid(int port1, int port2) : DoubleSolenoid(port1, port2), inverted(false) {}
    BetterDoubleSolenoid(int port1, int port2, bool invert) : DoubleSolenoid(port1, port2), inverted(invert) {}

    void __RobotInit__() {}
    void __RobotPeriodic__() {}
    void __AutonomousInit__() {}
    void __AutonomousPeriodic__() {}
    void __TeleopInit__() {}
    void __TeleopPeriodic__() {}
    void __TestPeriodic__() {}

    void Extend() { //push the piston out
        if (!inverted) Set(frc::DoubleSolenoid::Value::kForward);
        else Set(frc::DoubleSolenoid::Value::kReverse);
    }

    void Retract() { //pull the piston in
        if (inverted) Set(frc::DoubleSolenoid::Value::kForward);
        else Set(frc::DoubleSolenoid::Value::kReverse);
    }

    void Off() { //
        Set(frc::DoubleSolenoid::Value::kOff);
    }
    void Invert() { //if extending, retract and vice versa
        if (inverted==(Get()==frc::DoubleSolenoid::Value::kForward)) Extend();
        else Retract();
    }

private:
    bool inverted;
};