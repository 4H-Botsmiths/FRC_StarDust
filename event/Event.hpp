#pragma once

#include <functional>
#include <vector>

#include "StarDust/core/StarDustComponent.hpp"

class Event : public StarDustComponent {
public:
    Event(const std::function<bool()> conditional, std::function<void()> action);
    Event(const std::function<bool()> conditional, std::vector<std::function<void()>> actions);

    void __RobotInit__() const;
    void __RobotPeriodic__() const;
    void __AutonomousInit__() const;
    void __AutonomousPeriodic__() const;
    void __TeleopInit__() const;
    void __TeleopPeriodic__() const;
    void __TestPeriodic__() const;

    void fire() const;

    void addAction(const std::function<void()> action);

private:
    const std::function<bool()> conditional;

    std::vector<std::function<void()>> actions;
};