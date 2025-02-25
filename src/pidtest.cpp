#include "main.h"
#include "robot.h"
#include "api.h"
#include "pid.h"

using namespace pros;
using namespace c;
using namespace std;

double trueTarget = 0;


 void resetEncoders(){

    LF.tare_position();
    LB.tare_position();
    LM.tare_position();
    RF.tare_position();
    RM.tare_position();
    RB.tare_position();

 }

void chasMove(int voltageLF, int voltageLM, int voltageLB, int voltageRF, int voltageRM, int voltageRB){

    LF.move(voltageLF);
    RF.move(voltageRF);
    LM.move(voltageLM);
    RM.move(voltageRM);
    LB.move(voltageLB);
    RB.move(voltageRB);

}





void TdriveStraight(int target){ //int macro = 4)
  
    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (0 * pow(x,5)) +  (0 * pow(x,4)) + (0 * pow(x,3)) + (0 * pow(x,2)) + (0 * x) + 0;

    imu.tare();

    

    double voltage;
    double encoderAVG;
    int count = 0;
    double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    if(init_heading > 180){
        init_heading = init_heading - 360;
    }

    resetEncoders();

    while (true){
        //liftauton(macro);
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
         setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
      
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((init_heading < 0) && (position > 0)){
        if((position - init_heading ) >= 180){
           init_heading = init_heading + 360;
            position = imu.get_heading();
        }
    }else if((init_heading > 0) && (position < 0)){
        if ((init_heading - position) >= 180){
            position = imu.get_heading();
        }
     }
    
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
    headingError = calcPID2(init_heading, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);
        
        if(voltage > 127){
            voltage = 127;
        } else if (voltage < -127){
            voltage = -127;
        }

        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if (abs(target - encoderAVG) <= 4) count++;
        if (count >= 20 || time2 > timeout){
            break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float (error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
             con.print(2,0, "EncoderAVG: %f           ", float(LF.get_encoder_units()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    //liftauton(4);
    
}


 void TdriveTurn(int target){

    double voltage;
    double position;
    int count = 0;
    time2 = 0;
    int timeout = 300000;
    double x = 0;
    double variKD = 0;
    double variKP = 0;
    x = double(abs(target));
    variKD =  (0 * pow(x,5)) +  (0 * pow(x,4)) + (0 * pow(x,3)) + (0 * pow(x,2)) + (0 * x) + 0;
    timeout = (0 * pow(x,5)) +  (0 * pow(x,4)) + (0 * pow(x,3)) + (0 * pow(x,2)) + (0 * x) + 0;


    //variKP = ((0) * pow(x,5)) + (0 * pow(x,4)) + (0.000015948* pow(x,3)) + (-0.00128717 * pow(x,2)) + (0.041072 * x) + 6.7388;
    setConstants(TURN_KP, TURN_KI, TURN_KD);
    imu.tare_heading();

    while(true) { 
        position = imu.get_heading();

        if (position > 180){
            position = ((360 - position) * -1);

        }
        voltage = calcPID2(target, position, TURN_INTEGRAL_KI, TURN_MAX_INTEGRAL);

        chasMove(voltage, voltage, voltage, - voltage, - voltage, - voltage);

        if(abs(target - position) <= 0.95) count++;

        if (count >= 20 || time2 > timeout) {

        break;
        }
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(1,0, "EncoderAVG: %f           ", float(imu.get_heading()));
        }
         if(time2 % 50 == 0){
            con.print(2,0, "time2: %f          ", float(time2));
        }
        
        time2 += 10;
        delay(10); 
    }
        LF.brake();
        LM.brake();
        LB.brake();
        RF.brake();
        RM.brake();
        RB.brake();

}

 void TdriveTurn2(int target){
    trueTarget = target;
    int turnv;
    double voltage;
    double position;
    int count = 0;
    time2 = 0;

    position = imu.get_heading();
     if(position > 180){
        position = ((360 - position)*-1);
     } 
     if ((target <0) && (position > 0)){
        if ((position - target) >= 180){
            target = target + 360;
            position = imu.get_heading();
            turnv = (target - position);
        } else {
            turnv = (abs(position) + abs(target));
        } 
     } else if ((target > 0) && (position < 0)){
        if((target - position) >= 180){
            position = imu.get_heading();
            turnv = (abs(position) - abs(target)); 
        } else {
            turnv = (abs (position) + target);
            }
     } else {
        turnv = abs(abs(position) - abs(target));
     }

    int timeout = 1000000;
    double x = 0;
    double variKD = 0;
    double variKP = 0;
    x = double(abs(turnv));
    variKD = (0 * pow(x,5)) +  (0 * pow(x,4)) + (0 * pow(x,3)) + (0 * pow(x,2)) + (0 * x) + 0;
    timeout = (0 * pow(x,5)) +  (0 * pow(x,4)) + (0 * pow(x,3)) + (0 * pow(x,2)) + (0 * x) + 0;

    //variKP = (0 *pow(x,5)) + (0 *pow(x,4)) + (0 *pow(x,3)) + (0 *pow(x,2)) + (0 *(x)) + 0;
    setConstants(TURN_KP, TURN_KI, TURN_KD);
    while(true) { 
    position = imu.get_heading();
     if(position > 180){
        position = ((360 - position)*-1);
     } 
     if ((target <0) && (position > 0)){
        if ((position - target) >= 180){
            target = target + 360;
            position = imu.get_heading();
            turnv = (target - position);
        } else {
            turnv = (abs(position) + abs(target));
        } 
     } else if ((target > 0) && (position < 0)){
        if((target - position) >= 180){
            position = imu.get_heading();
            turnv = (abs(position) - abs(target)); 
        } else {
            turnv = (abs (position) + target);
            }
     } else {
        turnv = abs(abs(position) - abs(target));
     }

        voltage = calcPID2(target, position, TURN_INTEGRAL_KI, TURN_MAX_INTEGRAL);

        chasMove(voltage, voltage, voltage, - voltage, - voltage, - voltage);

        if(abs(target - position) <= 0.95) count++;

        if (count >= 20 || time2 > timeout) {

        break;
        }
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(1,0, "EncoderAVG: %f           ", float(imu.get_heading()));
        }
         if(time2 % 50 == 0){
            con.print(2,0, "Time2: %f           ", float((time2)));
        }
        
        time2 += 10;
        delay(10); 
    }
        LF.brake();
        LM.brake();
        LB.brake();
        RF.brake();
        RM.brake();
        RB.brake();

}

void TdriveTurnT(int target){
    trueTarget = target;
    int turnv;
    double voltage;
    double position;
    int count = 0;
    time2 = 0;

    position = imu.get_heading();
     if(position > 180){
        position = ((360 - position)*-1);
     } 
     if ((target <0) && (position > 0)){
        if ((position - target) >= 180){
            target = target + 360;
            position = imu.get_heading();
            turnv = (target - position);
        } else {
            turnv = (abs(position) + abs(target));
        } 
     } else if ((target > 0) && (position < 0)){
        if((target - position) >= 180){
            position = imu.get_heading();
            turnv = (abs(position) - abs(target)); 
        } else {
            turnv = (abs (position) + target);
            }
     } else {
        turnv = abs(abs(position) - abs(target));
     }

    int timeout = 1000000;
    double x = 0;
    double variKD = 0;
    double variKP = 0;
    x = double(abs(turnv));
    variKD = (0 * pow(x,5)) +  (0 * pow(x,4)) + (0 * pow(x,3)) + (0 * pow(x,2)) + (0 * x) + 0;
    timeout = (0 * pow(x,5)) +  (0 * pow(x,4)) + (0 * pow(x,3)) + (0 * pow(x,2)) + (0 * x) + 0;

    //variKP = (0 *pow(x,5)) + (0 *pow(x,4)) + (0 *pow(x,3)) + (0 *pow(x,2)) + (0 *(x)) + 0;
    setConstants(TURN_KP, TURN_KI, TURN_KD);
    while(true) { 
    position = imu.get_heading();
     if(position > 180){
        position = ((360 - position)*-1);
     } 
     if ((target <0) && (position > 0)){
        if ((position - target) >= 180){
            target = target + 360;
            position = imu.get_heading();
            turnv = (target - position);
        } else {
            turnv = (abs(position) + abs(target));
        } 
     } else if ((target > 0) && (position < 0)){
        if((target - position) >= 180){
            position = imu.get_heading();
            turnv = (abs(position) - abs(target)); 
        } else {
            turnv = (abs (position) + target);
            }
     } else {
        turnv = abs(abs(position) - abs(target));
     }

        voltage = calcPIDT(target, position, TURN_INTEGRAL_KI, TURN_MAX_INTEGRAL);

        chasMove(voltage, voltage, voltage, - voltage, - voltage, - voltage);

        if(abs(target - position) <= 0.95) count++;

        if (count >= 20 || time2 > timeout) {

        break;
        }
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(1,0, "EncoderAVG: %f           ", float(imu.get_heading()));
        }
         if(time2 % 50 == 0){
            con.print(2,0, "Time2: %f           ", float((time2)));
        }
        
        time2 += 10;
        delay(10); 
    }
        LF.brake();
        LM.brake();
        LB.brake();
        RF.brake();
        RM.brake();
        RB.brake();

}


void TdriveStraight2(int target) {
    
    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (0 * pow(x,5)) +  (0 * pow(x,4)) + (0 * pow(x,3)) + (0 * pow(x,2)) + (0 * x) + 0;
    double voltage;
    double encoderAVG;
    int count = 0;
    //double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(trueTarget > 180) {
    trueTarget = (360 - trueTarget);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((trueTarget < 0) && (position > 0)){
        if((position - trueTarget ) >= 180){
            trueTarget = trueTarget + 360;
            position = imu.get_heading();
        }
    } else if((trueTarget > 0) && (position < 0)){
        if ((trueTarget - position) >= 180){
            position = imu.get_heading();
        }
     }
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(trueTarget, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);
        headingError = 0;

        if(voltage > 127){
            voltage = 127;
        } else if (voltage < -127){
            voltage = -127;
        }

        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if (abs(target - encoderAVG) <= 4) count++;
        if (count >= 20 || time2 > timeout){
           break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(trueTarget));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}


void TdriveStraightSlow(int target, int speed) {

    int timeout = 30000;
    
    double x = 0;
    timeout = (0 * pow(x,5)) +  (0 * pow(x,4)) + (0 * pow(x,3)) + (0 * pow(x,2)) + (0 * x) + 0;
    x = double(abs(target));
    timeout = timeout * (2 - (double(speed)/100.0));
    double voltage;
    double encoderAVG;
    int count = 0;
    // double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(trueTarget > 180) {
    trueTarget = (360 - trueTarget);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((trueTarget < 0) && (position > 0)){
        if((position - trueTarget ) >= 180){
            trueTarget = trueTarget + 360;
            position = imu.get_heading();
        }
    } else if((trueTarget > 0) && (position < 0)){
        if ((trueTarget - position) >= 180){
            position = imu.get_heading();
        }
     }
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(trueTarget, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);
        headingError = 0;

        if(voltage > 127 * double(speed)/100){
            voltage = 127 * double(speed)/100;
        } else if (voltage < -127 * double(speed)/100){
            voltage = -127 * double(speed)/100;
        }

        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if (abs(target - encoderAVG) <= 4) count++;
        if (count >= 20 || time2 > timeout){
           break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(trueTarget));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}







void TdriveStraightC(int target) {

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (0 * pow(x,5)) +  (0 * pow(x,4)) + (0 * pow(x,3)) + (0 * pow(x,2)) + (0 * x) + 0;


 if (target > 0){
    target = target + 500;
 } else{
    target = target - 500;
 }
    double voltage;
    double encoderAVG;
    int count = 0;
    // double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;
    bool over = false;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
        voltage = calcPID2(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(trueTarget > 180) {
    trueTarget = (trueTarget - 360);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((trueTarget < 0) && (position > 0)){
        if((position - trueTarget ) >= 180){
            trueTarget = trueTarget + 360;
            position = imu.get_heading();
        }
    } else if((trueTarget > 0) && (position < 0)){
        if ((trueTarget - position) >= 180){
            position = imu.get_heading();
        }
     }
    
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(trueTarget, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);

        if(voltage > 127){
            voltage = 127;
        } else if (voltage < -127){
            voltage = -127;
        }

        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if(target > 0){
            if((encoderAVG - (target-500)) > 0){
                over = true;
            }
        } else if(((target+500) - encoderAVG) > 0){
        over = true;
        }

        if(over || time2 > timeout){
            break;
        }



        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(time2));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(LF.get_encoder_units()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}



void TdriveClamp(int target, int clampDistance) {

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (0 * pow(x,5)) +  (0 * pow(x,4)) + (0 * pow(x,3)) + (0 * pow(x,2)) + (0 * x) + 0;

    double voltage;
    double encoderAVG;
    int count = 0;
    double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(init_heading > 180) {
    init_heading = (360 - init_heading);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((init_heading < 0) && (position > 0)){
        if((position - init_heading ) >= 180){
            init_heading = init_heading + 360;
            position = imu.get_heading();
        }
    } else if((init_heading > 0) && (position < 0)){
        if ((init_heading - position) >= 180){
            position = imu.get_heading();
        }
     }
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(init_heading, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);
        headingError = 0;

        if(voltage > 127){
            voltage = 127;
        } else if (voltage < -127){
            voltage = -127;
        }

         if(abs(target - encoderAVG) < clampDistance){
            Mogo.set_value(false);
        }


        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if (abs(target - encoderAVG) <= 4) count++;
        if (count >= 20 || time2 > timeout){
           break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(init_heading));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}



void TdriveClampS(int target, int clampDistance, int speed) {

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (0 * pow(x,5)) +  (0 * pow(x,4)) + (0 * pow(x,3)) + (0 * pow(x,2)) + (0 * x) + 0;
    double voltage;
    double encoderAVG;
    int count = 0;
    double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(init_heading > 180) {
    init_heading = (360 - init_heading);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((init_heading < 0) && (position > 0)){
        if((position - init_heading ) >= 180){
            init_heading = init_heading + 360;
            position = imu.get_heading();
        }
    } else if((init_heading > 0) && (position < 0)){
        if ((init_heading - position) >= 180){
            position = imu.get_heading();
        }
     }
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(init_heading, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);
        headingError = 0;


        if(voltage > 127 * double(speed)/100){
            voltage = 127 * double(speed)/100;
        } else if (voltage < -127 * double(speed)/100){
            voltage = -127 * double(speed)/100;
        }
        if(voltage > 127){
            voltage = 127;
        } else if (voltage < -127){
            voltage = -127;
        }

         if(abs(target - encoderAVG) < clampDistance){
            Mogo.set_value(false);
        }


        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if (abs(target - encoderAVG) <= 4) count++;
        if (count >= 20 || time2 > timeout){
           break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(init_heading));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}



void TdriveClampSC(int target, int clampDistance, int speed) {

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (0 * pow(x,5)) +  (0 * pow(x,4)) + (0 * pow(x,3)) + (0 * pow(x,2)) + (0 * x) + 0;

    double voltage;
    double encoderAVG;
    int count = 0;
    double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;
    bool over = false;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(init_heading > 180) {
    init_heading = (360 - init_heading);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((init_heading < 0) && (position > 0)){
        if((position - init_heading ) >= 180){
            init_heading = init_heading + 360;
            position = imu.get_heading();
        }
    } else if((init_heading > 0) && (position < 0)){
        if ((init_heading - position) >= 180){
            position = imu.get_heading();
        }
     }
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(init_heading, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);
        headingError = 0;


        if(voltage > 127 * double(speed)/100){
            voltage = 127 * double(speed)/100;
        } else if (voltage < -127 * double(speed)/100){
            voltage = -127 * double(speed)/100;
        }
        if(voltage > 127){
            voltage = 127;
        } else if (voltage < -127){
            voltage = -127;
        }

         if(abs(target - encoderAVG) < clampDistance){
            Mogo.set_value(false);
        }


        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if (abs(target - encoderAVG) <= 4) count++;
        // if (count >= 20 || time2 > timeout){
        //    break;
        // }

        if(target > 0){
            if((encoderAVG - (target-500)) > 0){
                over = true;
            }
        } else if(((target+500) - encoderAVG) > 0){
        over = true;
        }

        if(over || time2 > timeout){
            break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(init_heading));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}




void TdriveArcL(double theta, double radius, int timeout){
//bool over = false; 
//setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
totalError = 0;
double ltarget = 0; 
double rtarget = 0;
double pi = 3.14159265359;
// . I'm sorry :/ Now deal with pi. cole. why the sigma are you doing this - carlos
// double init_heading = imu.get_heading();

if(trueTarget > 180){
    trueTarget = trueTarget - 360;
}
int time = 0;
int count = 0;
resetEncoders();



ltarget = double((theta/360) *2 * pi * radius);
rtarget = double((theta / 360) * 2 * pi *(radius + 480));
//570
while(true){

setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
double encoderAvgL = LF.get_position(); 
double encoderAvgR = RB.get_position();
int voltageL = calcPID(ltarget, encoderAvgL, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageL > 127){
        voltageL = 127;
    }else if(voltageL < -127){
        voltageL = -127;
    }

    int voltageR = calcPID2(rtarget, encoderAvgR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageR > 127){
        voltageR = 127;
    }else if(voltageR < -127){
        voltageR = -127;
    }

double leftcorrect = -(encoderAvgL * 360) / (2 * pi * radius);
double position = imu.get_heading();

if(position > 180){
    position = position - 360;
}

if((leftcorrect < 0) && (position > 0)){
        if((position - leftcorrect ) >= 180){
            leftcorrect = leftcorrect + 360;
            position = imu.get_heading();
        }
    } else if((leftcorrect > 0) && (position < 0)){
        if ((leftcorrect - position) && (position < 0)){
            position = imu.get_heading();
        }
     }
    setConstants(ARC_HEADING_KP, ARC_HEADING_KI, ARC_HEADING_KD);
    int fix = calcPID3((trueTarget + leftcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);
    if (abs(ltarget - encoderAvgL) <= 25) fix = 0;   
        chasMove( (voltageL + fix), (voltageL + fix), (voltageL + fix), (voltageR - fix), (voltageR - fix), (voltageR - fix));
        if ((abs(ltarget - encoderAvgL) <= 10) && (abs(rtarget - encoderAvgR) <= 10)) count++;
        if (count >= 20 || time > timeout){
            trueTarget -= theta;
            break;
        }

     if(time % 50 == 0 && time % 100 != 0 && time % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(time));
        }
         if(time % 50 == 0 && time % 100 != 0){
            con.print(2,0, "Voltage: %f           ",float(voltageL));
        }
         if(time % 50 == 0){
            con.print(1,0, "leftcorrect: %f           ", float(leftcorrect));
        }
        

        time+= 10;
        delay(10);


    }
}


void TdriveArcLS(double theta, double radius, int timeout, int speed){
// bool over = false; 
setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
totalError = 0;
double ltarget = 0; 
double rtarget = 0;
double pi = 3.14159265359;
// . I'm sorry :/ Now deal with pi. cole. why the sigma are you doing this - carlos
// double init_heading = imu.get_heading();

if(trueTarget > 180){
    trueTarget = trueTarget - 360;
}
int time = 0;
int count = 0;
resetEncoders();



ltarget = double((theta/360) *2 * pi * radius);
rtarget = double((theta / 360) * 2 * pi *(radius + 480));
//570
while(true){

setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
double encoderAvgL = LF.get_position(); 
double encoderAvgR = RB.get_position();
 int voltageL = calcPID(ltarget, encoderAvgL, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

        if(voltageL > 127 * double(speed)/100){
            voltageL = 127 * double(speed)/100;
        } else if (voltageL < -127 * double(speed)/100){
            voltageL = -127 * double(speed)/100;
        }
    

    int voltageR = calcPID2(rtarget, encoderAvgR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
        if(voltageR > 127 * double(speed)/100){
            voltageR = 127 * double(speed)/100;
        } else if (voltageR < -127 * double(speed)/100){
            voltageR = -127 * double(speed)/100;
        }

double leftcorrect = -(encoderAvgL * 360) / (2 * pi * radius);
double position = imu.get_heading();

if(position > 180){
    position = position - 360;
}

if((leftcorrect < 0) && (position > 0)){
        if((position - leftcorrect ) >= 180){
            leftcorrect = leftcorrect + 360;
            position = imu.get_heading();
        }
    } else if((leftcorrect > 0) && (position < 0)){
        if ((leftcorrect - position) && (position < 0)){
            position = imu.get_heading();
        }
     }
    setConstants(ARC_HEADING_KP, ARC_HEADING_KI, ARC_HEADING_KD);
    int fix = calcPID3((trueTarget + leftcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);  
    if (abs(ltarget - encoderAvgL) <= 25) fix = 0;   
        chasMove( (voltageL + fix), (voltageL + fix), (voltageL + fix), (voltageR - fix), (voltageR - fix), (voltageR - fix));
        if ((abs(ltarget - encoderAvgL) <= 10) && (abs(rtarget - encoderAvgR) <= 10)) count++;
        if (count >= 20 || time > timeout){
            trueTarget -= theta;
            break;
        }

     if(time % 50 == 0 && time % 100 != 0 && time % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(time));
        }
         if(time % 50 == 0 && time % 100 != 0){
            con.print(2,0, "Voltage: %f           ",float(voltageL));
        }
         if(time % 50 == 0){
            con.print(1,0, "leftcorrect: %f           ", float(leftcorrect));
        }
        

        time+= 10;
        delay(10);


    }
}




void TdriveArcR(double theta, double radius, int timeout){
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);


double ltarget = 0;
double rtarget = 0;
double pi =  3.14159265359;
// double init_heading = imu.get_heading();
if(trueTarget > 180){
    trueTarget = trueTarget - 360;
}
int count = 0;
time2 = 0;
resetEncoders();

rtarget = double((theta/360) *2 * pi * radius);
ltarget = double((theta / 360) * 2 * pi *(radius + 480)); 

while (true){

if(trueTarget > 180){
    trueTarget = trueTarget - 360;
}
double position = imu.get_heading();

if(position > 180){
    position = position - 360;
}
double encoderAVGL = (LF.get_position() + LB.get_position()) /2;
double encoderAVGR = (RB.get_position() + RB.get_position()) /2;
double rightcorrect = (encoderAVGR * 360) / (2 * pi * radius);

if((rightcorrect < 0) && (position > 0)){
        if((position - rightcorrect) >= 180){
            rightcorrect = rightcorrect + 360;
            position = imu.get_heading();
        }
    } else if((rightcorrect > 0) && (position < 0)){
        if ((rightcorrect - position) >= 180){
            position = imu.get_heading();
        }
     }
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
       
         int voltageL = calcPID(ltarget, encoderAVGL, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL); 
    if (voltageL > 127){
        voltageL = 127;
    }else if(voltageL < -127){
        voltageL = -127;
    }

    int voltageR = calcPID2(rtarget, encoderAVGR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageR > 127){
        voltageR = 127;
    }else if(voltageR < -127){
        voltageR = -127;
    }
    
    setConstants(ARC_HEADING_KP, ARC_HEADING_KI, ARC_HEADING_KD);
int fix = calcPID3((trueTarget + rightcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);
    if (abs(rtarget - encoderAVGR) <= 25) fix = 0;  

    chasMove( (voltageL + fix), (voltageL + fix ), (voltageL + fix), (voltageR - fix), (voltageR - fix), (voltageR - fix));
    if ((abs(ltarget - encoderAVGL) <= 4) && (abs(rtarget - encoderAVGR)<= 4)) count++;
    if (count >= 20  || time2 > timeout){
        trueTarget += theta;
       break;
    }
     if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "fix: %f           ", float(fix));
        } else if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(1,0, "position: %f           ", float(position));
        }else if(time2 % 50 == 0){
            con.print(2,0, "init_heading: %f         ", float(trueTarget + rightcorrect));
        }
        time2 += 10;
        delay(10);
    }   
}


void TdriveArcRS(double theta, double radius, int timeout, int speed){
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);


double ltarget = 0;
double rtarget = 0;
double pi =  3.14159265359;
// double init_heading = imu.get_heading();
if(trueTarget > 180){
    trueTarget = trueTarget - 360;
}
int count = 0;
time2 = 0;
resetEncoders();

rtarget = double((theta/360) *2 * pi * radius);
ltarget = double((theta / 360) * 2 * pi *(radius + 480)); 

while (true){

if(trueTarget > 180){
    trueTarget = trueTarget - 360;
}
double position = imu.get_heading();

if(position > 180){
    position = position - 360;
}
double encoderAVGL = (LF.get_position() + LB.get_position()) /2;
double encoderAVGR = (RB.get_position() + RB.get_position()) /2;
double rightcorrect = (encoderAVGR * 360) / (2 * pi * radius);

if((rightcorrect < 0) && (position > 0)){
        if((position - rightcorrect) >= 180){
            rightcorrect = rightcorrect + 360;
            position = imu.get_heading();
        }
    } else if((rightcorrect > 0) && (position < 0)){
        if ((rightcorrect - position) >= 180){
            position = imu.get_heading();
        }
     }
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
       
         int voltageL = calcPID(ltarget, encoderAVGL, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL); 
        if(voltageL > 127 * double(speed)/100){
            voltageL = 127 * double(speed)/100;
        } else if (voltageL < -127 * double(speed)/100){
            voltageL = -127 * double(speed)/100;
        }
    
    

    int voltageR = calcPID2(rtarget, encoderAVGR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
      if(voltageR > 127 * double(speed)/100){
            voltageR = 127 * double(speed)/100;
        } else if (voltageR < -127 * double(speed)/100){
            voltageR = -127 * double(speed)/100;
        }
    
    setConstants(ARC_HEADING_KP, ARC_HEADING_KI, ARC_HEADING_KD);
int fix = calcPID3((trueTarget + rightcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);
    if (abs(rtarget - encoderAVGR) <= 25) fix = 0;  

    chasMove( (voltageL + fix), (voltageL + fix ), (voltageL + fix), (voltageR - fix), (voltageR - fix), (voltageR - fix));
    if ((abs(ltarget - encoderAVGL) <= 4) && (abs(rtarget - encoderAVGR)<= 4)) count++;
    if (count >= 20  || time2 > timeout){
        trueTarget += theta;
       break;
    }
     if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "fix: %f           ", float(fix));
        } else if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(1,0, "position: %f           ", float(position));
        }else if(time2 % 50 == 0){
            con.print(2,0, "init_heading: %f         ", float(trueTarget + rightcorrect));
        }
        time2 += 10;
        delay(10);
    }   
}





void TdriveArcLF(double theta, double radius, int timeout){
int trueTheta = theta;
setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);

double ltarget = 0; 
double rtarget = 0;
double ltargetF = 0; 
double rtargetF = 0;
double pi = 3.14159265359;
// . I'm sorry :/ Now deal with pi. 
double init_heading = imu.get_heading();
int time = 0;
int count = 0;
bool over = false;
resetEncoders();
ltargetF = double(( theta/360) *2 * pi * radius);
rtargetF = double((theta / 360) * 2 * pi *(radius + 480 ));
theta = theta + 45;
ltarget = double(( theta/360) *2 * pi * radius);
rtarget = double((theta / 360) * 2 * pi *(radius + 480 ));
while(true){

if(init_heading > 180){
    init_heading = init_heading - 360;
}
double position = imu.get_heading();


if(position > 180){
    position = position - 360;
}
double encoderAvgL = LF.get_position(); 
double encoderAvgR = RB.get_position();
double leftcorrect = -(encoderAvgL * 360) / (2 * pi * radius);

if((init_heading + leftcorrect < 0) && (position > 0)){
        if((position - (init_heading + leftcorrect)) >= 180){
            leftcorrect = leftcorrect + 360;
            position = imu.get_heading();
        }
    } else if(((init_heading + leftcorrect) > 0) && (position < 0)){
        if (((init_heading + leftcorrect) - position) >= 180){
            position = imu.get_heading();
        }
     }

     




    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
 
    int voltageL = calcPID(ltarget, encoderAvgL, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageL > 127){
        voltageL = 127;
    }else if(voltageL < -127){
        voltageL = -127;
    }

    int voltageR = calcPID2(rtarget, encoderAvgR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageR > 127){
        voltageR = 127;
    }else if(voltageR < -127){
        voltageR = -127;
    }

 setConstants(ARC_HEADING_KP, ARC_HEADING_KI, ARC_HEADING_KD);
int fix = calcPID3((init_heading + leftcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);

        chasMove( (voltageL + fix), (voltageL + fix), (voltageL + fix), (voltageR - fix), (voltageR - fix), (voltageR - fix));
        
        // if (theta > 0){
        //     if ((encoderAvgL - ltargetF) > 0){
        //         over = true;
        //     }
        // } else {
        //     if ((ltargetF - encoderAvgL)>0){
        //         over = true;
        //     }
        // }
        if (abs(init_heading - position) > trueTheta - 20){
        over = true;
}
        if (over || time > timeout){
            trueTarget -= trueTheta;
            break;
        }

     if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(time2));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(LF.get_encoder_units()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        

        time+= 10;
        delay(10);


    }
}


void TdriveArcRF(double theta, double radius, int timeout){
    int trueTheta = theta;
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
bool over = false;
double ltargetF = 0;
double rtargetF = 0;
double ltarget = 0;
double rtarget = 0;
double pi =  3.14159265359;
double rightcorrect = 0;
int fix = 0;
// . I'm sorry :/ Now deal with pi. 
double init_heading = imu.get_heading();
if(init_heading > 180){
    init_heading = init_heading - 360;
}
int count = 0;
int time2 = 0;
resetEncoders();
rtargetF = double((theta/360) *2 * pi * radius);
ltargetF= double((theta / 360) * 2 * pi *(radius + 480)); 
theta = theta + 45;
rtarget = double((theta/360) *2 * pi * radius);
ltarget = double((theta / 360) * 2 * pi *(radius + 480)); 

while (true){

if(init_heading > 180){
    init_heading = init_heading - 360;
}
double position = imu.get_heading();

if(position > 180){
    position = position - 360;
}

if(((init_heading + rightcorrect) < 0) && (position > 0)){
        if((position - (init_heading + rightcorrect)) >= 180){
            init_heading = init_heading + 360;
            position = imu.get_heading();
        }
    } else if(((init_heading + rightcorrect) > 0) && (position < 0)){
        if (((init_heading + rightcorrect) - position) >= 180){
            position = imu.get_heading();
        }
     }
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
         double encoderAVGL = (LF.get_position() + LB.get_position()) /2;
         double encoderAVGR = (RF.get_position() + RB.get_position()) /2;
         int voltageL = calcPID(ltarget, encoderAVGL, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL); 
    if (voltageL > 127){
        voltageL = 127;
    } else if(voltageL < -127){
        voltageL = -127;
    }

    int voltageR = calcPID2(rtarget, encoderAVGR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageR > 127){
        voltageR = 127;
    }else if(voltageR < -127){
        voltageR = -127;
    }
    rightcorrect = (encoderAVGR * 360) / (2 * pi * radius);
        setConstants(ARC_HEADING_KP, ARC_HEADING_KI, ARC_HEADING_KD);
fix = calcPID3((init_heading + rightcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);
// if (abs(rtarget - encoderAVGR) <= 25) fix = 0;
//fix = 0;

    // if (fix > 40){
    //     fix = 40;
    // }else if(fix < -40){
    //     fix = -40;
    // }
    chasMove( (voltageL + fix), (voltageL + fix ), (voltageL + fix), (voltageR - fix), (voltageR - fix), (voltageR - fix));
//    if (theta > 0){
//     if ((encoderAVGR - (rtargetF)) > 0){
//         over = true;
//     }
//    } else {
//     if(((rtarget) - encoderAVGR) > 0){
//         over = true;
//     }
//    }


if (abs(init_heading - position) > trueTheta){
    over = true;
}
    if (over || time2 > timeout){
        break;
    }

    //fix = calcPID3((init_heading + rightcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);
     if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "fix: %f           ", float(fix));
        } else if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(1,0, "encodeR %f           ", float(encoderAVGR));
        }else if(time2 % 50 == 0){
            con.print(2,0, "encodeL: %f         ", float(encoderAVGL));
        }
        time2 += 10;
        delay(10);
    }   
} 



void TdriveDoink(int target, int doinkDistance) {

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (0 * pow(x,5)) +  (0 * pow(x,4)) + (0 * pow(x,3)) + (0 * pow(x,2)) + (0 * x) + 0;

    double voltage;
    double encoderAVG;
    int count = 0;
    // double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(trueTarget > 180) {
    trueTarget = (360 - trueTarget);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((trueTarget < 0) && (position > 0)){
        if((position - trueTarget ) >= 180){
            trueTarget = trueTarget + 360;
            position = imu.get_heading();
        }
    } else if((trueTarget > 0) && (position < 0)){
        if ((trueTarget - position) >= 180){
            position = imu.get_heading();
        }
     }
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(trueTarget, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);
        headingError = 0;

        if(voltage > 127){
            voltage = 127;
        } else if (voltage < -127){
            voltage = -127;
        }

         if(abs(target - encoderAVG) < doinkDistance){
            Doinker.set_value(true);
        }


        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if (abs(target - encoderAVG) <= 4) count++;
        if (count >= 20 || time2 > timeout){
           break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(error));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(trueTarget));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}


void TdriveDoinkC(int target, int doinkDistance){

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (0 * pow(x,5)) +  (0 * pow(x,4)) + (0 * pow(x,3)) + (0 * pow(x,2)) + (0 * x) + 0;


 if (target > 0){
    target = target + 500;
 } else{
    target = target - 500;
 }
    double voltage;
    double encoderAVG;
    int count = 0;
    // double init_heading = imu.get_heading();
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;
    bool over = false;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;
        setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
        voltage = calcPID2(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

if(trueTarget > 180) {
    trueTarget = (trueTarget - 360);
}


        
       double position = imu.get_heading();

      if(position > 180){
        position = position - 360;
      }

    if((trueTarget < 0) && (position > 0)){
        if((position - trueTarget ) >= 180){
            trueTarget = trueTarget + 360;
            position = imu.get_heading();
        }
    } else if((trueTarget > 0) && (position < 0)){
        if ((trueTarget - position) >= 180){
            position = imu.get_heading();
        }
     }
    
    
    setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
        headingError = calcPID2(trueTarget, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);

        if(voltage > 127){
            voltage = 127;
        } else if (voltage < -127){
            voltage = -127;
        }

        if(abs(target - encoderAVG) < doinkDistance){
        Doinker.set_value(true);
        }
        
        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if(target > 0){
            if((encoderAVG - (target-500)) > 0){
                over = true;
            }
        } else if(((target+500) - encoderAVG) > 0){
        over = true;
        }

        if(over || time2 > timeout){
            break;
        }



        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "ERROR: %f           ", float(time2));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(2,0, "EncoderAVG: %f           ", float(LF.get_encoder_units()));
        }
         if(time2 % 50 == 0){
            con.print(1,0, "Time2: %f           ", float(time2));
        }
        
        
        time2 += 10;


    }
    LF.brake();
    RF.brake();
    LM.brake();
    RM.brake();
    LB.brake();
    RB.brake();

    
}





