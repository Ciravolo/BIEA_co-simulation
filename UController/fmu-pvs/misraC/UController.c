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
    st->beta = 0.0f;
    st->k_beta = 1.0f;
    st->k_v = 0.05f;
    st->maneuver = 1;
    st->onDestination = 0.0f;
    st->phi = 0.0f;
    st->rho = 0.0f;
    st->servoLeft = 0.0f;
    st->servoRight = 0.0f;
    st->v = 0.0f;
    st->w = 0.0f;
    st->x = 0.0f;
    st->xDesired = 0.0f;
    st->y = 0.0f;
    st->yDesired = 0.0f;
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
State* tick(State* st) {
    
    st->onDestination = 0;
    
    if(((fabs(st->y-st->yDesired)) < 0.5) && ((fabs(st->x-st->xDesired)) < 0.5)) {
		st->servoLeft = 0;
		st->servoRight = 0;
		st->onDestination = 1;
	}
	else {
		st->beta = atan2((st->y-st->yDesired),(st->x-st->xDesired)) - st->phi + M_PI/2;
		if(st->maneuver == 2) {
			if((fabs(st->x-st->xDesired) + fabs(st->y-st->yDesired)) < TOLLERANCE)
				st->maneuver = 1;
		}
		else if(st->maneuver == 1) {
			if(fabs(st->beta) < 0.1)
				st->maneuver = 2;
		}
		if(st->maneuver == 1) {
			st->beta = atan2((st->y-st->yDesired),(st->x-st->xDesired)) - st->phi + M_PI/2;
			st->v = 0;
			st->w = -st->k_beta * st->beta;
			st->servoLeft = ((1 / R)*st->v + (L / (2*R))*st->w) / 5.18;
			st->servoRight = -(((1 / R)*st->v - (L / (2*R))*st->w)) / 5.18;
		}
		else
		if(st->maneuver == 2) {
			st->rho = sqrt(pow((st->x-st->xDesired), 2) + pow((st->y-st->yDesired), 2));
			st->beta = atan2((st->y-st->yDesired),(st->x-st->xDesired)) - st->phi + M_PI/2;
			st->v = st->rho*st->k_v*(pow(st->rho, 2)*cos(st->beta) + st->beta*sin(st->beta));
			st->w = -st->k_beta*st->beta;
			st->servoLeft = ((1 / R)*st->v + (L / (2*R))*st->w) / 5.18;
			st->servoRight = -((((1 / R)*st->v - (L / (2*R))*st->w))) / 5.18;
		}
	}
	
    return st;
}




