#include "DesiredPosition.h"
/**
 * init function
 */
void init(State* st) { 
    st->previous_mode = DesiredPosition;
    st->mode = DesiredPosition;
    st->xDesired = 0.0f;
    st->xLocal = 0.0f;
    st->yDesired = 0.0f;
    st->yLocal = 0.0f;
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
    return (st->mode == DesiredPosition);
}
State* tick(State* st) {
	
    st->xDesired = st->xLocal;
    st->yDesired = st->yLocal;
 
    return st;
}




