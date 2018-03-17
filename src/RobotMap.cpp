#include "RobotMap.hpp"

std::shared_ptr<frc::Spark> RobotMap::left_drive;
std::shared_ptr<frc::Spark> RobotMap::right_drive;
std::shared_ptr<frc::Encoder> RobotMap::left_drive_enc;
std::shared_ptr<frc::Encoder> RobotMap::right_drive_enc;
std::shared_ptr<frc::DifferentialDrive> RobotMap::tank_drive;
std::shared_ptr<frc::PIDController> RobotMap::left_drive_vel_PID;
std::shared_ptr<frc::PIDController> RobotMap::left_drive_dist_PID;
std::shared_ptr<frc::PIDController> RobotMap::right_drive_vel_PID;
std::shared_ptr<frc::PIDController> RobotMap::right_drive_dist_PID;

std::shared_ptr<frc::VictorSP> RobotMap::left_climber;
std::shared_ptr<frc::VictorSP> RobotMap::right_climber;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::climber_solenoid;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::brake_solenoid;

std::shared_ptr<frc::DoubleSolenoid> RobotMap::arm_solenoid;
std::shared_ptr<ctre::CANTalonSRX> RobotMap::left_internal_intake;
constexpr int RobotMap::left_talon;
std::shared_ptr<ctre::CANTalonSRX> RobotMap::right_internal_intake;
constexpr int RobotMap::right_talon;
std::shared_ptr<frc::DoubleSolenoid> RobotMap::intake_solenoid;
std::shared_ptr<frc::Spark> RobotMap::left_external_intake;
std::shared_ptr<frc::Spark> RobotMap::right_external_intake;

std::shared_ptr<frc::PowerDistributionPanel> RobotMap::pdp;
constexpr int RobotMap::pdp_num;
std::shared_ptr<frc::Compressor> RobotMap::compressor;
constexpr int RobotMap::pcm_num;

void RobotMap::init() {
    std::cout << "Starting RobotMap::init() ..." << std::endl;

    left_drive = std::make_shared<frc::Spark>(1);
    //left_drive->SetInverted(true);
    right_drive = std::make_shared<frc::Spark>(0);
    //right_drive->SetInverted(true);

    // 6" diameter heels, 1440 pulse/rev encoders
    left_drive_enc = std::make_shared<frc::Encoder>(0, 1, true, frc::Encoder::k4X);
    left_drive_enc->SetDistancePerPulse(6 * M_PI / 1440);
    left_drive_enc->Reset();
    right_drive_enc = std::make_shared<frc::Encoder>(2, 3, false, frc::Encoder::k4X);
    right_drive_enc->SetDistancePerPulse(6 * M_PI / 1440);
    right_drive_enc->Reset();

    tank_drive = std::make_shared<frc::DifferentialDrive>(
            *left_drive, *right_drive);
    tank_drive->SetSafetyEnabled(true);
    tank_drive->SetExpiration(0.1);
    tank_drive->SetMaxOutput(1.0);

    left_drive_vel_PID = std::make_shared<frc::PIDController>(
            0, 0, 0, *left_drive_enc, *left_drive);
    left_drive_vel_PID->SetPIDSourceType(frc::PIDSourceType::kDisplacement);
    left_drive_vel_PID->SetOutputRange(-1.0, 1.0);
    left_drive_vel_PID->Disable();

    left_drive_dist_PID = std::make_shared<frc::PIDController>(
            0, 0, 0, *left_drive_enc, *left_drive);
    left_drive_dist_PID->SetPIDSourceType(frc::PIDSourceType::kDisplacement);
    left_drive_dist_PID->SetOutputRange(-1.0, 1.0);
    left_drive_dist_PID->Disable();

    right_drive_vel_PID = std::make_shared<frc::PIDController>(
            0, 0, 0, *right_drive_enc, *right_drive);
    right_drive_vel_PID->SetPIDSourceType(frc::PIDSourceType::kDisplacement);
    right_drive_vel_PID->SetOutputRange(-1.0, 1.0);
    right_drive_vel_PID->Disable();

    right_drive_dist_PID = std::make_shared<frc::PIDController>(
            0, 0, 0, *right_drive_enc, *right_drive);
    right_drive_dist_PID->SetPIDSourceType(frc::PIDSourceType::kDisplacement);
    right_drive_dist_PID->SetOutputRange(-1.0, 1.0);
    right_drive_dist_PID->Disable();

    left_climber = std::make_shared<frc::VictorSP>(3);
    right_climber = std::make_shared<frc::VictorSP>(4);

    // TODO: Add in solenoid ports
    climber_solenoid = std::make_shared<frc::DoubleSolenoid>(pcm_num, 2, 3);
    brake_solenoid = std::make_shared<frc::DoubleSolenoid>(pcm_num, 4, 6);


    arm_solenoid = std::make_shared<frc::DoubleSolenoid>(pcm_num, 5, 7);

    left_internal_intake = std::make_shared<ctre::CANTalonSRX>(left_talon);
    right_internal_intake = std::make_shared<ctre::CANTalonSRX>(right_talon);

    intake_solenoid = std::make_shared<frc::DoubleSolenoid>(pcm_num, 0, 1);

    left_external_intake = std::make_shared<frc::Spark>(2);
    right_external_intake = std::make_shared<frc::Spark>(5);

    pdp = std::make_shared<frc::PowerDistributionPanel>(pdp_num);
    compressor = std::make_shared<frc::Compressor>(pcm_num);

    std::cout << "RobotMap::init() ended." << std::endl;
}

void RobotMap::ResetEncoders() {
    left_drive_enc->Reset();
    right_drive_enc->Reset();
}
