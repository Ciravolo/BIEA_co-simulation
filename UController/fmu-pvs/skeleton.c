/*! \file skeleton.c 
 * In this file there are the implementations
 * of the fuctions declared in fmu.h
 * along with the data needed.
 */
#include "fmu.h"
#include "misraC/UController.h"


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
    fmiBuffer.realBuffer[7] = st.servoLeft;
    fmiBuffer.realBuffer[8] = st.servoRight;
    
    
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

    st.beta = fmiBuffer.realBuffer[1] ;
    st.k_beta = fmiBuffer.realBuffer[2] ;
    st.k_v = fmiBuffer.realBuffer[3] ;
    st.rho = fmiBuffer.realBuffer[6] ;
    st.v = fmiBuffer.realBuffer[9] ;
    st.w = fmiBuffer.realBuffer[10] ;
    
    first = 1;
}
	
    st.phi = fmiBuffer.realBuffer[5];
    st.x = fmiBuffer.realBuffer[11];
    st.xDesired = fmiBuffer.realBuffer[12];
    st.y = fmiBuffer.realBuffer[13];
    st.yDesired = fmiBuffer.realBuffer[14];
	
    tick(&st);
    
    
    fmiBuffer.realBuffer[7] = st.servoLeft;
    fmiBuffer.realBuffer[8] = st.servoRight;
    /*
    fmiBuffer.realBuffer[1] = st.beta;
    fmiBuffer.realBuffer[2] = st.k_beta;
    fmiBuffer.realBuffer[3] = st.k_v;
    fmiBuffer.realBuffer[6] = st.rho;
    fmiBuffer.realBuffer[9] = st.v;
    fmiBuffer.realBuffer[10] = st.w;
    fmiBuffer.intBuffer[4] = st.maneuver;*/
}

void terminate(){ }


