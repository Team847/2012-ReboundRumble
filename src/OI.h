#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:

public:
	OI();
	void SD(void);
	KinectStick *leftArm; // Your left arm.
	KinectStick *rightArm; // Your right arm.
	KinectStick *lowerBT; // ou left leg. Note: It drops the bridge tipper
	bool lJoyButton(int);
	bool rJoyButton(int);
	bool mJoyButton(int); 
	Joystick *lStick; //Drive Joystick. Note: It's the left one
	Joystick *rStick; //Drive Joystick. Note: It's the right one
	Joystick *mStick; //Joystick. Note: It's the silver one
	SmartDashboard *sd; //This is the dashboard. Note: It's what you look at on the driver station
	DriverStation *db; //This is the DriverStation. Note: 
//	Gyro *SDInit_turnGyro;
//	Gyro *SDInit_tipGyro;
//	AnalogChannel *SDInit_groundUS;
//	Victor *SDInit_smL;
//	Victor *SDInit_smR;
	
};
#endif
