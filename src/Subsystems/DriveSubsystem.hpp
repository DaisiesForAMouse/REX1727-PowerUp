#ifndef DRIVE_SUBSYSTEM_HPP
#define DRIVE_SUBSYSTEM_HPP


#include <Commands/Subsystem.h>
#include <Drive/DifferentialDrive.h>
#include <Spark.h>

#include "../RobotMap.hpp"

class DriveSubsystem: public frc::Subsystem {
    public:
        DriveSubsystem();
        void InitDefaultCommand() override;
        void Periodic() override;
        void SetDriveRaw(double left, double right, bool squared = true);
    private:
        std::shared_ptr<frc::Spark> left_drive;
        std::shared_ptr<frc::Spark> right_drive;
        std::shared_ptr<frc::DifferentialDrive> tank_drive;
        std::shared_ptr<frc::PIDController> left_drive_vel_PID;
        std::shared_ptr<frc::PIDController> right_drive_vel_PID;
        std::shared_ptr<frc::PIDController> left_drive_dist_PID;
        std::shared_ptr<frc::PIDController> right_drive_dist_PID;
        std::shared_ptr<frc::Encoder> left_drive_enc;
        std::shared_ptr<frc::Encoder> right_drive_enc;
};

#endif
