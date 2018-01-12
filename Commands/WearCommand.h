#pragma once

#include <Commands/Command.h>
#include <Timer.h>

class WearCommand : public frc::Command {
    public:
        WearCommand();
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
    private:
        double p;
        Timer wear_timer;
};
