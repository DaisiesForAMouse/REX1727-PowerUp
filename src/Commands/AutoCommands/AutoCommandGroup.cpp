#include "AutoCommandGroup.hpp"

AutoCommandGroup::AutoCommandGroup(std::string&& info, char c):
        frc::CommandGroup("Auto Group"),
        position(c),
        switch_pos(info[0]) {

    AddParallel(new DeployCommand());
    AddSequential(new DistanceCommand(107,36));

    if (position == switch_pos)
        AddSequential(new DropCommand());

    /* AddSequential(new TurnCommand(90, 36, TurnCommand::left)); */
}

void AutoCommandGroup::Initialize() {
}

void AutoCommandGroup::Execute() {
}

bool AutoCommandGroup::IsFinished() {
    return false;
}

void AutoCommandGroup::Interrupted() {
}

void AutoCommandGroup::End() {
}
