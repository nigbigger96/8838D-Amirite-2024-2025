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
   // Red left Safe  
   color = 0;
   Intake.move(127);


  for(int i = 0; i < 15000; i+=10){
  ColorSort();
  delay(10);


  ////////////skills move later

  // Intake.move(127);
  // LIFTS.move(-40);
  // delay(500);
  // Intake.move(0);
  // driveStraightC(175);
  // driveTurn2(-90);
  // driveClampS(-725, 50, 80);
  // driveTurn2(0);
  // Intake.move(127);
  // driveStraightC(575);
  // driveTurn2(45);
  // driveStraightC(650);
  // driveTurn2(5);
  // driveStraightSlow(1500, 60);
  // driveStraightC(-400);
  // driveTurn2(135);
  // automacro = 1;
  // delay(100);
  // driveStraightC(250);
  // driveTurn2(90);
  // driveStraightC(100);
  // LIFTS.move(127);
  

///////////mogo rush move later

  Mogo.set_value(false);
  LIFTS.move(-40);
  Intake.move(82.5);
  DoinkerTwo.set_value(true);
  driveStraightC(1260);
  driveStraightSC(75, 5);
  DoinkerTwo.set_value(false);
  delay(150);
  driveStraightSlow(-400, 60);
  Intake.move(0);
  DoinkerTwo.set_value(true);
  driveStraightSlow(-150, 55);
  DoinkerTwo.set_value(false);
  driveTurn2(168);
  driveClampS(-750, 50, 60);
  Intake.move(127);
  delay(500);
  driveStraightC(100);
  Mogo.set_value(false);
  driveStraightC(100);
  driveTurn2(82);
  driveClampS(-725, 60, 70);
  driveTurn2(155);
  driveStraightSC(700, 75);
  driveStraightSC(-400, 75);
  driveTurn2(105);
  driveStraightSC(1000, 90);
  driveTurn2(118.5);
  driveStraightSlow(1500, 70);
  delay(200);
  driveStraightSC(-300, 70);
  driveTurn2(-55);
  Mogo.set_value(false);
  LIFTS.move(40);
  driveStraight2(1300);



 // ring rush


  // ColorSort();
  // delay(10);
  // Mogo.set_value(false);
  // LIFTS.move(-40);
  // Intake.move(127);
  // DoinkerTwo.set_value(true);
  // driveStraightC(1260);
  // driveStraightSC(75, 5);
  // DoinkerTwo.set_value(false);
  // delay(150);
  // Intake.move(25);
  // driveStraightSlow(-500, 55);
  // DoinkerTwo.set_value(true);
  // driveTurn2(71);
  // driveClampS(-790, 50, 70);
  // Intake.move(0);
  // DoinkerTwo.set_value(false);
  // Intake.move(127);
  // driveTurn2(-217.5);
  // driveStraightC(450);
  // driveTurn2(0);
  // delay(400);
  // Mogo.set_value(false);
  // driveStraightC(180);
  // driveTurn2(-175);
  // driveClampS(-1040, 100, 60);
  // driveTurn2(140);
  // driveStraightSC(1200, 75);
  // driveTurn2(115);
  // driveStraightSlow(450, 60);
  // delay(150);
  // driveTurn2(-280);
  // driveStraightC(-600);
  // driveTurn2(-60);
  // driveStraight2(1400);
  // LIFTS.move(127);

  
  break;
   }  

    
 


  


    
   



    // Mogo.set_value(false);
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
      //Blue right Safe

    color = 1;
    Intake.move(0);
    Mogo.set_value(false);
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
    //red left rush
    color = 2;
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
  

   //
    }



    if(atn == 3){
    //blue right rush
    color = 1;



    }



    if(atn == 4){
      // red left elim
      color = 0;
     


    }



    if(atn == 5) {
      //blue right elim 
      color = 1;
      

      
    }
    
    if(atn == 6) {
    // red right safe
    color = 0;
    Intake.move(0);
    Mogo.set_value(false);
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



    }



    if(atn == 7)  {
    //blue left safe
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

     if(atn == 8){
    color = 0;
    for(int i = 0; i < 35000; i+=10){
      ColorSort();
    }  

     color = 0;
    //  Mogo.set_value(false);
    //  LIFTS.move(-40);
    //  Intake.move(127);
    //  driveStraightC(1175);
    //  Intake.move(0);
    //  DoinkerTwo.set_value(true);
    //  driveStraightSlow(-500, 80);
    //  driveTurn2(65);
    //  DoinkerTwo.set_value(false);
    //  driveClampS(-800, 50, 65);
    //  Intake.move(127);
    //  driveTurn2(-56);
    //  delay(50);
    //  Intake.move(0);
    //  driveStraightSlow(550, 30);
    //  Doinker.set_value(true);

     
     }



    if(atn == 9){
    //blue left 
    color = 1;
     }

    if(atn == 10) {
     //red right elim 
    color = 2;  
   
    }

      if(atn == 11) {
     //blue left elim
    
    
    }
    if(atn == 12) {
      //SigAwpRedSafe
      color= 0;
      Mogo.set_value(false);
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
    if(atn == 13) {
      //SigAwpBlueSafe
      color= 2;
      Mogo.set_value(false);
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
      Mogo.set_value(true);
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
     if(atn == 14) {
      //SigAwpRed
      Mogo.set_value(false);
      LIFTS.move(127);
      delay(550);
      LIFTS.move(0);
      LIFTS.move(-127);
      delay(500);
      driveTurn2(35);
      driveStraightSC(-700, 60);
      driveClampS(-600, 100, 50);
      driveTurn2(205);
      Intake.move(127);
      driveStraightC(210);
      driveTurn2(151);
      driveStraightSC(550, 32.5);
      driveTurn2(160);
      driveStraightC(-400);
      driveTurn2(130);
      delay(150);
       driveStraightSC(475,110);
       driveTurn2(-7.5);
       driveStraightC(1450);
       driveTurn2(-40);
       delay(100);
       Intake.move(-40);
       Intake.move(127);
      Mogo.set_value(true);
      driveStraightSlow(500, 30);
      delay(250);
      Intake.move(0);
      driveStraightSlow(350, 55);
      driveTurn2(72.5);
      driveClampS(-875, 50, 80);
      Intake.move(127);
      driveTurn2(200);
      LIFTS.move(127);
     
     }
     if(atn == 15) {
      //SigAwpBlue
      color= 2;
      Mogo.set_value(false);
      LIFTS.move(127);
      delay(550);
      LIFTS.move(0);
      LIFTS.move(-127);
      delay(500);
      driveTurn2(-42.5);
      driveStraightSC(-700, 80);
      driveClampS(-700, 100, 60);
      driveTurn2(-200);
      Intake.move(127);
      driveStraightC(245);
      driveTurn2(-151);
      driveStraightSC(450, 25);
      driveTurn2(-160);
      driveStraightC(-400);
      driveTurn2(-130);
      driveStraightSC(525,110);
      driveTurn2(7.5);
      driveStraightC(1300);
      driveTurn2(40);
      delay(100);
      Intake.move(-40);
      Intake.move(127);
      Mogo.set_value(true);
      driveStraightSlow(500, 40);
      delay(50);
      driveStraightSlow(350, 40);
      Intake.move(0);
      driveTurn2(-72.5);
      driveClampS(-800, 50, 75);
      Intake.move(127);
      driveTurn2(-200);
      driveStraight2(200);
      LIFTS.move(127);

     }

     if(atn == 16) {
      //skills
     }
     if(atn == 17) {
      //safety
     }






}

