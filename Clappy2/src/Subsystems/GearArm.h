#ifndef GearArm_H
#define GearArm_H

#include <Commands/Subsystem.h>
#include "WPILib.h"

class GearArm : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	std::shared_ptr<SpeedController> motor;
	std::shared_ptr<Encoder> encoder;
	//std::shared_ptr<Limit> switch;

public:
	GearArm();
	void InitDefaultCommand();
};

#endif  // GearArm_H
