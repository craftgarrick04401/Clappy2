#ifndef GearPCM_H
#define GearPCM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <string>

/**
 *
 *
 * @author Garrick Craft
 */

enum class PCMStatus
{
	OPENED,
	CLOSED
};

class GearPCM : public Subsystem {
private:

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

#endif
