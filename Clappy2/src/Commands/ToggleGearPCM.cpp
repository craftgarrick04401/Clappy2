#include "ToggleGearPCM.h"

#include "../Subsystems/GearPCM.h"

ToggleGearPCM::ToggleGearPCM() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::gearPCM.get());
	m_done = false;
}

// Called just before this Command runs the first time
void ToggleGearPCM::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ToggleGearPCM::Execute() {

	if (Robot::gearPCM->GetArmStatus() == static_cast<bool>(ArmStatus::OPENED))
		Robot::gearPCM->SetGearArms(ArmStatus::CLOSED);
	else
		Robot::gearPCM->SetGearArms(ArmStatus::OPENED);

	m_done = true;

}

// Make this return true when this Command no longer needs to run execute()
bool ToggleGearPCM::IsFinished() {
	return m_done;
}

// Called once after isFinished returns true
void ToggleGearPCM::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleGearPCM::Interrupted() {

}
