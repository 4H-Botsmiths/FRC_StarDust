#pragma once

#include <frc/Timer.h>
#include <functional>

//this class is not a stardust component, it does not need to be updated over time
//timers are started, they run their function, then expire and quit. calling .Start() again will rerun the timer

class Timer : public frc::Timer {
public:
    //dummy timer, must be ran manually
    Timer(const double time) :
        frc::Timer(),
        time(time)
        {}

    //this timer takes a function and must be manually called with .Start()
    Timer(const std::function<void()> func, const double time) :
        frc::Timer(),
        func(func),
        time(time) {}

    //this is a timer that immediately runs the function "func" and quits after "time" seconds
    Timer(const bool autoRun, const std::function<void()> func, const double time) :
        frc::Timer(),
        func(func),
        time(time)
    {
        if (autoRun) Start();
    }

    bool HasPeriodPassed(const double time) {
        const bool done=frc::Timer::HasPeriodPassed(time);

        if (done) Stop();

        return done;
    }

    void Start() {
        Reset();
        frc::Timer::Start();

        while(!HasPeriodPassed(time)) {
            if (func) func();
        }
    }

private:
    const std::function<void()> func;
    const double time;
};