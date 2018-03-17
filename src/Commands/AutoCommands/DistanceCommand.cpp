#include "DistanceCommand.hpp"

DistanceCommand::DistanceCommand(double d) :
        frc::Command("Drive Command"),
        start_l(Robot::drive_subsystem->GetEncDist(DriveSubsystem::left)),
        start_r(Robot::drive_subsystem->GetEncDist(DriveSubsystem::right)) {

    Requires(Robot::drive_subsystem.get());
    dist = d;
    p = dist < 0 ? -1 : 1;
}

void DistanceCommand::Initialize() {
}

void DistanceCommand::Execute() {
    Robot::drive_subsystem->SetDriveRaw(p, p, false);
}

bool DistanceCommand::IsFinished() {
    double left = std::abs(Robot::drive_subsystem->GetEncDist(DriveSubsystem::left)) - start_l;
    double right = std::abs(Robot::drive_subsystem->GetEncDist(DriveSubsystem::right)) - start_r;
    return  left > std::abs(dist) && right > std::abs(dist);
}

void DistanceCommand::End() {
    Robot::drive_subsystem->SetDriveRaw(0, 0, false);
}

void DistanceCommand::Interrupted() {
    Robot::drive_subsystem->SetDriveRaw(0, 0, false);
}
