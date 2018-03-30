/*
 * VelocityTuningCommand.h
 *
 *  Created on: Mar 19, 2018
 *      Author: anton
 */

#pragma once

#include <vector>

#include <Commands/Command.h>
#include "../Robot.hpp"

class VelocityTuningCommand: public frc::Command {
    public:
        VelocityTuningCommand();
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End() override;
        void Interrupted() override;
    private:
        std::vector<double> left_pid_vals;
        std::vector<double> right_pid_vals;
};
