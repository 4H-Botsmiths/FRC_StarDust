#include "StarDust/core/StarDustComponent.hpp"
#include "StarDust/core/StarDustRobot.hpp"

//Each of these functions when called will call the internal function of each component
//For example, running AutoInit() will run all the components __AutoInit__() function

void StarDustRobot::RobotInit() {
    for (auto component : components) {
        if (!component->disableRobotInit) component->__RobotInit__();
    }
}
void StarDustRobot::RobotPeriodic() {
    for (auto component : components) {
        if (!component->disableRobotPeriodic) component->__RobotPeriodic__();
    }
}
void StarDustRobot::AutonomousInit() {
    for (auto component : components) {
        if (!component->disableAutonomousInit) component->__AutonomousInit__();
    }
}
void StarDustRobot::AutonomousPeriodic() {
    for (auto component : components) {
        if (!component->disableAutonomousPeriodic) component->__AutonomousPeriodic__();
    }
}
void StarDustRobot::TeleopInit() {
    for (auto component : components) {
        if (!component->disableTeleopInit) component->__TeleopInit__();
    }
}
void StarDustRobot::TeleopPeriodic() {
    for (auto component : components) {
        if (!component->disableTeleopPeriodic) component->__TeleopPeriodic__();
    }
}
void StarDustRobot::TestPeriodic() {
    for (auto component : components) {
        if (!component->disableTestPeriodic) component->__TestPeriodic__();
    }
}