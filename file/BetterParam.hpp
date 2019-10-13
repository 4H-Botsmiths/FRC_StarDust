#pragma once

#include <sstream>
#include <vector>
#include <string>

#include "StarDust/file/BetterParamBase.hpp"

//_parse() is the basic parser, it does not directly parse the data
template<typename T> extern T _parse(std::string* data, T* fail);

//wrapper to check if a passed variable is a vector
template<class T> struct __is_vector { static const bool value=false; };
template<class T> struct __is_vector<std::vector<T>> { static const bool value=true; };

template<class T>
class BetterParam : public BetterParamBase {
public:
    //takes in name for parameter/variable in config file, and pointer to variable to update
    BetterParam(std::string name, T* var) : param(name), variable(var), fail(T {}) {}

    //same as above but takes in a default value to use if the conversion fails
    BetterParam(std::string name, T* var, T iffail) : param(name), variable(var), fail(iffail) {}

    //special templates do a specific string-to-variable conversion for its type
    //this is what actually parses and sets the input
    inline void parse(std::string data, T* input, T fail) {
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