#include "StarDust/control/BetterController.hpp"
#include <stdlib.h>
#include <math.h>

void BetterController::__RobotPeriodic__() {
    //Clear button cache while waiting for autonomous to start
    clearCache();
}
//for all the other overriden functions, update the controller buttons, then run the autorun function
void BetterController::__AutonomousPeriodic__() {
    updateBoth();
	autorun();
}
void BetterController::__TeleopPeriodic__() {
    updateBoth();
	autorun();
}
void BetterController::__TestPeriodic__() {
    updateBoth();
	autorun();
}
void BetterController::__RobotInit__() {
	updateBoth();
	autorun();
}
void BetterController::__AutonomousInit__() {
	updateBoth();
	autorun();
}
void BetterController::__TeleopInit__() {
	updateBoth();
	autorun();
}

//take in a map of {int, function} and check of the current cached values match any functions
void BetterController::autorun() {
	if (!binds.empty()) {
		for (const auto& i : binds) {
			//check if passed enum value matches a on:: call, if so check function output and run lambda if true
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
		}
	}
}

double BetterController::GetXLeft() { return XboxController::GetX(frc::GenericHID::JoystickHand::kLeftHand); }
double BetterController::GetXLeftDeadzone() { deadzone(GetXLeft(), stickDeadzone); }
double BetterController::GetXRight() { return XboxController::GetX(frc::GenericHID::JoystickHand::kRightHand); }
double BetterController::GetXRightDeadzone() { deadzone(GetXRight(), stickDeadzone); }

double BetterController::GetYLeft() { return XboxController::GetY(frc::GenericHID::JoystickHand::kLeftHand); }
double BetterController::GetYLeftDeadzone() { deadzone(GetYLeft(), stickDeadzone); }
double BetterController::GetYRight() { return XboxController::GetY(frc::GenericHID::JoystickHand::kRightHand); }
double BetterController::GetYRightDeadzone() { deadzone(GetYRight(), stickDeadzone); }

double BetterController::GetTriggerLeft() { return XboxController::GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand); }
double BetterController::GetTriggerLeftDeadzone() { deadzone(GetTriggerLeft(), triggerDeadzone); }
double BetterController::GetTriggerRight() { return XboxController::GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand); }
double BetterController::GetTriggerRightDeadzone() { deadzone(GetTriggerRight(), triggerDeadzone); }

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
        XboxController::GetBumperPressed(frc::GenericHID::JoystickHand::kLeftHand)<<6 |
        XboxController::GetBumperPressed(frc::GenericHID::JoystickHand::kRightHand)<<7 |
        XboxController::GetStickButtonPressed(frc::GenericHID::JoystickHand::kLeftHand)<<8 |
        XboxController::GetStickButtonPressed(frc::GenericHID::JoystickHand::kRightHand)<<9
    );
}

void BetterController::updateReleased() {
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

double BetterController::deadzone(double v, double r) {
	double old=v;
	v=abs(v);
	return copysign(v<r?0:(v-r)/(1-r), old);
}