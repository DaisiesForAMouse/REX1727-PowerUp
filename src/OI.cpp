/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.hpp"

OI::OI() {
    std::cout << "OI constructor called..." << std::endl;
    xbox_controller = std::make_shared<frc::XboxController>(0);
    logitech_joy = std::make_shared<frc::Joystick>(1);
    std::cout << "OI constructor finished." << std::endl;
}

OI::~OI() {
}

std::shared_ptr<frc::XboxController> OI::GetXboxController() {
    return xbox_controller;
}

std::shared_ptr<frc::Joystick> OI::GetLogitech() {
    return logitech_joy;
}

void OI::SetLiveWindow() {
    auto lw = frc::LiveWindow::GetInstance();
    lw->Add(RobotMap::right_drive_dist_PID);
    lw->Add(RobotMap::left_drive_vel_PID);
}
