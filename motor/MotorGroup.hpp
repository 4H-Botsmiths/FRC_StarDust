#include <vector>

#include "StarDust/motor/Motor.hpp"

class MotorGroup {
public:
    MotorGroup(std::vector<Motor*> motors) :
        motors(motors)
        {}

    void Set(double speed) {
        for (auto& motor : motors) {
            motor->Set(speed);
        }
    }

    void Set(double speed, double time) {
        Timer {
            true,
            [=]{ Set(speed); },
            time
        };
    }

private:
    std::vector<Motor*> motors;
};