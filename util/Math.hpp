//adds delta to value if positive.
//subtracts delta from value if negative.
double signedAdd(const double value, const double delta) {
    if (value < 0) {
        return value - delta;
    }
    else {
        return value + delta;
    }
}

//returns -1 if value is negative, 1 if value is positive.
double signiness(const double value) {
    if (value < 0) {
        return -1;
    }
    else {
        return 1;
    }
}

//sets value to the signiness of "sign".
double updateSign(double& const value, const double sign) {
    value*=signiness(sign);
}