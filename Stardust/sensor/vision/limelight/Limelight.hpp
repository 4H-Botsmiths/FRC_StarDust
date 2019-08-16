#pragma once

#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTable.h>
#include <string.h>

#include "Stardust/core/StarDustComponent.hpp"

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

    //true turns lights on, false turns off
    void setLights(bool on) { mLimelight->PutNumber("ledMode", (on?3:1)); }

    //grabs a value by key "key" from local network table
    double get(std::string key) { return mLimelight->GetNumber(key, 0); }

    //commonly used values
    //to get uncommon values (contours, debugging, etc), use get(keyname) or add a custom get function (recommended)
    double getTV() { return TV; } //get valid status
    double getTX() { return TX; } //get x offset
    double getTY() { return TY; } //get y offset
    double getTA() { return TA; } //get area
    double getTS() { return TS; }

    void update() {
        TV=(get("tv")==1); //TV is a bool, convert double output to bool
        TX=get("tx"); //update the doubles
        TY=get("ty"); //
        TA=get("ta"); //

        double tmp=get("ts");

        //make skew usable
        if (tmp<-45) tmp+=90;
        TS=tmp*-1;
    }

private:
    std::shared_ptr<NetworkTable> mLimelight=nt::NetworkTableInstance::GetDefault().GetTable("limelight");

    bool TV=false;
    double TX=0;
    double TY=0;
    double TA=0;
    double TS=0;
};