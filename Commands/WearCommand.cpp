/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "WearCommand.h"
#include "../Robot.h"
#include "../Subsystems/WearSubsystem.h"

WearCommand::WearCommand() {
    // Use Requires() here to declare subsystem dependencies
    // eg. Requires(&Robot::chassis);
}

// Called just before this Command runs the first time
void WearCommand::Initialize() {
    wear_timer.Reset();
    wear_timer.Start();
    p = 1;
}

// Called repeatedly when this Command is scheduled to run
void WearCommand::Execute() {
    static int64_t change = wear_timer.Get() + (p == 0 ? 30 : 60);
    if (wear_timer.Get() > change) {
        p = p == 1 ? -1 : p + 1;
    }
    Robot::wear_subsystem->motorSet(p);
}

// Make this return true when this Command no longer needs to run execute()
bool WearCommand::IsFinished() {
    return wear_timer.Get() > 3600; // Run for 1 hour
}

// Called once after isFinished returns true
void WearCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WearCommand::Interrupted() {}
