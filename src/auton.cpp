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
    
////////////////safe redmo

  









      Intake.move(0);
    LIFTS.move(127);
    delay(550);
    LIFTS.move(0);
    driveStraight2(-375);
    LIFTS.move(-127);
    driveTurn2(51.5);
    driveClampS(-1100, 50, 62.5);
    Intake.move(127);
    driveTurn2(187.5);
    driveStraight2(540);
    driveTurn2(166);
    driveStraightSlow(307.5, 92.5);
    driveStraight2(-375);
    driveTurn2(110);
    driveStraight2(425);
    driveTurn2(42);
    driveStraightC(475);
    driveTurn2(105);
    driveStraightSlow(2350, 62.5);
    delay(250);
    driveStraight2(-1750);
    driveTurn2(-72.5);
    delay(50);
    LIFTS.move(127);
    delay(250);
    LIFTS.move(0);
  
  


 


  

    

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


    LIFTS.move(127);
    delay(550);
    Intake.move(127);
    LIFTS.move(0);
    driveStraight2(-375);
    LIFTS.move(-127);
    driveTurn2(-51.5);
    driveClampS(-1100, 50, 62.5);
    driveTurn2(-140);
    driveStraight2(500);
    delay(200);
    driveStraightC(-300);
    driveTurn2(880);
    Intake.move(0);
    driveStraight2(300);
    Doinker.set_value(true);
    delay(200);
    driveStraight2(-500);
    Doinker.set_value(false);
  

   //
    }



    if(atn == 3){
    //blue mogo
    color = 1;
   
    }



    if(atn == 4){
      //sigawp red
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

