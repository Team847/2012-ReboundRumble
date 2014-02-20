#include "BridgeTipper.h"
#include "../Robotmap.h"

BridgeTipper::BridgeTipper(){
	lUpper = new DigitalInput(BRIDGETIPPER_LIMIT_UPPER_PORT);
	lLower = new DigitalInput(BRIDGETIPPER_LIMIT_LOWER_PORT);
	tipperMotor = new Victor(BRIDGETIPPER_VICTOR_PORT);
	oI = new OI();
}

void BridgeTipper::doTipper(){
	
	if(oI->mStick->GetY()>BRIDGETIPPER_JOYSTICK_SENSITIVITY || oI->mStick->GetY()<-BRIDGETIPPER_JOYSTICK_SENSITIVITY){
		if(oI->mStick->GetY()>BRIDGETIPPER_JOYSTICK_SENSITIVITY && (lUpper->Get() ? true : false) == true){			// somehow, the softbot buttons are backwards; these "true" values represent this backwards return
			tipperMotor->Set(-(oI->mStick->GetY()));
		}else{
			if(oI->mStick->GetY()<-BRIDGETIPPER_JOYSTICK_SENSITIVITY && (lLower->Get() ? true : false) == true){
				tipperMotor->Set(-(oI->mStick->GetY()));
			}else{
				tipperMotor->Set(0);
			}
		}
	}else{
		tipperMotor->Set(0);
//I can write this entire function in ONE LINE!!! WOO!!!
//		tipperMotor->Set((oI->mStick->GetY()<BRIDGETIPPER_JOYSTICK_SENSITIVITY || oI->mStick->GetY()>-BRIDGETIPPER_JOYSTICK_SENSITIVITY)? BRIDGETIPPER_JOYSTICK_SPEED*((oI->mStick->GetY()>0 && lUpper->Get() ? true : false )== false) ? 1 : ((oI->mStick->GetY()<0 && lLower->Get() ? true : false) == false) ? 1 : 0) : 0);
	}
	
//	oI->sd->Log(((lUpper->Get() ? true : false) == false), "Upper Limit Switch");
//	oI->sd->Log(((lLower->Get() ? true : false) == false), "Lower Limit Switch");
}

void BridgeTipper::setTipper(float f){
	if(f<0 && lUpper->Get() ? true : false == true){
		tipperMotor->Set(f);
	}else{
		if(f>0 && lLower->Get() ? true : false == true){
			tipperMotor->Set(f);
		}else{
			tipperMotor->Set(0);
		}
	}
}

