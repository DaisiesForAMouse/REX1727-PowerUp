#include "IntakeCommand.hpp"

IntakeCommand::IntakeCommand() : frc::Command("IntakeCommand") {
    Requires(Robot::intake_subsystem.get());
}

void IntakeCommand::Initialize() {
}

void IntakeCommand::Execute() {
    auto joy = Robot::oi->GetXboxController();
    if (joy->GetXButton()) {
        Robot::intake_subsystem->SetIntake(IntakeSubsystem::intake);
    } if (joy->GetYButton()) {
        Robot::intake_subsystem->SetIntake(IntakeSubsystem::outtake);
    } else {
        Robot::intake_subsystem->SetIntake(IntakeSubsystem::off);
    }

    if (joy->GetBumperPressed(frc::GenericHID::kLeftHand)) {
        Robot::intake_subsystem->Toggle();
    }
}

bool IntakeCommand::IsFinished() {
    return false;
}

void IntakeCommand::End() {
}

void IntakeCommand::Interrupted() {
}
