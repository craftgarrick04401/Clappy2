#include "../Commands/DriveTeleop.h"
#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {

    topLeft = RobotMap::driveTrainTopLeft;
    topRight = RobotMap::driveTrainTopRight;
    bottomLeft = RobotMap::driveTrainBottomLeft;
    bottomRight = RobotMap::driveTrainBottomRight;
    center = RobotMap::driveTrainCenter;

    m_direction = Direction::FORWARD;

    StopMoving();

}

void DriveTrain::InitDefaultCommand() {

		SetDefaultCommand(new DriveTeleop());

}

void DriveTrain::SetMotorSpeed(DriveMotor motor, double speed)
{
	switch (motor)
	{
	case DriveMotor::TOP_LEFT:
		DriveTrain::topLeft->Set(speed);
		break;
	case DriveMotor::TOP_RIGHT:
		DriveTrain::topRight->Set(speed);
		break;
	case DriveMotor::BOTTOM_LEFT:
		DriveTrain::bottomLeft->Set(speed);
		break;
	case DriveMotor::BOTTOM_RIGHT:
		DriveTrain::bottomRight->Set(speed);
		break;
	case DriveMotor::CENTER:
		DriveTrain::center->Set(speed);
		break;
	}

}

void DriveTrain::StopMoving()
{
	DriveTrain::SetMotorSpeed(DriveMotor::TOP_LEFT, 0.0);
	DriveTrain::SetMotorSpeed(DriveMotor::TOP_RIGHT, 0.0);
	DriveTrain::SetMotorSpeed(DriveMotor::BOTTOM_LEFT, 0.0);
	DriveTrain::SetMotorSpeed(DriveMotor::BOTTOM_RIGHT, 0.0);
	DriveTrain::SetMotorSpeed(DriveMotor::CENTER, 0.0);


}

void DriveTrain::ChangeDirection()
{
	if (m_direction == Direction::FORWARD)
		m_direction = Direction::REVERSE;
	else
		m_direction = Direction::FORWARD;
}

void DriveTrain::SetDirection(Direction direction)
{
	m_direction = direction;
}

int DriveTrain::GetDirection()
{
	return static_cast<int>(m_direction);
}

std::string DriveTrain::GetDirectionS()
{
	if (m_direction == Direction::FORWARD)
		return "Forward";
	else
		return "Reverse";
}


