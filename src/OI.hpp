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
#include <Joystick.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/Sendable.h>

#include "RobotMap.hpp"

class OI {
    public:
        OI();
        ~OI();
        std::shared_ptr<frc::XboxController> GetXboxController();
        std::shared_ptr<frc::Joystick> GetLogitech();
        void SetLiveWindow();
    private:
        std::shared_ptr<frc::XboxController> xbox_controller;
        std::shared_ptr<frc::Joystick> logitech_joy;
};

#endif
