#ifndef INTAKE_COMMAND_HPP
#define INTAKE_COMMAND_HPP

#include <Commands/Command.h>

#include "../Robot.hpp"
#include "../Subsystems/IntakeSubsystem.hpp"

class IntakeCommand : public frc::Command {
    public:
        IntakeCommand();

        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
};

#endif
