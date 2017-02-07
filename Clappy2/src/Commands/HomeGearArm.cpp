#include "HomeGearArm.h"
#include "../RobotMap.h"

HomeGearArm::HomeGearArm() {

	Requires(Robot::gearArm.get());
	m_done = false;

}


void HomeGearArm::Initialize() {

	//Robot::gearArm->ControlMotor(0.0);

}


void HomeGearArm::Execute() {

	while (!Robot::gearArm->GetHomeSwitch())
	{
		Robot::gearArm->ControlMotor(0.3);
	}
	Robot::gearArm->Zero();
	m_done = true;
}


bool HomeGearArm::IsFinished() {
	return m_done;
}


void HomeGearArm::End() {
	Robot::gearArm->ControlMotor(0.0);
}


void HomeGearArm::Interrupted() {
	Robot::gearArm->ControlMotor(0.0);
}
