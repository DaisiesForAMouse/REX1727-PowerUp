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
    auto xbox = Robot::oi->GetXboxController();

    constexpr auto right = frc::GenericHID::kRightHand;
    constexpr auto left = frc::GenericHID::kLeftHand;

    if (xbox->GetTriggerAxis(right) >= 0.25) {
        Robot::drive_subsystem->SetDriveRaw(
                xbox->GetY(left) * 0.4,
                xbox->GetY(right) * 0.4);
    } else {
        Robot::drive_subsystem->SetDriveRaw(
                xbox->GetY(left),
                xbox->GetY(right));
    }
}

bool DriveCommand::IsFinished() {
    return false;
}

void DriveCommand::End() {
}

void DriveCommand::Interrupted() {
}
