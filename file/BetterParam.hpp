#pragma once

#include <string>

#include "StarDust/file/BetterParamBase.hpp"

//do NOT use __parse__ functions, these should only be used by the BetterParam class
template<typename T>
void __parse__(std::string data, T* input, T fail) {} //normal template does nothing

//special templates do a specific string-to-variable conversion for its type
template<>
void __parse__<int>(std::string data, int* input, int fail) {
    try { *input=std::stoi(data); }
    catch (...) { *input=fail; }
}

template<>
void __parse__<double>(std::string data, double* input, double fail) {
    try { *input=std::stod(data); }
    catch (...) { *input=fail; }
}

template<>
void __parse__<float>(std::string data, float* input, float fail) {
    try { *input=std::stof(data); }
    catch (...) { *input=fail; }
}
template<>
void __parse__<bool>(std::string data, bool* input, bool fail) {
    try {
        if (data=="true") { *input=true; }
        else { *input=false; }
    }
    catch (...) { *input=fail; }
}

template<>
void __parse__<std::string>(std::string data, std::string* input, std::string fail) {
    try { *input=data; }
    catch (...) { *input=fail; }
}

template<class T>
class BetterParam : BetterParamBase {
public:
    //takes in name for parameter in config file, and pointer to variable to update
    BetterParam(std::string name, T* var) : param(name), variable(var), fail(T {}) {}

    //same as above but takes in a default value to use if try conversion fails
    BetterParam(std::string name, T* var, T iffail) : param(name), variable(var), fail(iffail) {}

    //automatically checks and parses, returns true if matched and should move to next param (else keep checking)
    bool convert(std::string name, std::string data) {
        if (param==name) {
            __parse__<T>(data, variable, fail);
            return true;
        }
        return false;
    }

private:
    std::string param; //name of variable as a string in config file
    T* variable; //pointer to variable to update
    T fail; //used if try catch fails
};