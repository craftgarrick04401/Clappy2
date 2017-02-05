#ifndef GearPCM_H
#define GearPCM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

enum class ArmStatus
{
	OPENED,
	CLOSED
};

class GearPCM : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	std::shared_ptr<Compressor> compressor;
	std::shared_ptr<Solenoid> solenoid;

public:
	GearPCM();
	void InitDefaultCommand();

	void SetGearArms(ArmStatus status);

	bool GetArmStatus();

	void StartCompressor();

	void StopCompressor();
};

#endif  // GearPCM_H
