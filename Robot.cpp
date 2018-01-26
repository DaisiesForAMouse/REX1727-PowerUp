/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.hpp"

std::shared_ptr<DriveSubsystem> Robot::drive_subsystem;
std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit() {
    //chooser.AddDefault("Default Auto", auto_command);
    //frc::SmartDashboard::PutData("Auto Modes", &chooser);
    RobotMap::init();
    oi = std::make_unique<OI>();
    auto_command = nullptr;
    drive_subsystem = std::make_shared<DriveSubsystem>();
}

/**
 * This function is called once each time the robot enters Disabled
 * mode.
 * You can use it to reset any subsystem information you want to clear
 * when
 * the robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {
    frc::Scheduler::GetInstance()->Run();
}

/**
 * This autonomous (along with the chooser code above) shows how to
 * select
 * between different autonomous modes using the dashboard. The sendable
 * chooser code works with the Java SmartDashboard. If you prefer the
 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
 * GetString code to get the auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to
 * the
 * chooser code above (like the commented example) or additional
 * comparisons
 * to the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit() {
    //std::string autoSelected = frc::SmartDashboard::GetString(
              //"Auto Selector", "Default");
    if (auto_command != nullptr) {
         auto_command->Start();
    }
}

void Robot::AutonomousPeriodic() {
    frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
    // This makes sure that the autonomous stops running when
    // teleop starts running. If you want the autonomous to
    // continue until interrupted by another command, remove
    // this line or comment it out.
    if (auto_command != nullptr) {
        auto_command->Cancel();
        auto_command = nullptr;
    }
    if (drive_command != nullptr) {
        drive_command->Start();
    }
}

void Robot::TeleopPeriodic() {
    frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {}

START_ROBOT_CLASS(Robot)
