#include "api.h"
#include "auton.h"
#include "main.h"
#include "robot.h"
#include "pid.h"
using namespace std;
using namespace pros;

//LIFTS.move(-30);
// Intake.move(127);
// driveStraightSC(930 , 100);
// driveArcLFS(25, 625, 700, 50);
// driveStraightSlow(300, 80);
// stall = false;
// Intake.move(0);
// driveTurn2(-40);
// driveClampS(-500, 50, 70);
// stall = true;
// Intake.move(127);
// driveTurn2(-55);
// driveStraightC(385);
// driveStraightSC(320, 40);
// driveStraightSC(-400, 30);
// driveTurn2(-105);
// driveStraightSC(350, 70);
// driveArcLFS(75, 600, 2000, 70);
// stall = false;
// Intake.move(20);
// driveStraightC(800);
// stall = true;
// Intake.move(127);
// delay(350);
// driveTurn2(-137);
// driveStraightSlow(800, 80);
// driveStraightSlow(-200, 50);
// driveTurn2(-137);
// driveStraightSlow(500, 80);
// delay(150);
// driveStraightSlow(-200, 50);
// driveTurn2(-137);
// delay(150);
// driveStraightSlow(500, 80);
// driveStraightSC(-300, 70);
// driveTurn2(110);
// driveStraightSlow(700, 70);
// driveTurn2(35);
// driveStraightC(450);
// LIFTS.move(127);
//when color is = to 1 or 0, it is already intaking
//when color is = to 2 it doesnt stops anything, just turns off colorsort
void autonomous() {

    
    if(atn == 0){    
   // Red left Safe  
   color = 0;
   for(int i = 0; i < 15000; i+=10){
    ColorSort();
    stall = true;
    stallProtection();
    // automacro = 1;
    delay(10);
 
   Mogo.set_value(false);
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
    driveStraight2(-1775);
    driveTurn2(-72.5);
    delay(50);
    LIFTS.move(127);
    delay(250);
    LIFTS.move(0);
  

    
    break;

  
  }
  
    

    }
    if(atn == 1) {
      //Blue right Safe
      color = 1;
      for(int i = 0; i < 15000; i+=10){
        ColorSort();
        stall = true;
        stallProtection();
        delay(10);
      
      stall = false;
    Intake.move(0);
    Mogo.set_value(false);
  LIFTS.move(127);
  delay(550);
  LIFTS.move(0);
  driveStraight2(-375);
  LIFTS.move(-127);
  driveTurn2(-51.5);
  driveClampS(-1100, 50, 62.5);
  stall = true;
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
  driveStraight2(-1775);
  driveTurn2(75);
  delay(50);
  LIFTS.move(127);
  delay(250);
  LIFTS.move(0);
  
  break;
      }
    }

    if(atn == 2){ 
    //red left rush
    color = 0;
    for(int i = 0; i < 15000; i+=10){
      ColorSort();
      delay(10);
   

    Intake.move(120);
    LIFTS.move(-30);
    Mogo.set_value(false);
    driveStraightC(910);
    driveArcLFS(25, 625, 900, 70);
    driveTurn2(-40);
    Intake.move(0);
    driveClampS(-750, 50, 60);
    Intake.move(127);
    driveTurn2(-90);
    driveStraightC(450);
    driveArcRFS(80, 50, 1000, 60);
    driveStraightSlow(470, 50);
    driveTurn2(-20);
    driveStraightSC(-750, 80);
    driveTurn2(-130);
    driveStraightC(400);
    driveStraightSlow(625, 70);
    driveStraightSC(-300, 80);
    driveTurn2(113.5);
    driveStraightSC(400, 50);
    driveTurn2(58.5);
    driveStraightSC(400, 55);
    Mogo.set_value(false);
    driveStraightSlow(400, 35);
    delay(325);
    color = 2;
    LIFTS.move(16);
    driveStraightSlow(525, 70);
    LIFTS.move(0);
    LIFTS.brake();
    driveStraightSC(-160, 90);
    Doinker.set_value(true);
    driveTurn2(187);
    Doinker.set_value(false);
    delay(200);
    driveStraightSlow(300, 75);
    Intake.move(-20);
    LIFTS.move(127);



    // driveTurn2(-160);
    // color = 0;
    // driveStraight2(750);
    // driveTurn2(-160);
    // driveStraightSC(1000, 95);
    // driveTurn2(-135);
    // color = 0;
    // driveStraightC(-400);
    // driveTurn2(-270);
    // Intake.move(127);
    // driveStraightC(500);
    // delay(650);
    // Mogo.set_value(false);
    // driveStraightSlow(900, 45);
    // delay(350);
    // Intake.move(0);
    // driveTurn2(55);
    // driveStraightC(-1400);
    // driveStraightC(150);
    // driveTurn2(0);
    // driveStraightC(-150);
    // Intake.move(127);

    
    


    // driveStraightC(-225);
    // driveArcRF(-45, 200, 850);
    // stall = false;
    // Intake.move(0);
    // driveClampS(-600, 50, 500); 
    // Intake.move(-25);
    // delay(20);
    // stall = true;
    // Intake.move(127);
    // driveTurn2(-55);
    // driveStraightSlow(775, 85);
    // delay(250);
    // driveStraightC(-225);
    // driveTurn2(-100);
    // driveStraightSC(575, 90);
    // driveStraightC(-450);
    // stall = false;
    // driveTurn2(-137.5);
    // driveStraightC(2000);
    // driveStraightSC(150, 40);
    // driveStraightSC(-200, 50);
    // driveTurn2(-130);
    // driveStraightSC(475, 40);
    // delay(75);
    // stall = true;
    // driveStraightC(-150);
    // delay(200);
    // driveTurn2(89);
    // driveStraightC(500);
    // Mogo.set_value(false);
    // driveStraightC(550);
    // Intake.move(0);
    // driveTurn2(0);
    // driveStraightC(-150);
    // Intake.move(127);
    // delay(500);
    // LIFTS.move(50);
    // driveStraightC(900);
    

 

    

    break;
    }

   //
    }



    if(atn == 3){
    //blue right rush
    color = 1;
    for(int i = 0; i < 15000; i+=10){
      ColorSort();
      delay(10);
    

      break;
    }
    }



    if(atn == 4){
      // red left elim
      color = 0;
      for(int i = 0; i < 15000; i+=10){
        ColorSort();
        delay(10);
      
     
        break;
      }
    }



    if(atn == 5) {
      //blue right elim 
      color = 1;
      for(int i = 0; i < 15000; i+=10){
        ColorSort();
        delay(10);







        break;

      }
    }
    
    if(atn == 6) {
    // red right safe
    color = 0;
    for(int i = 0; i < 15000; i+=10){
      ColorSort();
      stall = true;
      stallProtection();
      delay(10);
    Intake.move(0);
    Mogo.set_value(false);
    LIFTS.move(127);
    delay(550);
    LIFTS.move(0);
    driveStraight2(-380);
    LIFTS.move(-127);
    driveTurn2(-50);
    driveClampS(-1175, 50, 70);
    stall = false;
    Intake.move(-40);
    stall = true;
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
    stall = false;
    Intake.move(0);
    driveTurn2(70);
    driveStraight2(1650);
    LIFTS.move(127);
    break;
    }


    }



    if(atn == 7)  {
    //blue left safe
    color = 1;
    for(int i = 0; i < 15000; i+=10){
      ColorSort();
      delay(10);
    
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
    break;
    }
     }

     if(atn == 8){
      //red right
    color = 0;
    for(int i = 0; i < 35000; i+=10){
      ColorSort();


    

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
  driveTurn2(115);
  driveStraightSC(1000, 90);
  driveTurn2(118.5);
  driveStraightSlow(1500, 70);
  delay(200);
  driveStraightSC(-300, 70);
  driveTurn2(-55);
  Mogo.set_value(false);
  LIFTS.move(40);
  driveStraight2(1300);

      break;
    }  



     
     }



    if(atn == 9){
    //blue left 
    color = 1;
    for(int i = 0; i < 15000; i+=10){
      ColorSort();
      delay(10);

    

  Mogo.set_value(false);
  LIFTS.move(-40);
  Intake.move(80);
  Doinker.set_value(true);
  driveStraightC(1260);
  driveStraightSC(75, 5);
  Doinker.set_value(false);
  delay(150);
  driveStraightSlow(-400, 60);
  Intake.move(0);
  Doinker.set_value(true);
  driveStraightSlow(-150, 55);
  Doinker.set_value(false);
  driveTurn2(-168);
  driveClampS(-750, 50, 60);
  Intake.move(127);
  delay(500);
  driveStraightC(100);
  Mogo.set_value(false);
  driveStraightC(100);
  driveTurn2(-82);
  driveClampS(-600, 60, 70);
  driveTurn2(-155);
  driveStraightSC(700, 75);
  driveStraightSC(-400, 75);
  driveTurn2(-115);
  driveStraightSC(1000, 90);
  driveTurn2(-115);
  driveStraightSlow(1500, 70);
  delay(200);
  driveStraightSC(-350, 70);
  driveTurn2(65);
  LIFTS.move(40);
  driveStraight2(1300);
      break;
    }
     }

    if(atn == 10) {
     //red right elim 
    color = 0;  
    for(int i = 0; i < 15000; i+=10){
      ColorSort();
      delay(10);
      




      break;
    }
   
    }

      if(atn == 11) {
     //blue left elim
    color = 1;
    for(int i = 0; i < 15000; i+=10){
      ColorSort();
      delay(10);
      break;
    }
    }
    if(atn == 12) {
      //SigAwpRedSafe
      color= 0;
      for(int i = 0; i < 15000; i+=10){
        ColorSort();
        delay(10);
      stall = true;
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
      stall = false;
      Intake.move(0);
      driveTurn2(85);
      driveClampS(-950, 50, 60);
      driveTurn2(-31);
      stall = true;
      Intake.move(127);
      driveStraightSlow(700, 70);
      delay(200);
     driveStraightC(-400);
     driveTurn2(166);
     LIFTS.move(127);
    break;
      }
     }     
    if(atn == 13) {
      //SigAwpBlueSafe
      color= 1;
      for(int i = 0; i < 15000; i+=10){
        ColorSort();
        delay(10);
      stall = true;
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
      stall = false;
      Intake.move(70);
      driveTurn2(-10);
      Intake.move(127);
      stall = true;
      driveStraightSC(910, 60);
      driveTurn2(29);
      Mogo.set_value(false);
      driveStraightSlow(700, 40);
      delay(625);
      driveStraightSlow(600, 55);
      stall = false;
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
     break;
      }
     }


     if(atn == 14) {
      //skills
      color = 0;
      for(int i = 0; i < 15000; i+=10){
        ColorSort();
        stall = true;
        stallProtection();
        // automacro = 1;
        delay(10);
       Intake.move(127);
       stallProtection();
       stall = false;
      LIFTS.move(-40);
      delay(500);
      Intake.move(0);
      driveStraightC(225);
      driveTurn2(-90);
      driveClampS(-780, 50, 50);
      driveTurn2(0);
      Intake.move(127);
      driveStraightC(525);
      driveTurn2(52.5);
      driveStraight2(1300);
      delay(150);
      driveStraightC(-85);
      driveTurn2(182);
      driveStraightSC(900, 50);
      driveTurn2(181);
      delay(300);
      driveStraightSC(500, 35);     
      delay(250);
      driveStraightC(-500);
      driveTurn2(155);
      driveStraightC(1000);
      driveStraightC(-150);
      delay(50);
      driveTurn2(-30);
      Mogo.set_value(false);
      driveStraightSC(-750, 85);
      Intake.move(-40);
      delay(400);
      driveStraightSlow(600, 80);
      driveTurn2(90);
      Intake.move(0);
      driveStraightSC(-500, 70);
      driveClampS(-2000, 50, 55);
      driveTurn2(0);

 
    


      


      
 


  break;
     }}
     if(atn == 15) {
      //safety
     }






}

