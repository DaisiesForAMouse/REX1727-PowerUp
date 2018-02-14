#include "IntakeSubsystem.hpp"

IntakeSubsystem::IntakeSubsystem() : frc::Subsystem("IntakeSubsystem") {
    std::cout << "IntakeSubsystem constructor called ...";
    left_external_intake = RobotMap::left_external_intake;
    right_external_intake = RobotMap::right_external_intake;
    std::cout << "IntakeSubsystem constructor ended.";
}

void IntakeSubsystem::SetIntake(IntakeAction i) {
    switch (i) {
        case intake:
            left_external_intake->Set(1.0);
            right_external_intake->Set(-1.0);
            break;
        case outtake:
            left_external_intake->Set(-1.0);
            right_external_intake->Set(1.0);
            break;
        case off:
            left_external_intake->frc::MotorSafety::StopMotor();
            right_external_intake->frc::MotorSafety::StopMotor();
            break;
    }
}

void IntakeSubsystem::SetIntake(double pow) {
    left_external_intake->Set(pow);
    right_external_intake->Set(-pow);
}

void IntakeSubsystem::deploy() {
    frc::Timer t;
    t.Start();
    while (t.Get() < 2) {
        left_external_intake->Set(0.25);
    }
    left_external_intake->Set(0);
}

void IntakeSubsystem::InitDefaultCommand() {
}

void IntakeSubsystem::Periodic() {
}
