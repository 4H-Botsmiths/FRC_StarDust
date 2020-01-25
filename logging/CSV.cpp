#include "StarDust/logging/CSV.hpp"

CSVLogger::CSVLogger() {
    CSVLogger(filename, header);
}

CSVLogger::CSVLogger(std::string header) {
    CSVLogger(filename, header);
}

CSVLogger::CSVLogger(std::string filename, std::string header)
    : filename(filename), header(header)
{
    start();
}

void CSVLogger::start() {
    file.open(filename);

    if (!header.empty()) {
        push(header);
    }
}

void CSVLogger::stop() {
    file.close();
}