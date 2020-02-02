#pragma once

#include <string>

//This class is NOT a StarDust component, it is a helper class for the ParserParam class
//Do NOT include this class unless you know what youre doing

class ParserParamBase {
public:
    ParserParamBase() {}

    virtual bool convert(std::string name, std::string data)=0;
};