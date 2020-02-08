#pragma once

#include <string>

class StarDustRobot;

//A StarDustComponent is the base class for passing into a StarDustRobot.

class StarDustComponent {
public:
    StarDustComponent() {}

    //These functions can optionally be ovveridden by components
    virtual void __RobotInit__() {}
    virtual void __RobotPeriodic__() {}
    virtual void __AutonomousInit__() {}
    virtual void __AutonomousPeriodic__() {}
    virtual void __TeleopInit__() {}
    virtual void __TeleopPeriodic__() {}
    virtual void __TestPeriodic__() {}

    //optional status msg for modules
    std::string __status__="";

    //pass current robot to the module
    void provideContext(StarDustRobot* robot) {
        __robot__=robot;
    }

    //flags can be set to disbale a module from running certain code
    bool disabledRobotInit=false;
    bool disabledRobotPeriodic=false;
    bool disabledAutonomousInit=false;
    bool disabledAutonomousPeriodic=false;
    bool disabledTeleopInit=false;
    bool disabledTeleopPeriodic=false;
    bool disabledTestPeriodic=false;

protected:
    //stores a reference to the current robot
    StarDustRobot* __robot__;
};