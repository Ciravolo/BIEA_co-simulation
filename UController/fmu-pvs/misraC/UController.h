#ifndef _misraC_UController_
#define _misraC_UController_

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include "misraC_basic_types.h"
#define TOLLERANCE 0.5
/**
 * operating modes
 */
typedef enum { X1 } Mode;

/**
 * state attributes
 */
typedef struct { 
    Mode mode;
    Mode previous_mode;
    float64_t beta; //-- real
    float64_t k_beta; //-- real
    float64_t k_v; //-- real
    int32_t maneuver; //-- int
    float64_t onDestination;
    float64_t phi; //-- real
    float64_t rho; //-- real
    float64_t servoLeft; //-- real
    float64_t servoRight; //-- real
    float64_t v; //-- real
    float64_t w; //-- real
    float64_t x; //-- real
    float64_t xDesired; //-- real
    float64_t y; //-- real
    float64_t yDesired; //-- real
} State;

/**
 * init function
 */
void init(State* st);

/**
 * triggers
 */
bool per_tick(State* st);
State* tick(State* st);


/**
 * leave/enter functions
 */
void enter(Mode m, State* st);
void leave(Mode m, State* st);

#endif
