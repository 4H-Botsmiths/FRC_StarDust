#include "SpeedController.h"

//wrapper class for inverting motors upon construction
class BetterMotor {
public:
    BetterMotor(frc::SpeedController* m) : mMotor(m) {};

    BetterMotor(frc::SpeedController* m, bool invert) : mMotor(m) {
        mMotor->SetInverted(invert);
    }

private:
    frc::SpeedController* mMotor;
}