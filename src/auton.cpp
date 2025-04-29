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

color = 1;

  //   for(int i = 0; i < 150000; i++) {
      
  // break;

//}


// color = 0;
//   ColorSort();
//       Doinker.set_value(true);
//       driveStraightC(1025);
//       Intake.move(-127);
//       driveStraightSlow(700, 40);
//       delay(25);
//       driveTurn2(-30);
//       driveClampS(-975, 50, 57.5);
//       // ColorSort();
//       color = 1;
//       Doinker.set_value(false);
//       driveTurn2(-60);
//       driveStraightSC(875, 50);
//       driveTurn2(-160);
//       delay(200);
//       driveStraightSC(800, 65);
//       driveTurn2(-103.5);
//       delay(200);
//       Hooks.move(0);
//       driveStraightSlow(1375, 75);
//       Intake.move(-127);
//       delay(475);
//       driveStraightSC(-625, 47.5);
//       driveTurn2(110);
//       delay(50);
//       // ColorSort();
//       color = 1;
//       driveStraightSC(535, 70);
//       driveStraightSlow(150, 40);
//       delay(500);
//      Intakepiston.set_value(true);
//       Intake.move(-127);
//       driveStraightSlow(950, 25);

//       for(int i = 0; i<300; i+=10){
//         automacro = 2;
//         liftauton();
//         delay(10);
//       }
//       DoinkerTwo.set_value(true);
//       driveTurn2(-160);

 
  // for(int i = 0; i < 1000;) {
  //     liftauton();
  //     automacro = 2;
  //     if (roto.get_angle() > 32200){
  //       break;
  //     }

  // }
  //     driveStraight2(400);
   
      


      // Scoring.move(-127);



   
    
   }
    
  

if(atn == 1){    
    // Blue Ring 
color = 2;
    for(int i = 0; i < 15000; i+=10){
     color =0;
     ColorSort();
\
     
    DoinkerTwo.set_value(true);
    driveStraightC(1000);
    Intake.move(-127);
    driveStraightSlow(700, 45);
    delay(25);
    driveTurn2(27.5);
    driveClampS(-975, 50, 57.5);
 //   ColorSort();
     color = 2;
    DoinkerTwo.set_value(false);
    driveTurn2(60);
    driveStraightSC(850, 50);
    driveTurn2(160);
    delay(200);
    driveStraightSC(775, 80);
    driveTurn2(-103.5);
  Hooks.move(0);
    driveStraightSlow(1350, 65);
    Intake.move(-127);
    delay(475);
    driveStraightSC(-500, 55);
    delay(50);
    driveTurn2(250);
    delay(50);
 //   ColorSort();
    color = 2;
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
  
    for(int i = 0; i < 15000; i+=10){


     delay(2000);
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
    ColorSort();
    color = 1;
    Intake.move(-127);
    DoinkerTwo.set_value(false);
    delay(250);
    driveTurn2(86.5);
    Hooks.move(0);
    Intake.move(0);
    Intake.move(-127);
    driveStraightSC(400, 55);
    delay(100);
    driveStraightSC(-250, 40);
    driveTurn2(-145);
    ColorSort();
    color = 1;
    Intake.move(-127);
    driveStraightSC(400, 55);
   Scoring.move(-100);
   driveTurn2(-70);
   ColorSort();
   color = 1;
   Intake.move(-127);
   driveStraightSC(1000, 80);
   driveStraightSC(500, 65);
  Hooks.move(0);
  Intake.move(0);
   Intake.move(-127);
   driveStraightSlow(500, 70);
   delay(50);
   DoinkerTwo.set_value(true);
   driveStraightSlow(-350, 70);
   Intake.move(0);
   ColorSort();
   color = 1;
   Intake.move(-127);
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
    
    for(int i = 0; i < 15000; i+=10){
    
  
    // automacro = 1;
    delay(1000);
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
   ColorSort();
   color = 2;
   Intake.move(-127);
   Doinker.set_value(false);
   delay(250);
   driveTurn2(-86.5);
   Hooks.move(0);
   Intake.move(0);
   Intake.move(-127);
   driveStraightSC(400, 55);
   delay(100);
   driveStraightSC(-250, 40);
   driveTurn2(145);
   ColorSort();
   color = 2;
   Intake.move(-127);
   driveStraightSC(400, 55);
  Scoring.move(-100);
  driveTurn2(70);
  ColorSort();
  color = 2;
  Intake.move(-127);
  driveStraightSC(1000, 80);
  driveStraightSC(500, 65);
 Hooks.move(0);
 Intake.move(0);
  Intake.move(-127);
  driveStraightSlow(500, 70);
  delay(50);
  Doinker.set_value(true);
  driveStraightSlow(-350, 70);
  Intake.move(0);
  ColorSort();
  color = 2;
  Intake.move(-127);
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
      driveTurn2(-172.5);
      color = 1;
      ColorSort();
      Intake.move(-127);
      driveStraightSlow(600, 65);
      delay(300);
      driveTurn2(-182.5);
      driveStraightSlow(275, 70);
      delay(150);
      driveStraightSC(-100, 50);
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
    driveTurn2(100);
    driveClampS(-1450, 50, 55);
    ColorSort();
    color = 1;
    Hooks.move(-127);
    driveTurn2(-25);
    driveStraightSlow(675, 60);
    driveStraightSC(-235, 95);
    driveTurn2(-140);
driveStraightSC(500, 40);

    

      

   
   
            
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
      driveTurn2(172.5);
      ColorSort();
      color = 2;
      Intake.move(-127);
      driveStraightSlow(600, 65);
      delay(300);
      driveTurn2(182.5);
      driveStraightSlow(275, 70);
      delay(150);
      driveStraightSC(-100, 50);
      driveTurn2(-90);
      driveStraightSC(210, 75);
      driveTurn2(7);
      driveStraightSC(1100 , 60);
      Intakepiston.set_value(true);
      Mogo.set_value(false);
      color = 0;
      Hooks.move(0);
      driveStraightSlow(2200, 30);
      delay(50);
      Intakepiston.set_value(false);
    driveTurn2(-100);
    driveClampS(-1450, 50, 55);
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
      color = 2;

    for(int i = 0; i < 150000; i++) {
    
      ColorSort();
      Mogo.set_value(true);
      Intake.move(-127);
      driveStraightSC(1000, 30);
      driveStraightSC(1000, 30);

      driveStraightSC(1000, 30);
      driveStraightSC(1000, 30);
      driveStraightSC(1000, 30);
      driveStraightSC(1000, 30);
    
      // // automacro = 1;
      // delay(10);
            
              
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
      driveStraightSC(-75, 30);
      driveTurn2(67.5);
      driveStraightSC(200, 60);
      delay(750);
      driveStraightSC(-200, 50);
      driveTurn2(-45);
       driveStraightSC(-800, 65);
       Scoring.move(0);
       Mogo.set_value(false);
       Hooks.move(40);
       delay(10);
       driveStraightSC(470, 60);
       Hooks.move(0);
       driveTurn2(90);
       driveStraightSC(-1600, 60);
       driveClampS(-1100, 50, 60);



      


                
                  
      break;
      }
       }

      }
           
      