#include <fstream>

#include "StarDust/file/BetterParser.hpp"

//Only parse and update the config file when the robot boots and when autonomous starts
void BetterParser::__RobotInit__() { autorun(); }
void BetterParser::__RobotPeriodic__() {}
void BetterParser::__AutonomousInit__() { autorun(); }
void BetterParser::__AutonomousPeriodic__() {}
void BetterParser::__TeleopInit__() {}
void BetterParser::__TeleopPeriodic__() {}
void BetterParser::__TestPeriodic__() {}

void BetterParser::autorun() {
    std::ifstream stream(filename); //creates file stream
    std::string line="";

    if (stream.is_open()) {
        while (std::getline(stream, line)) { //loop through each line in the file
            int pos=line.find("="); //split each line on the first = sign
            bool semi=line.find(";")==(line.length()-1); //true if a semi-colon is at the end of the line

            if (pos>0&&(pos<line.length()-1-semi)) {  //must be at least one character on each side of the =
                for (auto* param : parameters) { //loop throught and check try to parse each parameter
                    if (param->convert(
                        line.substr(0, pos), //left hand side
                        semi ?
                            line.substr(pos+1, line.length()) : //right hand side (no semi-colon)
                            line.substr(pos+1, line.length()-1) //right hand side (with semi-colon)
                    )) break; //if parameter name is valid, skip to next file in line
                }
            }
        }
        stream.close();
    }
}