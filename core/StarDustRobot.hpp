#pragma once

#include <vector>

#include "StarDust/core/StarDustComponent.hpp"

class StarDustRobot {
public:
    //setup each of the components
    StarDustRobot(const std::vector<StarDustComponent*> components);

    //these functions DONT override the normal robot functions
    void RobotInit() const;
    void RobotPeriodic() const;
    void AutonomousInit() const;
    void AutonomousPeriodic() const;
    void TeleopInit() const;
    void TeleopPeriodic() const;
    void TestPeriodic() const;

    //RobotPeriodic is called each frame, including during auto and teleop
    //This flag allows modules to whether the robot is truly idling
    bool isIdle=true;

private:
    const std::vector<StarDustComponent*> components;
};