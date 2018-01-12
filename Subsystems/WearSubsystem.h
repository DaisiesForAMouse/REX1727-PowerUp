#pragma once

#include <memory>
#include <Commands/Subsystem.h>
#include <Spark.h>
#include "../RobotMap.h"

class WearSubsystem : public frc::Subsystem {
    public:
        WearSubsystem();
        void InitDefaultCommand() override;
        void motorSet(double);
    private:
        std::shared_ptr<Spark> test_left;
        std::shared_ptr<Spark> test_right;
};
