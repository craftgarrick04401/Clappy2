#include "ControlGearArm.h"

ControlGearArm::ControlGearArm() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::gearArm.get());
	joystick2 = Robot::oi->getJoystick2();
}

// Called just before this Command runs the first time
void ControlGearArm::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ControlGearArm::Execute() {
	Robot::gearArm->ControlMotor(joystick2->GetY() * 0.25);
}

// Make this return true when this Command no longer needs to run execute()
bool ControlGearArm::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ControlGearArm::End() {
	Robot::gearArm->ControlMotor(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlGearArm::Interrupted() {
	Robot::gearArm->ControlMotor(0.0);
}
