/*! \file skeleton.c 
 * In this file there are the implementations
 * of the fuctions declared in fmu.h
 * along with the data needed.
 */
#include "fmu.h"
#include "misraC/DesiredPosition.h"


State st; /*!< structure containing the state of the model */
int first = 0; /* variable for execution of setup option during first step only */


 /**
       * function for the initialization of the model.
       * It calls the init function of the model and
       * 	sets the output
       * @param location is the directory where the fmu has been unzipped. Might be used in future version
       * 
       */


void initialize(const char* location) {
    init(&st);
    fmiBuffer.realBuffer[1] = st.xDesired;
    fmiBuffer.realBuffer[3] = st.yDesired;
    
    
}

/**
 * function that performs a step of the simulation model.
 * At first the inputs of the are updated with the values fom the master algorithm
 * Then the tick function is called
 * Finally the outputs of the model are forwarded to the master algorithm 
 * @param action is the action to perform. Might be used in future version
 */
void doStep(const char* action) { 
if(first == 0){

    st.xLocal = fmiBuffer.realBuffer[2] ;
    st.yLocal = fmiBuffer.realBuffer[4] ;
    
    first = 1;
}
	
	
    tick(&st);
    
    
    fmiBuffer.realBuffer[1] = st.xDesired;
    fmiBuffer.realBuffer[3] = st.yDesired;
    /*
    fmiBuffer.realBuffer[2] = st.xLocal;
    fmiBuffer.realBuffer[4] = st.yLocal;*/
}

void terminate(){ }


