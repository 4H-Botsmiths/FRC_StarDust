#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTable.h>

class Limelight {
public:
    Limelight() {}

    //true turns lights on, false turns off
    void setLights(bool on) { mLimelight->PutNumber("ledMode", (on?3:1)); }

private:
    std::shared_ptr<NetworkTable> mLimelight=nt::NetworkTableInstance::GetDefault().GetTable("limelight");
};