#include "IntakeSubsystem.hpp"

IntakeSubsystem::IntakeSubsystem() : frc::Subsystem("IntakeSubsystem") {
    std::cout << "IntakeSubsystem constructor called ..." << std::endl;
    left_external_intake = RobotMap::left_external_intake;
    right_external_intake = RobotMap::right_external_intake;
    intake_solenoid = RobotMap::intake_solenoid;
    std::cout << "IntakeSubsystem constructor ended." << std::endl;
}

void IntakeSubsystem::Toggle() {
    if (GetOpened()) {
        SetPosition(grip);
    } else {
        SetPosition(deploy);
    }
}

void IntakeSubsystem::SetIntake(IntakeAction i) {
    constexpr double p = 0.75;
    constexpr double p_spin = 0.3;
    switch (i) {
        case intake: {
            left_external_intake->Set(p);
            right_external_intake->Set(-p);
            break;
        } case outtake: {
            left_external_intake->Set(-p);
            right_external_intake->Set(p);
            break;
        } case spin_left: {
            left_external_intake->Set(-p_spin);
            right_external_intake->Set(-p_spin);
            break;
        } case spin_right: {
            left_external_intake->Set(p_spin);
            right_external_intake->Set(p_spin);
            break;
        } case off: {
            left_external_intake->StopMotor();
            right_external_intake->StopMotor();
            break;
        }
    }
}

void IntakeSubsystem::SetPosition(PostionAction p) {
    switch (p) {
        case deploy: {
            if (!GetOpened())
                intake_solenoid->Set(frc::DoubleSolenoid::kForward);
            break;
        } case grip: {
            if (GetOpened())
                intake_solenoid->Set(frc::DoubleSolenoid::kReverse);
            break;
        }
    }
}

void IntakeSubsystem::SetIntake(double d) {
    left_external_intake->Set(d);
    right_external_intake->Set(-d);
}

void IntakeSubsystem::SetIntakeLeft(IntakeAction a) {
    switch (a) {
        case intake:
            left_external_intake->Set(1.0);
            break;
        case outtake:
            left_external_intake->Set(-1.0);
            break;
        default:
            break;
    }
}

void IntakeSubsystem::InitDefaultCommand() {
}

void IntakeSubsystem::Periodic() {
}

bool IntakeSubsystem::GetOpened() const {
    return intake_solenoid->Get() == frc::DoubleSolenoid::kForward ? true : false;
}
