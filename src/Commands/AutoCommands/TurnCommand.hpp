#pragma once

#include <cmath>

#include <Commands/Command.h>

#include "../../Robot.hpp"

class TurnCommand : public frc::Command {
    public:
        TurnCommand(double);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
    private:
        double dist;
        double deg;
        double p;
        double const start_l;
        double const start_r;
};
