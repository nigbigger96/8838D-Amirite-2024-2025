#include "api.h"
#include "auton.h"
#include "main.h"
#include "robot.h"
#include "pid.h"
using namespace std;
using namespace pros;


void autonomous() {


    
    if(atn == 0){
    //Solo AWP

//    driveStraight(200);
//6 inches
//    driveStraight(33.3);
//1 inch
    Mogo.set_value(true);
    driveStraight2(-550);
    driveClampS(-200,33.3,60);






    }





    if(atn == 1) {
    //Blue Mogo



    }


    if(atn == 2){ 
    //Red Ring





    }



    if(atn == 3){
    //Blue Mogo



    }



    if(atn == 4){



    }



    if(atn == 5) {


    }
    


    if(atn == 6) {
        
      
    }



    if(atn == 7) {
    //     driveClampS(-1000, 100, 90);
    //     driveStraight2(-100);
    //     Conveyor.move(127);
    //     driveTurn2(-90);
    //     Mogo.set_value(false);
    //     Conveyor.move(127);
    //     driveStraight2(-250);
    //     driveTurn2(45);
    //     driveClampS(400, 100, 90);
    //     Conveyor.move(127);
    //    driveTurn2(30);
    //    Doinker.set_value(true);
    //    driveStraight2(-1000);
    //    driveTurn2(-160);
    }



    if(atn == 8)  {

    }



    if(atn == 9){
    }


// dirve very slowly with drive straight slow into the 2 stack ring, (like 30%) Then go backward and raise lift and touch ladder

// driveStraightSlow(-800, 100);
// delay(400);
// driveStraightSlow(-800, 35);
// //delay(100);
// //driveStraightSlow(-1200, 40);
// //driveTurn2(10);
// //driveClamp(-500, -200);
// driveTurn2(23);
// delay(200);
// driveStraightSlow(-300, 80);
// driveStraightSlow(-150, 25);
// Mogo.set_value(true);
}

