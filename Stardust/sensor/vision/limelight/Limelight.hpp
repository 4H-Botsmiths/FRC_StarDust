#pragma once

#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTable.h>
#include <string.h>

class Limelight {
public:
    Limelight() {}

    //true turns lights on, false turns off
    void setLights(bool on) { mLimelight->PutNumber("ledMode", (on?3:1)); }

    double get(std::string key) { return mLimelight->GetNumber(key, 0); }
    double getTV() { return get("tv"); } //get valid status
    double getTX() { return get("tx"); } //get x offset
    double getTY() { return get("ty"); } //get y offset
    double getTA() { return get("ta"); } //get area
    double getTS() { //get (useful) skew
        double tmp=get("ts");

        //make skew usable
        if (tmp<-45) tmp+=90;
        return tmp*-1;
    }

private:
    std::shared_ptr<NetworkTable> mLimelight=nt::NetworkTableInstance::GetDefault().GetTable("limelight");
};