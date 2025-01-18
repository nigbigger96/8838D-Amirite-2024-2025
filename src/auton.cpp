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
    driveStraightC(925);
    driveArcL(45, 400, 900);
    driveStraightSlow(170, 80);
    delay(100);
    Intake.move(0);
    driveTurn2(-54);
    driveClampS(-825, 50, 75);
    delay(100);
    Intake.move(127);
    driveTurn2(-61);
   driveStraight2(1250);
   delay(600);
   driveStraight2(-100);
   driveStraightC(-450);
    driveTurn2(-90);
    delay(200);
    driveStraightC(150);
    driveArcLF(95, 450, 1000);
    driveStraightC(650);
    driveArcRF(20, 200, 1000);
    driveTurn2(-135);
    driveStraightSlow(175, 80);
    delay(300);
    driveStraight2(-400);
    driveTurn2(106);
    driveStraight2(700);
    driveTurn2(45);
    driveStraight2(1100);
    driveStraightSlow(200, 65);





    // driveStraight2(350);
    // driveTurn2(180);
    // driveStraight2(700);
    // driveTurn2(-130);
    // driveStraight2(975);
    // driveStraightSlow(150, 95);
    // delay(400);
    // driveStraight2(-300);
    // driveTurn2(110);
    // driveStraight2(800);
    // driveTurn2(45);
    // driveStraightSlow(1000, 80);

   

    

    }
    if(atn == 1) {
      //Blue Ring
     
    Intake.move(127);
    Mogo.set_value(true);
    driveStraightC(925);
    driveArcR(45, 400, 900);
    driveStraightSlow(200, 80);
    delay(100);
    Intake.move(0);
    driveClampS(-825, 50, 70);
    delay(100);
    Intake.move(127);
    driveTurn2(60);
    driveStraight2(1050);
    delay(600);
    driveStraightC(-550);
    driveTurn2(90);
    delay(200);
    driveStraightC(300);
    driveArcRF(90, 400, 1000);
    driveStraightC(200);
    driveArcLF(30, 150, 1000);
    driveTurn2(125);
    driveStraightSlow(500, 50);
    driveStraightSlow(-200, 50);
    driveTurn2(-100);
    driveStraightSlow(700, 70);
    driveTurn2(-45);
    wallResetF(1500);

      ///////////////
     
      



      
      //driveArcL(-40, 850, 800);
      //delay(300);
      //driveTurn2(20);
      //driveStraightC(-1000);
      // Mogo.set_value(true);

 
  
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
       Mogo.set_value(true);
      delay(100);
      driveStraightC(-500);
      driveClampS(-800, 100, 60);
      Intake.move(127);
      driveTurn2(90);
      driveStraightSlow(780, 65);
      driveTurn2(-45);
      driveStraight2(700);
      Mogo.set_value(true);
      Intakepiston.set_value(true);
      driveTurn2(-68);
      driveStraightSlow(1100, 60);
      Intakepiston.set_value(false);
      delay(200);
      driveStraightSlow(150, 70);
      Intake.move(95);
      driveTurn2(175);
      Intake.move(0);
      driveStraightSlow(-590, 50);
      driveTurn2(175);
      driveTurn2(170);
      Intake.move(120);





    }



    if(atn == 5) {
    //sigawp blue

    }
    


    if(atn == 6) {
     //skills   
    Mogo.set_value(true);
    Intake.move(127);
    delay(500);
    Intake.move(-127);
    driveStraightC(150);
    driveTurn2(90);
    driveClampS(-900, 50, 80);
    driveTurn2(0);
    Intake.move(127);
    driveStraightC(300);
    driveArcLF(25, 500, 1000);
    driveStraight2(2250);
    driveStraightSlow(-700, 70);
    driveTurn2(-90);
    LIFT.move(127);
    delay(175);
    LIFT.move(10);
    LIFT.set_brake_mode(E_MOTOR_BRAKE_COAST);
    driveStraightSlow(800, 50);
    delay(1000);
    Intake.move(0);
    LIFT.move(127);
    delay(500);
    driveStraightSlow(300, 60);
    driveStraight2(-500);
    driveTurn2(180);
    LIFT.move(0);
    Intake.move(127);
    driveStraightC(700);
    driveStraightSlow(3700, 30);
    delay(700);
    driveStraightSlow(500, 40);
    driveStraightSlow(-500, 50);
    driveTurn2(-90);
    driveStraightSlow(600, 50);
    driveTurn2(30);
    driveStraightSlow(-450, 50);
    Mogo.set_value(true);
    }



    // if(atn == 7) {
    
    // }



    // if(atn == 8)  {

    // }



    // if(atn == 9){
    // }



}

