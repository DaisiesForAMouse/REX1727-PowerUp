/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef OI_HPP
#define OI_HPP

#include <iostream>

#include <XboxController.h>

class OI {
    public:
        OI();
        std::shared_ptr<frc::XboxController> get_joystick1();
    private:
        std::shared_ptr<frc::XboxController> xbox_controller;
};

#endif
