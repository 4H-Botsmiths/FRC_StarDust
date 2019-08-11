#ifndef __BETTERMOTOR_H__
#define __BETTERMOTOR_H__

#include <frc/PWMSpeedController.h>

//wrapper class for inverting motors upon construction (if needed)
class BetterMotor : public frc::PWMSpeedController {
public:
    //create PWM controler from only port
    BetterMotor(int n) : frc::PWMSpeedController(n) {}

    //create PWM controller from port and polarity
    BetterMotor(int n, bool invert) : frc::PWMSpeedController(n) {
        mMotor->SetInverted(invert);
    }

    void __RobotInit__() {};
    void __RobotPeriodic__() {};
    void __AutonomousInit__() {};
    void __AutonomousPeriodic__() {};
    void __TeleopInit__() {};
    void __TeleopPeriodic__() {};
    void __TestPeriodic__() {};

private:
    frc::PWMSpeedController* mMotor;
};

#endif