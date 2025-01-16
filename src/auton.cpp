#include "api.h"
#include "auton.h"
#include "main.h"
#include "robot.h"
#include "pid.h"
using namespace std;
using namespace pros;


void autonomous() {


    
    if(atn == 0){
    Intake.move(127);
    Mogo.set_value(true);
    driveStraightC(900);
    driveArcL(45, 400, 1500);
    driveStraightSlow(150, 80);
    delay(100);
    Intake.move(0);
    driveClampS(-1000, 50, 85);
    Intake.move(0);
    driveTurn2(-52);
    driveClampS(-600, 50, 50);
    Intake.move(127);
    driveTurn2(-55);
    driveStraightC(400);
    driveStraightSlow(450, 60);
    driveStraightC(-350);
    driveTurn2(-100);
    driveArcL(70, 700, 2000);
    driveStraightC(400);
    driveTurn2(-125);
    driveStraight2(400);
    driveTurn2(-125);
    driveStraightC(-200);
    driveTurn2(110);
    driveStraight2(500);
    driveTurn2(80);
    Intakepiston.set_value(true);
    driveStraightSlow(780, 60);
    Intakepiston.set_value(false);
    delay(400);
    driveStraightSlow(-300, 60);

    // Ring rush red non elim
    // Mogo.set_value(true);
    // Intake.move(127);
    // driveStraightC(900);
    // driveArcL(50, 320, 1000);
    // driveStraight2(140);
    // Intake.move(0);
    // delay(300);
    // driveTurn2(-50);
    // driveClampS(-725, 50, 60);
    // driveTurn2(-60);
    // Intake.move(127);
    // driveStraightSlow(1150, 70);
    // driveStraightC(-600);
    // driveTurn2(-90);
    // driveStraightC(600);
    // driveTurn2(-180);
    // driveStraight2(1200);
    // driveTurn2(95);
    // driveStraight2(3000);
//    driveStraight(200);
//6 inches
//    driveStraight(33.3);
//1 inch

    }
    if(atn == 1) {
 
  
    // blue ring rush
    // Mogo.set_value(true);
    // Intake.move(127);
    // driveStraightC(900);
    // driveArcR(50, 320, 1000);
    // driveStraight2(230);
    // Intake.move(0);
    // delay(300);
    // // driveTurn2(50);
    // driveClampS(-875, 45, 40);
    // Intake.move(127);
    // driveTurn2(90);
    // driveStraight2(700);
    // delay(100);
    // driveStraight2(375);
    // driveTurn2(5);
    // driveStraightSlow(540, 55);
    // driveStraight2(-500);
    // driveTurn2(180);
    // driveStraight2(1300);
    // delay(250);
    // driveStraight2(-250);






    }

    if(atn == 2){ 
    //Red Right
    // Mogo.set_value(true);
    // driveStraightC(1300);
    // driveTurn2(25);
    // Doinker.set_value(true);
    // driveArcRS(-50, 1700, 1500, 80);
    // Doinker.set_value(false);
    // driveTurn2(160);
    // delay(400);
    // driveClampS(-675, 50, 45);
    // Intake.move(127);
    // driveArcR(57, 400, 1000);
    // driveTurn2(-140);
    // driveStraightSlow(250, 40);
    // driveStraightC(-350);
    // driveTurn2(0);
    // delay(400);
    // Mogo.set_value(true);
    // driveStraightC(700);
    // Intake.move(0);
    // driveStraight2(100);
    // driveTurn2(-90);
    // driveStraightC(-500);
    // driveClampS(-500, 50, 50);
    // Intake.move(127);
    // driveTurn2(0);
    // driveStraightSlow(700, 40);
    }



    if(atn == 3){
    //Blue left
    // Mogo.set_value(true);
    // Intake.move(127);
    // driveStraightSlow(800, 70);
    // driveArcL(50, 320, 1000);
    // driveStraight2(100);
    // Intake.move(0);
    // delay(300);
    // driveTurn2(-50);
    // driveClampS(-725, 50, 60);
    // driveTurn2(-60);
    // Intake.move(127);
    // driveStraightSlow(1150, 0);
    // driveStraightC(-600);
    // driveTurn2(-90);
    // driveStraightC(600);
    // driveTurn2(-180);
    // driveStraight2(1250);
    // driveTurn2(-130);
    // driveStraightSlow(450, 50);
    // driveStraight2(-300);
    // delay(100);
    // driveTurn2(-255);
    // driveStraight2(650);
    // driveTurn2(45);
    // driveStraightSlow(1150, 50);
    // driveTurn2(0);
    // driveStraightSlow(1000, 50);
    }



    if(atn == 4){
      //sigawp red
    }



    if(atn == 5) {
    //sigawp blue

    }
    


    if(atn == 6) {
     //skills   
      
    }



    // if(atn == 7) {
    
    // }



    // if(atn == 8)  {

    // }



    // if(atn == 9){
    // }



}

