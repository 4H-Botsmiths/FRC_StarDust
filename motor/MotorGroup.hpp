#include <vector>

#include "StarDust/motor/Motor.hpp"

class MotorGroup {
public:
    MotorGroup(const std::vector<Motor*> motors) :
        motors(motors)
        {}

    void Set(const double speed) {
        for (const auto& motor : motors) {
            motor->Set(speed);
        }
    }

    void Set(const double speed, const double time) {
        Timer {
            true,
            [=]{ Set(speed); },
            time
        };
    }

private:
    const std::vector<Motor*> motors;
};