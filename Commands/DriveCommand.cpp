#include "DriveCommand.hpp"

DriveCommand::DriveCommand() : frc::Command() {

}

void DriveCommand::Initialize() {

}

void DriveCommand::Execute() {
    Robot::drive_subsystem->set_drive_raw(Robot::oi->get_joystick1()->GetRawAxis(1),
                                          Robot::oi->get_joystick1()->GetRawAxis(5));
}

bool DriveCommand::IsFinished() {
    return false;
}

void DriveCommand::End() {

}

void DriveCommand::Interrupted() {

}
