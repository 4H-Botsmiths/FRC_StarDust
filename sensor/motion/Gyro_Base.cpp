#include "StarDust/sensor/motion/Gyro_Base.hpp"

void Gyro_Base::__RobotInit__() {
    gyro->Reset();
}
void Gyro_Base::__RobotPeriodic__() {
    if (!started) {
        //only calibrate if the robot is in pre-match state
        gyro->Calibrate();
    }
    update();
}
void Gyro_Base::__AutonomousInit__() {
    started=true;
    update();
}
void Gyro_Base::__AutonomousPeriodic__() {
    update();
}
void Gyro_Base::__TeleopInit__() {
    started=true;
    update();
}
void Gyro_Base::__TeleopPeriodic__() {
    update();
}
void Gyro_Base::__TestPeriodic__() {
    update();
}

double Gyro_Base::GetAngle() {
    return cached_degree;
}

double Gyro_Base::GetAngleMod() {
    return GetAngleMod(360);
}

double Gyro_Base::GetAngleMod(double deg) {
    return fmod(GetAngle(), deg);
}

double Gyro_Base::FastestToZero() {
    return FastestTo(0.0);
}

//given a degree offset, calculate what angle is fastest to turn to
double Gyro_Base::FastestTo(double desired) {
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

void Gyro_Base::update() {
    cached_degree=gyro->GetAngle();
}