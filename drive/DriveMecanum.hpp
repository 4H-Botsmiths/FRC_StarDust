#pragma once

#include <frc/drive/MecanumDrive.h>
#include <frc/SpeedController.h>

#include "StarDust/util/BetterTimer.hpp"
#include "DriveBase.hpp"

class DriveMecanum : public DriveBase {
public:
    DriveMecanum(frc::SpeedController* m0, frc::SpeedController* m1, frc::SpeedController* m2, frc::SpeedController* m3) : DriveBase() {
        //make a new mecanum drive reference
        mecanum=new frc::MecanumDrive(*m0, *m3, *m1, *m2);
    }
    DriveMecanum(frc::SpeedController* m0, frc::SpeedController* m1, frc::SpeedController* m2, frc::SpeedController* m3, float x, float y, float r) : DriveBase(x, y, r) {
        //make a new mecanum drive reference
        mecanum=new frc::MecanumDrive(*m0, *m3, *m1, *m2);
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
        mecanum->DriveCartesian(y*gety(), 0, 0);
    }

    void drive(float y, float r) {
        mecanum->DriveCartesian(y*gety(), 0, r*getr());
    }

    void drive(float x, float y, float r) {
        mecanum->DriveCartesian(-x*getx(), y*gety(), r*getr());
    }

    void drive(float x, float y, float r, float t) {
        BetterTimer{true, [=]{
            drive(x, y, r);
        }, t};
    }

    void drive(BetterController* x) {
        drive(
            getx()*x->GetXLeftDeadzone(),
            gety()*x->GetYLeftDeadzone(),
            getr()*x->GetXRightDeadzone()
        );
    }

private:
    frc::MecanumDrive* mecanum;
};