#ifndef CUBE_COMMAND_HPP
#define CUBE_COMMAND_HPP

#include "Commands/Command.h"
#include "../Robot.hpp"
#include "../Subsystems/ArmSubsystem.hpp"
#include "../Subsystems/IntakeSubsystem.hpp"

class CubeCommand : public frc::Command {
    public:
        CubeCommand();

        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
};

#endif
