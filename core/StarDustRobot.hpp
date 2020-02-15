#pragma once

#include <vector>

#include "StarDust/core/StarDustComponent.hpp"

class StarDustRobot {
public:
    //setup each of the components
    StarDustRobot(std::vector<StarDustComponent*> components);

    //these functions DONT override the normal robot functions
    void RobotInit();
    void RobotPeriodic();
    void AutonomousInit();
    void AutonomousPeriodic();
    void TeleopInit();
    void TeleopPeriodic();
    void TestPeriodic();

    //RobotPeriodic is called each frame, including during auto and teleop
    //This flag allows modules to whether the robot is truly idling
    bool isIdle=true;

private:
    std::vector<StarDustComponent*> components;
};