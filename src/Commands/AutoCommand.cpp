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
void AutoCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AutoCommand::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool AutoCommand::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void AutoCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCommand::Interrupted() {}
