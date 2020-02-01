#include "StarDust/event/Event.hpp"

void Event::__RobotInit__() { fire(); }
void Event::__RobotPeriodic__() { fire(); }
void Event::__AutonomousInit__() { fire(); }
void Event::__AutonomousPeriodic__() { fire(); }
void Event::__TeleopInit__() { fire(); }
void Event::__TeleopPeriodic__() { fire(); }
void Event::__TestPeriodic__() { fire(); }

void Event::addAction(std::function<void()> action) {
    actions.push_back(action);
}

void Event::fire() {
    if (conditional()) {
        for (auto action : actions) {
            action();
        }
    }
}