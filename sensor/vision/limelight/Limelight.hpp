#pragma once

#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTable.h>
#include <string.h>

#include "StarDust/core/StarDustComponent.hpp"

class Limelight : public StarDustComponent {
public:
    Limelight() {}

    void __RobotInit__() {};

    //update whenever possible
    void __RobotPeriodic__() { update(); };
    void __AutonomousInit__() { update(); };
    void __AutonomousPeriodic__() { update(); };
    void __TeleopInit__() { update(); };
    void __TeleopPeriodic__() { update(); };
    void __TestPeriodic__() { update(); };

    void setLights(bool on) { limelight->PutNumber("ledMode", (on ? 3 : 1)); }

    //grabs value "key" from local network table
    double get(std::string key) { return limelight->GetNumber(key, 0); }

    //wrappers for commonly used values
    //use get(keyname) or add a custom get function (recommended) to get uncommon variables

    bool getTV() { return TV; } //target valid
    double getTX() { return TX; } //target x offset
    double getTY() { return TY; } //target y offset
    double getTA() { return TA; } //target area
    double getTS() { return TS; } //target skew

private:
    void update() {
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

    std::shared_ptr<NetworkTable> limelight=nt::NetworkTableInstance::GetDefault().GetTable("limelight");

    bool TV=false;
    double TX=0;
    double TY=0;
    double TA=0;
    double TS=0;
};