#pragma once

#include <frc/SpeedController.h>
#include <frc/drive/MecanumDrive.h>

#include "StarDust/pneumatics/DoubleSolenoid.hpp"
#include "StarDust/drive/DriveMecanum.hpp"
#include "StarDust/util/Timer.hpp"

//DriveSpider (spider drive) is an expiremental drivetrain which uses both mecanum and normal wheels

class DriveSpider : public DriveMecanum {
public:
    //creates spider drive with just 4 speed controllers, and 1x multipliers on all axis
    DriveSpider(frc::SpeedController* motor_0, frc::SpeedController* motor_1, frc::SpeedController* motor_2, frc::SpeedController* motor_3, DoubleSolenoid* solenoid)
        : DriveSpider(motor_0, motor_1, motor_2, motor_3, solenoid, 1, 1, 1) {}

    //creates spider drive with the 4 speed controllers, but uses custom multipliers
    DriveSpider(frc::SpeedController* motor_0, frc::SpeedController* motor_1, frc::SpeedController* motor_2, frc::SpeedController* motor_3, DoubleSolenoid* solenoid, double x_mult, double y_mult, double rotation_mult)
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

    void drive(XboxController* controller) {
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
        Timer{true, [=] {
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

    DoubleSolenoid* shifter;
};