#include "DriveTeleop.h"
#include <cmath>

DriveTeleop::DriveTeleop(): Command() {

	Requires(Robot::driveTrain.get());

	m_X = 0.0;
	m_Y = 0.0;
	m_Z = 0.0;
	m_scalar = 0.0;

	driveStick = Robot::oi->getDriveStick();

}

void DriveTeleop::Initialize() {
	//Robot::driveTrain->StopMoving();
}

void DriveTeleop::Execute() {

	m_scalar = -0.5 * driveStick->GetRawAxis(3) + 0.5;
	m_X = driveStick->GetRawAxis(0);
	m_Y = driveStick->GetRawAxis(1);
	m_Z = -driveStick->GetRawAxis(2);

	if (Robot::driveTrain->GetDirection() == static_cast<int>(Direction::FORWARD))
	{
		Robot::driveTrain->SetMotorSpeed(DriveMotor::TOP_LEFT, DriveTeleop::CalculateSpeed(m_scalar, DriveTeleop::Left()));
		Robot::driveTrain->SetMotorSpeed(DriveMotor::TOP_RIGHT, DriveTeleop::CalculateSpeed(m_scalar, DriveTeleop::Right()));
		Robot::driveTrain->SetMotorSpeed(DriveMotor::BOTTOM_LEFT, DriveTeleop::CalculateSpeed(m_scalar, DriveTeleop::Left()));
		Robot::driveTrain->SetMotorSpeed(DriveMotor::BOTTOM_RIGHT, DriveTeleop::CalculateSpeed(m_scalar, DriveTeleop::Right()));
		Robot::driveTrain->SetMotorSpeed(DriveMotor::CENTER, DriveTeleop::CalculateSpeed(m_scalar, m_X));

	}
	else
	{
		Robot::driveTrain->SetMotorSpeed(DriveMotor::TOP_LEFT, DriveTeleop::CalculateSpeed(m_scalar, DriveTeleop::Right()));
		Robot::driveTrain->SetMotorSpeed(DriveMotor::TOP_RIGHT, DriveTeleop::CalculateSpeed(m_scalar, DriveTeleop::Left()));
		Robot::driveTrain->SetMotorSpeed(DriveMotor::BOTTOM_LEFT, DriveTeleop::CalculateSpeed(m_scalar, DriveTeleop::Right()));
		Robot::driveTrain->SetMotorSpeed(DriveMotor::BOTTOM_RIGHT, DriveTeleop::CalculateSpeed(m_scalar, DriveTeleop::Left()));
		Robot::driveTrain->SetMotorSpeed(DriveMotor::CENTER, DriveTeleop::CalculateSpeed(m_scalar, -m_X));

	}
}

bool DriveTeleop::IsFinished() {
    return false;
}

void DriveTeleop::End() {
	Robot::driveTrain->StopMoving();
}

void DriveTeleop::Interrupted() {
	Robot::driveTrain->StopMoving();
}

inline double DriveTeleop::CalculateSpeed(double scalar, double input)
{
	return (2 * scalar / (1 + std::exp(5 * input))) - scalar;
}

inline double DriveTeleop::Left()
{
	return -(m_Y + m_Z);
}

inline double DriveTeleop::Right()
{
	return m_Y - m_Z;
}
