#pragma once

#include <functional>
#include <vector>

#include "StarDust/core/StarDustComponent.hpp"

class Event : public StarDustComponent {
public:
    Event(std::function<bool()> conditional, std::function<void()> action);
    Event(std::function<bool()> conditional, std::vector<std::function<void()>> actions);

    void __RobotInit__() override;
    void __RobotPeriodic__() override;
    void __AutonomousInit__() override;
    void __AutonomousPeriodic__() override;
    void __TeleopInit__() override;
    void __TeleopPeriodic__() override;
    void __TestPeriodic__() override;

    void fire();

    void addAction(std::function<void()> action);

private:
    std::function<bool()> conditional;

    std::vector<std::function<void()>> actions;
};