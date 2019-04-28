#include "BetterController.h"

bool GetAButtonPressed() { return pressed & 1<<0; }
bool GetAButtonReleased() { return released & 1<<0; }

bool GetBButtonPressed() { return pressed & 1<<1; }
bool GetBButtonReleased() { return released & 1<<1; }

bool GetXButtonPressed() { return pressed & 1<<2; }
bool GetXButtonReleased() { return released & 1<<2; }

bool GetYButtonPressed() { return pressed & 1<<3; }
bool GetYButtonReleased() { return released & 1<<3; }

bool GetStartButtonPressed() { return pressed & 1<<4; }
bool GetStartButtonReleased() { return released & 1<<4; }

bool GetBackButtonPressed() { return pressed & 1<<5; }
bool GetBackButtonReleased() { return released & 1<<5; }

bool GetBumperPressed(frc::GenericHID::JoystickHand hand) {
    return pressed & 1 << (6 + (hand == frc::GenericHID::JoystickHand::kLeftHand));
}
bool GetBumperReleased(frc::GenericHID::JoystickHand hand) {
    return released & 1 << (6 + (hand == frc::GenericHID::JoystickHand::kLeftHand));
}

bool GetStickButtonPressed(JoystickHand hand) {
    return pressed & 1 << (8 + (hand == frc::GenericHID::JoystickHand::kLeftHand));
}
bool GetStickButtonReleased(JoystickHand hand) {
    return released & 1 << (8 + (hand == frc::GenericHID::JoystickHand::kLeftHand));
}

void updatePressed() {
    pressed=(
        mXbox.GetAButtonPressed()<<0 |
        mXbox.GetBButtonPressed()<<1 |
        mXbox.GetXButtonPressed()<<2 |
        mXbox.GetYButtonPressed()<<3 |
        mXbox.GetStartButtonPressed()<<4 |
        mXbox.GetBackButtonPressed()<<5 |
        mXbox.GetBumperPressed(frc::GenericHID::JoystickHand::kLeftHand)()<<6 |
        mXbox.GetBumperPressed(frc::GenericHID::JoystickHand::kRightHand)()<<7 |
        mXbox.GetStickButtonPressed(frc::GenericHID::JoystickHand::kLeftHand)()<<8 |
        mXbox.GetStickButtonPressed(frc::GenericHID::JoystickHand::kRightHand)()<<9 |
    );
}

void updateReleased() {
    released=(
        mXbox.GetAButtonReleased()<<0 |
        mXbox.GetBButtonReleased()<<1 |
        mXbox.GetXButtonReleased()<<2 |
        mXbox.GetYButtonReleased()<<3 |
        mXbox.GetStartButtonReleased()<<4 |
        mXbox.GetBackButtonReleased()<<5 |
        mXbox.GetBumperReleased(frc::GenericHID::JoystickHand::kLeftHand)()<<6 |
        mXbox.GetBumperReleased(frc::GenericHID::JoystickHand::kRightHand)()<<7 |
        mXbox.GetStickButtonReleased(frc::GenericHID::JoystickHand::kLeftHand)()<<8 |
        mXbox.GetStickButtonReleased(frc::GenericHID::JoystickHand::kRightHand)()<<9 |
    );
}