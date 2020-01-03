#pragma once

#include <frc/Timer.h>
#include <functional>

//this class is not a stardust component, it does not need to be updated over time
//timers are started, they run their function, then expire and quit. calling .Start() again will rerun the timer

class BetterTimer : public frc::Timer {
public:
    //dummy timer, must be ran manually
    BetterTimer(double _time)
        : frc::Timer(), time(_time) {}

    //this timer takes a function and must be manually called with .Start()
    BetterTimer(std::function<void()> func, double _time)
        : frc::Timer(), function(func), time(_time) {}

    //this is a timer that immediately runs the function "func" and quits after "_time" seconds
    BetterTimer(bool autoRun, std::function<void()> func, double _time)
        : frc::Timer(), function(func), time(_time)
    {
        if (autoRun) {
            Start();
        }
    }

    bool HasPeriodPassed(double _time) {
        bool done=frc::Timer::HasPeriodPassed(_time);

        if (done) {
            Stop();
        }

        return done;
    }

    void Start() {
        Reset();

        //run the actual timer
        frc::Timer::Start();

        if (function) {
            while(!HasPeriodPassed(time)) {
                function();
            }
        }
    }

private:
    std::function<void()> function;
    double time;
};