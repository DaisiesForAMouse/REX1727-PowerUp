#pragma once

#include <cmath>

#include <Commands/Command.h>

#include "../../Robot.hpp"

class DistanceCommand : public frc::Command {
    public:
        DistanceCommand(double);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
    private:
        double dist;
        double p;
        double const start_l;
        double const start_r;
};
