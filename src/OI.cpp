#include "OI.h"
#include "Robotmap.h"
//#include "/Subsystems/BallConveyor.h"
//#include "/Subsystems/BallShooter.h"
//#include "/Subsystems/DriveTrain.h"

OI::OI() {
	// Process operator interface input here. Okay
	
	rightArm = new KinectStick(1);
	leftArm = new KinectStick(2);
//	lowerBT = new KinectStick(5);
	lStick = new Joystick(1); //Create a Joystick Note: It's the left one
	rStick = new Joystick(2); //Create a Joystick Note: It's the right one
	mStick = new Joystick(3); //Create a Joystick Note: It's the one the driver isn't using
	sd = SmartDashboard::GetInstance(); //Create the Dashboard. Note: It's the one you are looking at.
	db = DriverStation::GetInstance();
}

bool OI::lJoyButton(int buttonnumber) {
	return lStick->GetRawButton(buttonnumber);
}

bool OI::rJoyButton(int buttonnumber) {
	return rStick->GetRawButton(buttonnumber);
}

bool OI::mJoyButton(int buttonnumber) {
	return mStick->GetRawButton(buttonnumber);
}
