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
    /* RobotMap::right_drive_vel_PID->SetPID(.0000, 0.00, 0, 1/84.3); */
    /* RobotMap::left_drive_vel_PID->SetPID(.0000, 0.00, 0, 1/84.3); */
    /* RobotMap::right_drive_vel_PID->SetPID(.0001331, 0.000146, 0, 0); */
    /* RobotMap::left_drive_vel_PID->SetPID(.0000, 0.000146, 0, 0); */
    RobotMap::right_drive_vel_PID->SetPID(0, 0, 0, 0);
    RobotMap::left_drive_vel_PID->SetPID(0, 0, 0, 0);
    RobotMap::right_drive_vel_PID->SetSetpoint(-36);
    RobotMap::left_drive_vel_PID->SetSetpoint(36);
    RobotMap::right_drive_vel_PID->Enable();
    RobotMap::left_drive_vel_PID->Enable();
}

void VelocityTuningCommand::Execute() {
    std::cout << RobotMap::left_drive_enc->GetRate() << '\t'
              << RobotMap::right_drive_enc->GetRate() << '\t'
              << RobotMap::left_drive_vel_PID->GetP() << '\t'
              << RobotMap::left_drive_vel_PID->GetI() << std::endl;

    auto xbox = Robot::oi->GetXboxController();

    char pick = true;

    if (xbox->GetBButtonPressed()) {
        double val = RobotMap::left_drive_vel_PID->GetP();
        if (val == 0)
            val = 0.0001;
        if (pick)
            RobotMap::left_drive_vel_PID->SetP(val*1.1);
        else
            RobotMap::left_drive_vel_PID->SetP(val*0.9);
    } else if (xbox->GetAButtonPressed()) {
        double val = RobotMap::left_drive_vel_PID->GetI();
        if (pick)
            RobotMap::left_drive_vel_PID->SetI(val*1.1);
        else
            RobotMap::left_drive_vel_PID->SetI(val*0.9);
    } else if (xbox->GetXButtonPressed()) {
        double val = RobotMap::left_drive_vel_PID->GetP();
        if (pick)
            RobotMap::right_drive_vel_PID->SetP(val*1.1);
        else
            RobotMap::right_drive_vel_PID->SetP(val*0.9);
    } else if (xbox->GetYButtonPressed()) {
        double val = RobotMap::right_drive_vel_PID->GetI();
        if (pick)
            RobotMap::right_drive_vel_PID->SetI(val*1.1);
        else
            RobotMap::right_drive_vel_PID->SetI(val*0.9);
    } else if (xbox->GetStartButtonPressed()) {
        pick = !pick;
    }
}

bool VelocityTuningCommand::IsFinished() {
    return false;
}

void VelocityTuningCommand::End() {

}
void VelocityTuningCommand::Interrupted() {

}
