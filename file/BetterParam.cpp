#include "StarDust/file/BetterParam.hpp"

template<typename T>
bool BetterParam<T>::convert(std::string name, std::string data) {
    if (param==name) {
        parse(data, variable, fail);
        return true;
    }
    return false;
}

//special templates do a specific string-to-variable conversion for its type
template<>
void BetterParam<int>::parse(std::string data, int* input, int fail) {
    try { *input=std::stoi(data); }
    catch (...) { *input=fail; }
}

template<>
void BetterParam<double>::parse(std::string data, double* input, double fail) {
    try { *input=std::stod(data); }
    catch (...) { *input=fail; }
}

template<>
void BetterParam<float>::parse(std::string data, float* input, float fail) {
    try { *input=std::stof(data); }
    catch (...) { *input=fail; }
}
template<>
void BetterParam<bool>::parse(std::string data, bool* input, bool fail) {
    try {
        if (data=="true") { *input=true; }
        else { *input=false; }
    }
    catch (...) { *input=fail; }
}

template<>
void BetterParam<std::string>::parse(std::string data, std::string* input, std::string fail) {
    try { *input=data; }
    catch (...) { *input=fail; }
}