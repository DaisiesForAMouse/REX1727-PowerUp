/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef ROBOT_MAP_HPP
#define ROBOT_MAP_HPP

#include <memory>
#include <iostream>
#include <cmath>

#include <Drive/DifferentialDrive.h>
#include <Spark.h>
#include <Encoder.h>
#include <PIDController.h>
#include <DoubleSolenoid.h>
#include <VictorSP.h>
#include <PowerDistributionPanel.h>
#include <Compressor.h>
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

namespace ctre {
    typedef ctre::phoenix::motorcontrol::can::TalonSRX CANTalonSRX;
}

class RobotMap {
    public:
        static std::shared_ptr<frc::Spark> left_drive;
        static std::shared_ptr<frc::Spark> right_drive;
        static std::shared_ptr<frc::Encoder> left_drive_enc;
        static std::shared_ptr<frc::Encoder> right_drive_enc;
        static std::shared_ptr<frc::DifferentialDrive> tank_drive;
        static std::shared_ptr<frc::PIDController> left_drive_vel_PID;
        static std::shared_ptr<frc::PIDController> left_drive_dist_PID;
        static std::shared_ptr<frc::PIDController> right_drive_vel_PID;
        static std::shared_ptr<frc::PIDController> right_drive_dist_PID;
        static std::shared_ptr<frc::VictorSP> left_climber;
        static std::shared_ptr<frc::VictorSP> right_climber;
        static std::shared_ptr<frc::DoubleSolenoid> arm_solenoid;
        static std::shared_ptr<ctre::CANTalonSRX> left_internal_intake;
        static std::shared_ptr<ctre::CANTalonSRX> right_internal_intake;
        static std::shared_ptr<frc::Spark> left_external_intake;
        static std::shared_ptr<frc::Spark> right_external_intake;
        static std::shared_ptr<frc::PowerDistributionPanel> pdp;
        static std::shared_ptr<frc::Compressor> compressor;

        static void init();
};

#endif
