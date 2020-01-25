#include "StarDust/sensor/motion/BetterGyro.hpp"

void BetterGyro::__RobotInit__() {
    Reset();
}
void BetterGyro::__RobotPeriodic__() {
    if (!started) {
        //only calibrate if the robot is in pre-match state
        Calibrate();
    }
    update();
}
void BetterGyro::__AutonomousInit__() {
    started=true;
    update();
}
void BetterGyro::__AutonomousPeriodic__() {
    update();
}
void BetterGyro::__TeleopInit__() {
    started=true;
    update();
}
void BetterGyro::__TeleopPeriodic__() {
    update();
}
void BetterGyro::__TestPeriodic__() {
    update();
}

double BetterGyro::FastestToZero() {
    return FastestTo(0.0);
}

//given a degree offset, calculate what angle is fastest to turn to
double BetterGyro::FastestTo(double desired) {
    double fastest=BetterGyro::GetAngleMod()-desired;

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