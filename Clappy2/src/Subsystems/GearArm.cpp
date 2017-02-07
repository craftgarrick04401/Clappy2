#include "GearArm.h"
#include "../RobotMap.h"

GearArm::GearArm() : Subsystem("GearArm") {

	std::shared_ptr<SpeedController> motor = RobotMap::gearArmMotor;
	std::shared_ptr<Encoder> encoder = RobotMap::gearArmEncoder;

}

void GearArm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
