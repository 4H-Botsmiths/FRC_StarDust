#pragma once

#include <frc/drive/DifferentialDrive.h>
#include <frc/SpeedController.h>

#include "DriveBase.hpp"

class DriveBasic : public DriveBase {
public:
    //create drivetrain with default multipliers
    DriveBasic(frc::SpeedController* m0, frc::SpeedController* m1) : DriveBase() {
        //make a new basic drivetrain
        differential=new frc::DifferentialDrive(*m0, *m1);
    }
    //create drivetrain with custom multipliers (basic drive has no X movement)
    DriveBasic(frc::SpeedController* m0, frc::SpeedController* m1, float y, float r) : DriveBase(1, y, r) {
        //make a new basic drivetrain
        differential=new frc::DifferentialDrive(*m0, *m1);
    }

    //required to be implemented by the drivebase to be considered a stardust component
    void __RobotInit__() {}
    void __RobotPeriodic__() {}
    void __AutonomousInit__() {}
    void __AutonomousPeriodic__() {}
    void __TeleopInit__() {}
    void __TeleopPeriodic__() {}
    void __TestPeriodic__() {}

    void drive(float y) {
        differential->ArcadeDrive(y*gety(), 0);
    }

    void drive(float y, float r) {
        differential->ArcadeDrive(y*gety(), r*getr());
    }

    void drive(float y, float r, float t) {
        BetterTimer{true, [=]{
            drive(y, r);
        }, t};
    }

    void drive(BetterController* x) {
        drive(x, 0);
    }

    void drive(BetterController* x, int mode) {
        if (mode==0) { //default mode
            drive(
                x->GetYLeftDeadzone()*gety(), //Y on left stick controls Y direction
                x->GetXRightDeadzone()*getr() //X on right stick controls turning
            );
        }
        else if (mode==1) {
            drive(
                x->GetYLeftDeadzone()*gety(), //Y on left stick controls Y direction
                x->GetXLeftDeadzone()*getr() //X on left stick controls turning
            );
        }
        else if (mode==2) {
            differential->TankDrive(
                x->GetYRightDeadzone()*gety(), //Y on right controlls right motor speed
                x->GetYLeftDeadzone()*gety() //Y on left controlls left motor speed
            );
        }
    }

private:
    frc::DifferentialDrive* differential;
};