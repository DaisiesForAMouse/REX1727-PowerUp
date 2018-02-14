#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <memory>
#include <iostream>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <TimedRobot.h>

#include "Commands/AutoCommand.hpp"
#include "Commands/DriveCommand.hpp"
#include "Commands/ArmCommand.hpp"
#include "Commands/IntakeCommand.hpp"
#include "Commands/RumbleCommand.hpp"
#include "Subsystems/DriveSubsystem.hpp"
#include "Subsystems/ArmSubsystem.hpp"
#include "Subsystems/IntakeSubsystem.hpp"
#include "RobotMap.hpp"
#include "OI.hpp"

class Robot : public frc::TimedRobot {
    public:
        std::shared_ptr<frc::Command> drive_command;
        std::shared_ptr<frc::Command> arm_command;
        std::shared_ptr<frc::Command> intake_command;
        std::shared_ptr<frc::Command> auto_command;
        std::shared_ptr<frc::Command> rumble_command;

        static std::unique_ptr<OI> oi;
        static std::unique_ptr<DriveSubsystem> drive_subsystem;
        static std::unique_ptr<ArmSubsystem> arm_subsystem;
        static std::unique_ptr<IntakeSubsystem> intake_subsystem;

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
