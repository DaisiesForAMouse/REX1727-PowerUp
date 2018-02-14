#include "ArmCommand.hpp"

ArmCommand::ArmCommand() : frc::Command("ArmCommand") {
    Requires(Robot::arm_subsystem.get());
}

void ArmCommand::Initialize() {
    std::cout << "ArmCommand initialized.";
}

void ArmCommand::Execute() {
    auto joy = Robot::oi->GetXboxController();

    if (joy->GetBumperPressed(frc::GenericHID::kRightHand)) {
        Robot::arm_subsystem->Toggle();
    }

    if (joy->GetAButton()) {
        Robot::arm_subsystem->SetIntake(ArmSubsystem::intake);
    } else if (joy->GetBButton()) {
        Robot::arm_subsystem->SetIntake(ArmSubsystem::outtake);
    } else {
        Robot::arm_subsystem->SetIntake(0);
    }
}

bool ArmCommand::IsFinished() {
    return false;
}

void ArmCommand::End() {
}

void ArmCommand::Interrupted() {
}
