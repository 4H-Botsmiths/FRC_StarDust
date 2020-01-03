#pragma once

#include <frc/PWMSpeedController.h>

#include "StarDust/core/StarDustComponent.hpp"
#include "StarDust/util/BetterTimer.hpp"

//wrapper class for dampening and inverting motors

class BetterMotor : public StarDustComponent, public frc::PWMSpeedController {
public:
    //create PWM controler from port
    BetterMotor(int port)
        : frc::PWMSpeedController(port), dampen(1) {}

    //create PWM controller from port and polarity
    BetterMotor(int port, bool invert)
        : frc::PWMSpeedController(port), dampen(1)
    {
        SetInverted(invert);
    }

    //create a motor controller from port, polarity, and input dampening
    BetterMotor(int port, double damp, bool invert)
        : frc::PWMSpeedController(port), dampen(damp)
    {
        SetInverted(invert);
    }

    void __RobotInit__() {}
    void __RobotPeriodic__() {}
    void __AutonomousInit__() { update(); }
    void __AutonomousPeriodic__() { update(); }
    void __TeleopInit__() { update(); }
    void __TeleopPeriodic__() { update(); }
    void __TestPeriodic__() { update(); }

    void Set(double input) {
        PWMSpeedController::Set(input * dampen);
    }

    //keep motor at "speed" percent for "time" seconds (will stop when done)
    //this is blocking code, use AsyncSet to keep other robot code running
    void Set(double speed, double time) {
        Set(speed, time, true);
    }

    //keep motor at "speed" percent for "time" seconds (will stop if "brake" is set)
    //this is blocking code, use AsyncSet to keep other robot code running
    void Set(double speed, double time, bool brake) {
        BetterTimer bt { true, [=]{
            BetterMotor::Set(speed);
        }, time};

        if (brake) BetterMotor::Set(0);
    }

    void AsyncSet(double speed, double time) {
        asyncspeed=speed;
        asyncwait=time;
        asynctimer=new BetterTimer(time);
        asynctimer->Start();
    }

private:
    void update() {
        if (asynctimer!=nullptr) {
            if (!asynctimer->HasPeriodPassed(asyncwait)) {
                Set(asyncspeed);
            }
            else {
                Set(0);
                asynctimer=nullptr;
            }
        }
    }

    double dampen=0;

    //only used by the SetAsync function, not needed to be set in the constructor
    BetterTimer* asynctimer;
    double asyncspeed=0; //timer cannot asynchronously set motor speed
    double asyncwait=0;
};