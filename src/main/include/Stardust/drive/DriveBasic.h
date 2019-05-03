#include "DriveBase.h"

#include <drive/DifferentialDrive.h>
#include <frc/SpeedController.h>

class DriveBasic : public DriveBase {
public:
    //DriveBase requires 4 motors, only 2 are used, other 2 motors are set to the firt one
    DriveBasic(frc::SpeedController* m0, frc::SpeedController* m1) : DriveBase(m0, m1, m0, m0) {
        //make a new mecanum drive reference
        mDifferential=new frc::DifferentialDrive(*m0, *m1);
    }

    void drive(float y) {
        mDifferential->ArcadeDrive(y, 0);
    }

    void drive(float y, float r) {
        mDifferential->ArcadeDrive(y, r);
    }

private:
    frc::SpeedController* mMotor0;
    frc::SpeedController* mMotor1;
    frc::SpeedController* mMotor2;
    frc::SpeedController* mMotor3;

    frc::DifferentialDrive* mDifferential;
};