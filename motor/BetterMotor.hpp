#pragma once

#include <frc/PWMSpeedController.h>

#include "StarDust/core/StarDustComponent.hpp"
#include "StarDust/util/BetterTimer.hpp"

//wrapper class for inverting motors upon construction (if needed)
class BetterMotor : public StarDustComponent, public frc::PWMSpeedController {
public:
    //create PWM controler from only port
    BetterMotor(int n) : frc::PWMSpeedController(n), dampen(1) {}

    //create PWM controller from port and polarity
    BetterMotor(int n, bool invert) : frc::PWMSpeedController(n), dampen(1) {
        SetInverted(invert);
    }

    //create a motor controller given port, polarity, and input dampening
    BetterMotor(int n, double damp, bool invert) : frc::PWMSpeedController(n), dampen(damp) {
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
        PWMSpeedController::Set(input*dampen);
    }

    //call Set(s) for "t" seconds (will stop when done automatically)
    //this is blocking code, use AsyncSet to keep other robot code running
    void Set(double s, double t) {
        Set(s, t, true);
    }

    //call Set(s) for "t" seconds (will stop if p is set)
    //this is blocking code, use AsyncSet to keep other robot code running
    void Set(double s, double t, bool p) {
        BetterTimer bt { true, [=]{
            BetterMotor::Set(s);
        }, t };

        if (p) BetterMotor::Set(0);
    }

    void AsyncSet(double s, double t) {
        asyncspeed=s;
        asyncwait=t;
        asynctimer=new BetterTimer(t);
        asynctimer->Start();
    }

private:
    void update() {
        //check if asynctimer is activated before calling it
        if (asynctimer!=nullptr) {
            //check if it is still valid
            if (!asynctimer->HasPeriodPassed(asyncwait)) {
                Set(asyncspeed);
            }
            else {
                //unset the timer, stop motor
                Set(0);
                asynctimer=nullptr;
            }
        }
    }

    //multiplier to dampen the input to the motor controller
    double dampen=0;

    //only used by the SetAsync function, not needed to be set in the constructor
    BetterTimer* asynctimer;
    double asyncspeed=0; //timer cannot asynchronously set motor speed
    double asyncwait=0;
};