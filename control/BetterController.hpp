#pragma once

#include <frc/XboxController.h>
#include <map>

#include "StarDust/core/StarDustComponent.hpp"

//Xbox controller that uses seperate internal caching and clears pressed states for reliability

//issues with original xboxcontroller class:
//  functions that return doubles are ok, but all bool types are prone to keeping button states cached
//  all pressed() and released() functions only check the state from the last time the function was called

//fix:
//  now after calling updateBoth() each frame, the get functions will return fresh button states
//  doing clearCache() while the robot is in idle will ensure that the buttons remain cleared
class BetterController : public StarDustComponent, public frc::XboxController {
public:
    BetterController(int n) : frc::XboxController(n) {}
    BetterController(int n, double s) : frc::XboxController(n), stickDeadzone(s), triggerDeadzone(s) {}
    BetterController(int n, double s, double t) : frc::XboxController(n), stickDeadzone(s), triggerDeadzone(t) {}
    BetterController(int n, double s, double t, std::map<int, std::function<void()>> b) : frc::XboxController(n), stickDeadzone(s), triggerDeadzone(t), binds(b) {}

    void __RobotInit__() override;
    void __RobotPeriodic__() override;
    void __AutonomousInit__() override;
    void __AutonomousPeriodic__() override;
    void __TeleopInit__() override;
    void __TeleopPeriodic__() override;
    void __TestPeriodic__() override;

	//provides syntax similar to JS .onclick() e.g; on::GetAbuttonPressed
	enum on {
		AButton,
		AButtonPressed,
		AButtonReleased,
		BButton,
		BButtonPressed,
		BButtonReleased,
		XButton,
		XButtonPressed,
		XButtonReleased,
		YButton,
		YButtonPressed,
		YButtonReleased,
		StartButton,
		StartButtonPressed,
		StartButtonReleased,
		BackButton,
		BackButtonPressed,
		BackButtonReleased,
        LeftBumper,
        LeftBumperPressed,
        RightBumperPressed,
        LeftBumperReleased,
        RightBumperReleased,
        LeftStickButtonPressed,
        RightStickButtonPressed,
        LeftStickButtonReleased,
        RightStickButtonReleased
	};

	//take in a map of {int, function} and check of the current cached values match any functions
	void autorun();

    //Get() without needing to type out joystick hand, and auto deadzones
    double GetXLeft();
    double GetXLeftDeadzone();
    double GetXLeftDeadzone(double r);

    double GetXRight();
    double GetXRightDeadzone();
    double GetXRightDeadzone(double r);

    double GetYLeft();
    double GetYLeftDeadzone();
    double GetYLeftDeadzone(double r);

    double GetYRight();
    double GetYRightDeadzone();
    double GetYRightDeadzone(double r);

    double GetTriggerLeft();
    double GetTriggerLeftDeadzone();
    double GetTriggerLeftDeadzone(double r);

    double GetTriggerRight();
    double GetTriggerRightDeadzone();
    double GetTriggerRightDeadzone(double r);

    bool GetAButtonPressed();
    bool GetAButtonReleased();

    bool GetBButtonPressed();
    bool GetBButtonReleased();

    bool GetXButtonPressed();
    bool GetXButtonReleased();

    bool GetYButtonPressed();
    bool GetYButtonReleased();

    bool GetStartButtonPressed();
    bool GetStartButtonReleased();

    bool GetBackButtonPressed();
    bool GetBackButtonReleased();

    bool GetLeftBumper();
    bool GetRightBumper();
    bool GetLeftStickButton();
    bool GetRightStickButton();

    bool GetLeftBumperPressed();
    bool GetRightBumperPressed();

    bool GetLeftBumperReleased();
    bool GetRightBumperReleased();

    bool GetLeftStickButtonPressed();
    bool GetRightStickButtonPressed();

    bool GetLeftStickButtonReleased();
    bool GetRightStickButtonReleased();

    void updatePressed(); //updates all pressed states internally
    void updateReleased();  //updates all released states internally

    void updateBoth() { //run the 2 above functions at once
        updatePressed();
        updateReleased();
    }

    void clearCache() { //clears internal state of xbox object
        updateBoth();
        updateBoth(); //run twice so that the pressed/released state for buttons will always be false
    }

private:
	std::map<int, std::function<void()>> binds; //stores a map of binds

    /* flag states are as followed:
    1<<0 A button
    1<<1 B button
    1<<2 X button
    1<<3 Y button
    1<<4 Start button
    1<<5 Back button
    1<<6 Left bumper
    1<<7 Right bumper
    1<<8 Left stick down
    1<<9 Right stock down
    */
    int released;
    int pressed;

    double stickDeadzone=0;
    double triggerDeadzone=0;

    double deadzone(double v, double r);
};