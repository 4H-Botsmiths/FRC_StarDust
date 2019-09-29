#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "StarDust\core\StarDustComponent.hpp"
#include "StarDust\file\BetterParamBase.hpp"
#include "StarDust\file\BetterParam.hpp"

class BetterParser : public StarDustComponent {
public:
    //takes in a vector of BetterParams to be parsed
    BetterParser(std::vector<BetterParamBase*> params) : parameters(params) {}
    //same as above but overrides default filename with a diffent one
    BetterParser(std::vector<BetterParamBase*> params, std::string name) : parameters(params), filename(name) {}

    void __RobotInit__() override;
    void __RobotPeriodic__() override;
    void __AutonomousInit__() override;
    void __AutonomousPeriodic__() override;
    void __TeleopInit__() override;
    void __TeleopPeriodic__() override;
    void __TestPeriodic__() override;

private:
    void autorun();

    std::string filename="/home/lvuser/config.dat";
    std::vector<BetterParamBase*> parameters;
};