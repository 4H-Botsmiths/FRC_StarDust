#include "StarDust/sensor/motion/ADXRS450_Gyro.hpp"

void ADXRS450_Gyro::__RobotInit__() {
    Reset();
}
void ADXRS450_Gyro::__RobotPeriodic__() {
    if (!started) {
        //only calibrate if the robot is in pre-match state
        Calibrate();
    }
    update();
}
void ADXRS450_Gyro::__AutonomousInit__() {
    started=true;
    update();
}
void ADXRS450_Gyro::__AutonomousPeriodic__() {
    update();
}
void ADXRS450_Gyro::__TeleopInit__() {
    started=true;
    update();
}
void ADXRS450_Gyro::__TeleopPeriodic__() {
    update();
}
void ADXRS450_Gyro::__TestPeriodic__() {
    update();
}

double ADXRS450_Gyro::GetAngle() {
    return cached_degree;
}

double ADXRS450_Gyro::GetAngleMod() {
    return GetAngleMod(360);
}

double ADXRS450_Gyro::GetAngleMod(double deg) {
    return fmod(GetAngle(), deg);
}

double ADXRS450_Gyro::FastestToZero() {
    return FastestTo(0.0);
}

//given a degree offset, calculate what angle is fastest to turn to
double ADXRS450_Gyro::FastestTo(double desired) {
    double fastest=GetAngleMod() - desired;

    if (fastest <= 180 && fastest >= -180) {
        return fastest;
    }
    else if (fastest > 180) {
        return fastest - 360;
    }
    else {
        return 360 + fastest;
    }
}

void ADXRS450_Gyro::update() {
    cached_degree=frc::ADXRS450_Gyro::GetAngle();
}