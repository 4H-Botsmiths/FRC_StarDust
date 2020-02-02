#include <stdlib.h>
#include <math.h>

#include "StarDust/control/XboxController.hpp"

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
void XboxController::autorun() {
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

double XboxController::GetXLeft() { return XboxController::GetX(frc::GenericHID::JoystickHand::kLeftHand); }
double XboxController::GetXLeftDeadzone() { return deadzone(GetXLeft(), stickDeadzone); }
double XboxController::GetXLeftDeadzone(double range) { return deadzone(GetXLeft(), range); }

double XboxController::GetXRight() { return XboxController::GetX(frc::GenericHID::JoystickHand::kRightHand); }
double XboxController::GetXRightDeadzone() { return deadzone(GetXRight(), stickDeadzone); }
double XboxController::GetXRightDeadzone(double range) { return deadzone(GetXRight(), range); }

double XboxController::GetYLeft() { return XboxController::GetY(frc::GenericHID::JoystickHand::kLeftHand); }
double XboxController::GetYLeftDeadzone() { return deadzone(GetYLeft(), stickDeadzone); }
double XboxController::GetYLeftDeadzone(double range) { return deadzone(GetYLeft(), range); }

double XboxController::GetYRight() { return XboxController::GetY(frc::GenericHID::JoystickHand::kRightHand); }
double XboxController::GetYRightDeadzone() { return deadzone(GetYRight(), stickDeadzone); }
double XboxController::GetYRightDeadzone(double range) { return deadzone(GetYRight(), range); }

double XboxController::GetTriggerLeft() { return XboxController::GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand); }
double XboxController::GetTriggerLeftDeadzone() { return deadzone(GetTriggerLeft(), triggerDeadzone); }
double XboxController::GetTriggerLeftDeadzone(double range) { return deadzone(GetTriggerLeft(), range); }

double XboxController::GetTriggerRight() { return XboxController::GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand); }
double XboxController::GetTriggerRightDeadzone() { return deadzone(GetTriggerRight(), triggerDeadzone); }
double XboxController::GetTriggerRightDeadzone(double range) { return deadzone(GetTriggerRight(), range); }

bool XboxController::GetAButtonPressed() { return pressed & 1<<0; }
bool XboxController::GetAButtonReleased() { return released & 1<<0; }

bool XboxController::GetBButtonPressed() { return pressed & 1<<1; }
bool XboxController::GetBButtonReleased() { return released & 1<<1; }

bool XboxController::GetXButtonPressed() { return pressed & 1<<2; }
bool XboxController::GetXButtonReleased() { return released & 1<<2; }

bool XboxController::GetYButtonPressed() { return pressed & 1<<3; }
bool XboxController::GetYButtonReleased() { return released & 1<<3; }

bool XboxController::GetStartButtonPressed() { return pressed & 1<<4; }
bool XboxController::GetStartButtonReleased() { return released & 1<<4; }

bool XboxController::GetBackButtonPressed() { return pressed & 1<<5; }
bool XboxController::GetBackButtonReleased() { return released & 1<<5; }

bool XboxController::GetLeftBumper() {
    return frc::XboxController::GetBumper(frc::GenericHID::kLeftHand);
}
bool XboxController::GetRightBumper() {
    return frc::XboxController::GetBumper(frc::GenericHID::kLeftHand);
}
bool XboxController::GetLeftStickButton() {
    return frc::XboxController::GetStickButton(frc::GenericHID::kLeftHand);
}
bool XboxController::GetRightStickButton() {
    return frc::XboxController::GetStickButton(frc::GenericHID::kLeftHand);
}

bool XboxController::GetLeftBumperPressed() {
    return pressed & 1 << 6;
}
bool XboxController::GetRightBumperPressed() {
    return pressed & 1 << 7;
}
bool XboxController::GetLeftBumperReleased() {
    return released & 1 << 6;
}
bool XboxController::GetRightBumperReleased() {
    return released & 1 << 7;
}

bool XboxController::GetLeftStickButtonPressed() {
    return pressed & 1 << 8;
}
bool XboxController::GetRightStickButtonPressed() {
    return pressed & 1 << 9;
}
bool XboxController::GetLeftStickButtonReleased() {
    return released & 1 << 8;
}
bool XboxController::GetRightStickButtonReleased() {
    return released & 1 << 9;
}

void XboxController::updatePressed() {
    pressed=(
        XboxController::GetAButtonPressed()<<0 |
        XboxController::GetBButtonPressed()<<1 |
        XboxController::GetXButtonPressed()<<2 |
        XboxController::GetYButtonPressed()<<3 |
        XboxController::GetStartButtonPressed()<<4 |
        XboxController::GetBackButtonPressed()<<5 |
        XboxController::GetBumperPressed(frc::GenericHID::JoystickHand::kLeftHand)<<6 |
        XboxController::GetBumperPressed(frc::GenericHID::JoystickHand::kRightHand)<<7 |
        XboxController::GetStickButtonPressed(frc::GenericHID::JoystickHand::kLeftHand)<<8 |
        XboxController::GetStickButtonPressed(frc::GenericHID::JoystickHand::kRightHand)<<9
    );
}

void XboxController::updateReleased() {
    released=(
        XboxController::GetAButtonReleased()<<0 |
        XboxController::GetBButtonReleased()<<1 |
        XboxController::GetXButtonReleased()<<2 |
        XboxController::GetYButtonReleased()<<3 |
        XboxController::GetStartButtonReleased()<<4 |
        XboxController::GetBackButtonReleased()<<5 |
        XboxController::GetBumperReleased(frc::GenericHID::JoystickHand::kLeftHand)<<6 |
        XboxController::GetBumperReleased(frc::GenericHID::JoystickHand::kRightHand)<<7 |
        XboxController::GetStickButtonReleased(frc::GenericHID::JoystickHand::kLeftHand)<<8 |
        XboxController::GetStickButtonReleased(frc::GenericHID::JoystickHand::kRightHand)<<9
    );
}

double XboxController::deadzone(double value, double range) {
    double old=value;
    value=abs(value);

    return copysign(
        value<range?
            0:
            (value-range)/(1-range),
        old
    );
}