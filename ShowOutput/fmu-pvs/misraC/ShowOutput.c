#include "ShowOutput.h"
/**
 * init function
 */
void init(State* st) { 
    st->previous_mode = ShowOutput;
    st->mode = ShowOutput;
    st->dummy = 0;
    st->eP = 0.0f;
    st->sTime = 0.0f;
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
    return (st->mode == ShowOutput && ( TRUE ));
}
State* tick(State* st) {
    // assert( per_tick(st) );
    if (st->mode == ShowOutput && ( TRUE )) {
        #ifdef DBG
        _dbg_print_condition("st->mode == ShowOutput && ( TRUE )");
        #endif
        leave(ShowOutput, st);
        st->eP = st->eP;
        st->sTime = st->sTime;
        enter(ShowOutput, st);
    }
    #ifdef DBG
    _dbg_print_state(st);
    #endif
    return st;
}




