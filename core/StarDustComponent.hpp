#pragma once

#include <string>

//forward declaration of required StarDustRobot, ignore
class StarDustRobot;

//StarDustComponent's contains the core functions which all StarDust components will be based off of

class StarDustComponent {
public:
    StarDustComponent() {}

    //These functions must be overriden by components that derive this class
    virtual void __RobotInit__()=0;
    virtual void __RobotPeriodic__()=0;
    virtual void __AutonomousInit__()=0;
    virtual void __AutonomousPeriodic__()=0;
    virtual void __TeleopInit__()=0;
    virtual void __TeleopPeriodic__()=0;
    virtual void __TestPeriodic__()=0;

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