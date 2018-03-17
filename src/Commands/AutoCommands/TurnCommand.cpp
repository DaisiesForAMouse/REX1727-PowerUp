#include "TurnCommand.hpp"

TurnCommand::TurnCommand(double d) :
        frc::Command("Turn Command"),
        start_l(Robot::drive_subsystem->GetEncDist(DriveSubsystem::left)),
        start_r(Robot::drive_subsystem->GetEncDist(DriveSubsystem::right)) {
    Requires(Robot::drive_subsystem.get());
    constexpr double pi = 3.14159265358979323846;
    deg = d;
    dist = 24 * pi * (deg / 360);

    p = deg < 0 ? 0.5 : -0.5;
}

void TurnCommand::Initialize() {
}

void TurnCommand::Execute() {
    Robot::drive_subsystem->SetDriveRaw(p, -p, false);
}

bool TurnCommand::IsFinished() {
    double left = std::abs(Robot::drive_subsystem->GetEncDist(DriveSubsystem::left)) - start_l;
    double right = std::abs(Robot::drive_subsystem->GetEncDist(DriveSubsystem::right)) - start_r;
    return  left > std::abs(dist) && right > std::abs(dist);
}

void TurnCommand::End() {
    Robot::drive_subsystem->SetDriveRaw(0, 0, false);
}

void TurnCommand::Interrupted() {
    Robot::drive_subsystem->SetDriveRaw(0, 0, false);
}
