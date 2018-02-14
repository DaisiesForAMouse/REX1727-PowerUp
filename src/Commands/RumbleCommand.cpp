#include "RumbleCommand.hpp"

RumbleCommand::RumbleCommand() {
}

void RumbleCommand::Initialize() {};

void RumbleCommand::Execute() {
    auto joy = Robot::oi->GetXboxController();
    auto pdp = RobotMap::pdp;
    double curr = pdp->GetTotalCurrent();
    double avg = 0;
    currents.pop_front();
    currents.push_back(curr);
    for (auto& d : currents) {
        avg += d;
    }
    avg /= 10;
    joy->SetRumble(frc::GenericHID::RumbleType::kLeftRumble, std::abs((curr - avg) / 75));
    joy->SetRumble(frc::GenericHID::RumbleType::kRightRumble, std::abs((curr - avg) / 75));
};

bool RumbleCommand::IsFinished() {
    return false;
};

void RumbleCommand::End() {};

void RumbleCommand::Interrupted() {};
