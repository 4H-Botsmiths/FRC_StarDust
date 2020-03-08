#include <stdlib.h>
#include <math.h>

#include "StarDust/control/XboxController.hpp"

XboxController::XboxController(int port) :
    frc::XboxController(port)
    {}

XboxController::XboxController(int port, const double stick_deadzone) :
    frc::XboxController(port),
    stickDeadzone(stick_deadzone),
    triggerDeadzone(stick_deadzone)
    {}

XboxController::XboxController(int port, const double stick_deadzone, const double trigger_deadzone) :
    frc::XboxController(port),
    stickDeadzone(stick_deadzone),
    triggerDeadzone(trigger_deadzone)
    {}

XboxController::XboxController(int port, const double stick_deadzone, const double trigger_deadzone, const std::map<int, std::function<void()>> binds) :
    frc::XboxController(port),
    stickDeadzone(stick_deadzone),
    triggerDeadzone(trigger_deadzone),
    binds(binds)
    {}

void XboxController::__RobotPeriodic__() {
    clearCache();
}
void XboxController::__AutonomousPeriodic__() {
    updateBoth();
    autorun();
}
void XboxController::__TeleopPeriodic__() {
    updateBoth();
    autorun();
}
void XboxController::__TestPeriodic__() {
    updateBoth();
    autorun();
}
void XboxController::__RobotInit__() {
    updateBoth();
    autorun();
}
void XboxController::__AutonomousInit__() {
    updateBoth();
    autorun();
}
void XboxController::__TeleopInit__() {
    updateBoth();
    autorun();
}

//go through all binds and check/dispatch functions if event handler conditions are met
void XboxController::autorun() const {
    if (!binds.empty()) {
        for (const auto& i : binds) {
            if (i.first==on::AButton&&GetAButton()) i.second();
            else if (i.first==on::AButtonPressed&&GetAButtonPressed()) i.second();
            else if (i.first==on::AButtonReleased&&GetAButtonReleased()) i.second();
            else if (i.first==on::BButton&&GetBButton()) i.second();
            else if (i.first==on::BButtonPressed&&GetBButtonPressed()) i.second();
            else if (i.first==on::BButtonReleased&&GetBButtonReleased()) i.second();
            else if (i.first==on::XButton&&GetXButton()) i.second();
            else if (i.first==on::XButtonPressed&&GetXButtonPressed()) i.second();
            else if (i.first==on::XButtonReleased&&GetXButtonReleased()) i.second();
            else if (i.first==on::YButton&&GetYButton()) i.second();
            else if (i.first==on::YButtonPressed&&GetYButtonPressed()) i.second();
            else if (i.first==on::YButtonReleased&&GetYButtonReleased()) i.second();
            else if (i.first==on::StartButton&&GetStartButton()) i.second();
            else if (i.first==on::StartButtonPressed&&GetStartButtonPressed()) i.second();
            else if (i.first==on::StartButtonReleased&&GetStartButtonReleased()) i.second();
            else if (i.first==on::BackButton&&GetBackButton()) i.second();
            else if (i.first==on::BackButtonPressed&&GetBackButtonPressed()) i.second();
            else if (i.first==on::BackButtonReleased&&GetBackButtonReleased()) i.second();
            else if (i.first==on::LeftBumper&&GetLeftBumper()) i.second();
            else if (i.first==on::LeftBumperPressed&&GetLeftBumperPressed()) i.second();
            else if (i.first==on::RightBumperPressed&&GetRightBumperPressed()) i.second();
            else if (i.first==on::LeftBumperReleased&&GetLeftBumperReleased()) i.second();
            else if (i.first==on::RightBumperReleased&&GetRightBumperReleased()) i.second();
            else if (i.first==on::LeftStickButtonPressed&&GetLeftStickButtonPressed()) i.second();
            else if (i.first==on::RightStickButtonPressed&&GetRightStickButtonPressed()) i.second();
            else if (i.first==on::LeftStickButtonReleased&&GetLeftStickButtonReleased()) i.second();
            else if (i.first==on::RightStickButtonReleased&&GetRightStickButtonReleased()) i.second();
        }
    }
}

double XboxController::GetXLeft() const { return XboxController::GetX(frc::GenericHID::JoystickHand::kLeftHand); }
double XboxController::GetXLeftDeadzone() const { return deadzone(GetXLeft(), stickDeadzone); }
double XboxController::GetXLeftDeadzone(double range) const { return deadzone(GetXLeft(), range); }

double XboxController::GetXRight() const { return XboxController::GetX(frc::GenericHID::JoystickHand::kRightHand); }
double XboxController::GetXRightDeadzone() const { return deadzone(GetXRight(), stickDeadzone); }
double XboxController::GetXRightDeadzone(double range) const { return deadzone(GetXRight(), range); }

double XboxController::GetYLeft() const { return XboxController::GetY(frc::GenericHID::JoystickHand::kLeftHand); }
double XboxController::GetYLeftDeadzone() const { return deadzone(GetYLeft(), stickDeadzone); }
double XboxController::GetYLeftDeadzone(double range) const { return deadzone(GetYLeft(), range); }

double XboxController::GetYRight() const { return XboxController::GetY(frc::GenericHID::JoystickHand::kRightHand); }
double XboxController::GetYRightDeadzone() const { return deadzone(GetYRight(), stickDeadzone); }
double XboxController::GetYRightDeadzone(double range) const { return deadzone(GetYRight(), range); }

double XboxController::GetTriggerLeft() const { return XboxController::GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand); }
double XboxController::GetTriggerLeftDeadzone() const { return deadzone(GetTriggerLeft(), triggerDeadzone); }
double XboxController::GetTriggerLeftDeadzone(double range) const { return deadzone(GetTriggerLeft(), range); }

double XboxController::GetTriggerRight() const { return XboxController::GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand); }
double XboxController::GetTriggerRightDeadzone() const { return deadzone(GetTriggerRight(), triggerDeadzone); }
double XboxController::GetTriggerRightDeadzone(double range) const { return deadzone(GetTriggerRight(), range); }

bool XboxController::GetAButtonPressed() const { return pressed & 1<<0; }
bool XboxController::GetAButtonReleased() const { return released & 1<<0; }

bool XboxController::GetBButtonPressed() const { return pressed & 1<<1; }
bool XboxController::GetBButtonReleased() const { return released & 1<<1; }

bool XboxController::GetXButtonPressed() const { return pressed & 1<<2; }
bool XboxController::GetXButtonReleased() const { return released & 1<<2; }

bool XboxController::GetYButtonPressed() const { return pressed & 1<<3; }
bool XboxController::GetYButtonReleased() const { return released & 1<<3; }

bool XboxController::GetStartButtonPressed() const { return pressed & 1<<4; }
bool XboxController::GetStartButtonReleased() const { return released & 1<<4; }

bool XboxController::GetBackButtonPressed() const { return pressed & 1<<5; }
bool XboxController::GetBackButtonReleased() const { return released & 1<<5; }

bool XboxController::GetLeftBumper() const {
    return frc::XboxController::GetBumper(frc::GenericHID::kLeftHand);
}
bool XboxController::GetRightBumper() const {
    return frc::XboxController::GetBumper(frc::GenericHID::kRightHand);
}
bool XboxController::GetLeftStickButton() const {
    return frc::XboxController::GetStickButton(frc::GenericHID::kLeftHand);
}
bool XboxController::GetRightStickButton() const {
    return frc::XboxController::GetStickButton(frc::GenericHID::kRightHand);
}

bool XboxController::GetLeftBumperPressed() const {
    return pressed & 1 << 6;
}
bool XboxController::GetRightBumperPressed() const {
    return pressed & 1 << 7;
}
bool XboxController::GetLeftBumperReleased() const {
    return released & 1 << 6;
}
bool XboxController::GetRightBumperReleased() const {
    return released & 1 << 7;
}

bool XboxController::GetLeftStickButtonPressed() const {
    return pressed & 1 << 8;
}
bool XboxController::GetRightStickButtonPressed() const {
    return pressed & 1 << 9;
}
bool XboxController::GetLeftStickButtonReleased() const {
    return released & 1 << 8;
}
bool XboxController::GetRightStickButtonReleased() const {
    return released & 1 << 9;
}

void XboxController::updatePressed() {
    pressed=(
        frc::XboxController::GetAButtonPressed()<<0 |
        frc::XboxController::GetBButtonPressed()<<1 |
        frc::XboxController::GetXButtonPressed()<<2 |
        frc::XboxController::GetYButtonPressed()<<3 |
        frc::XboxController::GetStartButtonPressed()<<4 |
        frc::XboxController::GetBackButtonPressed()<<5 |
        frc::XboxController::GetBumperPressed(frc::GenericHID::JoystickHand::kLeftHand)<<6 |
        frc::XboxController::GetBumperPressed(frc::GenericHID::JoystickHand::kRightHand)<<7 |
        frc::XboxController::GetStickButtonPressed(frc::GenericHID::JoystickHand::kLeftHand)<<8 |
        frc::XboxController::GetStickButtonPressed(frc::GenericHID::JoystickHand::kRightHand)<<9
    );
}

void XboxController::updateReleased() {
    released=(
        frc::XboxController::GetAButtonReleased()<<0 |
        frc::XboxController::GetBButtonReleased()<<1 |
        frc::XboxController::GetXButtonReleased()<<2 |
        frc::XboxController::GetYButtonReleased()<<3 |
        frc::XboxController::GetStartButtonReleased()<<4 |
        frc::XboxController::GetBackButtonReleased()<<5 |
        frc::XboxController::GetBumperReleased(frc::GenericHID::JoystickHand::kLeftHand)<<6 |
        frc::XboxController::GetBumperReleased(frc::GenericHID::JoystickHand::kRightHand)<<7 |
        frc::XboxController::GetStickButtonReleased(frc::GenericHID::JoystickHand::kLeftHand)<<8 |
        frc::XboxController::GetStickButtonReleased(frc::GenericHID::JoystickHand::kRightHand)<<9
    );
}

void XboxController::updateBoth() {
    updatePressed();
    updateReleased();
}

void XboxController::clearCache() {
    //updating twice clears the xbox internal cache
    updateBoth();
    updateBoth();
}

double XboxController::deadzone(double value, double range) const {
    double old=value;
    value=abs(value);

    return copysign(
        value<range?
            0:
            (value-range)/(1-range),
        old
    );
}