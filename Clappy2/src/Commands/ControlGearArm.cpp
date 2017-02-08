#include "ControlGearArm.h"

ControlGearArm::ControlGearArm() {

	Requires(Robot::gearArm.get());
	gearStick = Robot::oi->getGearStick();

}

void ControlGearArm::Initialize() {

}

void ControlGearArm::Execute() {
	Robot::gearArm->ControlMotor(gearStick->GetY() * 0.25);
}

bool ControlGearArm::IsFinished() {
	return false;
}

void ControlGearArm::End() {
	Robot::gearArm->ControlMotor(0.0);
}

void ControlGearArm::Interrupted() {
	Robot::gearArm->ControlMotor(0.0);
}
