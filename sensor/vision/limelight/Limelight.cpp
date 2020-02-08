#include "StarDust/sensor/vision/limelight/Limelight.hpp"

//update whenever possible
void Limelight::__RobotPeriodic__() {
    update();
}
void Limelight::__AutonomousInit__() {
    update();
}
void Limelight::__AutonomousPeriodic__() {
    update();
}
void Limelight::__TeleopInit__() {
    update();
}
void Limelight::__TeleopPeriodic__() {
    update();
}
void Limelight::__TestPeriodic__() {
    update();
}

void Limelight::setLights(bool on) {
    limelight->PutNumber("ledMode", (
        on ? ledMode::ON : ledMode::OFF
    ));
}

double Limelight::get(std::string key) {
    return limelight->GetNumber(key, 0);
}

//target valid
bool Limelight::getTV() {
    return TV;
}

//target x offset
double Limelight::getTX() {
    return TX;
}

//target y offset
double Limelight::getTY() {
    return TY;
}

//target area
double Limelight::getTA() {
    return TA;
}

//target skew
double Limelight::getTS() {
    return TS;
}

void Limelight::update() {
    //convert double to bool
    TV=(get("tv")==1);

    TX=get("tx");
    TY=get("ty");
    TA=get("ta");

    double skew=get("ts");

    //make skew usable
    if (skew<-45) skew+=90;
    TS=skew*-1;
}