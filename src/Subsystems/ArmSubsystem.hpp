#ifndef ARM_SUBSYSTEM_HPP
#define ARM_SUBSYSTEM_HPP

#include <Commands/Subsystem.h>
#include <DoubleSolenoid.h>
#include <VictorSP.h>

#include "../RobotMap.hpp"

class ArmSubsystem : public frc::Subsystem {
    public:
        enum IntakeAction {off, intake, outtake};
        enum ArmAction {lift = true, drop = false};

        ArmSubsystem();
        void InitDefaultCommand() override;
        void Periodic() override;
        void Toggle();
        void SetArm(ArmAction);
        void SetIntake(IntakeAction);
        void SetIntake(double);
        bool GetRaised();
    private:
        std::shared_ptr<frc::DoubleSolenoid> arm_solenoid;
        std::shared_ptr<ctre::CANTalonSRX> left_internal_intake;
        std::shared_ptr<ctre::CANTalonSRX> right_internal_intake;
        bool raised;
};

#endif
