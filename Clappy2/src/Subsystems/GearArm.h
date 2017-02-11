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
	std::shared_ptr<DigitalInput> homeSwitch;

	inline bool EncoderP();
	inline bool MotorP();
	inline bool HomeSwitchP();

	inline bool Ground();
	inline bool Ramp();
	inline bool Hook();
	inline bool BetweenGroundAndRamp();
	inline bool BetweenRampAndHook();

public:

	GearArm();

	void InitDefaultCommand();

	void Zero();

	void Home();

	void MoveTo(double position);

	void ControlMotor(double speed);

	bool GetHomeSwitch();

	double GetDegreesD();

	bool Position(double position);

};

#endif
