#pragma once

#include <fstream>
#include <string>

#include "StarDust/core/StarDustComponent.hpp"

#define FILE_PATH "/home/lvuser/data.csv"

class CSVLogger : public StarDustComponent {
public:
    CSVLogger();
    CSVLogger(const std::string header);
    CSVLogger(const std::string filename, const std::string header);

    template<typename T>
    void push(const T data) {
        file << data << "\n";
    }

    template<typename T, typename... Ts>
    void push(const T data, const Ts... args) {
        file << data << ",";
        push(args...);
    }

    void start();
    void stop();

private:
    const std::string filename;
    const std::string header;

    std::ofstream file;
};