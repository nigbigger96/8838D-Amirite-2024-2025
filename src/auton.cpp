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
    driveTurn2(42.5);
    driveStraightSC(-700, 80);
    driveClampS(-700, 100, 40);
    driveTurn2(200);
    Intake.move(127);
    driveStraightC(300);
    driveTurn2(151);
    driveStraightSC(525, 30);
    driveTurn2(34.5);
    driveStraight2(900);
    driveTurn2(0);
    Mogo.set_value(false);
    driveStraightC(725);
    driveTurn2(-38.5);
    driveStraightSlow(800, 40);
    delay(300);
    driveStraightSlow(450, 55);
    Intake.move(0);
    driveTurn2(52.5);
    driveClampS(-1000, 50, 85);
    Intake.move(127);

  

 
  


    

      



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
    //red mogo safe
    color = 2;
      
   
    Intake.move(0);
    LIFTS.move(127);
    delay(550);
    LIFTS.move(0);
    driveStraight2(-380);
    LIFTS.move(-127);
    driveTurn2(-50);
    driveClampS(-1175, 50, 70);
    Intake.move(-40);
    Intake.move(127); 
    driveTurn2(-140);
    driveStraight2(675);
    delay(50); 
    driveStraight2(-650);
    driveTurn2(-53.5);
    driveStraightC(975);
    driveTurn2(-129);
    driveStraightSlow(5000, 80);
    driveStraightSlow(1500, 55);
    driveStraight2(-200);
    Doinker.set_value(true);
    driveTurn2(-115);
    driveStraight2(250);
    driveTurn2(-225);
    Intake.move(0);
    driveTurn2(70);
    driveStraight2(1650);
    LIFTS.move(127);
    

  
    
  

   //
    }



    if(atn == 3){
    //blue mogo safe
    color = 1;
    Intake.move(0);
    LIFTS.move(127);
    delay(550);
    LIFTS.move(0);
    driveStraight2(-380);
    LIFTS.move(-127);
    driveTurn2(50);
    driveClampS(-1175, 25, 70);
    Intake.move(-40);
    Intake.move(127); 
    driveTurn2(140);
    driveStraight2(675);
    delay(50); 
    driveStraight2(-650);
    driveTurn2(53.5);
    driveStraightC(975);
    driveTurn2(129);
    driveStraightSlow(4750, 75);
    driveStraightSlow(1500, 55);
    driveStraight2(-200);
    DoinkerTwo.set_value(true);
    driveTurn2(115);
    driveStraight2(250);
    driveTurn2(225);
    Intake.move(0);
    driveTurn2(-70);
    driveStraight2(1650);
    LIFTS.move(127);


    }



    if(atn == 4){
      // safe sigawp red
      color = 0;
     
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
      delay(625);
      driveStraightSlow(580, 55);
      Intake.move(0);
      driveTurn2(85);
      driveClampS(-950, 50, 60);
      driveTurn2(-31);
      Intake.move(127);
      driveStraightSlow(700, 70);
      delay(200);
     driveStraightC(-400);
     driveTurn2(166);
     LIFTS.move(127);

    }



    if(atn == 5) {
      //safe blue sigawp
      color = 1;
      
    color= 2;
    LIFTS.move(127);
    delay(550);
    LIFTS.move(0);
    LIFTS.move(-127);
    delay(500);
    driveTurn2(-42);
    driveStraightSC(-700, 80);
    driveClampS(-700, 100, 40);
    driveTurn2(-150);
    Intake.move(127);
    driveStraightSC(500, 70);
    Intake.move(70);
    driveTurn2(-10);
    Intake.move(127);
    driveStraightSC(910, 60);
    driveTurn2(29);
    Mogo.set_value(false);
    driveStraightSlow(700, 40);
    delay(625);
    driveStraightSlow(600, 55);
    Intake.move(0);
    driveTurn2(-85);
    driveClampS(-950, 50, 60);
    driveTurn2(31);
    Intake.move(127);
    driveStraightSlow(700, 70);
    delay(200);
   driveStraightC(-400);
   driveTurn2(-166);
   LIFTS.move(127);
      
    }
    
    if(atn == 6) {
    // red ring rush
    color = 0;
      
    Intake.move(127);
    Mogo.set_value(false);
    driveStraightC(920);
    driveArcLF(27.5, 625, 900);
    delay(100);
    driveStraightC(-225);
    driveArcRF(-45, 200, 850);
    Intake.move(0);
    driveClampS(-600, 50, 500); 
    Intake.move(-25);
    delay(20);
    Intake.move(127);
    driveTurn2(-55);
    driveStraight2(1100);
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

