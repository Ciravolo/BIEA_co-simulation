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
    st->k_beta = 1.0f;  //Local
    st->k_v = 1.0f;     //Local
    st->maneuver = 1;   //Local
    st->v = 0.0f;       //Local
    st->w = 0.0f;       //Local
    
    st->x = 0.0f;        //Input
    st->y = 0.0f;        //Input
    st->phi = 0.0f;      //Input
    st->xDesired = 0.0f; //Input
    st->yDesired = 0.0f; //Input
    
    st->onDestination = 0.0f; //Output
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
    
	// Se il robot è sufficientemente vicino al centro della cella, lo faccio fermare e ripristino la situazione iniziale con maneuver ad 1 e servo a 0. 
    if(((fabs(st->y-st->yDesired)) < 0.2) && ((fabs(st->x-st->xDesired)) < 0.2)) {
		//Questa informazione serve all'environment per sapere che questo robot ha raggiunto il target.
		st->onDestination = 1;
		st->maneuver = 1;
	}
	else {
		st->onDestination = 0;
		
		//Questo è l'uniplanner. Ho lasciato il valore di TOLLERANCE a 1. Ho tolto il numero di waypoints perchè nel mio caso è sempre 1 e lo fornisco in input al controllore.
		st->beta = -(atan2((st->y-st->yDesired),(st->x-st->xDesired)) - st->phi + M_PI/2);
		if(st->maneuver == 2) {
			if((fabs(st->x-st->xDesired) + fabs(st->y-st->yDesired)) < TOLLERANCE) {
				st->maneuver = 1;
			}
		}
		else if(st->maneuver == 1) {
			if(fabs(st->beta) < 0.1) {
				st->maneuver = 2;
			}
		}
		
		//Questo è il codice del controllore nelle due differenti fasi
		if(st->maneuver == 1) {
			st->v = 0;
			st->w = st->k_beta * st->beta;
		}
		else
		if(st->maneuver == 2) {
			st->rho = sqrt(pow((st->x-st->xDesired), 2) + pow((st->y-st->yDesired), 2));
			st->v = st->rho*st->k_v*(pow(st->rho, 2)*cos(st->beta) + st->beta*sin(st->beta));
			st->w = st->k_beta*st->beta;
		}
		
		//La formula per il calcolo dei servo che è uguale per entrambe le fasi
		st->servoLeft = ((1 / R)*st->v + (L / (2*R))*st->w);
		st->servoRight = -(((1 / R)*st->v - (L / (2*R))*st->w));
		
		//Questa è una mia aggiunta, poichè i valori dei servo a volte diventavano troppo alti, mentre io voglio che si mantengano nell'intervallo [-1,1] 
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
	
    return st;
}




