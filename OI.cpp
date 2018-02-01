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
    std::cout << "OI constructor finished." << std::endl;
}

std::shared_ptr<frc::XboxController> OI::get_joystick1() {
    return xbox_controller;
}
