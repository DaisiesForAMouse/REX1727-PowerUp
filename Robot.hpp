#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <memory>
#include <iostream>

#include "Commands/Command.h"
#include "Commands/Scheduler.h"
#include "LiveWindow/LiveWindow.h"
#include "SmartDashboard/SendableChooser.h"
#include "SmartDashboard/SmartDashboard.h"
#include "TimedRobot.h"

#include "Commands/DriveCommand.hpp"
#include "Commands/AutoCommand.hpp" 
#include "Subsystems/DriveSubsystem.hpp"
#include "RobotMap.hpp"
#include "OI.hpp"

class Robot : public frc::TimedRobot {
    public:
        DriveCommand drive_command;
        AutoCommand auto_command;

        static std::unique_ptr<OI> oi;
        static std::shared_ptr<DriveSubsystem> drive_subsystem;

        void RobotInit() override;
        void DisabledInit() override;
        void DisabledPeriodic() override;
        void AutonomousInit() override;
        void AutonomousPeriodic() override;
        void TeleopInit() override;
        void TeleopPeriodic() override;
        void TestPeriodic() override;
};

#endif
