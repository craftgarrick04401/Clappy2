// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "DriveTeleop.h"
#include <cmath>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

DriveTeleop::DriveTeleop(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	m_X = 0.0;
	m_Y = 0.0;
	m_Z = 0.0;
	m_scalar = 0.0;

	driveStick = Robot::oi->getDriveStick();
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
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

// Make this return true when this Command no longer needs to run execute()
bool DriveTeleop::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void DriveTeleop::End() {
	Robot::driveTrain->StopMoving();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
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
