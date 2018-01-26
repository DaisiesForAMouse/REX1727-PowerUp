#ifndef DRIVE_SUBSYSTEM_HPP
#define DRIVE_SUBSYSTEM_HPP


#include "Commands/Subsystem.h"
#include "Drive/DifferentialDrive.h"
#include "Spark.h"

#include "../RobotMap.hpp"

class DriveSubsystem: public frc::Subsystem {
    public:
        DriveSubsystem();
        void InitDefaultCommand() override;
        void Periodic() override;
        void set_drive(double, double);
    private:
        std::shared_ptr<frc::Spark> left_drive;
        std::shared_ptr<frc::Spark> right_drive;
        std::shared_ptr<frc::DifferentialDrive> tank_drive;
};

#endif
