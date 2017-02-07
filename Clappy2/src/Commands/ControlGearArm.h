#ifndef ControlGearArm_H
#define ControlGearArm_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class ControlGearArm : public Command {
public:
	ControlGearArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	std::shared_ptr<Joystick> joystick2;
};

#endif  // ControlGearArm_H
