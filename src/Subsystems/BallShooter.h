#ifndef BALLSHOOTER_H
#define BALLSHOOTER_H
#include "WPILib.h"
#include "../OI.h"

/**
 *
 *
 * @author xNPerson
 */
class BallShooter{
private:
	OI *oI;
	//ButtonsControlSpeed *BCS; //Do nothing variable that just runs the BSBCS function below.
public:
	BallShooter();
	void doShooter(void); //WTF WHY I DON"T EVEN
	void dsAuto(float, float);
	void dsTele(void);
	Victor *shootingMotorL; //This is a Shooting motor connected to a victor. Note: Left one
	Victor *shootingMotorR; //This is a Shooting motor connected to a victor. Note: Right one
//	Encoder *SMl; //This is the encoder attached to the shooting motor on the left. Note: SM=Shooting Motor
//	Encoder *SMr;//This is the encoder attached to the shooting motor on the right. Note: SM=Shooting Motor
	bool Trigger; //The Trigger Note: It turns the motors on or off.
	float Throttle;
	bool SCF; //SCF = Shoot Close Front. Note: Right in front of the baskets.
	bool SCC; //SCC = Shoot Close Corner. Note: In one of the enemy corners.
	bool SOB; //SOB = Shoot On Bridge. Note: When robot is balanced on the center bridge.
	bool SBB; //SBB = Shoot Beside Bridge. Note: On the _____ of the center bridge.
	bool SAD; //SAD = Shoot Alliance Dropoff. Note: Where alliance members return balls.
	bool SKC; //SKC = Shoot Key Center. Note: In our key/safezone, right in the center.
//	bool HAILMARY;
//	bool SMstate; //This is the variable for the state of the shooter. Note: It's either on(True) or off(false)
	//ShooterOff();
	int ShooterDistance;
	

};

/*class ButtonsControlSpeed : public BallShooter {
private:
	OI *oI;
public:
	void BSBCS(void);
	
};
*/
#endif
