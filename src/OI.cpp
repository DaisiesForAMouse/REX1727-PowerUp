/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.hpp"

OI::OI() {
    std::cout << "OI constructor called..." << std::endl;
    xbox_controller = std::make_shared<frc::XboxController>(0);
    logitech_joy = std::make_shared<frc::Joystick>(1);
    std::cout << "OI constructor finished." << std::endl;
}

OI::~OI() {
}

std::shared_ptr<frc::XboxController> OI::GetXboxController() const {
    return xbox_controller;
}

std::shared_ptr<frc::Joystick> OI::GetLogitech() const {
    return logitech_joy;
}

void OI::SetDashboard() {
    frc::SmartDashboard::PutData(
            "Left Vel PID", RobotMap::left_drive_vel_PID.get());
    frc::SmartDashboard::PutData(
            "Right Vel PID", RobotMap::right_drive_vel_PID.get());
    frc::SmartDashboard::PutData(
            "Left Drive Encoder", RobotMap::left_drive_enc.get());
    frc::SmartDashboard::PutData(
            "Right Drive Encoder", RobotMap::right_drive_enc.get());
    frc::SmartDashboard::PutNumber(
            "Left Encoder Rate", RobotMap::left_drive_enc->GetRate());
    frc::SmartDashboard::PutNumber(
            "Right Encoder Rate", -RobotMap::right_drive_enc->GetRate());
    frc::SmartDashboard::PutNumber(
            "Difference",
            RobotMap::left_drive_enc->GetDistance() + RobotMap::right_drive_enc->GetDistance());
    frc::SmartDashboard::PutNumber(
            "Velocity Difference",
            RobotMap::left_drive_enc->GetRate() + RobotMap::right_drive_enc->GetRate());
    frc::SmartDashboard::PutBoolean(
            "Arm Raised",
            RobotMap::arm_solenoid->Get() == frc::DoubleSolenoid::kForward ? true : false);
    frc::SmartDashboard::PutBoolean(
            "Intake Out",
            RobotMap::arm_solenoid->Get() == frc::DoubleSolenoid::kForward ? true : false);
    frc::SmartDashboard::PutBoolean(
            "Compressor On", RobotMap::compressor->Enabled());
}

void OI::LifeCamThread() {
    auto server = frc::CameraServer::GetInstance();
    auto cam = server->StartAutomaticCapture();
    cam.SetResolution(640, 480);
    cam.SetFPS(15);
    auto sink = server->GetVideo();
    auto output_stream = server->PutVideo("MS LifeCam", 640, 480);
    cv::Mat source;
    cv::Mat output;
    while (true) {
        if (!sink.GrabFrame(source)) {
            output_stream.PutFrame(output);
        }
        else {
            output_stream.PutFrame(source);
        }
    }
}

void OI::StartCameras() {
    std::thread life_cam_thread(LifeCamThread);
    life_cam_thread.detach();
}
