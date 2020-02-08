//adds delta to value if positive.
//subtracts delta from value if negative.
double signedAdd(double value, double delta) {
    if (value<0) {
        return value - delta;
    }
    else {
        return value + delta;
    }
}

//returns -1 if value is negative, 1 if value is positive.
double signiness(double value) {
    if (value<0) {
        return -1;
    }
    else {
        return 1;
    }
}

//sets value to the signiness of "sign".
double updateSign(double& value, double sign) {
    value*=signiness(sign);
}