#include "StarDust/core/StarDustComponent.hpp"

class Example : public StarDustComponent {
public:
	//default constructor, here you could setup some parameters and such
	Example() {}

	//these functions will be automatically ran when StarDustRobot calls "RobotInit", "TeleopPeriodic", etc.
    void __RobotInit__() override;
    void __RobotPeriodic__() override;
    void __AutonomousInit__() override;
    void __AutonomousPeriodic__() override;
    void __TeleopInit__() override;
    void __TeleopPeriodic__() override;
    void __TestPeriodic__() override;

	//allows user to easily update the class manually if needed
	void update();

private:
	//put the values you want to update here
	int somevalue=-1;
};