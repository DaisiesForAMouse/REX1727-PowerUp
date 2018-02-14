#ifndef ARM_COMMAND_HPP
#define ARM_COMMAND_HPP

#include "Commands/Command.h"
#include "../Robot.hpp"

class ArmCommand : public frc::Command {
    public:
        ArmCommand();

        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
};

#endif
