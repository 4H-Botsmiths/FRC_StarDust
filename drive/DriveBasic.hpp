#pragma once

#include <frc/drive/DifferentialDrive.h>
#include <frc/SpeedController.h>

#include "StarDust/util/Timer.hpp"
#include "DriveBase.hpp"

class DriveBasic : public DriveBase {
public:
    //create drivetrain with default multipliers
    DriveBasic(frc::SpeedController* motor_0, frc::SpeedController* motor_1) : DriveBase() {
        differential=new frc::DifferentialDrive(*motor_0, *motor_1);
    }
    //create drivetrain with custom multipliers (basic drive has no X movement)
    DriveBasic(frc::SpeedController* motor_0, frc::SpeedController* motor_1, double y_mult, double rotation_mult)
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

    void drive(double y) {
        DriveBasic::drive(y, 0);
    }

    void drive(double y, double rot) {
        differential->ArcadeDrive(
            y * gety(),
            rot * getr()
        );
    }

    void drive(double y, double rot, double time) {
        Timer{true, [=]{
            DriveBasic::drive(y, rot);
        }, time};
    }

    void drive(XboxController* controller) {
        DriveBasic::drive(controller, 0);
    }

    void drive(XboxController* controller, int mode) {
        //0 is default mode
        if (mode==0) {
            DriveBasic::drive(
                controller->GetYLeftDeadzone(),
                controller->GetXRightDeadzone()
            );
        }
        else if (mode==1) {
            DriveBasic::drive(
                controller->GetYLeftDeadzone(),
                controller->GetXLeftDeadzone()
            );
        }
        else if (mode==2) {
            DriveBasic::drive(
                controller->GetYRightDeadzone(),
                controller->GetYLeftDeadzone()
            );
        }
    }

private:
    frc::DifferentialDrive* differential;
};