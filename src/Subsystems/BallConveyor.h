#ifndef BALLCONVEYOR_H
#define BALLCONVEYOR_H
#include "WPILib.h"
#include "../OI.h"

class BallConveyor{
private:
//	DigitalInput *bLoad;
//	DigitalInput *bQueue;
//	DigitalInput *bShoot;
	OI *oI;
	
	Relay *cLoad;
	Relay *cQueue;
	Relay *swMotor;
	
//	bool bLoadOld;
//	bool bLoadNew;
//	bool bQueueOld;
//	bool bQueueNew;
//	bool bShootOld;
//	bool bShootNew;		
//	
//	bool btnDisableNew;
//	bool btnDisableOld;
//	bool disabled;
//
//	void doAuto(void);
//	void manageNew(void);
//	void manageOld(void);
public:
	BallConveyor();
	void doConveyor(void);
//	void shoot(void);
//	void load(void);
//	void disgorge(void);
	void doManual(void);
	void setMotors(int,int,int);
	
//	int lCount;
//	int qCount;
};

#endif
