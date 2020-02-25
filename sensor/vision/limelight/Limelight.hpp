#pragma once

#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTable.h>
#include <string.h>

#include "StarDust/core/StarDustComponent.hpp"

class Limelight : public StarDustComponent {
public:
    Limelight() {}

    void __RobotPeriodic__() override;
    void __AutonomousInit__() override;
    void __AutonomousPeriodic__() override;
    void __TeleopInit__() override;
    void __TeleopPeriodic__() override;
    void __TestPeriodic__() override;

    enum ledMode {
        CURRENT_PIPE,
        OFF,
        BLINK,
        ON
    };

    void turnLightsOn();
    void turnLightsOff();

    //grabs value "key" from local network table
    double get(std::string key);

    //wrappers for commonly used values
    bool getTV();
    double getTX();
    double getTY();
    double getTA();
    double getTS();

private:
    void update();

    std::shared_ptr<NetworkTable> limelight=nt::NetworkTableInstance::GetDefault().GetTable("limelight");

    bool TV=false;
    double TX=0;
    double TY=0;
    double TA=0;
    double TS=0;
};