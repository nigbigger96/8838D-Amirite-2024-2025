#include "api.h"
#include "main.h"
#include "robot.h"
#include "pros/motors.h"
using namespace pros;

#define LF_PORT 1
#define LM_PORT 2   
#define LB_PORT 3
#define RF_PORT 4  
#define RM_PORT 5
#define RB_PORT 6  
#define HOOKS_PORT 7 
#define INTAKE_PORT 21
#define LIFT_PORT 10 
#define IMU_PORT 13
#define OPTICAL_PORT 12
#define ROTO_PORT 11



//#define
pros::Imu imu (IMU_PORT);
pros::Motor LF (LF_PORT, pros::E_MOTOR_GEARSET_06,true);
pros::Motor LM (LM_PORT, pros::E_MOTOR_GEARSET_06,false);
pros::Motor LB (LB_PORT, pros::E_MOTOR_GEARSET_06,false);
pros::Motor RF (RF_PORT, pros::E_MOTOR_GEARSET_06,false);
pros::Motor RM (RM_PORT, pros::E_MOTOR_GEARSET_06,true);
pros::Motor RB (RB_PORT, pros::E_MOTOR_GEARSET_06,true);
pros::Motor Hooks(INTAKE_PORT, pros::E_MOTOR_GEARSET_06,false);
pros::Motor Intake(INTAKE_PORT, pros::E_MOTOR_GEARSET_18,true);
pros::Optical Opticala (OPTICAL_PORT);
pros::Motor LIFT(LIFT_PORT, pros::E_MOTOR_GEARSET_18, true);
pros::MotorGroup Scoring({Motor(7), Motor(21)});
pros::ADIDigitalOut Mogo ('A', false);
// pros::ADIDigitalOut DaSorter ('B', false);
pros::ADIDigitalOut Doinker ('B', false);
pros::ADIDigitalOut DoinkerTwo ('C', false);
pros::ADIDigitalIn selec ('D');
pros::ADIDigitalOut Intakepiston ('E');
pros::Controller con (pros::E_CONTROLLER_MASTER);
pros::Rotation roto(ROTO_PORT);



