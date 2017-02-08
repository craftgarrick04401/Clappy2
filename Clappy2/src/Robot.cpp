#include "Robot.h"

std::shared_ptr<DriveTrain> Robot::driveTrain;
std::shared_ptr<GearPCM> Robot::gearPCM;
std::shared_ptr<GearArm> Robot::gearArm;
std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit() {
	RobotMap::init();

    driveTrain.reset(new DriveTrain());
    gearPCM.reset(new GearPCM());
    gearArm.reset(new GearArm());
	oi.reset(new OI());

	autonomousCommand.reset(new AutonomousCommand());

  }

void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {

	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();

	driveTrain->SetDirection(Direction::FORWARD);
	gearPCM->StartCompressor();

}

void Robot::TeleopPeriodic() {

	Scheduler::GetInstance()->Run();
	SmartDashboard::PutNumber("Top Left Motor", RobotMap::driveTrainTopLeft->Get());
	SmartDashboard::PutNumber("Top Right Motor", RobotMap::driveTrainTopRight->Get());
	SmartDashboard::PutNumber("Bottom Left Motor", RobotMap::driveTrainTopRight->Get());
	SmartDashboard::PutNumber("Bottom Right Motor", RobotMap::driveTrainTopRight->Get());
	SmartDashboard::PutNumber("Center Motor", RobotMap::driveTrainTopRight->Get());
	SmartDashboard::PutString("Robot Direction", driveTrain->GetDirectionS());
	SmartDashboard::PutString("GearPCM Status", gearPCM->GetPCMStatusS());
	SmartDashboard::PutString("GearArm", gearArm->GetPositionS());

}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

