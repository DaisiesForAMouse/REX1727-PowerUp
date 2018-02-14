/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef AUTO_COMMAND_HPP
#define AUTO_COMMAND_HPP

#include <Commands/Command.h>
#include "../Robot.hpp"

class AutoCommand : public frc::Command {
public:
    AutoCommand();
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End() override;
    void Interrupted() override;
};

#endif
