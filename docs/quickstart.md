# StarDust Quickstart

This page will show how to start using StarDust inside your robot code.

We are assuming you already have StarDust installed and are in a fresh project file.

If not, please refer to the `README.md` file.

## Boilerplate

StarDust can do lots of things, but some initial code configuring is required to work.

In your `Robot.h` file:

```c++
//add these includes
#include "StarDust/core/StarDustComponent.hpp"
#include "StarDust/core/StarDustRobot.hpp"

class Robot : public frc::TimedRobot { //generated when creating project

// ...

private:
	
	//add a StarDustRobot object
	StarDustRobot NAME {{
		// ... for later
	}};
}
```

In your `Robot.cpp` File:

```c++
//For each of the functions of the Robot class, run the same function on the NAME class at the TOP of the function
//What this does is invokes each of the __FunctionName__() functions on each of the component passed into the StarDustRobot
//NAME.FunctionName() should be called at ONLY ONCE, and at the VERY TOP of the function

void Robot::RobotInit() {
	NAME.RobotInit();
}

void Robot::RobotPeriodic() {
	NAME.RobotPeriodic();
}

void Robot::AutonomousInit() {
	NAME.AutonomousInit();
}

void Robot::AutonomousPeriodic() {
	NAME.AutonomousPeriodic();
}

void Robot::TeleopInit() {
	NAME.TeleopInit();
}

void Robot::TeleopPeriodic() {
	NAME.TeleopPeriodic();
}

void Robot::TestPeriodic() {
	NAME.TestPeriodic();
}
```

Now when a component is added to the `StarDustRobot` object in the `Robot.h` file, code for the component is automatically ran!

Code can be added below the `NAME` call, as per usual.

## Adding Components

To add a component, in your `Robot.h` file, simply declare it and pass it into the `StarDustRobot` object:

```cpp
//setup the left and right controllers on USB port 0 and 1
BetterController left_controller { 0 };
BetterController right_controller { 1 };

//setup the arm motor on PWM port 0
BetterMotor arm { 0 };

//pass in all the components 
StarDustRobot NAME {{
	&left_controller,
	&right_controller,
	&arm
}};
```

Only `StarDustComponent` class objects can be added into the `StarDustRobot` object.

`StarDustComponents` Usually are prefixed with `Better`, although this is not always the case (ie, `DriveMecanum`)

On top of this, components must be passed via reference, that is using the `&` symbol
