#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "WPILib.h"
#include "../OI.h"
#include "BridgeTipper.h"

/**
 *
 *
 * @author Tom
 */
class DriveTrain{
private:
	RobotDrive *phredRobot;
	OI *driveOI;
	Gyro *tipGyro;
	Encoder *lEncoder;
	Encoder *rEncoder;
	Gyro *turnGyro;	
	AnalogChannel *groundUS;
	BridgeTipper *bT;
	Relay *bridgeLight;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	//ok
	float angle;
	float motorOne;
	float motorTwo;
	float gyroStable;
	float angleDif;
	float floorREF;
	
	float correctionFactor;
public:
	DriveTrain();
	void doTankDrive(void);
	void doRampClimb(void);
	void doDriveForward(float fDistance);
	void doDriveRight(float rDistance);
	void doDriveLeft(float lDistance);
	void doDriveReverse(float revDistance);
	void doKinectDrive(void);
	void resetGyro(void);
	void setSafety(bool);
};


#endif
