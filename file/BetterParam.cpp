#include "StarDust/file/BetterParam.hpp"

//templated code for primative parser
template<typename T>
T _parse(std::string* data, T* fail) {
    return *fail;
}
template<>
int _parse<int>(std::string* data, int* fail) {
    try { return std::stoi(*data); }
    catch (...) { return *fail; }
}
template<>
double _parse<double>(std::string* data, double* fail) {
    try { return std::stod(*data); }
    catch (...) { return *fail; }
}
template<>
float _parse<float>(std::string* data, float* fail) {
    try { return std::stof(*data); }
    catch (...) { return *fail; }
}
template<>
bool _parse<bool>(std::string* data, bool* fail) {
    try {
        if (*data=="true") { return true; }
        else { return false; }
    }
    catch (...) { return *fail; }
}
template<>
std::string _parse<std::string>(std::string* data, std::string* fail) {
    try { return *data; }
    catch (...) { return *fail; }
}

//templated code for BetterParam::parse parser
template<>
void BetterParam<int>::parse(std::string data, int* input, int fail) {
    *input=_parse<int>(&data, &fail);
}
template<>
void BetterParam<double>::parse(std::string data, double* input, double fail) {
    *input=_parse<double>(&data, &fail);
}
template<>
void BetterParam<float>::parse(std::string data, float* input, float fail) {
    *input=_parse<float>(&data, &fail);
}
template<>
void BetterParam<bool>::parse(std::string data, bool* input, bool fail) {
    *input=_parse<bool>(&data, &fail);
}
template<>
void BetterParam<std::string>::parse(std::string data, std::string* input, std::string fail) {
    *input=_parse<std::string>(&data, &fail);
}