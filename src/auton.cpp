#include "api.h"
#include "auton.h"
#include "main.h"
#include "robot.h"
#include "pid.h"
#include <iostream>
using namespace std;
using namespace pros;


void autonomous() {

///////new stuff :)

    
if(atn == 0){  
   Mogo.set_value(false);
   // Red Ring
   color = 1;
    for(int i = 0; i < 150000; i++) {
      
      ColorSort();
      color = 1;
      Scoring.move(0);
      Doinker.set_value(true);
      driveStraightC(1000);
      Intake.move(-127);
      driveStraightSlow(700, 40);
      delay(25);
      driveTurn2(-30);
      driveClampS(-975, 50, 57.5);
      Doinker.set_value(false);
      Scoring.move(-127);
      driveTurn2(-60);
      driveStraightSC(850, 50);
      driveTurn2(-160);
      delay(200);
      driveStraightSC(725, 65);
      driveTurn2(-103.5);
      delay(200);
      Scoring.move(0);
      driveStraightSlow(1000, 60);
      Intake.move(-127);
      delay(475);
      driveStraightSC(-625, 47.5);
      driveTurn2(-250);
      delay(50);
      Scoring.move(-127);
      driveStraightSC(500, 70);
      driveStraightSlow(150, 40);
      delay(450);
      // automacro = 2;
     Intakepiston.set_value(true);
      Intake.move(-127);
      // for(int i = 0; i < 1000; i++) {
      //   liftauton();
      //   automacro = 1;
      //   }
       
      driveStraightSlow(950, 25);
      Scoring.move(-127);
      // for(int i = 0; i < 10000; i++) {
      //   liftauton();
      //   }
          delay(250);
    // Intakepiston.set_value(false);
      delay(10);
      break;
         }









 
 

 
   
    
   }
    
  

if(atn == 1){    
    // Blue Ring 
    color = 0;
    for(int i = 0; i < 15000; i+=10){
     ColorSort();
     
     // automacro = 1;
     delay(10);
     
    DoinkerTwo.set_value(true);
    driveStraightC(1000);
    Intake.move(-127);
    driveStraightSlow(700, 45);
    delay(25);
    driveTurn2(27.5);
    driveClampS(-975, 50, 57.5);
    DoinkerTwo.set_value(false);
    Scoring.move(-127);
    driveTurn2(60);
    driveStraightSC(850, 50);
    driveTurn2(160);
    delay(200);
    driveStraightSC(775, 80);
    driveTurn2(-103.5);
    Scoring.move(0);
    driveStraightSlow(1350, 65);
    Intake.move(-127);
    delay(475);
    driveStraightSC(-500, 55);
    delay(50);
    driveTurn2(250);
    delay(50);
    Scoring.move(-127);
    driveStraightSC(500, 40);
    driveStraightSlow(325, 30);
    delay(200);
   Intakepiston.set_value(true);
    Intake.move(-127);
    delay(750);
    driveStraightSlow(775, 25);
    Scoring.move(-127);
  
    
    break;
    }
     }

if(atn == 2){    
    // Red Mogo 
    color = 0;
    for(int i = 0; i < 15000; i+=10){
     ColorSort();

     automacro = 1;
    delay(10);

     LIFT.move(-127);
     delay(450);
     LIFT.move(0);
     delay(250);
     driveStraightSlow(-375, 50);
     LIFT.move(127);
     driveTurn2(60);
     Intakepiston.set_value(true);
     Intake.move(-127);
     driveStraightSlow(750, 30);
     delay(200);
     Intakepiston.set_value(false);
     delay(100);
     driveTurn2(-14);
     LIFT.move(0);
    driveStraightSC(-780, 55);
    driveClampS(-500, 50, 25);
    driveTurn2(77);
    Intake.move(0);
    DoinkerTwo.set_value(true);
    driveStraightSC(710, 60);
    driveStraightSC(-550,45);
    Scoring.move(-127);
    DoinkerTwo.set_value(false);
    delay(250);
    driveTurn2(86.5);
    Scoring.move(0);
    Intake.move(-127);
    driveStraightSC(400, 55);
    delay(100);
    driveStraightSC(-250, 40);
    driveTurn2(-145);
    Scoring.move(-127);
    driveStraightSC(400, 55);
   Scoring.move(-100);
   driveTurn2(-70);
   Scoring.move(-127);
   driveStraightSC(1000, 80);
   driveStraightSC(500, 65);
   Scoring.move(0);
   Intake.move(-127);
   driveStraightSlow(500, 70);
   delay(50);
   DoinkerTwo.set_value(true);
   driveStraightSlow(-350, 70);
   Intake.move(0);
   Scoring.move(-127);
   driveStraightSC(150, 75);
   driveTurn2(-290);
   driveStraightC(-150);
    Mogo.set_value(false);
    driveStraightC(200);
    driveTurn2(-20);
  

   
    

  
    
    break;
    }
     }
    
   
if(atn == 3){    
    // Blue Mogo
    color = 0;
    for(int i = 0; i < 15000; i+=10){
    ColorSort();
  
    // automacro = 1;
    delay(10);
    LIFT.move(-127);
     delay(450);
     LIFT.move(0);
     delay(250);
     driveStraightSlow(-375, 50);
     LIFT.move(127);
     driveTurn2(-60);
     Intakepiston.set_value(true);
     Intake.move(-127);
     driveStraightSlow(750, 30);
     delay(200);
     Intakepiston.set_value(false);
     delay(100);
     driveTurn2(14);
     LIFT.move(0);
    driveStraightSC(-780, 55);
    driveClampS(-500, 50, 25);
    driveTurn2(-77);
    Intake.move(0);
    Doinker.set_value(true);
    driveStraightSC(710, 60);
    driveStraightSC(-550,45);
    Scoring.move(-127);
    Doinker.set_value(false);
    delay(250);
    driveTurn2(-86.5);
    Scoring.move(0);
    Intake.move(-127);
    driveStraightSC(400, 55);
    delay(100);
    driveStraightSC(-250, 40);
    driveTurn2(145);
    Scoring.move(-127);
    driveStraightSC(400, 55);
   Scoring.move(-100);
   driveTurn2(70);
   Scoring.move(-127);
   driveStraightSC(1000, 80);
   driveStraightSC(500, 65);
   Scoring.move(0);
   Intake.move(-127);
   driveStraightSlow(500, 70);
   delay(50);
   DoinkerTwo.set_value(true);
   driveStraightSlow(-350, 70);
   Intake.move(0);
   Scoring.move(-127);
   driveStraightSC(150, 75);
   driveTurn2(290);
   driveStraightC(-150);
    Mogo.set_value(false);
    driveStraightC(200);
    driveTurn2(20);
    
      
    break;
    }
      }

if(atn == 4){    
    // Red Sigawp
    color = 0;
    for(int i = 0; i < 15000; i+=10){
    ColorSort();

    // automacro = 1;
    delay(10);

    LIFT.move(-127);
    delay(450);
    LIFT.move(0);
    delay(250);
    driveStraightSlow(-150, 50);
    LIFT.move(127);
    driveTurn2(43.5);
    driveClampS(-1550, 50, 50);
    driveTurn2(145);
    LIFT.move(0);
    Scoring.move(-127);
    driveStraightSlow(745, 65);
    delay(200);
    driveTurn2(-9);
    delay(50);
    driveStraightSC(600, 55);
    Mogo.set_value(false);
    delay(100);
    driveStraightSC(1000 , 40);
    driveStraightSlow(1950, 25);
    delay(550);
    Scoring.move(0);
    Intake.move(-127);
    driveTurn2(84);
    driveClampS(-1400, 50, 60);
    Scoring.move(-127);
    delay(100);
    driveTurn2(-32.5);
    driveStraightSlow(700, 50);
    delay(350);
    driveStraightSC(-500, 75);
    driveTurn2(145);
    driveStraightSlow(700, 40);
    driveStraightSlow(100, 10);

    break;
    }
     }

   if(atn == 5){    
      // Blue Sigawp
      color = 0;
      for(int i = 0; i < 15000; i+=10){
      ColorSort();
    
      // automacro = 1;
      delay(10);

      LIFT.move(-127);
    delay(450);
    LIFT.move(0);
    delay(250);
    driveStraightSlow(-150, 50);
    LIFT.move(127);
    driveTurn2(-43.5);
    driveClampS(-1550, 50, 50);
    driveTurn2(-145);
    LIFT.move(0);
    Scoring.move(-127);
    driveStraightSlow(745, 65);
    delay(200);
    driveTurn2(9);
    delay(50);
    driveStraightSC(600, 55);
    Mogo.set_value(false);
    delay(100);
    driveStraightSC(1000 , 40);
    driveStraightSlow(1950, 25);
    delay(550);
    Scoring.move(0);
    Intake.move(-127);
    driveTurn2(-84);
    driveClampS(-1400, 50, 60);
    Scoring.move(-127);
    delay(100);
    driveTurn2(32.5);
    driveStraightSlow(700, 50);
    delay(350);
    driveStraightSC(-500, 75);
    driveTurn2(-145);
    driveStraightSlow(700, 40);
    driveStraightSlow(100, 10);

        
          
      break;
      }
       }

    if(atn == 6){    
      // Red Ring Elim
      color = 0;
      for(int i = 0; i < 15000; i+=10){
      ColorSort();
      
      // automacro = 1;
      delay(10);

      driveClampS(-1500,50, 60);
      Scoring.move(-127);
      delay(1000);
          
            
      break;
      }
       }


    if(atn == 7){    
      // Blue Ring Elim
      color = 0;
      for(int i = 0; i < 15000; i+=10){
      ColorSort();
     
      // automacro = 1;
      delay(10);
            
              
      break;
      }
       }

    if(atn == 8){    
      // Red Mogo Elim
      color = 0;
      for(int i = 0; i < 15000; i+=10){
      ColorSort();
    
      // automacro = 1;
      delay(10);
            
              
      break;
      }
       }
  
  
    if(atn == 9){    
      // Blue Mogo Elim
      color = 0;
      for(int i = 0; i < 15000; i+=10){
      ColorSort();
      
      // automacro = 1;
      delay(10);
              
                
      break;
      }
       }

    if(atn == 10){    
      // Safety
      color = 0;
      for(int i = 0; i < 15000; i+=10){
      ColorSort();
     
      // automacro = 1;
      delay(10);
              
                
      break;
      }
       }
    
    
    if(atn == 11){    
      // Skills
      color = 0;
      for(int i = 0; i < 15000; i+=10){
      ColorSort();
   
      // automacro = 1;
      delay(10);

      Scoring.move(-127);
      delay(350);
      driveStraightSC(175, 50);
      driveTurn2(-90);
      driveStraightSC(-450, 45);
      driveClampS(-400, 50, 30);
      driveTurn2(0);
      driveStraightSC(715, 65);
      driveTurn2(76.5);
      driveStraightSC(750, 75);
      driveStraightSlow(650, 65);
      delay(100);
      driveStraightSlow(-400, 70);
      delay(200);
      driveTurn2(180);
      delay(350);
      driveStraightSC(1150, 45);
      driveStraightSlow(1100, 30);
      delay(150);
      driveStraightSC(-75, 40);
      driveTurn2(90);
      driveStraightSC(200, 60);
      delay(750);
      driveStraightSC(-200, 50);
      driveTurn2(-45);
       driveStraightSC(-800, 65);
       Scoring.move(0);
       Mogo.set_value(false);
       Hooks.move(40);
       delay(10);
       driveStraightSC(600, 60);
       Hooks.move(0);
       driveTurn2(90);
       driveStraightSC(-1500, 75);
       driveClampS(-1000, 50, 60);



      


                
                  
      break;
      }
       }

      }
           
      