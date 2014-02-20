#ifndef BRIDGETIPPER_H
#define BRIDGETIPPER_H
#include "WPILib.h"
#include "../OI.h"

/**
 *
 *
 * @author Tom
 */
class BridgeTipper{
private:
	DigitalInput *lUpper;
	DigitalInput *lLower;
	Victor *tipperMotor;
	OI *oI;
	bool rButtonNew;
	bool lButtonNew;
	bool rButtonOld;
	bool lButtonOld;
public:
	BridgeTipper();
	void doTipper(void);
	void setTipper(float);
};

#endif
