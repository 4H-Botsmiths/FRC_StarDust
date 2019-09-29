#pragma once

#include <string>

//This class is NOT a stardust component, it is a helper class for the betterparam class
//Do NOT include this class unless you know what youre doing
class BetterParamBase {
public:
    BetterParamBase() {}

    virtual bool convert(std::string name, std::string data)=0;
};