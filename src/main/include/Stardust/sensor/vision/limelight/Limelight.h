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
    double getTX() { return get("tx"); }
    double getTY() { return get("ty"); }
    double getTA() { return get("ta"); }
    double getTS() {
        double tmp=get("ts");

        //make skew usable
        if (tmp<-45) tmp+=90;
        return tmp*-1;
    }

private:
    std::shared_ptr<NetworkTable> mLimelight=nt::NetworkTableInstance::GetDefault().GetTable("limelight");
};