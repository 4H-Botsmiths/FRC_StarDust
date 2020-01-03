#pragma once

#include <frc/drive/MecanumDrive.h>
#include <frc/SpeedController.h>

#include "StarDust/util/BetterTimer.hpp"
#include "DriveBase.hpp"

class DriveMecanum : public DriveBase {
public:
    DriveMecanum(frc::SpeedController* motor_0, frc::SpeedController* motor_1, frc::SpeedController* motor_2, frc::SpeedController* motor_3)
        : DriveBase()
    {
        //make a new mecanum drive reference
        mecanum=new frc::MecanumDrive(*motor_0, *motor_3, *motor_1, *motor_2);
    }

    DriveMecanum(frc::SpeedController* motor_0, frc::SpeedController* motor_1, frc::SpeedController* motor_2, frc::SpeedController* motor_3, float x_mult, float y_mult, float rotation_mult)
        : DriveBase(x_mult, y_mult, rotation_mult)
    {
        //make a new mecanum drive reference
        mecanum=new frc::MecanumDrive(*motor_0, *motor_3, *motor_1, *motor_2);
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
        mecanum->DriveCartesian(y * gety(), 0, 0);
    }

    void drive(float y, float rot) {
        mecanum->DriveCartesian(
            y * gety(),
            0,
            rot * getr()
        );
    }

    void drive(float x, float y, float rot) {
        mecanum->DriveCartesian(
            -x * getx(),
            y * gety(),
            rot * getr()
        );
    }

    void drive(float x, float y, float rot, float time) {
        BetterTimer{true, [=]{
            drive(x, y, rot);
        }, time};
    }

    void drive(BetterController* controller) {
        drive(
            getx() * controller->GetXLeftDeadzone(),
            gety() * controller->GetYLeftDeadzone(),
            getr() * controller->GetXRightDeadzone()
        );
    }

private:
    frc::MecanumDrive* mecanum;
};