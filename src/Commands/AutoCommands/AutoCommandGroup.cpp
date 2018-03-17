#include "AutoCommandGroup.hpp"

AutoCommandGroup::AutoCommandGroup(std::string&& info, char&& c):
        frc::CommandGroup("Auto Group"),
        position(c),
        switch_pos(info[0]) {

    constexpr char diff = 'r' - 'l';

    // Baseline auto
    if (std::abs(switch_pos - position) == std::abs(diff)) {
        AddSequential(new DistanceCommand(120));
        return;
    }

    switch (position) {
        case 'm': {
            AddSequential(new DistanceCommand(36));
            AddSequential(new TurnCommand((switch_pos == 'l' ? -90 : 90)));
            AddSequential(new DistanceCommand(60));
            AddSequential(new TurnCommand((switch_pos == 'l' ? 90 : -90)));
            AddSequential(new DistanceCommand(84));
            AddSequential(new DropCommand());
            break;
        } case 'l': {
            AddSequential(new DistanceCommand(120));
            AddSequential(new TurnCommand(-90));
            AddSequential(new DistanceCommand(24));
            AddSequential(new DropCommand());
            break;
        } case 'r': {
            AddSequential(new DistanceCommand(120));
            AddSequential(new TurnCommand(90));
            AddSequential(new DistanceCommand(24));
            AddSequential(new DropCommand());
            break;
        }
    }
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
