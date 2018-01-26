/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.hpp"

OI::OI() {
    std::cout << "OI constructor called...";
    joystick1 = std::make_shared<frc::Joystick>(0);
    std::cout << "OI constrcutor finished.";
}

std::shared_ptr<frc::Joystick> OI::get_joystick1() {
    return joystick1;
}
