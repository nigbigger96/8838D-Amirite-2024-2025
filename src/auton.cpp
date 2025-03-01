#include "api.h"
#include "auton.h"
#include "main.h"
#include "robot.h"
#include "pid.h"
using namespace std;
using namespace pros;

//when color is = to 1 or 0, it is already intaking
//when color is = to 2 it doesnt stops anything, just turns off colorsort
void autonomous() {


    
    if(atn == 0){    
    //Red Ring      
      color= 2;
      LIFTS.move(127);
      delay(550);
      LIFTS.move(0);
      LIFTS.move(-127);
      delay(500);
      driveTurn2(42);
      driveStraightSC(-700, 80);
      driveClampS(-700, 100, 40);
      driveTurn2(150);
      Intake.move(127);
      driveStraightSC(500, 70);
      Intake.move(70);
      driveTurn2(10);
      Intake.move(127);
      driveStraightSC(910, 60);
      driveTurn2(-29);
      Mogo.set_value(false);
      driveStraightSlow(700, 40);
      delay(650);
      driveStraightSlow(525, 55);
      Intake.move(0);
      driveTurn2(85);
      driveClampS(-950, 50, 60);
      driveTurn2(-31);
      Intake.move(127);
      driveStraightSlow(700, 70);
      delay(200);
      driveTurn2(150);
      driveStraightSlow(825, 60);
      LIFTS.move(127);



      

      // LIFTS.move(127);
      // delay(550);
      // LIFTS.move(0);
      // LIFTS.move(-127);
      // delay(500);
      // driveTurn2(51.5);
      // driveClampS(-1125, 50, 62.5);
      // LIFTS.move(0);
      // LIFTS.set_brake_modes(E_MOTOR_BRAKE_HOLD);
      // driveTurn2(140);
      // Intake.move(127);
      // driveStraight2(750);
      // delay(225);
      // driveTurn2(-10);
      // Mogo.set_value(false);
      // driveStraightC(855);
      // driveTurn2(-33.5);
      // driveStraightSlow(850, 37.5);
      // delay(375);
      // Intake.move(0);
      // driveTurn2(60);
      // driveClampS(-650, 50, 75);
      // Intake.move(127);
      // driveTurn2(-37.5);
      // driveStraight2(800);
      // driveStraightC(-400);
      // driveTurn2(90);
      // LIFTS.move(127);
      // delay(450);
      // LIFTS.move(0);


      // driveStraightSlow(500, 80);
      // delay(150);
      // Intake.move(0);





    //   Intake.move(0);

    // LIFTS.move(127);
    // delay(550);
    // LIFTS.move(0);
    // driveStraight2(-375);
    // LIFTS.move(-127);
    // driveTurn2(51.5);
    // driveClampS(-1100, 50, 62.5);
    // Intake.move(127);
    // driveTurn2(187.5);
    // driveStraight2(540);
    // driveTurn2(166);
    // driveStraightSlow(307.5, 92.5);
    // driveStraight2(-375);
    // driveTurn2(110);
    // driveStraight2(425);
    // driveTurn2(42);
    // driveStraightC(475);
    // driveTurn2(105);
    // driveStraightSlow(2350, 62.5);
    // delay(250);
    // driveStraight2(-1750);
    // driveTurn2(-72.5);
    // delay(50);
    // LIFTS.move(127);
    // delay(250);
    // LIFTS.move(0);
  
  


 


  

    

    }
    if(atn == 1) {
      //Blue Ring

    color = 2;
    Intake.move(0);
  LIFTS.move(127);
  delay(550);
  LIFTS.move(0);
  driveStraight2(-375);
  LIFTS.move(-127);
  driveTurn2(-51.5);
  driveClampS(-1100, 50, 62.5);
  Intake.move(127);
  driveTurn2(-187.5);
  driveStraight2(550);
  driveTurn2(-167);
  driveStraightSlow(310, 92.5);
  driveStraight2(-375);
  driveTurn2(-110);
  driveStraight2(425);
  driveTurn2(-42);
  driveStraightC(450);
  driveTurn2(-105);
  driveStraightSlow(2000, 62.5);
  delay(200);
  driveStraight2(-1750);
  driveTurn2(75);
  delay(50);
  LIFTS.move(127);
  delay(250);
  LIFTS.move(0);


    }

    if(atn == 2){ 
    //red mogo
    color = 2;
      
Intake.move(0);
LIFTS.move(127);
delay(550);
LIFTS.move(0);
driveStraight2(-200);
LIFTS.move(-127);
driveTurn2(46);
driveStraight2(280);
Doinker.set_value(true);
driveStraightC(-100);
driveArcR(-125, 100, 1000);
driveClampS(-1000, 50, 62.5);
Doinker.set_value(false);
driveTurn2(-79);
Intake.move(127);
driveStraight2(1425);
driveTurn2(-139);
driveStraightSlow(2500, 80);
driveStraight2(-250);
Doinker.set_value(true);
driveStraight2(200);
delay(100);
driveTurn2(-250);
driveStraightSlow(1000, 80);


  
    
  

   //
    }



    if(atn == 3){
    //blue mogo
    color = 1;
   
    }



    if(atn == 4){
      // safe sigawp red
      color = 0;
     

    }



    if(atn == 5) {
      //blue sigawp
      color = 1;
      
      
    }
    
    if(atn == 6) {
    // red ring elim
    color = 0;

    }



    if(atn == 7)  {
    //blue ring elim
    color = 1;

     }

     if(atn == 8){
    //red mogo elim
    color = 0;
     }

    if(atn == 9){
    //blue mogo elim
    color = 1;
     }

    if(atn == 10) {
     //skills 
    color = 2;  
   
    }

      if(atn == 11) {
     //safety
    
    driveStraight2(700);
    }







}

