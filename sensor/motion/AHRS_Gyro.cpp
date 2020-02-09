#include "StarDust/sensor/motion/AHRS_Gyro.hpp"

void AHRS_Gyro::__RobotInit__() {
    Reset();
}
void AHRS_Gyro::__RobotPeriodic__() {
    if (!started) {
        //only calibrate if the robot is in pre-match state
        Calibrate();
    }
    update();
}
void AHRS_Gyro::__AutonomousInit__() {
    started=true;
    update();
}
void AHRS_Gyro::__AutonomousPeriodic__() {
    update();
}
void AHRS_Gyro::__TeleopInit__() {
    started=true;
    update();
}
void AHRS_Gyro::__TeleopPeriodic__() {
    update();
}
void AHRS_Gyro::__TestPeriodic__() {
    update();
}

double AHRS_Gyro::FastestToZero() {
    return FastestTo(0.0);
}

//given a degree offset, calculate what angle is fastest to turn to
double AHRS_Gyro::FastestTo(double desired) {
    double fastest=AHRS_Gyro::GetAngleMod()-desired;

    if (fastest<=180&&fastest>=-180) {
        return fastest;
    }
    else if (fastest>180) {
        return fastest-360;
    }
    else {
        return 360+fastest;
    }
}