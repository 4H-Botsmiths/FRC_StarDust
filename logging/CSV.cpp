#include "StarDust/logging/CSV.hpp"

CSVLogger::CSVLogger() :
    CSVLogger("")
    {}

CSVLogger::CSVLogger(const std::string header) :
    CSVLogger(FILE_PATH, header)
    {}

CSVLogger::CSVLogger(const std::string filename, const std::string header) :
    filename(filename),
    header(header)
{
    start();
}

void CSVLogger::start() {
    stop();

    file.open(filename);

    if (!header.empty()) {
        push(header);
    }
}

void CSVLogger::stop() {
    file.close();
}