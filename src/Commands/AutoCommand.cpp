/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoCommand.hpp"

AutoCommand::AutoCommand() {
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(&Robot::chassis);
    Requires(Robot::arm_subsystem.get());
    Requires(Robot::drive_subsystem.get());
    Requires(Robot::intake_subsystem.get());
}

// Called just before this Command runs the first time
void AutoCommand::Initialize() {
    constexpr double kldP = 1.0;
    constexpr double kldI = 0.0;
    constexpr double kldD = 0.0;
    constexpr double krdP = 1.0;
    constexpr double krdI = 0.0;
    constexpr double krdD = 0.0;

    RobotMap::left_drive_dist_PID->SetP(kldP);
    RobotMap::left_drive_dist_PID->SetI(kldI);
    RobotMap::left_drive_dist_PID->SetD(kldD);
    RobotMap::right_drive_dist_PID->SetP(krdP);
    RobotMap::right_drive_dist_PID->SetI(krdI);
    RobotMap::right_drive_dist_PID->SetD(krdD);

    constexpr double klrP = 1.0;
    constexpr double klrI = 0.0;
    constexpr double klrD = 0.0;
    constexpr double krrP = 1.0;
    constexpr double krrI = 0.0;
    constexpr double krrD = 0.0;

    RobotMap::left_drive_dist_PID->SetP(klrP);
    RobotMap::left_drive_dist_PID->SetI(klrI);
    RobotMap::left_drive_dist_PID->SetD(klrD);
    RobotMap::right_drive_dist_PID->SetP(krrP);
    RobotMap::right_drive_dist_PID->SetI(krrI);
    RobotMap::right_drive_dist_PID->SetD(krrD);
}

// Called repeatedly when this Command is scheduled to run
void AutoCommand::Execute() {
    //RobotMap::left_drive_dist_PID->Enable();
}

// Make this return true when this Command no longer needs to run execute()
bool AutoCommand::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void AutoCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCommand::Interrupted() {}
