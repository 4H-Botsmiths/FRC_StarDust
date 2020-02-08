#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "StarDust\core\StarDustComponent.hpp"
#include "StarDust\file\ParserParamBase.hpp"
#include "StarDust\file\ParserParam.hpp"

class ConfigParser : public StarDustComponent {
public:
    //takes in a vector of ParserParams to be parsed
    ConfigParser(std::vector<ParserParamBase*> params)
        : parameters(params) {}
    //same as above but overrides default filename with a diffent one
    ConfigParser(std::vector<ParserParamBase*> params, std::string name)
        : parameters(params), filename(name) {}

    void __RobotInit__() override;
    void __AutonomousInit__() override;

private:
    void autorun();

    std::vector<ParserParamBase*> parameters;
    std::string filename="/home/lvuser/config.dat";
};