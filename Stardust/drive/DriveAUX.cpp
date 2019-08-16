#include "Stardust/drive/DriveAUX.hpp"

//unused, but allows for updating in the future
void DriveAUX::__RobotInit__() {}
void DriveAUX::__RobotPeriodic__() {}
void DriveAUX::__AutonomousInit__() {}
void DriveAUX::__AutonomousPeriodic__() {}
void DriveAUX::__TeleopInit__() {}
void DriveAUX::__TeleopPeriodic__() {}
void DriveAUX::__TestPeriodic__() {}

void DriveAUX::GyroRotate(double r) {
    GyroRotateTo(0, r);
}

void DriveAUX::GyroRotateTo(double g, double r) {
    double f2=gyro->FastestTo(g);

    if (!(-r<f2 && f2<r)) { //determine what side to rotate towards
        if (f2<0) {
            base->drive(0, -threshold+(f2*0.0025)); //move fast then slower as robot approaches angle
        }
        else {
            base->drive(0, threshold+(f2*0.0025));
        }
    }
}