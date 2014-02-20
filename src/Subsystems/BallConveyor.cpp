#include "BallConveyor.h"
#include "../Robotmap.h"
#include "../OI.h"

/* BEGIN COMMENT STORM
 * 
 * This class represent the conveyor system. 
 * Each iteration of the robot, the method BallConveyor::doConveyor is called.
 * While it is perfectly possible for all of the code to be in this menthod, I
 * split the automatic and manual portions of the code up for readablilty and 
 * organization. 
 * 
 * This is currently incomplete due to the OI being incomplete and my code 
 * depending on joysticks.
 */

BallConveyor::BallConveyor(){						//necessary objects initialized
//	bLoad = new DigitalInput(LOADING_BREAK_BEAM_PORT);	//break beam before loading conveyor
//	bQueue = new DigitalInput(QUEUE_BREAK_BEAM_PORT);					//break beam before queue conveyor
//	bShoot = new DigitalInput(SHOOTING_BREAK_BEAM_PORT);					//break beam after queue conveyor
	cLoad = new Relay(2, Relay::kBothDirections);	//conveyor belts
	cQueue = new Relay(1, Relay::kBothDirections);
	swMotor = new Relay(3,Relay::kBothDirections);
	oI = new OI();
													//The new and old variables are necessary to debounce the input. 
//	bLoadNew=bLoad->Get() ? true : false;			//get new values; ternary functions convert the integer to a boolean
//	bQueueNew=bQueue->Get() ? true : false;		
//	bShootNew=bShoot->Get() ? true : false;
//	
//	bLoadOld=bLoadNew;								//new values copied
//	bQueueOld=bQueueNew;
//	bShootOld=bShootNew;
//	
//	qCount=2;
}

void BallConveyor::doConveyor(){
//	btnDisableNew=oI->mStick->GetRawButton(BALLCONVEYOR_AUTO_BUTTON);	// this button toggles auto/manual
//	bLoadNew=bLoad->Get() ? true : false;
//	bQueueNew=bQueue->Get() ? true : false;
//	bShootNew=bShoot->Get() ? true : false;
	
//	if(btnDisableNew==true && btnDisableOld==false){//old and new variables used to return true only once per press-release of button
//		disabled=!disabled;
//	}
		
//	if(disabled){
		doManual();
//	}else{
//		doAuto();
//	}
	
//	btnDisableOld=btnDisableNew;
//	bLoadOld=bLoadNew;
//	bQueueOld=bQueueNew;
//	bShootOld=bShootNew;
}

//void BallConveyor::doAuto(){
//
//	if(oI->mStick->GetTrigger(Joystick::kRightHand)){//trigger enables queue conveyor
//		cQueue->Set(Relay::kForward);
//	}
//					
//	if(bShootNew==false && bShootOld==true){			//turn the queue off if the ball has just exited (to the shooter) and reduce the count
//		cQueue->Set(Relay::kOff);
//		qCount--;
//		if(cQueue<0){
//			qCount=0;
//		}
//	}
//
//	if(bLoadNew==true && bLoadOld==false && (lCount+qCount)<3){ //if it has found a ball, turn the loading conveyor on and increment the loading counter.
//		swMotor->Set(Relay::kForward);
//		cLoad->Set(Relay::kForward);
//		lCount++;
//	}
//				
//	if(bQueueNew==false && bQueueOld==true){ //if a ball has entered the queue, change the counts and turn off the loading conveyor if there are no more balls.
//		lCount--;
//		qCount++;
//		if(lCount<=0){
//			swMotor->Set(Relay::kOff);
//			cLoad->Set(Relay::kOff);
//			lCount=0;
//		}
//	}
//}
void BallConveyor::doManual(){
	// These really ugly if conditions simplify to an XOR gate.
	
//	if(oI->mStick->GetRawButton(QUEUE_CONVEYOR_REVERSEBUTTON) || oI->mStick->GetTrigger()){
//		if(oI->mStick->GetRawButton(QUEUE_CONVEYOR_REVERSEBUTTON)){
//			cQueue->Set(Relay::kReverse);
//		}else{
//			if(oI->mStick->GetTrigger()){
//				cQueue->Set(Relay::kForward);
//			}else{
//				cQueue->Set(Relay::kOff);
//			}
//		}
//	}else{
//		cQueue->Set(Relay::kOff);
//	}
//	cQueue->Set(Relay::kForward);
//	cLoad->Set(Relay::kForward);
//	swMotor->Set(Relay::kForward);
	if(oI->mStick->GetRawButton(QUEUE_CONVEYOR_FORWARDBUTTON) || oI->mStick->GetRawButton(QUEUE_CONVEYOR_REVERSEBUTTON)){
		if(oI->mStick->GetRawButton(QUEUE_CONVEYOR_FORWARDBUTTON)){
			cQueue->Set(Relay::kForward);
			cLoad->Set(Relay::kReverse);
			swMotor->Set(Relay::kForward);
		}else{
			if(oI->mStick->GetRawButton(QUEUE_CONVEYOR_REVERSEBUTTON)){
				cQueue->Set(Relay::kReverse);
				cLoad->Set(Relay::kForward);
				swMotor->Set(Relay::kReverse);
			}else{
				cQueue->Set(Relay::kOff);
				cLoad->Set(Relay::kOff);
				swMotor->Set(Relay::kOff);
			}
		}
	}else{
		cQueue->Set(Relay::kOff);
		cLoad->Set(Relay::kOff);
		swMotor->Set(Relay::kOff);
	}
//					
//	if(oI->mStick->GetRawButton(LOADING_CONVEYOR_FORWARDBUTTON) || oI->mStick->GetRawButton(LOADING_CONVEYOR_REVERSEBUTTON)){
//		if(oI->mStick->GetRawButton(LOADING_CONVEYOR_FORWARDBUTTON)){
//			cLoad->Set(Relay::kForward);
//			swMotor->Set(Relay::kForward);
//		}else{
//			cLoad->Set(Relay::kReverse);
//			swMotor->Set(Relay::kReverse);
//		}
//	}else{
//		cLoad->Set(Relay::kOff);
//		swMotor->Set(Relay::kOff);
//	}
}

//void BallConveyor::shoot(){
//	while(!(bShoot->Get() ? true: false)){
//		cQueue->Set(Relay::kForward);
//	}
//	cQueue->Set(Relay::kOff);
//	qCount--;
//}
//
//void BallConveyor::load(){
//	swMotor->Set(Relay::kForward);
//	cLoad->Set(Relay::kForward);
//}
//
//void BallConveyor::disgorge(){
//	while((lCount+qCount)>0){
//		manageNew();
//		
//		if(qCount>0){
//			cQueue->Set(Relay::kReverse);
//		}else{
//			cQueue->Set(Relay::kOff);
//		}
//		
//		if(lCount>0){
//			cLoad->Set(Relay::kReverse);
//			swMotor->Set(Relay::kReverse);
//		}else{
//			cLoad->Set(Relay::kOff);
//			swMotor->Set(Relay::kOff);
//		}
//		
//		if(bQueueNew==true && bQueueOld==false){
//			qCount--;
//		}
//		if(bLoadNew==true && bLoadOld==false){
//			lCount--;
//		}
//		
//		manageOld();
//	}
//	cQueue->Set(Relay::kOff);
//	cLoad->Set(Relay::kOff);
//	swMotor->Set(Relay::kOff);
//}
//
//void BallConveyor::manageNew(){
//	bLoadNew=bLoad->Get() ? true : false;
//	bQueueNew=bQueue->Get() ? true : false;
//	bShootNew=bShoot->Get() ? true : false;
//}
//
//void BallConveyor::manageOld(){
//	bLoadOld=bLoadNew;
//	bQueueOld=bQueueNew;
//	bShootOld=bShootNew;
//}
void BallConveyor::setMotors(int sweeper, int lowerConveyor, int upperConveyor){
	if(sweeper==0){
		swMotor->Set(Relay::kOff);
	}else{
		if(sweeper>0){
			swMotor->Set(Relay::kForward);
		}else{
			swMotor->Set(Relay::kReverse);
		}
	}
	if(lowerConveyor==0){
		cLoad->Set(Relay::kOff);
	}else{
		if(lowerConveyor>0){
			cLoad->Set(Relay::kForward);
		}else{
			cLoad->Set(Relay::kReverse);
		}
	}
	if(upperConveyor==0){
		cQueue->Set(Relay::kOff);
	}else{
		if(upperConveyor>0){
			cQueue->Set(Relay::kForward);
		}else{
			cQueue->Set(Relay::kReverse);
		}
	}
}
