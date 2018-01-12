#include "WearSubsystem.h"

WearSubsystem::WearSubsystem() : frc::Subsystem("WearSubsystem") {
    test_left = RobotMap::spark_port_1; 
    test_right = RobotMap::spark_port_2;
}

void WearSubsystem::motorSet(double n) {
    test_left->Set(n);
    test_right->Set(n);
}
