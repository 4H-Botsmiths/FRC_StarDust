#pragma once

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
};