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
	SetDefaultCommand(new ControlGearArm());
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
		return homeSwitch->GetTriggerState();
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
		return CvtPosition(encoder->GetDistance()) > position - 2.0 && CvtPosition(encoder->GetDistance()) < position + 2.0;
	else
		return false;
}

void GearArm::MoveTo(double position)
{
	if (EncoderP())
	{
		if (CvtPosition(encoder->GetDistance()) < position)
		{
			while (!Position(position))
				ControlMotor(3.0);
			ControlMotor(0.0);
		}
		else
		{
			while (!Position(position))
				ControlMotor(-3.0);
			ControlMotor(0.0);
		}
	}
}

double GearArm::CvtPosition(double position)
{
	if (position < 0.0)
		return (position + 360.0 < 0.0) ? CvtPosition(position + 360.0) : position + 360.0;
	else if (position > 360.0)
		return (position - 360.0 > 360.0) ? CvtPosition(position - 360.0) : position - 360.0;
	else
		return position;
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
