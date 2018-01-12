#pragma once

#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <TimedRobot.h>

#include "Commands/WearCommand.h"
#include "Subsystems/WearSubsystem.h"

class Robot : public frc::TimedRobot {
    public:
        void RobotInit() override;
        void DisabledInit() override;
        void DisabledPeriodic() override;
        void AutonomousInit() override;
        void AutonomousPeriodic() override;
        void TeleopInit() override;
        void TeleopPeriodic() override;
        void TestPeriodic() override;
        
        static std::unique_ptr<WearSubsystem> wear_subsystem;
    private:
        std::shared_ptr<frc::Command> auto_command;
        WearCommand wear_command;
        frc::SendableChooser<std::shared_ptr<frc::Command>> chooser;
};
