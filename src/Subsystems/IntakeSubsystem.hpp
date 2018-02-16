#ifndef INTAKE_SUBSYSTEM_HPP
#define INTAKE_SUBSYSTEM_HPP

#include <iostream>

#include <Commands/Subsystem.h>
#include <Spark.h>
#include <Timer.h>

#include "../RobotMap.hpp"

class IntakeSubsystem : public frc::Subsystem {
    public:
        enum IntakeAction {intake, outtake, off};
        enum PostionAction {deploy = true, grip = false};
        IntakeSubsystem();
        void InitDefaultCommand() override;
        void Periodic() override;
        void Deploy();
        void Toggle();
        void SetPosition(PostionAction);
        void SetIntake(IntakeAction);
        void SetIntake(double);
    private:
        std::shared_ptr<frc::Spark> left_external_intake;
        std::shared_ptr<frc::Spark> right_external_intake;
        std::shared_ptr<frc::DoubleSolenoid> intake_solenoid;
        bool opened;
};

#endif
