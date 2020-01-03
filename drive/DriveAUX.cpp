#include "StarDust/drive/DriveAUX.hpp"

//unused, but allows for updating in the future
void DriveAUX::__RobotInit__() {}
void DriveAUX::__RobotPeriodic__() {}
void DriveAUX::__AutonomousInit__() {}
void DriveAUX::__AutonomousPeriodic__() {}
void DriveAUX::__TeleopInit__() {}
void DriveAUX::__TeleopPeriodic__() {}
void DriveAUX::__TestPeriodic__() {}

//go to zero (center) with "range" degrees +/- of accuracy
void DriveAUX::GyroRotate(double range) {
    GyroRotateTo(0, range);
}

//go to a desired degree with "range" degrees +/- of accuracy
void DriveAUX::GyroRotateTo(double degree, double range) {
    //only continue if gyro is not nullptr
    if (gyro) {
        double fastestTo=gyro->FastestTo(degree);

        if (!(-range<fastestTo && fastestTo<range)) {
            if (fastestTo<0) {
                driveBase->drive(
                    0,
                    threshold+(-fastestTo * 0.0025)
                );
            }
            else {
                driveBase->drive(
                    0,
                    -threshold-(fastestTo * 0.0025)
                );
            }
        }
    }
}

//go to a desired degree with "range" degrees +/- of accuracy while going still going at "y_mult" speed
void DriveAUX::GyroRotateTo(double degree, double range, double y_mult) {
    //only continue if gyro is not nullptr
    if (gyro) {
        double fastestTo=gyro->FastestTo(degree);

        if (!(-range<fastestTo && fastestTo<range)) {
            if (fastestTo<0) {
                driveBase->drive(
                    y_mult,
                    threshold+(-fastestTo * 0.0025)
                );
            }
            else {
                driveBase->drive(
                    y_mult,
                    -threshold-(fastestTo * 0.0025)
                );
            }
        }
        else {
            driveBase->drive(y_mult, 0);
        }
    }
}