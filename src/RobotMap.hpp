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

#include <Drive/DifferentialDrive.h>
#include <Spark.h>
#include <Encoder.h>
#include <ctre/phoenix/MotorControl/CAN/TalonSRX.h>

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;

class RobotMap {
    public:
        static std::shared_ptr<frc::Spark> left_drive;
        static std::shared_ptr<frc::Spark> right_drive;
        static std::shared_ptr<frc::DifferentialDrive> tank_drive;
        static std::shared_ptr<frc::Encoder> left_drive_enc;
        static std::shared_ptr<frc::Encoder> right_drive_enc;
        static std::shared_ptr<ctre::phoenix::motorcontrol::can::TalonSRX> left_climber;
        static std::shared_ptr<ctre::phoenix::motorcontrol::can::TalonSRX> right_climber;
        static void init();
};

#endif