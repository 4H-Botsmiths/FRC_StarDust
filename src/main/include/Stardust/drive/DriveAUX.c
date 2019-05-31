#include "Stardust/drive/DriveAUX.h"

void DriveAUX::GyroRotate(double r) {
    GyroRotateTo(0, r);
}

void DriveAUX::GyroRotateTo(double g, double r) {
    double f2=gyro->FastestTo(g);

    if (!(-r<f2 && f2<r)) { //determine what side to rotate towards
        if (f2<0) {
            base->drive(0, -threshold+(f2*0.005)); //move fast then slower as robot approaches angle
        }
        else {
            base->drive(0, threshold+(f2*0.005));
        }
    }
}