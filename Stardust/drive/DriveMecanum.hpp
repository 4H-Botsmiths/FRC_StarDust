#include "DriveBase.hpp"

#include <frc/drive/MecanumDrive.h>
#include <frc/SpeedController.h>

class DriveMecanum : public DriveBase {
public:
    //pass motor controlers
    DriveMecanum(frc::SpeedController* m0, frc::SpeedController* m1, frc::SpeedController* m2, frc::SpeedController* m3) : DriveBase(m0, m1, m2, m3) {
        //make a new mecanum drive reference
        mMecanum=new frc::MecanumDrive(*m0, *m3, *m1, *m2);
    }

    void drive(float y) {
        mMecanum->DriveCartesian(y, 0, 0);
    }

    void drive(float y, float r) {
        mMecanum->DriveCartesian(y, 0, r);
    }

    void drive(float x, float y, float r) {
        mMecanum->DriveCartesian(-x, y, r);
    }

    void drive(BetterController* x) {
        drive(
            x->GetXLeftDeadzone(),
            x->GetYLeftDeadzone(),
            x->GetXRightDeadzone()
        );
    }

    //required to be implemented by the drivebase to be considered a stardust component
    void __RobotInit__() {}
    void __RobotPeriodic__() {}
    void __AutonomousInit__() {}
    void __AutonomousPeriodic__() {}
    void __TeleopInit__() {}
    void __TeleopPeriodic__() {}
    void __TestPeriodic__() {}

private:
    frc::SpeedController* mMotor0;
    frc::SpeedController* mMotor1;
    frc::SpeedController* mMotor2;
    frc::SpeedController* mMotor3;

    frc::MecanumDrive* mMecanum;
};