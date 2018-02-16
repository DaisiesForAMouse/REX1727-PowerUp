#include "IntakeSubsystem.hpp"

IntakeSubsystem::IntakeSubsystem() : frc::Subsystem("IntakeSubsystem") {
    std::cout << "IntakeSubsystem constructor called ...";
    left_external_intake = RobotMap::left_external_intake;
    right_external_intake = RobotMap::right_external_intake;
    intake_solenoid = RobotMap::intake_solenoid;
    opened = false;
    std::cout << "IntakeSubsystem constructor ended.";
}

void IntakeSubsystem::Toggle() {
    if (opened) {
        SetPosition(grip);
    } else {
        SetPosition(deploy);
    }
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
            left_external_intake->StopMotor();
            right_external_intake->StopMotor();
            break;
    }
}

void IntakeSubsystem::SetPosition(PostionAction p) {
    switch (p) {
        case deploy:
            if (!opened) {
                intake_solenoid->Set(frc::DoubleSolenoid::kForward);
            }
            opened = true;
            break;
        case grip:
            if (opened) {
                intake_solenoid->Set(frc::DoubleSolenoid::kReverse);
            }
            opened = false;
            break;
    }
}

void IntakeSubsystem::SetIntake(double pow) {
    left_external_intake->Set(pow);
    right_external_intake->Set(-pow);
}

void IntakeSubsystem::Deploy() {

}

void IntakeSubsystem::InitDefaultCommand() {
}

void IntakeSubsystem::Periodic() {
}