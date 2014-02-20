#include "DriveTrain.h"
#include "../Robotmap.h"
#include "math.h"
#include "BridgeTipper.h"

DriveTrain::DriveTrain(){
	phredRobot = new RobotDrive(3,4,1,2);
	driveOI = new OI();
	lEncoder = new Encoder(LEFT_ENCODER_PORT,Encoder::k1X);
	rEncoder = new Encoder(RIGHT_ENCODER_PORT,Encoder::k1X);
	lEncoder->SetDistancePerPulse(0.02);
	rEncoder->SetDistancePerPulse(0.02);
	lEncoder->Start();
	rEncoder->Start();
	turnGyro = new Gyro(TURN_GYRO_PORT);
	tipGyro = new Gyro(TIP_GYRO_PORT);
	tipGyro->Reset();
	//float gyroscope = ds->GetAnalogIn(3);
	angle=0;
	motorOne = driveOI->db->GetAnalogIn(1);
	motorTwo = driveOI->db->GetAnalogIn(1);
	correctionFactor = driveOI->db->GetAnalogIn(2);
	gyroStable = 0;
	angleDif = driveOI->db->GetAnalogIn(3);
	groundUS = new AnalogChannel(3);
	floorREF = groundUS->GetVoltage();
	bT = new BridgeTipper();
	tipGyro->SetSensitivity(.007);
	bridgeLight = new Relay(4, Relay::kForwardOnly);
}


void DriveTrain::doTankDrive(){
	phredRobot->TankDrive(-driveOI->lStick->GetY(),-driveOI->rStick->GetY());//not currently used
	//if	(driveOI->rStick->GetZ()>0)	{
	//				phredRobot->Drive(-driveOI->lStick->GetY(), -driveOI->rStick->GetY());
	
	
}
void DriveTrain::doRampClimb(){
	
//	bool ChaseDrive;
//	
//	if(driveOI->rStick->GetZ()<0) {
//		ChaseDrive = true;
//	}
//	else {
//		ChaseDrive = false;
//	}

	if(driveOI->lStick->GetRawButton(2)){
				tipGyro->Reset();
	}
	
//	if(fabs(tipGyro->GetAngle())<=5){
//		bridgeLight->Set(Relay::kOn);
//	}else{
//		bridgeLight->Set(Relay::kOff);	
//	}
	
//	tipGyro->SetSensitivity(.007);
	driveOI->sd->SmartDashboard::Log(tipGyro->GetAngle(), "Tip Gyro Angle");
	
	if(driveOI->lStick->GetTrigger()){ //Auto Balance
		 
		gyroStable=(tipGyro->GetAngle())/fabs(tipGyro->GetAngle());
		if(gyroStable>0){
			phredRobot->TankDrive(motorOne*gyroStable, motorTwo*gyroStable*0.95);
		}else{
			phredRobot->TankDrive(motorOne*gyroStable*0.95, motorTwo*gyroStable);
		}
//		phredRobot->TankDrive(motorOne*gyroStable, motorTwo*gyroStable);
		
		if(angle==0){
			angle = tipGyro->GetAngle();
		}
		if((fabs(angle)-fabs(tipGyro->GetAngle()))>angleDif) {
				phredRobot->Drive(0.0, 0.0);
				Wait(0.1);
		}
//		if(groundUS->GetAverageVoltage()>BRIDGE_GROUND_US_THRESHOLD){
//					phredRobot->Drive(0.0,0.0);
//		}
		
	}else{	
//		if(driveOI->rStick->GetTrigger()){ //GRANNY GEEEEEEEEEAAAAR	
//			phredRobot->TankDrive(-driveOI->lStick->GetY()*driveOI->db->GetAnalogIn(4), -driveOI->rStick->GetY()*driveOI->db->GetAnalogIn(4));
//		}else{
			if (driveOI->rStick->GetZ()>0){
				phredRobot->TankDrive(-driveOI->lStick->GetY()*0.75, -driveOI->rStick->GetY()*0.75);//used normaldrive code code
			}else{
				phredRobot->TankDrive(-driveOI->lStick->GetY(), -driveOI->rStick->GetY()); //used Chasedrive code
			}
//		}
		
	}
			
}
	
	
//	if((fabs(angle)-fabs(tipGyro->GetAngle()))>angleDif) {
//			phredRobot->Drive(0.0, 0.0);
//			Wait(5.000);
//		}




//}
void DriveTrain::doDriveForward(float fDistance){
	lEncoder->Reset();
	do {phredRobot->TankDrive(0.5, 0.5);} while (lEncoder->GetDistance()<fDistance);
	phredRobot->TankDrive(0.0, 0.0);
}
void DriveTrain::doDriveRight(float rDistance){
	turnGyro->Reset();
	do {phredRobot->TankDrive(0.5, 0.0);} while (turnGyro->GetAngle()<rDistance);
	phredRobot->TankDrive(0.0, 0.0);
}
void DriveTrain::doDriveLeft(float lDistance){
	turnGyro->Reset();
	do {
		phredRobot->TankDrive(0.0, 0.5);
		driveOI->sd->Log(turnGyro->GetAngle(),"turnGyroAngle");
	} while (turnGyro->GetAngle()<(360-lDistance));
	phredRobot->TankDrive(0.0, 0.0);
}
void DriveTrain::doDriveReverse(float revDistance){
	rEncoder->Reset();
	do {phredRobot->TankDrive(-0.5, -0.5);} while (lEncoder->GetDistance()<revDistance);
	phredRobot->TankDrive(0.0, 0.0);
}
void DriveTrain::doKinectDrive(){
	phredRobot->TankDrive(driveOI->rightArm->GetY()*0.75,driveOI->leftArm->GetY()*0.75);
	if(driveOI->rightArm->GetRawButton(7) || driveOI->rightArm->GetRawButton(5)){
		if(driveOI->rightArm->GetRawButton(7)){
			bT->setTipper(-.75);
		}else{
			bT->setTipper(.75);
		}
	}else{
		bT->setTipper(0);	
	}
}
void DriveTrain::resetGyro(){
	tipGyro->Reset(); 
	turnGyro->Reset();
}

void DriveTrain::setSafety(bool b){
	phredRobot->SetSafetyEnabled(b);
}
