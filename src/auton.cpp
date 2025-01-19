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
    driveTurn2(133);
    driveStraight2(200);
    driveStraightSlow(500, 80);
    delay(200);
    driveStraightSlow(-250, 65);
    driveTurn2(-100);
    driveStraightSlow(750, 70);
    driveTurn2(-40);
    driveStraight2(1000);
    driveStraightSlow(300, 80);

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
    Mogo.set_value(true);
    driveStraightC(1300);
    driveTurn2(25);
    Doinker.set_value(true);
    driveArcRS(-50, 1700, 1500, 80);
    Doinker.set_value(false);
    driveStraight2(-150);
    driveTurn2(175);
    delay(200);
    driveClampS(-600, 50, 70);
    Intake.move(127);
    driveStraightC(500);
    driveTurn2(-135);
    driveStraightSlow(400, 80);
    delay(250);
    driveStraightC(-450);
    driveTurn2(0);
    delay(200);
    Mogo.set_value(true);
    driveStraight2(650);
    delay(50); 
    Intake.move(0);
    driveTurn2(-90);
    driveClampS(-800, 50, 80);
    Intake.move(127);
    driveTurn2(90);
    driveStraight2(900);
    driveStraightSlow(200, 80);
   
    }



    if(atn == 3){
    //Blue left
    driveStraightC(1300);
    driveTurn2(25);
    Doinker.set_value(true);
    driveArcR(-25, 400, 1000);
    Doinker.set_value(false);
    driveStraight2(-200);
    driveTurn2(180);
    driveClampS(-500, 50, 70);
 
  
    // driveTurn2(-175);
    // delay(200);
    // driveClampS(-600, 50, 70);
    // Intake.move(127);
    // driveStraightC(500);
    // driveTurn2(135);
    // driveStraightSlow(400, 80);
    // delay(150);
    // driveStraightC(-450);
    // driveTurn2(0);
    // Mogo.set_value(true);
    // driveStraight2(550);
    // delay(100); 
    // Intake.move(0);
    // driveTurn2(90);
    // driveClampS(-800, 50, 80);
    // Intake.move(127);
    // driveTurn2(-90);
    // driveStraight2(900);
    // driveStraightSlow(200, 80);
    }



    if(atn == 4){
      //sigawp red
      Mogo.set_value(true);
      Intake.move(127);
      driveStraight2(320); //corner
      delay(200);
      driveStraightC(-800); //back
      Intake.move(0);
      driveClampS(-1200, 105, 85);
      //169 degrees is zero
      Intake.move(127);
      delay(150);
      driveTurn2(45);
      driveStraightSlow(800, 70);
      driveTurn2(-104);
      Mogo.set_value(true);
      Intake.move(-127);
      driveStraightC(1950);
      driveStraightSlow(525, 70);
      driveTurn2(-45);
      Intake.move(0);
      LIFT.move(127); //wallstake
      delay(150);
      driveStraight2(430);
      /* driveStraightSlow(350, 90);
      driveStraight2(100); */
      LIFT.move(-127);
      driveTurn2(-45);
      driveStraight2(-500);
      LIFT.move(0);
      driveTurn2(-8);
      driveClampS(-1300, 115, 100);
      driveTurn2(-135);
      Intake.move(127);
      driveStraight2(800);
      driveTurn2(47);
      driveStraight2(950);
      driveStraightSlow(200, 80);
   /*    driveTurn2(-75);
      driveStraightC(1300);
      driveStraightSlow(-2000, 70); */

      
      
      
      
      //First sigawp
      /* Mogo.set_value(true);
      driveStraightC(-500);
      driveClampS(-800, 100, 60);
      Intake.move(127);
      driveTurn2(90);
      driveStraightSlow(820, 80);
       */




      



      /* Mogo.set_value(true);
      Intakepiston.set_value(true);
      driveTurn2(-68);
      driveStraightSlow(1100, 60);
      Intakepiston.set_value(false);
      delay(200);
      driveStraightSlow(150, 70);
      Intake.move(60);
      driveTurn2(176);
      driveStraightSlow(-590, 50);
      driveTurn2(173.6);
      Intake.move(127);
      delay(500);
      driveStraight2(700);
      driveTurn2(47);
      driveClampS(-700, 80, 80);
      driveTurn2(-83);
      driveStraightC(700); */







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

