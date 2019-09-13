#pragma once

#include <vector>

#include "StarDust/core/StarDustComponent.hpp"

class StarDustRobot {
public:
    //pass all available StarDust components to the robot
    StarDustRobot(std::vector<StarDustComponent*> cs) : components(cs) {}

    //these functions DONT override the normal robot functions
    void RobotInit();
    void RobotPeriodic();
    void AutonomousInit();
    void AutonomousPeriodic();
    void TeleopInit();
    void TeleopPeriodic();
    void TestPeriodic();

private:
    std::vector<StarDustComponent*> components;
};