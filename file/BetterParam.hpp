#pragma once

#include <sstream>
#include <vector>
#include <string>

#include "StarDust/file/BetterParamBase.hpp"

//_parse() is the generic parser, it does not directly parse the data
template<typename T> extern T _parse(std::string* data, T* fail);

//wrapper to check if a passed variable is a vector
template<class T> struct __is_vector { static const bool value=false; };
template<class T> struct __is_vector<std::vector<T>> { static const bool value=true; };

template<class T>
class BetterParam : public BetterParamBase {
public:
    //takes in name for parameter/variable in config file, and pointer to variable to update
    BetterParam(std::string name, T* var)
        : param(name), variable(var), fail(T {}) {}

    //same as above but takes in a default value to use if the conversion fails
    BetterParam(std::string name, T* var, T ifFail)
        : param(name), variable(var), fail(ifFail) {}

    //specialized templates do a specific string-to-variable conversion for its type
    //this is what actually parses and sets the input
    inline void parse(std::string data, T* input, T fail) {
        //code to parse when vector is passed
        if (__is_vector<T>::value) {
            input->clear();

            using TT=typename T::value_type;

            //make sure string has [ and ] on the ends
            if (data[0]=='[' && data[data.length()-1]==']') {
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
                            new TT {} //default constructor for type inside vector
                        )
                    );
                }
            }
            //missing bracket, return default
            else {
                *input=fail;
            }
        }
        //run if non-vector type is passed
        else {
            parse(data,input, fail);
        }
    }

    //return true if variable was found and parsed
    //return false if variable was not found
    bool convert(std::string name, std::string data) {
        if (param==name) {
            parse(data, variable, fail);
            return true;
        }
        return false;
    }

private:
    //name of variable from config file
    std::string param;

    //pointer to actual variable
    T* variable;

    //variable to use when data cannot be parsed
    T fail;
};