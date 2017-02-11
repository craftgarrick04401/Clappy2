#include "ControlGearArm.h"

ControlGearArm::ControlGearArm() {

	Requires(Robot::gearArm.get());

	m_position = 0.0;
	m_done = false;

}

void ControlGearArm::Initialize() {

}

void ControlGearArm::Execute() {
	m_position = SmartDashboard::GetNumber("gy", 0.0);
	Robot::gearArm->MoveTo(m_position);
	m_done = true;
}

bool ControlGearArm::IsFinished() {
	return m_done;
}

void ControlGearArm::End() {
	Robot::gearArm->ControlMotor(0.0);
}

void ControlGearArm::Interrupted() {
	Robot::gearArm->ControlMotor(0.0);
}
