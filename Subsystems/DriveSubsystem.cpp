#include "DriveSubsystem.hpp"

DriveSubsystem::DriveSubsystem() : frc::Subsystem("DriveSubsystem") {
    left_drive = RobotMap::left_drive;
    right_drive = RobotMap::right_drive;
    tank_drive = RobotMap::tank_drive;
}

void DriveSubsystem::set_drive_raw(double left, double right, bool squared) {
    tank_drive->TankDrive(left, right, squared);
}

void DriveSubsystem::InitDefaultCommand() {
}

void DriveSubsystem::Periodic() {
}
