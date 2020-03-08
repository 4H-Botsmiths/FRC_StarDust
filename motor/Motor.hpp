#pragma once

#include <frc/PWMSpeedController.h>

#include "StarDust/core/StarDustComponent.hpp"
#include "StarDust/util/Timer.hpp"

//wrapper class for dampening and inverting motors

class Motor : public StarDustComponent, public frc::PWMSpeedController {
public:
    //create PWM controler from port
    Motor(int port) :
        frc::PWMSpeedController(port),
        dampen(1)
        {}

    //create PWM controller from port and polarity
    Motor(int port, const bool invert) :
        frc::PWMSpeedController(port),
        dampen(1)
    {
        SetInverted(invert);
    }

    //create a motor controller from port, polarity, and input dampening
    Motor(int port, const double dampen, const bool invert) :
        frc::PWMSpeedController(port),
        dampen(dampen)
    {
        SetInverted(invert);
    }

    void __AutonomousInit__() { update(); }
    void __AutonomousPeriodic__() { update(); }
    void __TeleopInit__() { update(); }
    void __TeleopPeriodic__() { update(); }
    void __TestPeriodic__() { update(); }

    void Set(const double input) {
        PWMSpeedController::Set(input * dampen);
    }

    //keep motor at "speed" percent for "time" seconds (will stop when done)
    //this is blocking code, use AsyncSet to keep other robot code running
    void Set(const double speed, const double time) {
        Set(speed, time, true);
    }

    //keep motor at "speed" percent for "time" seconds (will stop if "brake" is set)
    //this is blocking code, use AsyncSet to keep other robot code running
    void Set(const double speed, const double time, const bool brake) {
        Timer { true, [=]{
            Motor::Set(speed);
        }, time};

        if (brake) Motor::Set(0);
    }

    void AsyncSet(const double speed, const double time) {
        asyncspeed=speed;
        asyncwait=time;
        asynctimer=new Timer(time);
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

    const double dampen=0;

    //only used by the SetAsync function, not needed to be set in the constructor
    Timer* asynctimer;
    double asyncspeed=0; //timer cannot asynchronously set motor speed
    double asyncwait=0;
};