#include <fstream>

#include "StarDust/file/ConfigParser.hpp"

//only parse and update the config file when the robot boots and when autonomous starts
void ConfigParser::__RobotInit__() {
    autorun();
}
void ConfigParser::__AutonomousInit__() {
    autorun();
}
void ConfigParser::__RobotPeriodic__() {}
void ConfigParser::__AutonomousPeriodic__() {}
void ConfigParser::__TeleopInit__() {}
void ConfigParser::__TeleopPeriodic__() {}
void ConfigParser::__TestPeriodic__() {}

void ConfigParser::autorun() {
    //creates file stream
    std::ifstream stream(filename);
    std::string line="";

    if (stream.is_open()) {
        //loop through each line in the file
        while (std::getline(stream, line)) {
            //dont allow '\r' or '\n' at ELO
            if (line[line.length()-1]==13 || line[line.length()-1]==10) line.pop_back();

            unsigned int position=line.find("=");
            bool semi=line.find(";")==(line.length()-1); //true if a semi-colon is at the end of the line

            //must be at least one character on each side of the '='
            if (position>0 && (position<line.length()-1-semi)) {
                for (auto* param : parameters) {
                    if (param->convert(
                        line.substr(0, position), //left hand side
                        semi ?
                            line.substr(position+1, line.length()) : //right hand side (no semi-colon)
                            line.substr(position+1, line.length()-1) //right hand side (with semi-colon)
                    )) break; //if parameter name is valid, skip to next line in file
                }
            }
        }
        stream.close();
    }
}