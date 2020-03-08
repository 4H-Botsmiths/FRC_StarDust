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

void Limelight::turnLightsOn() {
    limelight->PutNumber("ledMode", ledMode::ON);
}

void Limelight::turnLightsOff() {
    limelight->PutNumber("ledMode", ledMode::OFF);
}

double Limelight::get(std::string key) const {
    return limelight->GetNumber(key, 0);
}

//target valid
bool Limelight::getTV() const {
    return TV;
}

//target x offset
double Limelight::getTX() const {
    return TX;
}

//target y offset
double Limelight::getTY() const {
    return TY;
}

//target area
double Limelight::getTA() const {
    return TA;
}

//target skew
double Limelight::getTS() const {
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