#include "GearPCM.h"
#include "../RobotMap.h"

GearPCM::GearPCM() : Subsystem("GearPCM") {

	compressor = RobotMap::gearPCMCompressor;
	solenoid = RobotMap::gearPCMSolenoid;

}

void GearPCM::InitDefaultCommand() {

}

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
