#include "main.h"
#include "robot.h"
#include "api.h"
#include "pid.h"

using namespace pros;
using namespace c;
using namespace std;

double trueTarget = 0;

int Jam = 1;
int color = 0;
bool stall = false;

double totalError;
int ringTime = 0;
double vKp;
double vKi;
double vKd;
double prevPower;
double currentpower;
double prevError;
double h;
double power;
float error;
int integral;
int derivitive;
int time2;
//Round two of variables. :/
double vKp2;
double vKi2;
double vKd2;
double prevPower2;
double currentpower2;
double prevError2;
double h2;
double power2;
float error2;
int integral2;
int derivitive2;
int time3;
// round three of variables :/ :/ 
double vKp3;
double vKi3;
double vKd3;
double prevPower3;
double currentpower3;
double prevError3;
double h3;
double power3;
float error3;
int integral3;
int derivitive3;
int time4;

double vKpl;
double vKil;
double vKdl;
double prevPowerl;
double currentpowerl;
double prevErrorl;
double hl;
double powerl;
float errorl;
int integrall;
int derivitivel;
int timel;

bool Backwards = false;
bool InitColor = false; 
int hookCount = 0;
double hookPos = 0;
double prevHook = 0;
bool stalled = false;
int stallTime = 0;

double LIFT_angle = 0;

void setConstants2(double kp, double ki, double kd){

    vKp2 = kp;
    vKi2 = ki;
    vKd2 = kd;
}

void ColorSort() {
    Opticala.set_led_pwm(100);
    if (color == 1) {
        if((Opticala.get_hue()<260 && Opticala.get_hue()>215) && Opticala.get_proximity()>100) {
            InitColor = true;
            Hooks.tare_position();
        }

        if (InitColor) {
            if(Backwards == false) {
            Hooks.move(-127);
            if(Hooks.get_position()< -10) {
                Backwards = true;
            }     } else{
                Hooks.move(127);
                if(Hooks.get_position() > 0) {
                    Backwards = false;
                    InitColor = false;
                }

            } 
        } else {
            Hooks.move(-127);
            prevHook = hookPos;
            hookPos = Hooks.get_position();
            if(prevHook ==hookPos) {
                hookCount++;
            } 

            if (hookCount > 8) {
                stalled = true;
            }
            if(stalled) {
                Hooks.move(127);
                stallTime+=10;
                if(stallTime > 400) {
                    hookCount = 0;
                    stalled = false;
                    stallTime = 0;
                }
            }   else {
                Hooks.move(-127);
            }
            
        
    }
} else if (color == 2) {
    if((Opticala.get_hue()>330 || Opticala.get_hue()<30) && Opticala.get_proximity()>100) {
        InitColor = true;
        Hooks.tare_position();
    }

    if (InitColor) {
        if(Backwards == false) {
        Hooks.move(-127);
        if(Hooks.get_position()<-10) {
            Backwards = true;
        }     } else{
            Hooks.move(127);
            if(Hooks.get_position() > 0) {
                Backwards = false;
                InitColor = false;
            }

        } 
    } else {
        Hooks.move(-127);
        prevHook = hookPos;
        hookPos = Hooks.get_position();
        if(prevHook ==hookPos) {
            hookCount++;
        } 

        if (hookCount > 8) {
            stalled = true;
        }
        if(stalled) {
            Hooks.move(127);
            stallTime+=10;
            if(stallTime > 400) {
                hookCount = 0;
                stalled = false;
                stallTime = 0;
            }
        }   else {
            Hooks.move(-127);
        }
        

}
}
}

// bool InitColor = false;
// bool InitCorrect = false;
// int ColorCount;
// bool Backwards = false;
// bool sortOn = false;
// int colorCount = 0;
// void ColorSort(){
//     Opticala.set_led_pwm(100);
//     if (color == 0){ //blue
//         if(Opticala.get_hue()<250 && Opticala.get_hue()>180){
//             sortOn = true;
//         }


//         if(sortOn && colorCount<250){
//             D1Discriminator.set_value(true);
//             colorCount+=10;
//         } else {
//             sortOn = false;
//             colorCount = 0;
//             D1Discriminator.set_value(false);
//         }

//     }  else if (color == 1){ //red
//         if(Opticala.get_hue()<30 || Opticala.get_hue()>335){
//             sortOn = true;
//         }
//         if(sortOn && colorCount<250){
//             D1Discriminator.set_value(true);
//             colorCount+=10;
//         } else {
//             sortOn = false;
//             colorCount = 0;
//             D1Discriminator.set_value(false);
//         }
//     }
// }




// void ColorSort(){
//     Opticala.set_led_pwm(100);
//     if (color == 0){ //blue
//         if(Opticala.get_hue()<250 && Opticala.get_hue()>180){
//             InitColor = true;
//         }

//         if(InitColor){
//             if(Backwards == false){
//                 Intake.move(100);
//                 if(Intake.get_position() > 530){ //need to tune. Encoder units for how far from sensed position to fling
//                     Backwards = true;
//                 }
//             } else {
//                 Intake.move(-50);//-127
//                 if(Intake.get_position() < 200){ //100
//                     Backwards = false;
//                     InitColor = false;
//                 } 
//             }
//         } else {
//             Intake.move(127);
//             Intake.tare_position();
//         }

//     }  else if (color == 1){ //red
//         if(Opticala.get_hue()<30 && Opticala.get_hue()>330){
//             InitColor = true;
//         }

//         if(InitColor){
//             if(Backwards == false){
//                 Intake.move(127);
//                 if(Intake.get_position() > 500){ //need to tune. Encoder units for how far from sensed position to fling
//                     Backwards = true;
//                 }
//             } else {
//                 Intake.move(-127);
//                 if(Intake.get_position() < 200){
//                     Backwards = false;
//                     InitColor = false;
//                 }
//             }
//         } else {
//             Intake.move(127);
//             Intake.tare_position();
//         }
//     }
// }

//int stallCount = 0;
// bool stalled = false;
// int HooksPosition = 0;
// int prevHooksPosition = 0;
// int stallTime = 0;

// void stallProtection() {
   
//     if (stall) {
//         prevHooksPosition = HooksPosition;
//         HooksPosition = Intake.get_position(); 
//         if (HooksPosition == prevHooksPosition) {
//             stallCount += 10;
//         } else {
//             stallCount = 0;
//         } 

//         if (stallCount > 130) {
//             stalled = true;
//         }
        
//         if (stalled){
//             stallTime += 10;
//             Intake.move(-80);
//             if (stallTime >= 200) {
//                 stalled = false;
//                 stallTime = 0;
//             }
//         } else {
//             Intake.move(127);
//             stallTime = 0;

//         }      

//     }
// }

void liftauton(){
    LIFT_angle = roto.get_angle();
    if (LIFT_angle < 3000) {
        LIFT_angle += 36000;
    }

    if (automacro == 1) {
		//zero position
		setConstants2(LIFT_KP, LIFT_KI, LIFT_KD);
 		LIFT.move(calcPIDlift(35000, LIFT_angle, 0, 0, 1));
	} else if (automacro == 2) {
		//first prime
		setConstants2(LIFT_KP, LIFT_KI, LIFT_KD);
 		LIFT.move(calcPIDlift(32150, LIFT_angle, 0, 0, 1));

	} else if (automacro == 3){
		//second prime
		
        setConstants2(3, 0, 16.5);
 		LIFT.move(calcPIDlift(14000, LIFT_angle, 0, 0, 1));
    } else if (automacro == 4){ 
		//descore
        setConstants2(LIFT_KP, LIFT_KI, LIFT_KD);
 		LIFT.move(calcPIDlift(17000, LIFT_angle, 0, 0, 1)); 
	} else {
         LIFT.move(0);
         LIFT.brake();
    }




}




void setConstants(double kp, double ki, double kd){

    vKp = kp;
    vKi = ki;
    vKd = kd;
}

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

double calcPID(double target, double input, int integralKI, int maxIntegral){
  liftauton();
     ColorSort();
   // stallProtection();
    int integral;
    prevError = error;
    error = target - input;

    if(abs(error) < integralKI){
        integral += error; 
    }
    else{
        integral = 0;
    }
    if(integral >= 0){
        integral = min(integral, maxIntegral);
    }
    else{
        integral = max(integral, -maxIntegral);
    }
    derivitive = error - prevError;

    power = (vKp * error) + (vKi * integral) + (vKd * derivitive);

    return power;

    
}

double calcPID2(double target2, double input2, int integralKI2, int maxIntegral2){

    // ColorSort();
    int integral2;
    prevError2 = error2;
    error2 = target2 - input2;

    if(abs(error2) < integralKI2){
        integral2 += error2;
    }
    else{
        integral2 = 0;
    }
    if(integral2 >= 0){
        integral2 = min(integral2, maxIntegral2);
    }
    else{
        integral2 = max(integral2, -maxIntegral2);
    }
    derivitive2 = error2 - prevError2;

    power2 = (vKp * error2) + (vKi * integral2) + (vKd * derivitive2);

    return power2;

}

double calcPID3(double target3, double input3, int integralKI3, int maxIntegral3){

    int integral3;
    prevError3 = error3;
    error3 = target3 - input3;

    if(abs(error3) < integralKI3){
        integral3 += error3;
    }
    else{
        integral3 = 0;
    }
    if(integral3 >= 0){
        integral3 = min(integral3, maxIntegral3);
    }
    else{
        integral3 = max(integral3, -maxIntegral3);
    }
    derivitive3 = error3 - prevError3;

    power3 = (vKp * error3) + (vKi * integral3) + (vKd * derivitive3);

    return power3;

} 

double calcPIDlift(double targetl, double inputl, int integralKIl, int maxIntegrall,int bias){
    // setConstants2(LIFT_KP, LIFT_KI, LIFT_KD);
    int integrall;
    prevErrorl = errorl;
    errorl = targetl - inputl;

    if(abs(errorl) < integralKIl){
        integrall += error3;
    }
    else{
        integrall = 0;
    }
    if(integrall >= 0){
        integrall = min(integrall, maxIntegrall);
    }
    else{
        integrall = max(integrall, -maxIntegrall);
    }
    derivitivel = errorl - prevErrorl;

    powerl = (vKp2 * errorl) + (vKi2 * integrall) + (vKd2 * derivitivel);
///// first way of powering lift ( only multiplying on the way up)
    // if(error > 0 ) {
    //     powerl= powerl * bias;
    // }
///// second way of powering lift( multipling on the way up and dividing on the way down)
    if(errorl < 0) {
       // powerl = powerl * bias;
    } else {
        powerl = powerl / bias;
    }
// ///// Third way of powering lift 
//   powerl += bias;
/////
   return powerl;

} 





//if (DaSortMaster == true){
	//int delayTime = 200;
	//ringTime += 1;
	//
	// DaSorter.set_value(true);

	// if (ringTime >= 1300) {
	// 	DaSortMaster = false;
	// 	ringTime=0;

// 	}
//      else if (ringTime>= 1000){
// 		Conveyor.move(-127);
	
// 	} else {
// 		Conveyor.move(127);
// 	}
// 	} else{
// 		Conveyor.move(127);
// 	} 
// }


void driveStraight(int target){ //int macro = 4)
  
    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
   // timeout = (0.000000000000222338 * pow(x,5)) +  (-0.00000000156125 * pow(x,4)) + (0.0000040982 * pow(x,3)) + (-0.00494966 * pow(x,2)) + (3.01987 * x) + 360.01232; ///variable timeout

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


    
}


 void driveTurn(int target){

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

 void driveTurn2(int target){
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
    variKD = (0.00000000448142 * pow(x,5)) +  (-0.0000023721 * pow(x,4)) + (0.000476337 * pow(x,3)) + (0-0.0456442* pow(x,2)) + (2.30482 * x) + -5.79329;
    timeout = (  -0.00000000221696 * pow(x,5)) +  (0.0000053207 * pow(x,4)) + (-0.00172341 * pow(x,3)) + (0.195436 * pow(x,2)) + (-6.05657 * x) + 592.42424;

    //variKP = (0 *pow(x,5)) + (0 *pow(x,4)) + (0 *pow(x,3)) + (0 *pow(x,2)) + (0 *(x)) + 0;
    setConstants(TURN_KP, TURN_KI, variKD);
    // if (fabs(error2) <= 2) {
    //     setConstants(9, 0, 0);
    // } else {
    // setConstants(TURN_KP, TURN_KI, TURN_KD);
    // }

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

        voltage = calcPID(target, position, TURN_INTEGRAL_KI, TURN_MAX_INTEGRAL);

        chasMove(voltage, voltage, voltage, - voltage, - voltage, - voltage);

        if(abs(target - position) <= 0.95) count++;

        if (count >= 20 || time2 > timeout) {

        break;
        }
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "error2: %f           ", float(error2));
        }
         if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(1,0, "EncoderAVG: %f           ", float(imu.get_heading()));
        }
         if(time2 % 50 == 0){
            con.print(2,0, "time2: %f           ", float((time2)));
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




void driveStraight2(int target) {

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (0.000000000000319827 * pow(x,5)) +  ( -0.00000000210804 * pow(x,4)) + (0.00000490242 * pow(x,3)) + (-0.00475824  * pow(x,2)) + (2.1909 * x) + 375.64904;
    double voltage;
    double encoderAVG;
    int count = 0;
   
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;

        setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
        if(abs(target - encoderAVG) < 22.5) {
            setConstants(2.575, 0, 0); //3.075 ///Onl
        } else {
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
        }

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

        // if(abs(target - encoderAVG) < (target * .10)){
        //     STRAIGHT_KD * 2;
        // }

        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if (abs(target - encoderAVG) <= 4) count++;
        if (count >= 20 || time2 > timeout){
           break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "error: %f           ", float(error));
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


void driveStraightSlow(int target, int speed) {

    int timeout = 30000;
    
    double x = 0;
    timeout = (0.000000000000319827 * pow(x,5)) +  ( -0.00000000210804 * pow(x,4)) + (0.00000490242 * pow(x,3)) + (-0.00475824  * pow(x,2)) + (2.1909 * x) + 375.64904;
    x = double(abs(target));
    timeout = timeout * (2 - (double(speed)/100.0));
    double voltage;
    double encoderAVG;
    int count = 0;
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;

        setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
        if(abs(target - encoderAVG) < 22.5) {
            setConstants(2.575, 0, 0); //3.075 ///Onl
        } else {
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
        }

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
            con.print(0,0, "error: %f           ", float(error));
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



void driveStraightC(int target) {

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (0.000000000000319827 * pow(x,5)) +  ( -0.00000000210804 * pow(x,4)) + (0.00000490242 * pow(x,3)) + (-0.00475824  * pow(x,2)) + (2.1909 * x) + 375.64904;

 if (target > 0){
    target = target + 500;
 } else{
    target = target - 500;
 }
    double voltage;
    double encoderAVG;
    int count = 0;
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;
    bool over = false;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;

        setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
        if(abs(target - encoderAVG) < 22.5) {
            setConstants(2.575, 0, 0); //3.075 ///Onl
        } else {
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
        }

        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

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
            con.print(0,0, "error: %f           ", float(error));
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





void driveStraightSC(int target, int speed) {

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (0.000000000000319827 * pow(x,5)) +  ( -0.00000000210804 * pow(x,4)) + (0.00000490242 * pow(x,3)) + (-0.00475824  * pow(x,2)) + (2.1909 * x) + 375.64904;


 if (target > 0){
    target = target + 500;
 } else{
    target = target - 500;
 }
    double voltage;
    double encoderAVG;
    int count = 0;
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;
    bool over = false;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;

        setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
        if(abs(target - encoderAVG) < 22.5) {
            setConstants(2.575, 0, 0); //3.075 ///Onl
        } else {
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
        }

        voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

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

        if(voltage > 127 * double(speed)/100){
            voltage = 127 * double(speed)/100;
        } else if (voltage < -127 * double(speed)/100){
            voltage = -127 * double(speed)/100;
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
            con.print(0,0, "error: %f           ", float(error));
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




void driveClamp(int target, int clampDistance) {

    int timeout = 0;

    double x = 0;
    x = double(abs(target));
    timeout = (0.000000000000109572 * pow(x,5)) +  ( -0.000000000539012 * pow(x,4)) + (0.000000775841 * pow(x,3)) + (-0.000327561  * pow(x,2)) + (0.674506 * x) + 543.33301;
    double voltage;
    double encoderAVG;
    int count = 0;
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;

        setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
        if(abs(target - encoderAVG) < 22.5) {
            setConstants(2.575, 0, 0); //3.075 ///Onl
        } else {
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
        }

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

         if(abs(target - encoderAVG) < clampDistance){
            Mogo.set_value(true);
        }


        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        if (abs(target - encoderAVG) <= 4) count++;
        if (count >= 20 || time2 > timeout){
           break;
        }

        delay(10);
        if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "error: %f           ", float(error));
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



void driveClampS(int target, int clampDistance, int speed) {

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (0.000000000000109572 * pow(x,5)) +  ( -0.000000000539012 * pow(x,4)) + (0.000000775841 * pow(x,3)) + (-0.000327561  * pow(x,2)) + (0.674506 * x) + 543.33301;
    double voltage;
    double encoderAVG;
    int count = 0;
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;

        setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
        if(abs(target - encoderAVG) < 22.5) {
            setConstants(2.575, 0, 0); //3.075 ///Onl
        } else {
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
        }

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
        if(voltage > 127){
            voltage = 127;
        } else if (voltage < -127){
            voltage = -127;
        }

         if(abs(target - encoderAVG) < clampDistance){
            Mogo.set_value(true);
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

void driveClampSC(int target, int clampDistance, int speed) {

    int timeout = 30000;
    bool over = false;
    double x = 0;
    x = double(abs(target));
    timeout = (0.000000000000109572 * pow(x,5)) +  ( -0.000000000539012 * pow(x,4)) + (0.000000775841 * pow(x,3)) + (-0.000327561  * pow(x,2)) + (0.674506 * x) + 543.33301;
    double voltage;
    double encoderAVG;
    int count = 0;
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        encoderAVG = (LF.get_position() + RF.get_position()) / 2;

        setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
        if(abs(target - encoderAVG) < 22.5) {
            setConstants(2.575, 0, 0); //3.075 ///Onl
        } else {
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
        }

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
        if(voltage > 127){
            voltage = 127;
        } else if (voltage < -127){
            voltage = -127;
        }

         if(abs(target - encoderAVG) < clampDistance){
            Mogo.set_value(true);
        }


        chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
        // if (abs(target - encoderAVG) <= 4) count++;
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




// void driveClampSC(int target, int clampDistance, int speed) {

//     int timeout = 30000;

//     double x = 0;
//     x = double(abs(target));
//    timeout = (0.000000000000109572 * pow(x,5)) +  ( -0.000000000539012 * pow(x,4)) + (0.000000775841 * pow(x,3)) + (-0.000327561  * pow(x,2)) + (0.674506 * x) + 543.33301;
//     double voltage;
//     double encoderAVG;
//     int count = 0;
//     double init_heading = imu.get_heading();
//     double headingError = 0;
//     int cycleTime = 0;
//     time2 = 0;
//     bool over = false;

//     setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
//     resetEncoders();

//     while (true){
//         encoderAVG = (LF.get_position() + RF.get_position()) / 2;
//         setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);   
//         voltage = calcPID(target, encoderAVG, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);

// if(init_heading > 180) {
//     init_heading = (360 - init_heading);
// }


        
//        double position = imu.get_heading();

//       if(position > 180){
//         position = position - 360;
//       }

//     if((init_heading < 0) && (position > 0)){
//         if((position - init_heading ) >= 180){
//             init_heading = init_heading + 360;
//             position = imu.get_heading();
//         }
//     } else if((init_heading > 0) && (position < 0)){
//         if ((init_heading - position) >= 180){
//             position = imu.get_heading();
//         }
//      }
    
//     setConstants(HEADING_KP, HEADING_KI, HEADING_KD);  
//         headingError = calcPID2(init_heading, position, HEADING_INTEGRAL_KI, HEADING_MAX_INTEGRAL);
//         headingError = 0;


//         if(voltage > 127 * double(speed)/100){
//             voltage = 127 * double(speed)/100;
//         } else if (voltage < -127 * double(speed)/100){
//             voltage = -127 * double(speed)/100;
//         }
//         if(voltage > 127){
//             voltage = 127;
//         } else if (voltage < -127){
//             voltage = -127;
//         }

//          if(abs(target - encoderAVG) < clampDistance){
//             Mogo.set_value(true);
//         }


//         chasMove((voltage + headingError), (voltage + headingError), (voltage + headingError), (voltage - headingError), (voltage - headingError),(voltage - headingError));
//         if (abs(target - encoderAVG) <= 4) count++;
//         // if (count >= 20 || time2 > timeout){
//         //    break;
//         // }

//         if(target > 0){
//             if((encoderAVG - (target-500)) > 0){
//                 over = true;
//             }
//         } else if(((target+500) - encoderAVG) > 0){
//         over = true;
//         }

//         if(over || time2 > timeout){
//             break;
//         }

//         delay(10);
//         if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
//             con.print(0,0, "error: %f           ", float(error));
//         }
//          if(time2 % 50 == 0 && time2 % 100 != 0){
//             con.print(2,0, "EncoderAVG: %f           ", float(init_heading));
//         }
//          if(time2 % 50 == 0){
//             con.print(1,0, "Time2: %f           ", float(time2));
//         }
        
        
//         time2 += 10;


//     }
//     LF.brake();
//     RF.brake();
//     LM.brake();
//     RM.brake();
//     LB.brake();
//     RB.brake();

    
// }




void driveArcL(double theta, double radius, int timeout, int speed){
//bool over = false; 
//setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
totalError = 0;
double ltarget = 0; 
double rtarget = 0;
double pi = 3.14159265359;
// . I'm sorry :/ Now deal with pi. cole. why the sigma are you doing this - carlos

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
    if (voltageL > 127 * double(speed) /100.0){
        voltageL = 127 * double(speed) /100.0;
    }else if(voltageL < -127 * double(speed) /100.0){
        voltageL = -127 * double(speed) /100.0;
    }

    int voltageR = calcPID2(rtarget, encoderAvgR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageR > 127 * double(speed) /100.0){
        voltageR = 127 * double(speed) /100.0;
    }else if(voltageR < -127 * double(speed) /100.0){
        voltageR = -127 * double(speed) /100.0;
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
    totalError += (abs(error3));   
    if (abs(ltarget - encoderAvgL) <= 25) fix = 0;   
        chasMove( (voltageL + fix), (voltageL + fix), (voltageL + fix), (voltageR - fix), (voltageR - fix), (voltageR - fix));
        if ((abs(ltarget - encoderAvgL) <= 10) && (abs(rtarget - encoderAvgR) <= 10)) count++;
        if (count >= 20 || time > timeout){
            trueTarget -= theta;
            break;
        }

     if(time % 50 == 0 && time % 100 != 0 && time % 150!= 0){
            con.print(0,0, "error: %f           ", float(error));
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


void driveArcLS(double theta, double radius, int timeout, int speed){
// bool over = false; 
setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
totalError = 0;
double ltarget = 0; 
double rtarget = 0;
double pi = 3.14159265359;
// . I'm sorry :/ Now deal with pi. cole. why the sigma are you doing this - carlos


if(trueTarget > 180){
    trueTarget = trueTarget - 360;
}
int time = 0;
int count = 0;
resetEncoders();



ltarget = double((theta/360) *2 * pi * radius);
rtarget = double((theta / 360) * 2 * pi *(radius + 475));
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
    totalError += (abs(error3));   
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




void driveArcR(double theta, double radius, int timeout, int speed){
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);


double ltarget = 0;
double rtarget = 0;
double pi =  3.14159265359;
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
    if (voltageL > 127 * double(speed) /100.0){
        voltageL = 127 * double(speed) /100.0;
    }else if(voltageL < -127 * double(speed) /100.0){
        voltageL = -127 * double(speed) /100.0;
    }

    int voltageR = calcPID2(rtarget, encoderAVGR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageR > 127 * double(speed) /100.0){
        voltageR = 127 * double(speed) /100.0;
    }else if(voltageR < -127 * double(speed) /100.0){
        voltageR = -127 * double(speed) /100.0;
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


void driveArcRS(double theta, double radius, int timeout, int speed){
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);


double ltarget = 0;
double rtarget = 0;
double pi =  3.14159265359;
double init_heading = imu.get_heading();
if(init_heading > 180){
    init_heading = init_heading - 360;
}
int count = 0;
time2 = 0;
resetEncoders();

rtarget = double((theta/360) *2 * pi * radius);
ltarget = double((theta / 360) * 2 * pi *(radius + 475)); 

while (true){

if(init_heading > 180){
    init_heading = init_heading - 360;
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
int fix = calcPID3((init_heading + rightcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);
    if (abs(rtarget - encoderAVGR) <= 25) fix = 0;  

    chasMove( (voltageL + fix), (voltageL + fix ), (voltageL + fix), (voltageR - fix), (voltageR - fix), (voltageR - fix));
    if ((abs(ltarget - encoderAVGL) <= 4) && (abs(rtarget - encoderAVGR)<= 4)) count++;
    if (count >= 20  || time2 > timeout){
       break;
    }
     if(time2 % 50 == 0 && time2 % 100 != 0 && time2 % 150!= 0){
            con.print(0,0, "fix: %f           ", float(fix));
        } else if(time2 % 50 == 0 && time2 % 100 != 0){
            con.print(1,0, "position: %f           ", float(position));
        }else if(time2 % 50 == 0){
            con.print(2,0, "init_heading: %f         ", float(init_heading + rightcorrect));
        }
        time2 += 10;
        delay(10);
    }   
}





void driveArcLF(double theta, double radius, int timeout, int speed){
int trueTheta = theta;
setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);

double ltarget = 0; 
double rtarget = 0;
double ltargetF = 0; 
double rtargetF = 0;
double pi = 3.14159265359;
// . I'm sorry :/ Now deal with pi. 
int time = 0;
int count = 0;
bool over = false;
resetEncoders();
ltargetF = double(( theta/360) *2 * pi * radius);
rtargetF = double((theta / 360) * 2 * pi *(radius + 490 ));
theta = theta + 45;
ltarget = double(( theta/360) *2 * pi * radius);
rtarget = double((theta / 360) * 2 * pi *(radius + 490 ));
while(true){

if(trueTarget > 180){
    trueTarget = trueTarget - 360;
}
double position = imu.get_heading();


if(position > 180){
    position = position - 360;
}
double encoderAvgL = LF.get_position(); 
double encoderAvgR = RB.get_position();
double leftcorrect = -(encoderAvgL * 360) / (2 * pi * radius);

if((trueTarget + leftcorrect < 0) && (position > 0)){
        if((position - (trueTarget + leftcorrect)) >= 180){
            leftcorrect = leftcorrect + 360;
            position = imu.get_heading();
        }
    } else if(((trueTarget + leftcorrect) > 0) && (position < 0)){
        if (((trueTarget + leftcorrect) - position) >= 180){
            position = imu.get_heading();
        }
     }

     




    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
 
    int voltageL = calcPID(ltarget, encoderAvgL, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageL > 127 * double(speed) /100.0){
        voltageL = 127 * double(speed) /100.0;
    }else if(voltageL < -127 * double(speed) /100.0){
        voltageL = -127 * double(speed) /100.0;
    }

    int voltageR = calcPID2(rtarget, encoderAvgR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageR > 127 * double(speed) /100.0){
        voltageR = 127 * double(speed) /100.0;
    }else if(voltageR < -127 * double(speed) /100.0){
        voltageR = -127 * double(speed) /100.0;
    }

 setConstants(ARC_HEADING_KP, ARC_HEADING_KI, ARC_HEADING_KD);
int fix = calcPID3((trueTarget + leftcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);

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
        if(theta > 0) {
            if(abs((trueTarget - position)) > trueTheta) {
                over = true;
            }
        } else {
            if((position - trueTarget) < - trueTheta) {
                over = true;
            }
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


void driveArcLFS(double theta, double radius, int timeout, int speed){
    int trueTheta = theta;
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    double ltarget = 0; 
    double rtarget = 0;
    double ltargetF = 0; 
    double rtargetF = 0;

    double pi = 3.14159265359;
    // . I'm sorry :/ Now deal with pi. 
    int time = 0;
    int count = 0;
    bool over = false;
    resetEncoders();
    ltargetF = double(( theta/360) *2 * pi * radius);
    rtargetF = double((theta / 360) * 2 * pi *(radius + 490 ));
    theta = theta + 45;
    ltarget = double(( theta/360) *2 * pi * radius);
    rtarget = double((theta / 360) * 2 * pi *(radius + 490 ));
    while(true){
    
    if(trueTarget > 180){
        trueTarget = trueTarget - 360;
    }
    double position = imu.get_heading();
    
    
    if(position > 180){
        position = position - 360;
    }
    double encoderAvgL = LF.get_position(); 
    double encoderAvgR = RB.get_position();
    double leftcorrect = -(encoderAvgL * 360) / (2 * pi * radius);
    
    if((trueTarget + leftcorrect < 0) && (position > 0)){
            if((position - (trueTarget + leftcorrect)) >= 180){
                leftcorrect = leftcorrect + 360;
                position = imu.get_heading();
            }
        } else if(((trueTarget + leftcorrect) > 0) && (position < 0)){
            if (((trueTarget + leftcorrect) - position) >= 180){
                position = imu.get_heading();
            }
         }
    
         
    
    
    
    
        setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
     
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
    
     setConstants(ARC_HEADING_KP, ARC_HEADING_KI, ARC_HEADING_KD);
    int fix = calcPID3((trueTarget + leftcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);
    
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
            if (abs(trueTarget - position) > trueTheta - 20){
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
    
    

void driveArcRF(double theta, double radius, int timeout, int speed){
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
if(trueTarget > 180){
    trueTarget = trueTarget - 360;
}
int count = 0;
int time2 = 0;
resetEncoders();
rtargetF = double((theta/360) *2 * pi * radius);
ltargetF= double((theta / 360) * 2 * pi *(radius + 475)); 
theta = theta + 45;
rtarget = double((theta/360) *2 * pi * radius);
ltarget = double((theta / 360) * 2 * pi *(radius + 475)); 

while (true){

if(trueTarget > 180){
    trueTarget = trueTarget - 360;
}
double position = imu.get_heading();

if(position > 180){
    position = position - 360;
}

if(((trueTarget + rightcorrect) < 0) && (position > 0)){
        if((position - (trueTarget + rightcorrect)) >= 180){
            trueTarget = trueTarget + 360;
            position = imu.get_heading();
        }
    } else if(((trueTarget + rightcorrect) > 0) && (position < 0)){
        if (((trueTarget + rightcorrect) - position) >= 180){
            position = imu.get_heading();
        }
     }
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
         double encoderAVGL = (LF.get_position() + LB.get_position()) /2;
         double encoderAVGR = (RF.get_position() + RB.get_position()) /2;
         int voltageL = calcPID(ltarget, encoderAVGL, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL); 
    if (voltageL > 127 * double(speed) /100.0){
        voltageL = 127 * double(speed) /100.0;
    } else if(voltageL < -127 * double(speed) /100.0){
        voltageL = -127 * double(speed) /100.0;
    }

    int voltageR = calcPID2(rtarget, encoderAVGR, STRAIGHT_INTEGRAL_KI, STRAIGHT_MAX_INTEGRAL);
    if (voltageR > 127 * double(speed) /100.0){
        voltageR = 127 * double(speed) /100.0;
    }else if(voltageR < -127 * double(speed) /100.0) {
        voltageR = -127 * double(speed) /100.0;
    }
    rightcorrect = (encoderAVGR * 360) / (2 * pi * radius);
        setConstants(ARC_HEADING_KP, ARC_HEADING_KI, ARC_HEADING_KD);
fix = calcPID3((trueTarget + rightcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);
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


if (abs(trueTarget - position) > trueTheta){
    over = true;
}
    if (over || time2 > timeout){
        trueTarget += trueTheta;
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


void driveArcRFS(double theta, double radius, int timeout, int speed){
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
if(trueTarget > 180){
    trueTarget = trueTarget - 360;
}
int count = 0;
int time2 = 0;
resetEncoders();
rtargetF = double((theta/360) *2 * pi * radius);
ltargetF= double((theta / 360) * 2 * pi *(radius + 475)); 
theta = theta + 45;
rtarget = double((theta/360) *2 * pi * radius);
ltarget = double((theta / 360) * 2 * pi *(radius + 475)); 

while (true){

if(trueTarget > 180){
    trueTarget = trueTarget - 360;
}
double position = imu.get_heading();

if(position > 180){
    position = position - 360;
}

if(((trueTarget + rightcorrect) < 0) && (position > 0)){
        if((position - (trueTarget + rightcorrect)) >= 180){
            trueTarget = trueTarget + 360;
            position = imu.get_heading();
        }
    } else if(((trueTarget + rightcorrect) > 0) && (position < 0)){
        if (((trueTarget + rightcorrect) - position) >= 180){
            position = imu.get_heading();
        }
     }
    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
         double encoderAVGL = (LF.get_position() + LB.get_position()) /2;
         double encoderAVGR = (RF.get_position() + RB.get_position()) /2;
    
    
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
    rightcorrect = (encoderAVGR * 360) / (2 * pi * radius);
        setConstants(ARC_HEADING_KP, ARC_HEADING_KI, ARC_HEADING_KD);
fix = calcPID3((trueTarget + rightcorrect), position, ARC_HEADING_INTEGRAL_KI, ARC_HEADING_MAX_INTEGRAL);
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


if (abs(trueTarget - position) > trueTheta){
    over = true;
}
    if (over || time2 > timeout){
        trueTarget += trueTheta;
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



void wallResetB(int resetTime){
    int count = 0;
    while (true){
        LF.move(-127);
        LM.move(-127);
        LB.move(-127);
        RF.move(-127);
        RM.move(-127);
        RB.move(-127);
        if (abs(RF.get_actual_velocity()) < 2) count ++;
        if (count >= 20) break;
    }
}

void wallResetF(int resetTime){
    int count = 0;
    while (true){
        LF.move(127);
        LM.move(127);
        LB.move(127);
        RF.move(127);
        RM.move(127);
        RB.move(127);
        if (abs(RF.get_actual_velocity()) < 2) count ++;
        if (count >= 20) break;
    }

}


void driveDoink(int target, int doinkDistance) {

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (0.000000000000109572 * pow(x,5)) +  ( -0.000000000539012 * pow(x,4)) + (0.000000775841 * pow(x,3)) + (-0.000327561  * pow(x,2)) + (0.674506 * x) + 543.33301;

    double voltage;
    double encoderAVG;
    int count = 0;
    double headingError = 0;
    int cycleTime = 0;
    time2 = 0;

    setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
    
    resetEncoders();

    while (true){
        if(abs(target - encoderAVG) < 22.5) {
            setConstants(2.25, 0, 0); //2.25
        } else {
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
        } 
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


void driveDoink2(int target, int doinkDistance) {

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (0.000000000000109572 * pow(x,5)) +  ( -0.000000000539012 * pow(x,4)) + (0.000000775841 * pow(x,3)) + (-0.000327561  * pow(x,2)) + (0.674506 * x) + 543.33301;

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
        if(abs(target - encoderAVG) < 22.5) {
            setConstants(2.25, 0, 0); //2.25
        } else {
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
        } 
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
        

         if(abs(target - encoderAVG) < doinkDistance){
            DoinkerTwo.set_value(true);
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




void driveDoinkC(int target, int doinkDistance){

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (0.000000000000109572 * pow(x,5)) +  ( -0.000000000539012 * pow(x,4)) + (0.000000775841 * pow(x,3)) + (-0.000327561  * pow(x,2)) + (0.674506 * x) + 543.33301;


 if (target > 0){
    target = target + 500;
 } else{
    target = target - 500;
 }
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
        if(abs(target - encoderAVG) < 22.5) {
            setConstants(2.25, 0, 0); //2.25
        } else {
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
        } 

if(init_heading > 180) {
    init_heading = (init_heading - 360);
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
            con.print(1,0, "error: %f           ", float(error));
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




void driveDoinkC2(int target, int doinkDistance){

    int timeout = 30000;

    double x = 0;
    x = double(abs(target));
    timeout = (0.000000000000109572 * pow(x,5)) +  ( -0.000000000539012 * pow(x,4)) + (0.000000775841 * pow(x,3)) + (-0.000327561  * pow(x,2)) + (0.674506 * x) + 543.33301;


 if (target > 0){
    target = target + 500;
 } else{
    target = target - 500;
 }
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
        if(abs(target - encoderAVG) < 22.5) {
            setConstants(2.25, 0, 0); //2.25
        } else {
            setConstants(STRAIGHT_KP, STRAIGHT_KI, STRAIGHT_KD);
        } 

if(init_heading > 180) {
    init_heading = (init_heading - 360);
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

        if(voltage > 127){
            voltage = 127;
        } else if (voltage < -127){
            voltage = -127;
        }


            if(abs(target - encoderAVG) < doinkDistance){
               DoinkerTwo.set_value(true);
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
            con.print(1,0, "error: %f           ", float(error));
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





