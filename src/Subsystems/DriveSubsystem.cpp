#include "DriveSubsystem.hpp"

DriveSubsystem::DriveSubsystem() : frc::Subsystem("DriveSubsystem") {
    std::cout << "DriveSubsystem constructor called ..." << std::endl;
    left_drive = RobotMap::left_drive;
    right_drive = RobotMap::right_drive;
    tank_drive = RobotMap::tank_drive;
    left_drive_vel_PID = RobotMap::left_drive_vel_PID;
    left_drive_vel_PID->Disable();
    right_drive_vel_PID = RobotMap::right_drive_vel_PID;
    right_drive_vel_PID->Disable();
    left_drive_dist_PID = RobotMap::left_drive_dist_PID;
    left_drive_dist_PID->Disable();
    right_drive_dist_PID = RobotMap::right_drive_dist_PID;
    right_drive_dist_PID->Disable();
    left_drive_enc = RobotMap::left_drive_enc;
    right_drive_enc = RobotMap::right_drive_enc;
    std::cout << "DriveSubsystem constructor ended." << std::endl;
}

void DriveSubsystem::SetDriveRaw(double left, double right, bool squared) {
    tank_drive->TankDrive(-left, -right, squared);
}

void DriveSubsystem::InitDefaultCommand() {
}

void DriveSubsystem::Periodic() {
}
