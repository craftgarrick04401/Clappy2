#ifndef GearPCM_H
#define GearPCM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <string>

enum class PCMStatus
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

	void SetGearPCM(PCMStatus status);

	bool GetPCMStatus();

	std::string GetPCMStatusS();

	void StartCompressor();

	void StopCompressor();
};

#endif  // GearPCM_H
