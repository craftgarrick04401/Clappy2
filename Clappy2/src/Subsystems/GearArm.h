#ifndef GearArm_H
#define GearArm_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include <string>

/**
 *
 *
 * @author Garrick Craft
 */

enum class Position
{
	GROUND,
	RAMP,
	HOOK
};

class GearArm : public Subsystem {
private:

	std::shared_ptr<SpeedController> motor;
	std::shared_ptr<Encoder> encoder;
	std::shared_ptr<AnalogTrigger> homeSwitch;

	inline bool Ground();
	inline bool Ramp();
	inline bool Hook();
	inline bool BetweenGroundAndRamp();
	inline bool BetweenRampAndHook();

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

#endif
