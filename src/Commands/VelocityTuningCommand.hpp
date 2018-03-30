/*
 * VelocityTuningCommand.h
 *
 *  Created on: Mar 19, 2018
 *      Author: anton
 */

#pragma once

#include <array>

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
};
