// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <string>

/**
 *
 *
 * @author Garrick Craft
 */

enum class Direction
{
	FORWARD,
	REVERSE
};

enum class DriveMotor
{
	TOP_LEFT,
	TOP_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_RIGHT,
	CENTER
};

class DriveTrain: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<SpeedController> topLeft;
	std::shared_ptr<SpeedController> topRight;
	std::shared_ptr<SpeedController> bottomLeft;
	std::shared_ptr<SpeedController> bottomRight;
	std::shared_ptr<SpeedController> center;
	Direction m_direction;

	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:

	DriveTrain();

	void InitDefaultCommand();

	void SetMotorSpeed(DriveMotor motor, double speed);

	void StopMoving();

	void ChangeDirection();

	void SetDirection(Direction direction);

	int GetDirection();

	std::string GetDirectionS();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
};

#endif
