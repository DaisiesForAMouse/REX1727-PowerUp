#include "CubeCommand.hpp"

CubeCommand::CubeCommand() {
    Requires(Robot::arm_subsystem.get());
    Requires(Robot::intake_subsystem.get());
}

void CubeCommand::Initialize() {
    std::cout << "CubeCommand initialized." << std::endl;
    RobotMap::arm_solenoid->Set(frc::DoubleSolenoid::kForward);
}

void CubeCommand::Execute() {
    auto xbox = Robot::oi->GetXboxController();
    auto logitech = Robot::oi->GetLogitech();

    constexpr auto right = frc::GenericHID::kRightHand;
    constexpr auto left = frc::GenericHID::kLeftHand;

    if (xbox->GetBumperPressed(right))
        SetArm(lift);
    else if (xbox->GetBumperPressed(left))
        SetArm(drop);

    if (xbox->GetTriggerAxis(left) > 0.25)
        Robot::arm_subsystem->SetIntake(-xbox->GetTriggerAxis(left));
    else if (logitech->GetRawButton(11) || logitech->GetRawButton(2))
        Robot::arm_subsystem->SetIntake(ArmSubsystem::intake);
    else if (logitech->GetRawButton(12))
        Robot::arm_subsystem->SetIntake(ArmSubsystem::outtake);
    else
        Robot::arm_subsystem->SetIntake(ArmSubsystem::off);

    if (logitech->GetRawButtonPressed(7))
        Robot::intake_subsystem->SetPosition(IntakeSubsystem::grip);
    else if (logitech->GetRawButtonPressed(8))
        Robot::intake_subsystem->SetPosition(IntakeSubsystem::deploy);

    if (logitech->GetRawButton(9) || logitech->GetRawButton(2))
        Robot::intake_subsystem->SetIntake(IntakeSubsystem::intake);
    else if (logitech->GetRawButton(10))
        Robot::intake_subsystem->SetIntake(IntakeSubsystem::outtake);
    else
        Robot::intake_subsystem->SetIntake(IntakeSubsystem::off);
}

bool CubeCommand::IsFinished() {
    return false;
}

void CubeCommand::End() {
}

void CubeCommand::Interrupted() {
}

void CubeCommand::SetArm(ArmAction a) {
    switch (a) {
        case lift:
            //Robot::intake_subsystem->SetIntake(IntakeSubsystem::off);
            Robot::intake_subsystem->SetPosition(IntakeSubsystem::grip);
            Robot::arm_subsystem->SetArm(ArmSubsystem::lift);
            break;
        case drop:
            //Robot::intake_subsystem->SetIntake(IntakeSubsystem::off);
            Robot::intake_subsystem->SetPosition(IntakeSubsystem::deploy);
            Robot::arm_subsystem->SetArm(ArmSubsystem::drop);
            break;
    }

}

void CubeCommand::ToggleArm() {
    if (Robot::arm_subsystem->GetRaised())
        SetArm(drop);
    else
        SetArm(lift);
}
