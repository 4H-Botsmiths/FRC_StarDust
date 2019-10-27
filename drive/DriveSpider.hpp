#pragma once

#include <frc/drive/MecanumDrive.h>
#include <frc/SpeedController.h>

#include "StarDust/util/BetterTimer.hpp"
#include "DriveBase.hpp"

//DriveSpider (spider drive) is an expiremental drivetrain which uses both mecanum and normal wheels
class DriveSpider: public DriveMecanum, public DriveBasic {
public:
				//creates spider drive with just 4 speed controllers, and 1x multipliers on all axis
    DriveSpider(frc::SpeedController* m0, frc::SpeedController* m1, frc::SpeedController* m2, frc::SpeedController* m3, BetterDoubleSolenoid* solenoid) :
								DriveSpider(m0, m1, m2, m3, 1, 1, 1),
								shifter(solenoid)
								{}

				//creates spider drive with the 4 speed controllers, but uses custom multipliers
    DriveSpider(frc::SpeedController* m0, frc::SpeedController* m1, frc::SpeedController* m2, frc::SpeedController* m3, BetterDoubleSolenoid* solenoid, float x, float y, float r) :
								DriveMecanum( //creates mecanum drive train
												*m0,
												*m3,
												*m1,
												*m2,
												x,
												y,
												r
								),
								DriveBasic( //creates normal drive train
            new frc::SpeedControllerGroup(*m0, *m3),
            new frc::SpeedControllerGroup(*m1, *m2),
												y,
												r
								),
								shifter(solenoid)
								{}

    //required to be implemented by the drivebase to be considered a stardust component
    void __RobotInit__() {}
    void __RobotPeriodic__() {}
    void __AutonomousInit__() {}
    void __AutonomousPeriodic__() {}
    void __TeleopInit__() {}
    void __TeleopPeriodic__() {}
    void __TestPeriodic__() {}

    void drive(float y) {
								if (usingMec) {
												//mecanum->DriveCartesian(y*gety(), 0, 0);
												DriveMecanum::drive(y);
								}
								else {
												DriveBasic::drive(y);
								}
    }

    void drive(float y, float r) {
        if (usingMec) {
												DriveMecanum::drive(y, r);
												//mecanum->DriveCartesian(y*gety(), 0, r*getr());
								}
								else {
												DriveBasic::drive(y, r);
								}
    }

    void drive(float x, float y, float r) {
								if (usingMec) {
 				       //mecanum->DriveCartesian(-x*getx(), y*gety(), r*getr());
												DriveMecanum::drive(x, y ,r);
								}
								else {
												DriveBasic::drive(0, y, r);
								}
    }

    void drive(float x, float y, float r, float t) {
        BetterTimer{true, [=]{
												//calls drive from current class to make sure useMec is respected
            DriveSpider::drive(x, y, r);
        }, t};
    }

    void drive(BetterController* x) {
        DriveSpider::drive(
            getx()*x->GetXLeftDeadzone(),
            gety()*x->GetYLeftDeadzone(),
            getr()*x->GetXRightDeadzone()
        );
    }

				void useMecanum() { //go into mecanum mode
								usingMec=true;
								solenoid->Retract();
				}

				void useNormal() { //go into normal mode
								usingMec=false;
								solenoid->Extend();
				}

				void invert() { //invert current mode state
								if (usingMec) {
												useNormal();
								}
								else {
												useMec();
								}
				}

private:
				//true if mecs are in use, false if normal wheels are in use
				bool usingMec=true;

				//double solenoid to use when shifting between the 2 modes
				BetterDoubleSolenoid* shifter;
};