#include "Stardust/sensor/motion/BetterGyro.h"

//given a degree offset, calculate what angle is fastest to turn to
double BetterGyro::FastestTo(double deg) {
    double g=BetterGyro::GetAngleMod()-deg;

    if (g<=180&&g>=-180) {
        return g; //if within half turn just return
    }
    else if (g>180) {
        return g-360; //if over 180 turn convert to negative
    }
    else {
        return 360+g; //if under -180 convert to positive
    }
}

double BetterGyro::FastestToZero() {
    return FastestTo(0.0);
}