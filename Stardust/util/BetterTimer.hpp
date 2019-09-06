#pragma once

#include <frc/Timer.h>
#include <functional>

//this class is not a stardust component, it does not need to be ran over time
//timers are started, they run their function, then expire and quit. calling .Start() again will rerun the timer

class BetterTimer : public frc::Timer {
public:
    //normal timer, doesnt run a function, just counts
    BetterTimer(double t) : frc::Timer(), time(t) {}

    //this is the base timer, it takes a function and must be manually called with .Start()
    BetterTimer(std::function<void()> f, double t) : frc::Timer(), func(f), time(t) {}

    //this is a basic timer, it immediately runs the function "f" and quits after "t" seconds
    BetterTimer(bool s, std::function<void()> f, double t) : frc::Timer(), func(f), time(t) {
        //only auto-run if "s" is set
        if (s) {
            Start();
        }
    }

    //when this returns true, timer is automatically stoped
    bool HasPeriodPassed(double t) {
        bool ret=frc::Timer::HasPeriodPassed(t);

        if (ret) Stop();

        return ret;
    }

    void Start() {
        //when start is called, keep running function until time has passed

        Reset();

        frc::Timer::Start(); //run timer for actual timer

        if (func) {
            //if function is defined, run it untill timer is done
            while(!HasPeriodPassed(time)) {
                func();
            }
        }
    }

private:
    std::function<void()> func; //function to be ran when timer is running
    double time; //timer exits after "time" seconds
};