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
   
   // Red Ring
  //    6 ring
     // driveStraightSlow(950, 25);


color = 1;

    for(int i = 0; i < 150000; i++) {
      



color = 0;
  ColorSort();
      Doinker.set_value(true);
      driveStraightC(1025);
      Intake.move(-127);
      driveStraightSlow(700, 45);
      delay(25);
      driveTurn2(-30);
      driveClampS(-975, 50, 57.5);
      // ColorSort();
      color = 1;
      Doinker.set_value(false);
      driveTurn2(-60);
      driveStraightSC(875, 55);
      driveTurn2(-160);
      delay(150);
      driveStraightSC(675, 75);
       driveTurn2(-120);
      delay(100);
      Hooks.move(0);
      driveStraightSC(800, 50);
      driveStraightSC(200, 25);
      Intake.move(-127);
      driveStraightSlow(-537.5, 70);
      driveTurn2(112.5);
      delay(50);
      // ColorSort();
      color = 1;
      driveStraightSC(765, 70);
      driveStraightSlow(500, 70);
      delay(200);
Intake.move(-127);
Intakepiston.set_value(true);
      driveStraightSlow(1500, 41.75);
      color = 0;
Hooks.move(0);
      Intakepiston.set_value(false);
      for(int i = 0; i<800; i+=10){
        automacro = 2;
        liftauton();
        delay(10);
      }
      LIFT.move(0);
     color = 1;
      DoinkerTwo.set_value(true);
      delay(200);
      color = 0;
      Hooks.move(-127);
      driveTurn2(-155);
      DoinkerTwo.set_value(false);
      delay(50);
      color = 0;
      driveStraightSlow(1100, 70);
      driveStraightSlow(-300, 80);
      Hooks.move(20);
      for(int i = 0; i<900; i+=10){
        automacro = 3;
        liftauton();
        delay(10);
      }
      LIFT.move(0);
      
      driveStraightC(-250);

      for(int i = 0; i<500; i+=10){
        automacro = 1;
        liftauton();
        delay(10);
      }




    

 


      break;

    }
   
    
   }
    
  

if(atn == 1){    
    // Blue Ring 
color = 2;
    for(int i = 0; i < 15000; i+=10){
  


color = 0;
ColorSort();
    DoinkerTwo.set_value(true);
    driveStraightC(1025);
    Intake.move(-127);
    driveStraightSlow(700, 45);
    delay(25);
    driveTurn2(30);
    driveClampS(-975, 50, 57.5);
    // ColorSort();
    color = 2;
    DoinkerTwo.set_value(false);
    driveTurn2(60);
    driveStraightSC(875, 55);
    driveTurn2(160);
    delay(150);
    driveStraightSC(675, 75);
     driveTurn2(120);
    delay(100);
    Hooks.move(0);
    driveStraightSC(800, 50);
    driveStraightSC(250, 25);
    Intake.move(-127);
    driveStraightSlow(-537.5, 70);
    driveTurn2(-112.5);
    delay(50);
    // ColorSort();
    color = 2;
    driveStraightSC(765, 70);
    driveStraightSlow(500, 70);
    delay(200);
Intake.move(-127);
Intakepiston.set_value(true);
    driveStraightSlow(1500, 41.75);
    color = 0;
Hooks.move(0);
    Intakepiston.set_value(false);
    for(int i = 0; i<800; i+=10){
      automacro = 2;
      liftauton();
      delay(10);
    }
    LIFT.move(0);
   color = 2;
    Doinker.set_value(true);
    delay(200);
    color = 0;
    Hooks.move(-127);
    driveTurn2(155);
    Doinker.set_value(false);
    delay(50);
    color = 0;
    driveStraightSlow(1100, 70);
    driveStraightSlow(-300, 80);
    Hooks.move(20);
    for(int i = 0; i<900; i+=10){
      automacro = 3;
      liftauton();
      delay(10);
    }
    LIFT.move(0);
    
    driveStraightC(-250);

    for(int i = 0; i<500; i+=10){
      automacro = 1;
      liftauton();
      delay(10);
    }


    
    break;
    }
     }

if(atn == 2){    
    // Red Mogo 
  color = 1;
    for(int i = 0; i < 15000; i+=10){
color = 0;
ColorSort();
automacro = false;
     LIFT.move(-127);
     delay(450);
     LIFT.move(0);
     delay(250);
     driveStraightSlow(-375, 50);
     LIFT.move(127);
     driveTurn2(60);
     Intakepiston.set_value(true);
     Intake.move(-127);
     driveStraightSlow(550, 50);
     delay(200);
     Intakepiston.set_value(false);
     delay(100);
     driveTurn2(-15);
     LIFT.move(0);
    driveStraightSC(-780, 70);
    driveClampS(-400, 50, 45);
    driveTurn2(81.5);
    Intake.move(0);
    driveStraightSC(700, 60);    
    DoinkerTwo.set_value(true);
    driveStraightSC(-550,45);
    ColorSort();
    color = 1;
    Intake.move(-127);
    DoinkerTwo.set_value(false);
    delay(250);
    driveTurn2(86.5);
    Hooks.move(0);
    Intake.move(0);
    Intake.move(-127);
    driveStraightSC(400, 60);
    delay(100);
    driveStraightSC(-250, 40);
    driveTurn2(-145);
    ColorSort();
    color = 1;
    Intake.move(-127);
    driveStraightSC(400, 55);
   Scoring.move(-100);
   driveTurn2(-75);
   ColorSort();
   color = 1;
   Intake.move(-127);
   driveStraightSC(1100, 50);
   driveStraightSC(850, 40);
  Hooks.move(0);
  Intake.move(0);
   Intake.move(-127);
   driveStraightC(50);
   DoinkerTwo.set_value(true);
   driveStraightSC(-200, 95);
   Intake.move(0);
   ColorSort();
   color = 1;
   Intake.move(-127);
   driveStraightC(25);
   driveTurn2(-175);
    driveTurn2(145);
    driveStraightC(250);
    Mogo.set_value(false);
    driveTurn2(-60);
    driveStraightC(-1000);
    
  

  

   
    

  
    
    break;
    }
     }
    
   
if(atn == 3){    
    // Blue Mogo
    color= 2;
    for(int i = 0; i < 15000; i+=10){
    color = 0;
    ColorSort();
  
    // automacro = 1;
    LIFT.move(-127);
    delay(450);
    LIFT.move(0);
    delay(250);
    driveStraightSlow(-375, 50);
    LIFT.move(127);
    driveTurn2(-60);
    Intakepiston.set_value(true);
    Intake.move(-127);
    driveStraightSlow(550, 50);
    delay(200);
    Intakepiston.set_value(false);
    delay(100);
    driveTurn2(15);
    LIFT.move(0);
   driveStraightSC(-780, 70);
   driveClampS(-400, 50, 45);
   driveTurn2(-81.5);
   Intake.move(0);
   driveStraightSC(700, 60); 
   Doinker.set_value(true);   
   driveStraightSC(-550,45);
   ColorSort();
   color = 2;
   Intake.move(-127);
   Doinker.set_value(false);
   delay(250);
   driveTurn2(-86.5);
   Hooks.move(0);
   Intake.move(0);
   Intake.move(-127);
   driveStraightSC(400, 60);
   delay(100);
   driveStraightSC(-250, 40);
   driveTurn2(145);
   ColorSort();
   color = 2;
   Intake.move(-127);
   driveStraightSC(400, 55);
  Scoring.move(-100);
  driveTurn2(75);
  ColorSort();
  color = 2;
  Intake.move(-127);
  driveStraightSC(1075, 50);
  driveStraightSC(900, 40);
 Hooks.move(0);
 Intake.move(0);
  Intake.move(-127);
  driveStraightC(65);
  Doinker.set_value(true);
  driveStraightSC(-200, 97.5);
  Intake.move(0);
  ColorSort();
  color = 2;
  Intake.move(-127);
  driveStraightC(25);
  driveTurn2(175);
   driveTurn2(-145);
   driveStraightC(250);
   Mogo.set_value(false);
   driveTurn2(-60);
   driveStraightC(-1000);
    
      
    break;
    }
      }

if(atn == 4){    
    // Red Sigawp
   
    for(int i = 0; i < 15000; i+=10){
   
  

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
    ColorSort();
    color = 1;
    Intake.move(-127);
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
   Hooks.move(0);
   Intake.move(0);
    Intake.move(-127);
    driveTurn2(84);
    driveClampS(-1400, 50, 60);
    ColorSort();
    color = 1;
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
      ColorSort();
      color = 2;
      Intake.move(-127);
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
     Hooks.move(0);
     Intake.move(0);
      Intake.move(-127);
      driveTurn2(-84);
      driveClampS(-1400, 50, 60);
      ColorSort();
      color = 2;
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
      // 6 ring sigawp red
     
      for(int i = 0; i < 15000; i+=10){

      
      
      LIFT.move(-127);
      delay(450);
      LIFT.move(0);
      delay(250);
      driveStraightSlow(-150, 65);
      LIFT.move(127);
      driveTurn2(46.5);
      driveClampS(-1550, 50, 50);
      LIFT.move(0);
      driveTurn2(-170);
      color = 1;
      ColorSort();
      Intake.move(-127);
      driveStraightSlow(550, 65);
      delay(300);
      driveTurn2(-190);
      driveStraightSlow(275, 70);
      delay(150);
      driveStraightSC(-100, 25);
      driveTurn2(90);
      driveStraightSC(210, 75);
      driveTurn2(-7);
      driveStraightSC(1100 , 60);
      Intakepiston.set_value(true);
      Mogo.set_value(false);
      color = 0;
      Hooks.move(0);
      driveStraightSlow(2200, 30);
      delay(50);
      Intakepiston.set_value(false);
    driveTurn2(110);
    driveClampS(-1450, 50, 55);
    ColorSort();
    color = 1;
    Hooks.move(-127);
    driveTurn2(-25);
    driveStraightSlow(675, 60);
    driveStraightSC(-235, 95);
    driveTurn2(-140);
driveStraightSC(500, 30);

    

      

   
   
            
      break;
      }
       }


    if(atn == 7){    
      // 6 ring blue sigawp
      
      for(int i = 0; i < 15000; i+=10){
      ColorSort();
     
 

      LIFT.move(-127);
      delay(450);
      LIFT.move(0);
      delay(250);
      driveStraightSlow(-150, 65);
      LIFT.move(127);
      driveTurn2(-46.5);
      driveClampS(-1550, 50, 50);
      LIFT.move(0);
      driveTurn2(170);
      ColorSort();
      color = 2;
      Intake.move(-127);
      driveStraightSlow(550, 65);
      delay(300);
      driveTurn2(-165);
      driveStraightSlow(275, 70);
      delay(150);
      driveStraightSC(-100, 50);
      driveTurn2(-90);
      driveStraightSC(210, 75);
      driveTurn2(6.75);
      driveStraightSC(1100 , 60);
      Intakepiston.set_value(true);
      Mogo.set_value(false);
      color = 0;
      Hooks.move(0);
      driveStraightSlow(2300, 30);
      delay(50);
      Intakepiston.set_value(false);
    driveTurn2(-107.5);
    driveClampS(-1350, 50, 55);
    ColorSort();
    ColorSort();
    color = 2;
    Hooks.move(-127);
    driveTurn2(25);
    driveStraightSlow(675, 60);
    driveStraightSC(-235, 95);
    driveTurn2(140);
driveStraightSC(500, 40);

    


            
              
      break;
      }
       }

    if(atn == 8){    
      color = 1;

    for(int i = 0; i < 150000; i++) {
      color = 0; 
      ColorSort();
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
     color = 1;
     driveTurn2(-145);
     driveStraightSlow(800, 50);
  delay(200);
  driveStraightSC(-750, 60);
  driveTurn2(125);
  driveStraightSlow(50, 50);
  LIFT.move(-127);

     
    
      // // automacro = 1;
      // delay(10);
            
              
      break;
      }
       }
  
  
    if(atn == 9){    
      // Blue Mogo Elim
      color = 2;

    for(int i = 0; i < 150000; i++) {
      color = 0; 
      ColorSort();
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
     color = 2;
     driveTurn2(145);
     driveStraightSlow(800, 50);
  delay(200);
  driveStraightSC(-750, 60);
  driveTurn2(-125);
  driveStraightSlow(50, 50);
  LIFT.move(-127);

                
      break;
      }
       }

    if(atn == 10){    
      // Safety
      color = 0;
      for(int i = 0; i < 15000; i+=10){
      ColorSort();
     
      // automacro = 1;
  driveClampS(-1100, 50, 70);
  Scoring.move(-127);
  driveTurn2(90);
  driveStraightSlow(800, 50);
  delay(200);
  driveStraightSC(-1000, 60);
  driveTurn2(-160);
  driveStraightSlow(50, 50);
  LIFT.move(-127);

              
                
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
      driveStraightSC(725, 65);
      driveTurn2(70);
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
      driveStraightSC(-100, 30);
      driveTurn2(60);
      driveStraightSC(200, 60);
      delay(750);
      driveStraightSC(-200, 50);
      driveTurn2(-45);
       driveStraightSC(-800, 65);
       Scoring.move(0);
       Mogo.set_value(false);
       Hooks.move(40);
       delay(10);
       driveStraightSC(400, 60);
       Hooks.move(0);
       driveTurn2(90);
       driveTurn2(90);
       driveStraightSC(-1450, 50);
       driveClampS(-1185, 50, 45);
       driveTurn2(0);
       Scoring.move(-127);
       driveStraightSC(725, 65);
       driveTurn2(-72.5);
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
       driveStraightSC(-75, 30);
       driveTurn2(-60);
       driveStraightSC(200, 60);
       delay(750);
       driveStraightSC(-200, 50);
       driveTurn2(45);
       driveStraightSC(-800, 65);
       Scoring.move(0);
       Mogo.set_value(false);
       Hooks.move(40);
       delay(50);
       driveStraightSC(200, 60);
       Hooks.move(0);
       driveTurn2(0);
       Intake.move(-127);
       driveStraightSC(2700, 60);
       driveTurn2(-107.5);
       driveStraightSC(-1100, 65);
       driveClampS(-750, 50, 50);
       Intake.move(0);
       driveTurn2(0);
       for(int i = 0; i<800; i+=10){
        automacro = 2;
        liftauton();
        delay(10);
      }
      Hooks.move(-127);
       driveStraightSlow(1100, 40);
       driveStraightSlow(-300, 30);
       Hooks.move(0);
       for(int i = 0; i<900; i+=10){
        automacro = 3;
        liftauton();
        delay(10);
      }



       



      


                
                  
      break;
      }
       }

      }
           
      