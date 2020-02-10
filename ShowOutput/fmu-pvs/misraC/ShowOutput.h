#ifndef _misraC_ShowOutput_
#define _misraC_ShowOutput_

#include <assert.h>
#include <stdio.h>
#include "misraC_basic_types.h"
/**
 * operating modes
 */
typedef enum { ShowOutput } Mode;

/**
 * state attributes
 */
typedef struct { 
    Mode mode;
    Mode previous_mode;
    int32_t dummy; //-- int
    float64_t eP; //-- int
    float64_t sTime; //-- int
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
