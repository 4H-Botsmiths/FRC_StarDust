#include <frc/AnalogInput.h>

//wrapper class for using an infa-red sensor
class IR {
public:
    IR(int port) {
        sensor=new frc::AnalogInput(port);
    }

    double getV() { return sensor->GetVoltage(); }
    double getVV() { return sensor->GetValue(); }
    double getAV() { return sensor->GetAverageVoltage(); }
    double getAVV() { return sensor->GetAverageValue(); }

private:
    frc::AnalogInput* sensor; //cannot use "ir" here
};