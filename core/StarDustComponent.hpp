#pragma once

#include <string>

class StarDustRobot; //forward declaration of required StarDustRobot, ignore

//This class contains the core functions which all StarDust components will be based off of

//This includes things such as automatic setup, cleanup, and updating

class StarDustComponent {
public:
    StarDustComponent() {}

    //These functions can be overriden by a component thats wants certain actions to be called automatically
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
    void provideContext(StarDustRobot* r) { __robot__=r; }

    //flags can be set to disbale a module from running certain code
    bool disableRobotInit=false;
    bool disableRobotPeriodic=false;
    bool disableAutonomousInit=false;
    bool disableAutonomousPeriodic=false;
    bool disableTeleopInit=false;
    bool disableTeleopPeriodic=false;
    bool disableTestPeriodic=false;

protected:
    //stores a reference to the current robot
    StarDustRobot* __robot__;
};