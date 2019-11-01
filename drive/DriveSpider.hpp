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
    DriveSpider(frc::SpeedController* m0, frc::SpeedController* m1, frc::SpeedController* m2, frc::SpeedController* m3, BetterDoubleSolenoid* solenoid) :
        DriveSpider(m0, m1, m2, m3, solenoid, 1, 1, 1) {}

    //creates spider drive with the 4 speed controllers, but uses custom multipliers
    DriveSpider(frc::SpeedController* m0, frc::SpeedController* m1, frc::SpeedController* m2, frc::SpeedController* m3, BetterDoubleSolenoid* solenoid, float x, float y, float r) :
        DriveMecanum( //creates mecanum drive train
            m0,
            m1,
            m2,
            m3,
            x,
            y,
            r
        ),
        shifter(solenoid)
        {}

    //required to be implemented by the drivebase to be considered a stardust component
    void __RobotInit__() {}
    void __RobotPeriodic__() {}
    void __AutonomousInit__() {}
    void __AutonomousPeriodic__() {}
    void __TeleopInit__() {}
    void __TeleopPeriodic__() {}
    void __TestPeriodic__() {}

    void drive(float x, float y, float r) {
        if (usingMec) {
            DriveMecanum::drive(x, y, r);
        }
        else {
            DriveMecanum::drive(0, y, r);
        }
    }

    void drive(float x, float y, float r, float t) {
        BetterTimer{true, [=] {
            //calls drive from current class to make sure useMec is respected
            DriveSpider::drive(x, y, r);
        }, t};
    }

    void drive(BetterController* x) {
        DriveSpider::drive(
            getx()*x->GetXLeftDeadzone(),
            gety()*x->GetYLeftDeadzone(),
            getr()*x->GetXRightDeadzone()
        );
    }

    void useMecanum() {  //go into mecanum mode
        usingMec = true;
        shifter->Retract();
    }

    void useNormal() {  //go into normal mode
        usingMec = false;
        shifter->Extend();
    }

    void invert() {  //invert current mode state
        if (usingMec) {
            useNormal();
        }
        else {
            useMecanum();
        }
    }

private:
    //true if mecs are in use, false if normal wheels are in use
    bool usingMec=true;

    //double solenoid to use when shifting between the 2 modes
    BetterDoubleSolenoid* shifter;
};