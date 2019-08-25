#pragma once

#include <frc/drive/DifferentialDrive.h>
#include <frc/SpeedController.h>

#include "DriveBase.hpp"

class DriveBasic : public DriveBase {
public:
    //DriveBase requires 4 motors, only 2 are used, other 2 motors are set to the firt one
    DriveBasic(frc::SpeedController* m0, frc::SpeedController* m1) : DriveBase() {
        //make a new mecanum drive reference
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
        differential->ArcadeDrive(y, 0);
    }

    void drive(float y, float r) {
        differential->ArcadeDrive(y, r);
    }

    void drive(BetterController* x) {
        drive(x, 0);
    }

    void drive(BetterController* x, int mode) {
        if (mode==0) { //default mode
            drive(
                x->GetYLeftDeadzone(), //Y on left stick controls Y direction
                x->GetXRightDeadzone() //X on right stick controls turning
            );
        }
        else if (mode==1) {
            drive(
                x->GetYLeftDeadzone(), //Y on left stick controls Y direction
                x->GetYRightDeadzone() //Y on right stick controls turning
            );
        }
    }

private:
    frc::DifferentialDrive* differential;
};