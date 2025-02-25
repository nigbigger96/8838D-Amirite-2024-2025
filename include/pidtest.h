#include "api.h"
#include "main.h"
#include "okapi/api.hpp"


#ifndef PIDH
#define PIDH


extern void TdriveTurn(int target);
extern void TdriveTurn2(int target);
extern void tdriveTurnT(int target);
extern void TdriveStraight2(int target);
extern void TdriveStraightC(int target);
extern void TdriveClampSC(int target, int clampDistance, int speed);
extern void TdriveClamp(int target, int clampDistance);
extern void TdriveStraightSlow(int target, int speed);
extern void TdriveClampS(int target, int clampDistanceFromTarget, int speed);
extern void TdriveArcLS(double theta, double radius, int timeout, int speed);
extern void TdriveArcRS(double theta, double radius, int timeout, int speed);
extern void TdriveArcL(double theta, double radius, int timeout);
extern void TdriveArcR(double theta, double radius, int timeout);
extern void TdriveArcLF(double theta, double radius, int timeout);
extern void TdriveArcRF(double theta, double radius, int timeout);
extern void TdriveDoink(int target, int doinkDistance);
extern void TdriveDoinkC(int target, int doinkDistance);



// straight stuff
#define STRAIGHT_KP 1 //3 
#define STRAIGHT_KI 0
#define STRAIGHT_KD 0
#define STRAIGHT_INTEGRAL_KI 40
#define STRAIGHT_MAX_INTEGRAL 14.5

// turn stuff
#define TURN_KP 1
#define TURN_KI 0
#define TURN_KD 1
#define TURN_INTEGRAL_KI 30
#define TURN_MAX_INTEGRAL 25


// better turning stuff
#define TURNT_KP 1
#define TURNT_KI 0 //I is going to be huge
#define TURNT_KD 0
#define TURNT_INTEGRAL_KI 30
#define TURNT_MAX_INTEGRAL 25
//arc turn stiff
//#define driveArcL 10
#define HEADING_KP 6
#define HEADING_KI 0
#define HEADING_KD 0
#define HEADING_MAX_INTEGRAL 0
#define HEADING_INTEGRAL_KI 0

#define ARC_HEADING_KP 3
#define ARC_HEADING_KI 0
#define ARC_HEADING_KD 1
#define ARC_HEADING_MAX_INTEGRAL 0
#define ARC_HEADING_INTEGRAL_KI 0

#define LIFT_KP 0.005
#define LIFT_KI 0
#define LIFT_KD 5

#define TOP_KP 0.1
#define TOP_KI 0
#define TOP_KD 1

#endif