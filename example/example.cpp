#include "StarDust/example/example.hpp"

//in each of the below functions, the update function is called
void Example::__RobotInit__() {
	update();
}
void Example::__RobotPeriodic__() {
	update();
}
void Example::__AutonomousInit__() {
	update();
}
void Example::__AutonomousPeriodic__() {
	update();
}
void Example::__TeleopInit__() {
	update();
}
void Example::__TeleopPeriodic__() {
	update();
}
void Example::__TestPeriodic__() {
	update();
}

void Example::update() {
	//just for this example, a counter is incremented each time update is called
	somevalue++;
}