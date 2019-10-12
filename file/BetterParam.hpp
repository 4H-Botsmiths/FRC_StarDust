#pragma once

#include <sstream>
#include <vector>
#include <string>

#include "StarDust/file/BetterParamBase.hpp"

//_parse() is the basic parser, it does not directly parse the data
template<typename T>
inline T _parse(std::string* data, T* fail) { return *fail; }

template<>
inline int _parse<int>(std::string* data, int* fail) {
    try { return std::stoi(*data); }
    catch (...) { return *fail; }
}

template<>
inline double _parse<double>(std::string* data, double* fail) {
    try { return std::stod(*data); }
    catch (...) { return *fail; }
}

template<>
inline float _parse<float>(std::string* data, float* fail) {
    try { return std::stof(*data); }
    catch (...) { return *fail; }
}
template<>
inline bool _parse<bool>(std::string* data, bool* fail) {
    try {
        if (*data=="true") { return true; }
        else { return false; }
    }
    catch (...) { return *fail; }
}

template<>
inline std::string _parse<std::string>(std::string* data, std::string* fail) {
    try { return *data; }
    catch (...) { return *fail; }
}

//wrapper to check if a passed variable is a vector
template<class T>
struct __is_vector { static const bool value=false; };

template<class T>
struct __is_vector<std::vector<T>> { static const bool value=true; };

template<class T>
class BetterParam : public BetterParamBase {
public:
    //takes in name for parameter/variable in config file, and pointer to variable to update
    BetterParam(std::string name, T* var) : param(name), variable(var), fail(T {}) {}

    //same as above but takes in a default value to use if the conversion fails
    BetterParam(std::string name, T* var, T iffail) : param(name), variable(var), fail(iffail) {}

    //callable parser, interperets and parses type automatically.
    //void parse(std::string data, T* input, T fail);

    //special templates do a specific string-to-variable conversion for its type
    //this is what actually parses and sets the input
    void parse(std::string data, T* input, T fail) {
        //code to parse when vector is passed
        if (__is_vector<T>::value) {
            //make it so original vector gets overriden
            input->clear();

            using TT=typename T::value_type;

            //make sure string has [ and ] on the ends
            if (data[0]=='['&&data[data.length()-1]==']') {
                //get rid of brackets and create string stream
                std::stringstream ss(
                    data.substr(1, data.length()-2)
                );
                std::string line;

                //loop through and split on each "," character
                while (std::getline(ss, line, ',')) {
                    //parse the data using the type inside the vector
                    input->emplace_back(
                        _parse<TT>(
                            &line,
                            new TT {} //default ctor for type inside vector
                        )
                    );
                }
            }
            //[ or ] was missing, return default
            else {
                *input=fail;
            }
        }
        //code to run if normal variable is passed
        else {
            parse(data,input, fail);
        }
    }
    template<typename U>
    void parse(std::string data, int* input, int fail) {
        *input=_parse<int>(&data, &fail);
    }
    template<typename U>
    void parse(std::string data, double* input, double fail) {
        *input=_parse<double>(&data, &fail);
    }
    template<typename U>
    void parse(std::string data, float* input, float fail) {
        *input=_parse<float>(&data, &fail);
    }
    template<typename U>
    void parse(std::string data, bool* input, bool fail) {
        *input=_parse<bool>(&data, &fail);
    }
    template<typename U>
    void parse(std::string data, std::string* input, std::string fail) {
        *input=_parse<std::string>(&data, &fail);
    }

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