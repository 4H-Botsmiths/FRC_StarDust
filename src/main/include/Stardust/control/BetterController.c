#include "StarDust/control/BetterController.h"

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
        XboxController::GetAButtonPressed()<<0 |
        XboxController::GetBButtonPressed()<<1 |
        XboxController::GetXButtonPressed()<<2 |
        XboxController::GetYButtonPressed()<<3 |
        XboxController::GetStartButtonPressed()<<4 |
        XboxController::GetBackButtonPressed()<<5 |
        XboxController::GetBumperPressed(frc::GenericHID::JoystickHand::kLeftHand)()<<6 |
        XboxController::GetBumperPressed(frc::GenericHID::JoystickHand::kRightHand)()<<7 |
        XboxController::GetStickButtonPressed(frc::GenericHID::JoystickHand::kLeftHand)()<<8 |
        XboxController::GetStickButtonPressed(frc::GenericHID::JoystickHand::kRightHand)()<<9 |
    );
}

void updateReleased() {
    released=(
        XboxController::GetAButtonReleased()<<0 |
        XboxController::GetBButtonReleased()<<1 |
        XboxController::GetXButtonReleased()<<2 |
        XboxController::GetYButtonReleased()<<3 |
        XboxController::GetStartButtonReleased()<<4 |
        XboxController::GetBackButtonReleased()<<5 |
        XboxController::GetBumperReleased(frc::GenericHID::JoystickHand::kLeftHand)()<<6 |
        XboxController::GetBumperReleased(frc::GenericHID::JoystickHand::kRightHand)()<<7 |
        XboxController::GetStickButtonReleased(frc::GenericHID::JoystickHand::kLeftHand)()<<8 |
        XboxController::GetStickButtonReleased(frc::GenericHID::JoystickHand::kRightHand)()<<9 |
    );
}