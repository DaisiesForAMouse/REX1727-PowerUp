#ifndef DRIVE_COMMAND_HPP
#define DRIVE_COMMAND_HPP

#include "Commands/Command.h"
#include "../Robot.hpp"

class DriveCommand: public frc::Command {
    public:
        DriveCommand();

        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
};

#endif
