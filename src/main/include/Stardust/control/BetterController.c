#include "StarDust/control/BetterController.h"

bool BetterController::GetAButtonPressed() { return pressed & 1<<0; }
bool BetterController::GetAButtonReleased() { return released & 1<<0; }

bool BetterController::GetBButtonPressed() { return pressed & 1<<1; }
bool BetterController::GetBButtonReleased() { return released & 1<<1; }

bool BetterController::GetXButtonPressed() { return pressed & 1<<2; }
bool BetterController::GetXButtonReleased() { return released & 1<<2; }

bool BetterController::GetYButtonPressed() { return pressed & 1<<3; }
bool BetterController::GetYButtonReleased() { return released & 1<<3; }

bool BetterController::GetStartButtonPressed() { return pressed & 1<<4; }
bool BetterController::GetStartButtonReleased() { return released & 1<<4; }

bool BetterController::GetBackButtonPressed() { return pressed & 1<<5; }
bool BetterController::GetBackButtonReleased() { return released & 1<<5; }

bool BetterController::GetBumperPressed(frc::GenericHID::JoystickHand hand) {
    return pressed & 1 << (6 + (hand == frc::GenericHID::JoystickHand::kLeftHand));
}
bool BetterController::GetBumperReleased(frc::GenericHID::JoystickHand hand) {
    return released & 1 << (6 + (hand == frc::GenericHID::JoystickHand::kLeftHand));
}

bool BetterController::GetStickButtonPressed(JoystickHand hand) {
    return pressed & 1 << (8 + (hand == frc::GenericHID::JoystickHand::kLeftHand));
}
bool BetterController::GetStickButtonReleased(JoystickHand hand) {
    return released & 1 << (8 + (hand == frc::GenericHID::JoystickHand::kLeftHand));
}

void BetterController::updatePressed() {
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