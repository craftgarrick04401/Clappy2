// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "../Commands/DriveTeleop.h"
#include "DriveTrain.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    topLeft = RobotMap::driveTrainTopLeft;
    //topRight = RobotMap::driveTrainTopRight;
    //bottomLeft = RobotMap::driveTrainBottomLeft;
    //bottomRight = RobotMap::driveTrainBottomRight;
    //center = RobotMap::driveTrainCenter;

    m_direction = Direction::FORWARD;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void DriveTrain::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
		SetDefaultCommand(new DriveTeleop());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void DriveTrain::SetMotorSpeed(DriveMotor motor, double speed)
{
	switch (motor)
	{
	case DriveMotor::TOP_LEFT:
	{
		DriveTrain::topLeft->Set(speed);
		break;
	}
	/*
	case DriveMotor::TOP_RIGHT:
	{
		DriveTrain::topRight->Set(speed);
		break;
	}
	case DriveMotor::BOTTOM_LEFT:
	{
		DriveTrain::bottomLeft->Set(speed);
		break;
	}
	case DriveMotor::BOTTOM_RIGHT:
	{
		DriveTrain::bottomRight->Set(speed);
		break;
	}
	case DriveMotor::CENTER:
	{
		DriveTrain::center->Set(speed);
		break;
	}
	*/
	}

}

void DriveTrain::StopMoving()
{
	DriveTrain::SetMotorSpeed(DriveMotor::TOP_LEFT, 0.0);
	//DriveTrain::SetMotorSpeed(DriveMotor::TOP_RIGHT, 0.0);
	//DriveTrain::SetMotorSpeed(DriveMotor::BOTTOM_LEFT, 0.0);
	//DriveTrain::SetMotorSpeed(DriveMotor::BOTTOM_RIGHT, 0.0);
	//DriveTrain::SetMotorSpeed(DriveMotor::CENTER, 0.0);


}

void DriveTrain::ChangeDirection()
{
	if (m_direction == Direction::FORWARD)
		m_direction = Direction::REVERSE;
	else
		m_direction = Direction::FORWARD;
}

int DriveTrain::GetDirection()
{
	return static_cast<int>(m_direction);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

