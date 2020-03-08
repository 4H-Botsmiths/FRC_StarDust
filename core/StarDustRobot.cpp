#include "StarDust/core/StarDustComponent.hpp"
#include "StarDust/core/StarDustRobot.hpp"

StarDustRobot::StarDustRobot(const std::vector<StarDustComponent*> components) :
    components(components)
{
    for (const auto component : components) {
        component->provideContext(this);
    }
}

//Each of these functions when called will call the internal function of each component
//For example, running AutoInit() will run all the components __AutoInit__() function

void StarDustRobot::RobotInit() const {
    for (const auto component : components) {
        if (!component->disabledRobotInit) component->__RobotInit__();
    }
}
void StarDustRobot::RobotPeriodic() const {
    for (const auto component : components) {
        if (!component->disabledRobotPeriodic) component->__RobotPeriodic__();
    }
}
void StarDustRobot::AutonomousInit() const {
    for (const auto component : components) {
        if (!component->disabledAutonomousInit) component->__AutonomousInit__();
    }
}
void StarDustRobot::AutonomousPeriodic() const {
    for (const auto component : components) {
        if (!component->disabledAutonomousPeriodic) component->__AutonomousPeriodic__();
    }
}
void StarDustRobot::TeleopInit() const {
    for (const auto component : components) {
        if (!component->disabledTeleopInit) component->__TeleopInit__();
    }
}
void StarDustRobot::TeleopPeriodic() const {
    for (const auto component : components) {
        if (!component->disabledTeleopPeriodic) component->__TeleopPeriodic__();
    }
}
void StarDustRobot::TestPeriodic() const {
    for (const auto component : components) {
        if (!component->disabledTestPeriodic) component->__TestPeriodic__();
    }
}