#include "GearArm.h"
#include "../RobotMap.h"
#include "../Commands/ControlGearArm.h"

GearArm::GearArm() : Subsystem("GearArm") {

	motor = RobotMap::gearArmMotor;
	encoder = RobotMap::gearArmEncoder;
	homeSwitch = RobotMap::gearArmSwitch;

	motor->Set(0.0);
	encoder->SetDistancePerPulse(360.0);
}

void GearArm::InitDefaultCommand() {
	SetDefaultCommand(new ControlGearArm());
}

void GearArm::Zero()
{
	encoder->Reset();
}

void GearArm::ControlMotor(double speed)
{
	motor->Set(speed);
}

bool GearArm::GetHomeSwitch()
{
	return homeSwitch->GetTriggerState();
}

std::string GearArm::GetPositionS()
{
	if (GearArm::Ground())
		return "Ground";
	else if (GearArm::Ramp())
		return "Ramp";
	else if (GearArm::Hook())
		return "Hook";
	else if (GearArm::BetweenGroundAndRamp())
		return "Between Ground and Ramp";
	else if (GearArm::BetweenRampAndHook())
		return "Between Ramp and Hook";
	else
		return "Not Initialized";
}

void GearArm::MoveTo(Position position)
{
	switch (position)
	{
	case Position::GROUND:
		while (!GearArm::Ground())
			motor->Set(0.3);
		motor->Set(0.0);
		break;
	case Position::RAMP:
		if (GearArm::Hook() || GearArm::BetweenRampAndHook())
		{
			while(!GearArm::Ramp())
				motor->Set(0.3);
		}
		else
		{
			while(!GearArm::Ramp())
				motor->Set(-3.0);
		}
		motor->Set(0.0);
		break;
	case Position::HOOK:
		while (!GearArm::Hook())
			motor->Set(-0.3);
		motor->Set(0.0);
		break;
	}
}

inline bool GearArm::Ground()
{
	return encoder->GetDistance() <= 0.0;
}

inline bool GearArm::Ramp()
{
	return encoder->GetDistance() <= 46.0 && encoder->GetDistance() >= 44.0;
}

inline bool GearArm::Hook()
{
	return encoder->GetDistance() >= 90.0;
}

inline bool GearArm::BetweenGroundAndRamp()
{
	return encoder->GetDistance() < 44.0 && encoder->GetDistance() > 0.0;
}

inline bool GearArm::BetweenRampAndHook()
{
	return encoder->GetDistance() < 90.0 && encoder->GetDistance() > 46.0;
}
