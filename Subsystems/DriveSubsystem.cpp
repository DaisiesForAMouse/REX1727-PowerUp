#include "DriveSubsystem.hpp"

DriveSubsystem::DriveSubsystem() : frc::Subsystem("DriveSubsystem") {
    left_drive = RobotMap::left_drive;
    right_drive = RobotMap::right_drive;
    tank_drive = RobotMap::tank_drive;
}

void DriveSubsystem::set_drive(double left, double right) {
    tank_drive->TankDrive(left, right, true);
}

void DriveSubsystem::InitDefaultCommand() {
}

void DriveSubsystem::Periodic() {
}
