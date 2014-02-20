#include "WPILib.h"
#include "OI.h"
#include "./Subsystems/BallConveyor.h"
#include "./Subsystems/BallShooter.h"
#include "./Subsystems/BridgeTipper.h"
#include "./Subsystems/DriveTrain.h"
#include "Robotmap.h"

class PHRED12 : public IterativeRobot {
private:
	BallConveyor *bC;
	BridgeTipper *bT;
	DriveTrain *dT;
	BallShooter *bS;
	
	OI *oI;
	int autoMethodID;
	bool autoDo;
	
	virtual void RobotInit() {
		bC = new BallConveyor();
		bT = new BridgeTipper();
		dT = new DriveTrain();
		bS = new BallShooter();
		oI = new OI();
		autoMethodID=0;
		autoDo=true;
	}
	
	virtual void AutonomousInit() {
		for(int i=1; i<9; i++){
			if(oI->db->GetDigitalIn(i)){
				if(autoMethodID!=0){
					autoMethodID=10;
					i=10;
				}else{
				autoMethodID=i;
				}
			}
		}
	}
	
	virtual void AutonomousPeriodic() {
		if(autoDo){
			switch (autoMethodID){
				case 1:
					//kinect drive
					do{
						dT->doKinectDrive();
					}while(oI->db->IsAutonomous());
					break;
				case 2:
					//ball feed to other bot on floor / puke out balls
					bC->setMotors(-1,1,-1);
					break;
				case 3:
					//shoot two balls
					dT->doDriveForward(144);
					bS->dsAuto(-SCF_SPEED,SCF_SPEED);
					bC->setMotors(0,-1,1);
					break;
				case 4:
					//tip middle ramp
					dT->doDriveForward(130); //some distance
					do{
						bT->setTipper(-1);
						Wait(0.05);
					}while(oI->db->IsAutonomous());
					break;
				case 5:
					//dribble feed to other bot
					bS->dsAuto(-SCF_SPEED,SCF_SPEED);
					bC->setMotors(0,-1,1);
					break;
				case 6:
					//prep go over alliance bridge
					dT->doDriveForward(100);
					dT->doDriveLeft(270);
					dT->doDriveForward(100);
					break;
				case 7:
					//get out of way
					dT->doDriveForward(72);
					break;
				case 8:
					break;
				default:
					break;
			}
		}
		autoDo=false;
	}
	
	virtual void TeleopInit() {
		dT->setSafety(false);
		dT->resetGyro();
		bS->dsAuto(0.0,0.0);
		bC->setMotors(0,0,0);
		bT->setTipper(0.0);
	}
	
	virtual void TeleopPeriodic() {
		bC->doManual();
		bT->doTipper();
		dT->doRampClimb();
		bS->doShooter();
	}
};

START_ROBOT_CLASS(PHRED12);

