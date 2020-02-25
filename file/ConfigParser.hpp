#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "StarDust\core\StarDustComponent.hpp"
#include "StarDust\file\ParserParamBase.hpp"
#include "StarDust\file\ParserParam.hpp"

#define CONFIG_FILE_PATH "/home/lvuser/config.dat"

class ConfigParser : public StarDustComponent {
public:
    //takes in a vector of ParserParams to be parsed
    ConfigParser(std::vector<ParserParamBase*> parameters);

    //same as above but overrides default filename with a diffent one
    ConfigParser(std::vector<ParserParamBase*> parameters, std::string filename);

    void __RobotInit__() override;
    void __AutonomousInit__() override;

private:
    void autorun();

    std::vector<ParserParamBase*> parameters;
    std::string filename;
};