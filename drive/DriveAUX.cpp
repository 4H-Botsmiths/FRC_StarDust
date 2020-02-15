#include <cmath>

#include <frc/smartdashboard/SmartDashboard.h>

#include "StarDust/drive/DriveAUX.hpp"

const double PI = 3.141592653589793;

DriveAUX::DriveAUX(DriveBase driveBase, ADXRS450_Gyro* gyro, double threshold) :
    driveBase(driveBase),
    gyro(gyro),
    threshold(threshold)
    {}

//go to zero (center) with "range" degrees +/- of accuracy
void DriveAUX::GyroRotateToZero(double range) {
    GyroRotateTo(0, range);
}

//go to a desired degree with "range" degrees +/- of accuracy
void DriveAUX::GyroRotateTo(double degree, double range) {
    GyroRotateTo(degree, range, 0);
}

//go to a desired degree with "range" degrees +/- of accuracy while going still going at "y_mult" speed
void DriveAUX::GyroRotateTo(double degree, double range, double y_mult) {
    double fastestTo=gyro->FastestTo(degree);

    if (!(-range<fastestTo && fastestTo<range)) {
        if (fastestTo<0) {
            driveBase.drive(
                y_mult,
                threshold+(-fastestTo * 0.0025)
            );
        }
        else {
            driveBase.drive(
                y_mult,
                -threshold-(fastestTo * 0.0025)
            );
        }
    }
    else {
        driveBase.drive(y_mult, 0);
    }
}

void DriveAUX::drive(double x, double y, double rot) {
    DriveAUX::drive(
        x,
        y,
        rot,
        gyro->GetAngleMod()
    );
}

void DriveAUX::drive(double x, double y, double z, double deg) {
    double hyp=sqrt( x*x + y*y );

    //convert x and y speeds to polar cords
    //phase shift by the degree from the gyro
    double adjusted_rads=(
        acos( x/hyp ) * copysign(1, y))
        -
        (deg * (PI/180)
    );

    driveBase.drive(
        hyp*cos(adjusted_rads),
        hyp*sin(adjusted_rads),
        z
    );
}