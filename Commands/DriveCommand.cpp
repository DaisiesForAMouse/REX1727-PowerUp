#include "DriveCommand.hpp"

DriveCommand::DriveCommand() : frc::Command() {

}

void DriveCommand::Initialize() {
    std::cout << "DriveCommand initialized.";
}

void DriveCommand::Execute() {
    auto joy = Robot::oi->get_joystick1();
    Robot::drive_subsystem->set_drive_raw(joy->GetY(frc::GenericHID::kLeftHand),
                                          joy->GetY(frc::GenericHID::kRightHand));
}

bool DriveCommand::IsFinished() {
    return false;
}

void DriveCommand::End() {

}

void DriveCommand::Interrupted() {

}
