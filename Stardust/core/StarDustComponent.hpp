//This class contains the core functions which all StarDust components will be based off of

//This includes things such as automatic setup, cleanup, and updating

class StarDustComponent {
public:
    //These functions can be overriden by a component thats wants certain actions to be called automatically
    virtual void __RobotInit__() {};
    virtual void __RobotPeriodic__() {};
    virtual void __AutonomousInit__() {};
    virtual void __AutonomousPeriodic__() {};
    virtual void __TeleopInit__() {};
    virtual void __TeleopPeriodic__() {};
    virtual void __TestPeriodic__() {};
};