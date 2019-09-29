#pragma once

#include <string>

#include "StarDust/file/BetterParamBase.hpp"

template<class T>
class BetterParam : public BetterParamBase {
public:
    //takes in name for parameter/variable in config file, and pointer to variable to update
    BetterParam(std::string name, T* var) : param(name), variable(var), fail(T {}) {}

    //same as above but takes in a default value to use if the conversion fails
    BetterParam(std::string name, T* var, T iffail) : param(name), variable(var), fail(iffail) {}

    //generic parse function, overriden for certain types
    void parse(std::string data, T* input, T fail);

    //automatically checks and parses, returns true if matched and should move to next param (else keep checking)
    bool convert(std::string name, std::string data) {
        if (param==name) {
            parse(data, variable, fail);
            return true;
        }
        return false;
    }

private:
    std::string param; //name of variable as a string in config file
    T* variable; //pointer to variable to update
    T fail; //used if try catch fails
};