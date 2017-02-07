#include "GearPCM.h"
#include "../RobotMap.h"

GearPCM::GearPCM() : Subsystem("GearPCM") {

	compressor = RobotMap::gearPCMCompressor;
	solenoid = RobotMap::gearPCMSolenoid;

}

void GearPCM::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void GearPCM::SetGearPCM(PCMStatus status)
{
	solenoid->Set(static_cast<bool>(status));
}

bool GearPCM::GetPCMStatus()
{
	return solenoid->Get();
}

std::string GearPCM::GetPCMStatusS()
{
	if (solenoid->Get() == static_cast<bool>(PCMStatus::OPENED))
		return "Opened";
	else
		return "Closed";
}

void GearPCM::StartCompressor()
{
	compressor->Start();
}

void GearPCM::StopCompressor()
{
	compressor->Stop();
}
