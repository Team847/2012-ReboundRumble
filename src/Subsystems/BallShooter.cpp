#include "BallShooter.h"
#include "../Robotmap.h"
#include "../OI.h"

BallShooter::BallShooter(){
	shootingMotorL = new Victor(SHOOTER_LEFT_MOTOR); //Initializing the motor. Note: I am assuming the victor is in port one.
	shootingMotorR = new Victor(SHOOTER_RIGHT_MOTOR); //Initializing the motor. Note: I am assuming the victor is in port two.
//	SMl = new Encoder(1, 2, false, Encoder::k1X); //Initializing the encoder. Note: I am assuming the encoder is in port one.
//	SMr = new Encoder(3, 4, false, Encoder::k1X); //Initializing the encoder. Note: I am assuming the encoder in in port two.
	oI= new OI(); //Initializing the OI.
	ShooterDistance = 0; //This is the switch variable. Note: The three letter variables above are what sets the number of the switch.
	
}

void BallShooter::doShooter(void){	
//	HAILMARY = oI->mStick->GetRawButton(2);
	SCF = oI->mStick->GetRawButton(7); //SCF = Shoot Close Front. Note: Right in front of the baskets
	SCC = oI->mStick->GetRawButton(8); //SCC = Shoot Close Corner. Note: In one of the enemy corners.
	SOB = oI->mStick->GetRawButton(9); //SOB = Shoot On Bridge. Note: When robot is balanced on the center bridge.
	SBB = oI->mStick->GetRawButton(10); //SBB = Shoot Beside Bridge. Note: On the _____ of the center bridge.
	SAD = oI->mStick->GetRawButton(12); //SAD = Shoot Alliance Dropoff. Note: Where alliance members return balls.
	SKC = oI->mStick->GetRawButton(11); //SKC = Shoot Key Center. Note: In our key/safezone, right in the center.
//	Trigger = oI->mStick->GetTrigger(); //The trigger. Note: It to use the shooter, the trigger must be pulled.
	Throttle = (oI->mStick->GetThrottle()+1)*0.5*0.1; //Throttle value. Note: May need to change to GetZ.
	

	if(SCF){
		ShooterDistance = 1;
	}
	if(SCC){
			ShooterDistance = 2;
		}
	if(SOB){
			ShooterDistance = 3;
		}
	if(SBB){
			ShooterDistance = 4;
		}
	if(SAD){
			ShooterDistance = 5;
		}
	if(SKC){
			ShooterDistance = 6;
		}
//	if(HAILMARY){
//		ShooterDistance=0;
//	}
		
	oI->sd->SmartDashboard::Log(ShooterDistance, "Position");

	if(oI->mStick->GetTrigger()) {
			switch(ShooterDistance){ //SPINFUSOR!!!
			case 1:
				shootingMotorL->Set(-SCF_SPEED-Throttle, 0); //Random values !!! CHANGE !!! CHANGE  !!! CHANGE !!! CHANGE !!!
				shootingMotorR->Set(SCF_SPEED+Throttle, 0);
				break;
			case 2:
				shootingMotorL->Set(-SCC_SPEED-Throttle, 0); //Random values !!! CHANGE !!! CHANGE  !!! CHANGE !!! CHANGE !!!
				shootingMotorR->Set(SCC_SPEED+Throttle, 0);
				break;
			case 3:
				shootingMotorL->Set(-SOB_SPEED-Throttle, 0); //Random values !!! CHANGE !!! CHANGE  !!! CHANGE !!! CHANGE !!!
				shootingMotorR->Set(SOB_SPEED+Throttle, 0);
				break;
			case 4:
				shootingMotorL->Set(-SBB_SPEED-Throttle, 0); //Random values !!! CHANGE !!! CHANGE  !!! CHANGE !!! CHANGE !!!
				shootingMotorR->Set(SBB_SPEED+Throttle, 0);
				break;
			case 5:
				shootingMotorL->Set(-SAD_SPEED-Throttle, 0); //Random values !!! CHANGE !!! CHANGE  !!! CHANGE !!! CHANGE !!!
				shootingMotorR->Set(SAD_SPEED+Throttle, 0);
				break;
			case 6:
				shootingMotorL->Set(-SKC_SPEED-Throttle, 0); //Random values !!! CHANGE !!! CHANGE  !!! CHANGE !!! CHANGE !!!
				shootingMotorR->Set(SKC_SPEED+Throttle, 0);
				break;
			default:
				shootingMotorL->Set(-1-Throttle,0); //Random values !!! CHANGE !!! CHANGE  !!! CHANGE !!! CHANGE !!!
				shootingMotorR->Set(1+Throttle,0);
				break;
			}
	}
	else {
		shootingMotorL->Set(0,0); //Stop the shooting motors
		shootingMotorR->Set(0,0);
	}
	}


void BallShooter::dsAuto(float motor1, float motor2) {
	shootingMotorL->Set(motor1);
	shootingMotorR->Set(motor2);
}

void BallShooter::dsTele(void){
	
}

