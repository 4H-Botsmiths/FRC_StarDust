#pragma once

#include <frc/drive/DifferentialDrive.h>
#include <frc/SpeedController.h>

#include "StarDust/util/BetterTimer.hpp"
#include "DriveBase.hpp"

class DriveBasic : public DriveBase {
public:
    //create drivetrain with default multipliers
    DriveBasic(frc::SpeedController* motor_0, frc::SpeedController* motor_1) : DriveBase() {
        differential=new frc::DifferentialDrive(*motor_0, *motor_1);
    }
    //create drivetrain with custom multipliers (basic drive has no X movement)
    DriveBasic(frc::SpeedController* motor_0, frc::SpeedController* motor_1, float y_mult, float rotation_mult)
            : DriveBase(1, y_mult, rotation_mult)
    {
        differential=new frc::DifferentialDrive(*motor_0, *motor_1);
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
        differential->ArcadeDrive(
            y * gety(),
            0
        );
    }

    void drive(float y, float rot) {
        differential->ArcadeDrive(
            y * gety(),
            rot * getr()
        );
    }

    void drive(float y, float rot, float time) {
        BetterTimer{true, [=]{
            drive(y, rot);
        }, time};
    }

    void drive(BetterController* controller) {
        drive(controller, 0);
    }

    void drive(BetterController* controller, int mode) {
        //0 is default mode
        if (mode==0) {
            drive(
                controller->GetYLeftDeadzone() * gety(),
                controller->GetXRightDeadzone() * getr()
            );
        }
        else if (mode==1) {
            drive(
                controller->GetYLeftDeadzone() * gety(),
                controller->GetXLeftDeadzone() * getr()
            );
        }
        else if (mode==2) {
            differential->TankDrive(
                controller->GetYRightDeadzone() * gety(),
                controller->GetYLeftDeadzone() * gety()
            );
        }
    }

private:
    frc::DifferentialDrive* differential;
};