#include "RobotMap.hpp"

std::shared_ptr<frc::Spark> RobotMap::left_drive = nullptr;
std::shared_ptr<frc::Spark> RobotMap::right_drive = nullptr;
std::shared_ptr<frc::DifferentialDrive> RobotMap::tank_drive = nullptr;

void RobotMap::init() {
    left_drive = std::make_shared<frc::Spark>(0);
    right_drive = std::make_shared<frc::Spark>(1);
    tank_drive = std::make_shared<frc::DifferentialDrive>(*left_drive, *right_drive);

    tank_drive->SetSafetyEnabled(true);
    tank_drive->SetExpiration(0.1);
    tank_drive->SetMaxOutput(1.0);
}