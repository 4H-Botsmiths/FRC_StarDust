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
class XboxController : public StarDustComponent, public frc::XboxController {
public:
    XboxController(int port);
    XboxController(int port, const double stick_deadzone);
    XboxController(int port, const double stick_deadzone, const double trigger_deadzone);
    XboxController(int port, const double stick_deadzone, const double trigger_deadzone, const std::map<int, std::function<void()>> binds);

    void __RobotInit__() override;
    void __RobotPeriodic__() override;
    void __AutonomousInit__() override;
    void __AutonomousPeriodic__() override;
    void __TeleopInit__() override;
    void __TeleopPeriodic__() override;
    void __TestPeriodic__() override;

    //custom event handlers
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
    void autorun() const;

    //Get() without needing to type out joystick hand, and auto deadzones
    double GetXLeft() const;
    double GetXLeftDeadzone() const;
    double GetXLeftDeadzone(const double range) const;

    double GetXRight() const;
    double GetXRightDeadzone() const;
    double GetXRightDeadzone(const double range) const;

    double GetYLeft() const;
    double GetYLeftDeadzone() const;
    double GetYLeftDeadzone(const double range) const;

    double GetYRight() const;
    double GetYRightDeadzone() const;
    double GetYRightDeadzone(const double range) const;

    double GetTriggerLeft() const;
    double GetTriggerLeftDeadzone() const;
    double GetTriggerLeftDeadzone(const double range) const;

    double GetTriggerRight() const;
    double GetTriggerRightDeadzone() const;
    double GetTriggerRightDeadzone(const double range) const;

    bool GetAButtonPressed() const;
    bool GetAButtonReleased() const;

    bool GetBButtonPressed() const;
    bool GetBButtonReleased() const;

    bool GetXButtonPressed() const;
    bool GetXButtonReleased() const;

    bool GetYButtonPressed() const;
    bool GetYButtonReleased() const;

    bool GetStartButtonPressed() const;
    bool GetStartButtonReleased() const;

    bool GetBackButtonPressed() const;
    bool GetBackButtonReleased() const;

    bool GetLeftBumper() const;
    bool GetRightBumper() const;
    bool GetLeftStickButton() const;
    bool GetRightStickButton() const;

    bool GetLeftBumperPressed() const;
    bool GetRightBumperPressed() const;

    bool GetLeftBumperReleased() const;
    bool GetRightBumperReleased() const;

    bool GetLeftStickButtonPressed() const;
    bool GetRightStickButtonPressed() const;

    bool GetLeftStickButtonReleased() const;
    bool GetRightStickButtonReleased() const;

    void updatePressed();
    void updateReleased();

    void updateBoth();

    void clearCache();

private:
    const double stickDeadzone=0;
    const double triggerDeadzone=0;

    const std::map<int, std::function<void()>> binds; //stores a map of binds

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
    unsigned long released;
    unsigned long pressed;

    double deadzone(const double value, const double range) const;
};