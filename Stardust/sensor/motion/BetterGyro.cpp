#include "Stardust/sensor/motion/BetterGyro.hpp"

//always get the most recent of the robot where it makes sense
void BetterGyro::__RobotInit__() {}
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

//given a degree offset, calculate what angle is fastest to turn to
double BetterGyro::FastestTo(double deg) {
    double g=BetterGyro::GetAngleMod()-deg;

    if (g<=180&&g>=-180) {
        return g; //if within half turn just return
    }
    else if (g>180) {
        return g-360; //if over 180 turn convert to negative
    }
    else {
        return 360+g; //if under -180 convert to positive
    }
}

double BetterGyro::FastestToZero() {
    return FastestTo(0.0);
}