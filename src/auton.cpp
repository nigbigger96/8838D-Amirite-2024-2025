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

    color = 0;

    

    }
    if(atn == 1) {
      //Blue Ring
    color = 1;

    }

    if(atn == 2){ 
    //red mogo
    color = 0;
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

