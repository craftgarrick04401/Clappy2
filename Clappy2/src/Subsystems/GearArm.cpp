#include "GearArm.h"
#include "../RobotMap.h"
#include "../Commands/ControlGearArm.h"

GearArm::GearArm() : Subsystem("GearArm") {

	motor = RobotMap::gearArmMotor;
	encoder = RobotMap::gearArmEncoder;
	homeSwitch = RobotMap::gearArmSwitch;
	m_position = Position::NOT_INITIALIZED;

	motor->Set(0.0);
	encoder->SetDistancePerPulse(360.0);
}

void GearArm::InitDefaultCommand() {
	SetDefaultCommand(new ControlGearArm());
}

void GearArm::Zero()
{
	encoder->Reset();
	m_position = Position::GROUND;
}

void GearArm::ControlMotor(double speed)
{
	motor->Set(speed);
}

bool GearArm::GetHomeSwitch()
{
	return homeSwitch->GetTriggerState();
}

int GearArm::GetPosition()
{
	return static_cast<int>(m_position);
}

std::string GearArm::GetPositionS()
{
	switch (m_position)
	{
	case Position::NOT_INITIALIZED:
		return "Not Initialized";
	case Position::GROUND:
		return "Ground";
	case Position::RAMP:
		return "Ramp";
	default:
		return "Hook";
	}
}

void GearArm::MoveTo(Position position)
{
	switch (position)
	{
	case Position::GROUND:
	{
		while (encoder->GetDistance() > 0.0)
			motor->Set(0.3);
		m_position = Position::GROUND;
		break;
	}
	case Position::RAMP:
	{
		while (encoder->GetDistance() > 46.0)
			motor->Set(0.3);
		while (encoder->GetDistance() < 44.0)
			motor->Set(-0.3);
		m_position = Position::RAMP;
		break;
	}
	case Position::HOOK:
	{
		while (encoder->GetDistance() < 90.0)
			motor->Set(-0.3);
		m_position = Position::HOOK;
		break;
	}
	default:
		break;
	}
}
