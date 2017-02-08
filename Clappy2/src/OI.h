#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:

	std::shared_ptr<Joystick> driveStick;
	std::shared_ptr<Joystick> gearStick;
	std::shared_ptr<JoystickButton> controlSwitchButton;
	std::shared_ptr<JoystickButton> toggleGearPCMButton;

public:
	OI();

	std::shared_ptr<Joystick> getDriveStick();
	std::shared_ptr<Joystick> getGearStick();

};

#endif
