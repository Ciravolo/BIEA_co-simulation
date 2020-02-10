#include "UController.h"
/**
 * user-defined constants
 */
const float64_t L = 0.052f;
const float64_t R = 0.032f;

/**
 * init function
 */
void init(State* st) { 
    st->previous_mode = X1;
    st->mode = X1;
    
    st->beta = 0.0f;    //Local
    st->rho = 0.0f;     //Local
    st->k_beta = 0.2f;  //Local
    st->k_v = 1.0f;     //Local
    st->maneuver = 2;   //Local
    st->v = 0.0f;       //Local
    st->w = 0.0f;       //Local
    
    st->x = 0.0f;        //Input
    st->y = 0.0f;        //Input
    st->phi = 0.0f;      //Input
    st->xDesired = 0.0f; //Input
    st->yDesired = 0.0f; //Input
    st->onDestinationInput = 0.0f; //Input
    
    st->onDestinationOutput = 0.0f; //Output
    st->servoLeft = 0.0f;     //Output
    st->servoRight = 0.0f;    //Output
}

/**
 * leave/enter functions
 */
void enter(Mode m, State* st) { 
    st->mode = m;
}
void leave(Mode m, State* st) { 
    st->previous_mode = m;
}

/**
 * triggers
 */
bool per_tick(State* st) {
    return (st->mode == X1 && ( TRUE ));
}

// E' la funzione principale che viene eseguita ad intervalli di una step di 0.1s
State* tick(State* st) {
    
    float64_t deltaX, deltaY;
    
    if(st->onDestinationInput == 0) {
		if(st->onDestinationOutput == 0) {
		
			deltaX = st->x-st->xDesired;
			deltaY = st->y-st->yDesired;
			
			//Movement toward objective
			if(st->maneuver == 2) {
				//If the maneuver is two I consider the absolute value of beta
				st->beta = fabs(atan2((deltaY),(deltaX)) - st->phi + M_PI/2);
				if((fabs(deltaX) + fabs(deltaY)) < 0.3) {
					st->maneuver = 1;
					st->onDestinationOutput = 1;
					st->servoLeft = 0;
					st->servoRight = 0;
				}
			}
			//Orientation 
			else if(st->maneuver == 1) {
				// This fix the co-simulation problem
				if(!((fabs(deltaX) < TOLLERANCE) && (fabs(deltaY) < TOLLERANCE))) {
					if(fabs(deltaX) < TOLLERANCE){
						deltaX = 0;
					}
					if(fabs(deltaY) < TOLLERANCE){
						deltaY = 0;
					}
				}
				st->beta = atan2((deltaY),(deltaX)) - st->phi + M_PI/2;
				if(fabs(st->beta) < 0.01) {
					st->maneuver = 2;
				}
			}
			
			//This is the code of the controller in the two differents phases
			if(st->maneuver == 1) 
				st->v = 0;
			else
			if(st->maneuver == 2) {
				st->rho = sqrt(pow((deltaX), 2) + pow((deltaY), 2));
				st->v = st->rho*st->k_v*(pow(st->rho, 2)*cos(st->beta) + st->beta*sin(st->beta));
			}
			st->w = -st->k_beta * st->beta;

			//Formulas to compute the motors powers
			st->servoLeft = ((1 / R)*st->v + (L / (2*R))*st->w);
			st->servoRight = -(((1 / R)*st->v - (L / (2*R))*st->w));
			
			//This code is neaded to mantain servoLeft and servoRight between -1 and 1
			if(st->servoLeft > 1)
				st->servoLeft = 1;
			else
			if(st->servoLeft < -1)
				st->servoLeft = -1;
				
			if(st->servoRight > 1)
				st->servoRight = 1;
			else
			if(st->servoRight < -1)
				st->servoRight = -1;
		}
		else{
			st->servoLeft = 0;
			st->servoRight = 0;
		}
	}
	else {
		st->onDestinationOutput = 0;
		st->servoLeft = 0;
		st->servoRight = 0;
	}
	
    return st;
}




