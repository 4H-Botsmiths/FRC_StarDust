#include "StarDust/core/StarDustComponent.hpp"
#include "StarDust/core/StarDustRobot.hpp"

//Each of these functions when called will call the internal function of each component
//For example, running AutoInit() will run all the components __AutoInit__() function

void StarDustRobot::RobotInit() {
    for (auto component : components) {
        component->__RobotInit__();
    }
}
void StarDustRobot::RobotPeriodic() {
    for (auto component : components) {
        component->__RobotPeriodic__();
    }
}
void StarDustRobot::AutonomousInit() {
    for (auto component : components) {
        component->__AutonomousInit__();
    }
}
void StarDustRobot::AutonomousPeriodic() {
    for (auto component : components) {
        component->__AutonomousPeriodic__();
    }
}
void StarDustRobot::TeleopInit() {
    for (auto component : components) {
        component->__TeleopInit__();
    }
}
void StarDustRobot::TeleopPeriodic() {
    for (auto component : components) {
        component->__TeleopPeriodic__();
    }
}
void StarDustRobot::TestPeriodic() {
    for (auto component : components) {
        component->__TestPeriodic__();
    }
}