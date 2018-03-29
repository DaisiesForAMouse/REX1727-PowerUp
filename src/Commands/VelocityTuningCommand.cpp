/*
 * VelocityTuningCommand.cpp
 *
 *  Created on: Mar 19, 2018
 *      Author: anton
 */

#include "VelocityTuningCommand.hpp"

VelocityTuningCommand::VelocityTuningCommand() {
    Requires(Robot::drive_subsystem.get());
}


void VelocityTuningCommand::Initialize() {
    RobotMap::right_drive_enc->Reset();
    RobotMap::left_drive_enc->Reset();
    RobotMap::right_drive_vel_PID->Reset();
    RobotMap::left_drive_vel_PID->Reset();
    RobotMap::right_drive_vel_PID->SetPID(.0005,0.001,0,1/84.3);
    RobotMap::left_drive_vel_PID->SetPID(.0005,0.001,0,1/84.3);
    RobotMap::right_drive_vel_PID->SetSetpoint(-36);
    RobotMap::left_drive_vel_PID->SetSetpoint(36);
    RobotMap::right_drive_vel_PID->Enable();
    RobotMap::left_drive_vel_PID->Enable();
}

void VelocityTuningCommand::Execute() {
    std::cout << RobotMap::left_drive_enc->GetRate() << '\t'
        << RobotMap::right_drive_enc->GetRate() << std::endl;
}
bool VelocityTuningCommand::IsFinished() {
    return false;
}

void VelocityTuningCommand::End() {

}
void VelocityTuningCommand::Interrupted() {

}
