#include "StarDust/sensor/motion/Gyro.hpp"

void Gyro::__RobotInit__() {
    Reset();
}
void Gyro::__RobotPeriodic__() {
    if (!started) {
        //only calibrate if the robot is in pre-match state
        Calibrate();
    }
    update();
}
void Gyro::__AutonomousInit__() {
    started=true;
    update();
}
void Gyro::__AutonomousPeriodic__() {
    update();
}
void Gyro::__TeleopInit__() {
    started=true;
    update();
}
void Gyro::__TeleopPeriodic__() {
    update();
}
void Gyro::__TestPeriodic__() {
    update();
}

double Gyro::FastestToZero() {
    return FastestTo(0.0);
}

//given a degree offset, calculate what angle is fastest to turn to
double Gyro::FastestTo(double desired) {
    double fastest=Gyro::GetAngleMod()-desired;

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