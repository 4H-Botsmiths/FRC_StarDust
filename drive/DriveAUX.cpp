#include "StarDust/drive/DriveAUX.hpp"

//unused, but allows for updating in the future
void DriveAUX::__RobotInit__() {}
void DriveAUX::__RobotPeriodic__() {}
void DriveAUX::__AutonomousInit__() {}
void DriveAUX::__AutonomousPeriodic__() {}
void DriveAUX::__TeleopInit__() {}
void DriveAUX::__TeleopPeriodic__() {}
void DriveAUX::__TestPeriodic__() {}

//go to zero (center) with "r" degrees +/- of accuracy
//eg, "r" 10 will stop when within a 10 degree range from the center (20 from both sides)
void DriveAUX::GyroRotate(double r) {
    GyroRotateTo(0, r);
}

//go to a desired degree with "r" degrees +/- of accuracy
void DriveAUX::GyroRotateTo(double g, double r) {
    if (gyro) { //only continue if gyro is available
        double f2=gyro->FastestTo(g);

        if (!(-r<f2 && f2<r)) { //only move if in range
            if (f2<0) {
                base->drive(0, threshold+(-f2*0.0025)); //move fast then slower as robot approaches angle
            }
            else {
                base->drive(0, -threshold-(f2*0.0025));
            }
        }
    }
}

//go to a desired degree with "r" degrees +/- of accuracy while going still going at "y" speed
void DriveAUX::GyroRotateTo(double g, double r, double y) {
    if (gyro) { //only continue if gyro is available
        double f2=gyro->FastestTo(g);

        if (!(-r<f2 && f2<r)) { //only move if in range
            if (f2<0) {
                base->drive(y, threshold+(-f2*0.0025)); //move fast then slower as robot approaches angle
            }
            else {
                base->drive(y, -threshold-(f2*0.0025));
            }
        }
        else {
            base->drive(y, 0);
        }
    }
}