#include <fstream>
#include <string>

#include "StarDust/core/StarDustComponent.hpp"

class CSVLogger : public StarDustComponent {
public:
    CSVLogger();
    CSVLogger(std::string header);
    CSVLogger(std::string filename, std::string header);

    void __RobotInit__() {}
	void __RobotPeriodic__() {}
	void __AutonomousInit__() {}
	void __AutonomousPeriodic__() {}
	void __TeleopInit__() {}
	void __TeleopPeriodic__() {}
	void __TestPeriodic__() {}
	void __DisabledInit__() {}

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
    std::string filename="/home/lvuser/data.csv";
    std::string header="";

    std::ofstream file;
};