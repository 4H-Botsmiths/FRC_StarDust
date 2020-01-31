#pragma once

#include <frc/SpeedController.h>
#include <frc/drive/MecanumDrive.h>

#include "StarDust/pneumatics/BetterDoubleSolenoid.hpp"
#include "StarDust/drive/DriveMecanum.hpp"
#include "StarDust/util/BetterTimer.hpp"

//DriveSpider (spider drive) is an expiremental drivetrain which uses both mecanum and normal wheels

class DriveSpider : public DriveMecanum {
public:
    //creates spider drive with just 4 speed controllers, and 1x multipliers on all axis
    DriveSpider(frc::SpeedController* motor_0, frc::SpeedController* motor_1, frc::SpeedController* motor_2, frc::SpeedController* motor_3, BetterDoubleSolenoid* solenoid)
        : DriveSpider(motor_0, motor_1, motor_2, motor_3, solenoid, 1, 1, 1) {}

    //creates spider drive with the 4 speed controllers, but uses custom multipliers
    DriveSpider(frc::SpeedController* motor_0, frc::SpeedController* motor_1, frc::SpeedController* motor_2, frc::SpeedController* motor_3, BetterDoubleSolenoid* solenoid, double x_mult, double y_mult, double rotation_mult)
        : DriveMecanum(
            motor_0,
            motor_1,
            motor_2,
            motor_3,
            x_mult,
            y_mult,
            rotation_mult
        ),
        shifter(solenoid) {}

    //required to be implemented by the drivebase to be considered a stardust component
    void __RobotInit__() {}
    void __RobotPeriodic__() {}
    void __AutonomousInit__() {}
    void __AutonomousPeriodic__() {}
    void __TeleopInit__() {}
    void __TeleopPeriodic__() {}
    void __TestPeriodic__() {}

    void drive(BetterController* controller) {
        DriveSpider::drive(
            controller->GetXLeftDeadzone(),
            controller->GetYLeftDeadzone(),
            controller->GetXRightDeadzone()
        );
    }

    void drive(double y) {
        DriveSpider::drive(0, y, 0);
    }

    void drive(double y, double rot) {
        DriveSpider::drive(0, y, rot);
    }

    void drive(double x, double y, double rot) {
        if (usingMec) {
            DriveMecanum::drive(x, y, rot);
        }
        else {
            DriveMecanum::drive(0, y, rot);
        }
    }

    void drive(double x, double y, double rot, double time) {
        BetterTimer{true, [=] {
            DriveSpider::drive(x, y, rot);
        }, time};
    }

    void invert() {
        if (usingMec) {
            useNormal();
        }
        else {
            useMecanum();
        }
    }

    void useMecanum() {
        usingMec = true;
        shifter->Retract();
    }

    void useNormal() {
        usingMec = false;
        shifter->Extend();
    }

private:
    bool usingMec=true;

    BetterDoubleSolenoid* shifter;
};