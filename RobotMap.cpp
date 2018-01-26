#include "RobotMap.hpp"

std::shared_ptr<frc::Spark> RobotMap::left_drive;
std::shared_ptr<frc::Spark> RobotMap::right_drive;
std::shared_ptr<frc::DifferentialDrive> RobotMap::tank_drive;
std::shared_ptr<frc::Encoder> RobotMap::left_drive_enc;
std::shared_ptr<frc::Encoder> RobotMap::right_drive_enc;

void RobotMap::init() {
    std::cout << "Starting RobotMap::init() ...";
    left_drive = std::make_shared<frc::Spark>(0);
    right_drive = std::make_shared<frc::Spark>(1);

    tank_drive = std::make_shared<frc::DifferentialDrive>(*left_drive, *right_drive);
//    tank_drive->SetSafetyEnabled(true);
//    tank_drive->SetExpiration(0.1);
//    tank_drive->SetMaxOutput(1.0);

    left_drive_enc = std::make_shared<frc::Encoder>(0, 1, true);
    right_drive_enc = std::make_shared<frc::Encoder>(2, 3, false);
    std::cout << "RobotMap::init ended.";
}
