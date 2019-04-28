#include <frc/XboxController.h>

//Xbox controller that uses seperate internal caching and clears pressed states for reliability

//issues with original xboxcontroller class:
//  functions that return doubles are ok, but all bool types are prone to keeping button states cached
//  all pressed() and released() functions only check the state from the last time the function was called

//fix:
//  now after calling updateBoth() each frame, the get functions will return fresh button states
//  doing clearCache() while the robot is in idle will ensure that the buttons remain cleared
class BetterController : public frc::XboxController {
public:
    BetterController(int n) : frc::XboxController(n) {}

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

    bool GetBumperPressed(frc::GenericHID::JoystickHand hand);
    bool GetBumperReleased(frc::GenericHID::JoystickHand hand);

    bool GetStickButtonPressed(JoystickHand hand);
    bool GetStickButtonReleased(JoystickHand hand);

    void updatePressed() {} //updates all pressed states internally
    void updateReleased() {} //updates all released states internally

    void updateBoth() { //run the 2 above functions at once
        updatePressed();
        updateReleased();
    }

    void clearCache() { //clears internal state of xbox object
        updateBoth();
        updateBoth(); //run twice so that the pressed/released state for buttons will always be false
    }

private:
    frc::XboxController* mXbox;

    /* flag states are as followed:
    2<<0 A button
    2<<1 B button
    2<<2 X button
    2<<3 Y button
    2<<4 Start button
    2<<5 Back button
    2<<6 Left bumper
    2<<7 Right bumper
    2<<8 Left stick down
    2<<9 Right stock down
    */
    int released;
    int pressed;
}