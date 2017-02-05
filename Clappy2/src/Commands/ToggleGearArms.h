#ifndef ToggleGearArms_H
#define ToggleGearArms_H

#include "Commands/Subsystem.h"
#include "../Robot.h"


class ToggleGearArms : public Command {
public:
	ToggleGearArms();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool m_done;
};

#endif  // ToggleGearArms_H
