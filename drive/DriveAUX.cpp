#include <cmath>

#include <frc/smartdashboard/SmartDashboard.h>

#include "StarDust/drive/DriveAUX.hpp"

const double PI = 3.141592653589793;

DriveAUX::DriveAUX(DriveBase* driveBase, Gyro_Base* gyro, double threshold) :
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
    GyroRotateTo(degree, range, 0, 0);
}

//go to a desired degree with "range" degrees +/- of accuracy while going still going at "y_mult" speed
void DriveAUX::GyroRotateTo(double degree, double range, double y_mult) {
    GyroRotateTo(degree, range, 0, y_mult);
}

//go to a desired degree with "range" degrees +/- of accuracy while going still going at x_mult and y_mult speed in the x and y direction
void DriveAUX::GyroRotateTo(double degree, double range, double x_mult, double y_mult) {
    driveBase->drive(
        x_mult,
        y_mult,
        calculateRotation(degree, range)
    );
}

void DriveAUX::drive(XboxController* controller) {
    DriveAUX::drive(
        controller->GetXLeftDeadzone(),
        controller->GetYLeftDeadzone(),
        controller->GetXRightDeadzone()
    );
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

    driveBase->drive(
        hyp*cos(adjusted_rads),
        hyp*sin(adjusted_rads),
        z
    );
}

void DriveAUX::driveGyro(double degree, double range, XboxController* controller) {
    DriveAUX::drive(
        controller->GetXRightDeadzone(),
        controller->GetYRightDeadzone(),
        calculateRotation(degree, range)
    );
}

void DriveAUX::driveGyro(double degree, double range, double x_mult, double y_mult) {
    DriveAUX::drive(
        x_mult,
        y_mult,
        calculateRotation(degree, range)
    );
}

double DriveAUX::calculateRotation(double degree, double range) {
    double fastestTo=gyro->FastestTo(degree);

    if (-range < fastestTo && fastestTo < range) {
        return 0;
    }
    else if (fastestTo < 0) {
        return threshold + (-fastestTo * 0.005);
    }
    else {
        return -threshold - (fastestTo * 0.005);
    }
}