/*! \file skeleton.c 
 * In this file there are the implementations
 * of the fuctions declared in fmu.h
 * along with the data needed.
 */
#include "fmu.h"
#include <string.h>


 /**
 * Function for the initialization of the model.
 * It calls the init function of the model and sets the output.
 * It initializes the semaphore and creates the websocket thread.
 * @param location is the directory where the fmu has been unzipped. Might be used in future version
 * 
 */
void initialize(ModelInstance* comp, const char* location) {
    init(&comp->st);
    
    comp->fmiBuffer.intBuffer[1] = comp->st.dummy;
    

    comp->first = 0;   
}

/**
 * Function that performs a step of the simulation model.
 * At first the inputs of the are updated with the values fom the master algorithm.
 * Then the tick function is called inside the mutex, in order to guarantee mutual exlusion.
 * Finally the outputs of the model are forwarded to the master algorithm 
 * @param action is the action to perform. Might be used in future version.
 */
void doStep(ModelInstance* comp, const char* action) {
	if(comp->first == 0) {
	
		comp->st.dummy = comp->fmiBuffer.intBuffer[1];
		
		comp->first = 1;
	}
	
	comp->st.eP = comp->fmiBuffer.intBuffer[2];
	comp->st.sTime = comp->fmiBuffer.intBuffer[3];
	
    tick(&comp->st);
       
    
    comp->fmiBuffer.intBuffer[1] = comp->st.dummy;
    
    
    
}

/**
* Function used to convert the state into a string
*/
void stateToString(State st, char* str) {
	char* temp = (char*)malloc(1024);
	
	strcpy(str, "(#");
	
	sprintf(temp, " dummy := %d,", st.dummy);
	strcat(str, temp);
	sprintf(temp, " nCells := %g,", st.eP);
	strcat(str, temp);
	sprintf(temp, " vCells := %g,", st.sTime);
	strcat(str, temp);	
	//Remove the last char ','
	str[strlen(str)-1] = '\0';	
	strcat(str, " #);");

	free(temp);
}

void terminate(ModelInstance* comp) {
	
}


