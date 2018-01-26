#include "DriveCommand.hpp"

DriveCommand::DriveCommand() : frc::Command() {

}

void DriveCommand::Initialize() {
    std::cout << "DriveCommand initialized.";
}

void DriveCommand::Execute() {
	std::cout << "DriveCommand executing...";
    auto joy = Robot::oi->get_joystick1();
    Robot::drive_subsystem->set_drive_raw(joy->GetRawAxis(1),
                                          joy->GetRawAxis(5));
}

bool DriveCommand::IsFinished() {
    return false;
}

void DriveCommand::End() {

}

void DriveCommand::Interrupted() {

}
