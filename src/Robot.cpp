/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.hpp"

std::unique_ptr<OI> Robot::oi;
std::unique_ptr<DriveSubsystem> Robot::drive_subsystem;
std::unique_ptr<ArmSubsystem> Robot::arm_subsystem;
std::unique_ptr<IntakeSubsystem> Robot::intake_subsystem;
std::unique_ptr<ClimberSubsystem> Robot::climber_subsystem;

void Robot::RobotInit() {
    chooser.AddObject("Left", 'l');
    chooser.AddObject("Middle", 'm');
    chooser.AddObject("Right", 'r');
    frc::SmartDashboard::PutData("Starting position", &chooser);

    RobotMap::init();

    oi = std::make_unique<OI>();
    oi->SetDashboard();
    oi->StartCameras();

    drive_subsystem = std::make_unique<DriveSubsystem>();
    drive_command = std::make_shared<DriveCommand>();

    arm_subsystem = std::make_unique<ArmSubsystem>();
    intake_subsystem = std::make_unique<IntakeSubsystem>();
    cube_command = std::make_shared<CubeCommand>();

    climber_subsystem = std::make_unique<ClimberSubsystem>();
    climber_command = std::make_shared<ClimberCommand>();

    rumble_command = std::make_shared<RumbleCommand>();
}

/**
 * This function is called once each time the robot enters Disabled
 * mode.
 * You can use it to reset any subsystem information you want to clear
 * when
 * the robot is disabled.
 */
void Robot::DisabledInit() {
}

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
 * to the if-else structure frbelow with additional strings & commands.
 */
void Robot::AutonomousInit() {
    char position = chooser.GetSelected();
    std::string game_data = frc::DriverStation::GetInstance().GetGameSpecificMessage();

    std::transform(game_data.begin(), game_data.end(), game_data.begin(), ::tolower);

    auto_command_grp = std::make_shared<AutoCommandGroup>(
            std::move(game_data), std::move(position));

    if (false)
        auto_command_grp->Start();

    RobotMap::ResetEncoders();
}

void Robot::AutonomousPeriodic() {
    frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
    RobotMap::ResetEncoders();
    auto_command_grp->Cancel();
    drive_command->Start();
    cube_command->Start();
    rumble_command->Start();
}

void Robot::TeleopPeriodic() {
    frc::Scheduler::GetInstance()->Run();
    /* std::cout << RobotMap::left_drive_enc->Get() << '\t' */
    /*           << RobotMap::right_drive_enc->Get() << std::endl; */
    oi->SetDashboard();
}

void Robot::TestPeriodic() {
}

START_ROBOT_CLASS(Robot)
