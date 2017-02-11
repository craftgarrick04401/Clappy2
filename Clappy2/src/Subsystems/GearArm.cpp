#include "GearArm.h"
#include "../RobotMap.h"
#include "../Commands/ControlGearArm.h"

GearArm::GearArm() : Subsystem("GearArm") {

	motor = RobotMap::gearArmMotor;
	encoder = RobotMap::gearArmEncoder;
	homeSwitch = RobotMap::gearArmSwitch;

	if (EncoderP())
		encoder->SetDistancePerPulse(360.0 / 497.0);

	ControlMotor(0.0);

}

void GearArm::InitDefaultCommand() {
	//SetDefaultCommand(new ControlGearArm());
}

void GearArm::Zero()
{
	if (EncoderP())
		encoder->Reset();
}

void GearArm::ControlMotor(double speed)
{
	if (MotorP())
		motor->Set(speed);
}

bool GearArm::GetHomeSwitch()
{
	if (HomeSwitchP())
		return homeSwitch->Get();
	else
		return false;
}

double GearArm::GetDegreesD()
{
	if (EncoderP())
		return encoder->GetDistance();
	else
		return static_cast<double>(RobotError::POINTER_IS_NULL);
}

bool GearArm::Position(double position)
{
	if (EncoderP())
		return encoder->GetDistance() > position - 2.0 && encoder->GetDistance() < position + 2.0;
	else
		return false;
}

void GearArm::MoveTo(double position)
{
	if (EncoderP())
	{
		while (encoder->GetDistance() < position - 2.0)
			ControlMotor(-0.2);
		while (encoder->GetDistance() > position + 2.0)
			ControlMotor(0.2);
		ControlMotor(0.0);
	}
}

inline bool GearArm::EncoderP()
{
	return encoder != nullptr;
}

inline bool GearArm::MotorP()
{
	return motor != nullptr;
}

inline bool GearArm::HomeSwitchP()
{
	return homeSwitch != nullptr;
}
