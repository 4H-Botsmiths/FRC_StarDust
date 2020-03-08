#include "StarDust/event/Event.hpp"

Event::Event(const std::function<bool()> conditional, std::function<void()> action) :
    conditional(conditional),
    actions({ action })
    {}

Event::Event(const std::function<bool()> conditional, std::vector<std::function<void()>> actions) :
    conditional(conditional),
    actions(actions)
    {}

void Event::__RobotInit__() const { fire(); }
void Event::__RobotPeriodic__() const { fire(); }
void Event::__AutonomousInit__() const { fire(); }
void Event::__AutonomousPeriodic__() const { fire(); }
void Event::__TeleopInit__() const { fire(); }
void Event::__TeleopPeriodic__() const { fire(); }
void Event::__TestPeriodic__() const { fire(); }

void Event::addAction(const std::function<void()> action) {
    actions.push_back(action);
}

void Event::fire() const {
    if (conditional()) {
        for (const auto& action : actions) {
            action();
        }
    }
}