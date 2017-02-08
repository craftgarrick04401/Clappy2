#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/DriveTeleop.h"
#include "Commands/ToggleGearPCM.h"
#include "Commands/ToggleRobotDirection.h"

OI::OI() {

    driveStick.reset(new Joystick(0));
    gearStick.reset(new Joystick(1));
    
    controlSwitchButton.reset(new JoystickButton(driveStick.get(), 1));
    controlSwitchButton->WhenPressed(new ToggleRobotDirection());

    toggleGearPCMButton.reset(new JoystickButton(gearStick.get(), 1));
    toggleGearPCMButton->WhenPressed(new ToggleGearPCM());

}

std::shared_ptr<Joystick> OI::getDriveStick() {
   return driveStick;
}

std::shared_ptr<Joystick> OI::getGearStick()
{
	return gearStick;
}

