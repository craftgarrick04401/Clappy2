#ifndef GearArm_H
#define GearArm_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include <string>

enum class Position
{
	NOT_INITIALIZED,
	GROUND,
	RAMP,
	HOOK
};

class GearArm : public Subsystem {
private:

	std::shared_ptr<SpeedController> motor;
	std::shared_ptr<Encoder> encoder;
	std::shared_ptr<AnalogTrigger> homeSwitch;
	Position m_position;

public:
	GearArm();
	void InitDefaultCommand();

	void Zero();

	void MoveTo(Position position);

	void ControlMotor(double speed);

	bool GetHomeSwitch();

	int GetPosition();

	std::string GetPositionS();

};

#endif  // GearArm_H
