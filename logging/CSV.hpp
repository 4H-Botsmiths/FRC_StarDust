#pragma once

#include <fstream>
#include <string>

#include "StarDust/core/StarDustComponent.hpp"

#define FILE_PATH "home/lvuser/data.csv"

class CSVLogger : public StarDustComponent {
public:
    CSVLogger();
    CSVLogger(std::string header);
    CSVLogger(std::string filename, std::string header);

    template<typename T>
    void push(T data) {
        file << data << "\n";
    }

    template<typename T, typename... Ts>
    void push(T data, Ts... args) {
        file << data << ",";
        push(args...);
    }

    void start();
    void stop();

private:
    std::string filename;
    std::string header;

    std::ofstream file;
};