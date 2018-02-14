/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef OI_HPP
#define OI_HPP

#include <iostream>
#include <functional>

#include <XboxController.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/Sendable.h>

#include "RobotMap.hpp"

class OI {
    public:
        OI();
        ~OI();
        std::shared_ptr<frc::XboxController> GetXboxController();
        void SetLiveWindow();
    private:
        static void DestroyWindow(frc::LiveWindow*);
        std::shared_ptr<frc::XboxController> xbox_controller;
};

#endif
