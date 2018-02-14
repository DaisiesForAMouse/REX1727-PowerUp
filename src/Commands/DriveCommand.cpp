#include "DriveCommand.hpp"

DriveCommand::DriveCommand() : frc::Command() {
    Requires(Robot::drive_subsystem.get());
}

void DriveCommand::Initialize() {
    currents.resize(10);
    currents.shrink_to_fit();
    for (auto it = currents.begin(); it != currents.end(); ++it) {
        *it = 0;
    }
    std::cout << "DriveCommand initialized.";
}

void DriveCommand::Execute() {
    auto joy = Robot::oi->GetXboxController();
    Robot::drive_subsystem->SetDriveRaw(
            joy->GetY(frc::GenericHID::kLeftHand),
            joy->GetY(frc::GenericHID::kRightHand));
}

bool DriveCommand::IsFinished() {
    return false;
}

void DriveCommand::End() {
}

void DriveCommand::Interrupted() {
}
