/*! \file skeleton.c 
 * In this file there are the implementations
 * of the fuctions declared in fmu.h
 * along with the data needed.
 */
#include "fmu.h"
#include <string.h>

static int WebSocketCallback(struct lws*, enum lws_callback_reasons, void*, void*, size_t);

 /**
 * Function for the initialization of the model.
 * It calls the init function of the model and sets the output.
 * It initializes the semaphore and creates the websocket thread.
 * @param location is the directory where the fmu has been unzipped. Might be used in future version
 * 
 */
void initialize(ModelInstance* comp, const char* location) {
    init(&comp->st);
    
    comp->fmiBuffer.realBuffer[44] = comp->st.eP;
    comp->fmiBuffer.realBuffer[45] = comp->st.sTime;
    
    comp->fmiBuffer.realBuffer[1] = comp->st.a1;
    comp->fmiBuffer.realBuffer[2] = comp->st.a2;
    comp->fmiBuffer.realBuffer[3] = comp->st.ertu_perc;
    comp->fmiBuffer.realBuffer[4] = comp->st.eta;
    comp->fmiBuffer.realBuffer[5] = comp->st.lambda;
    comp->fmiBuffer.intBuffer[6] = comp->st.mapSize;
    comp->fmiBuffer.realBuffer[7] = comp->st.max_ph;
    comp->fmiBuffer.intBuffer[8] = comp->st.nRobots;
    comp->fmiBuffer.realBuffer[9] = comp->st.phi;
    comp->fmiBuffer.intBuffer[10] = comp->st.s_range;
    comp->fmiBuffer.realBuffer[11] = comp->st.step_size;
    comp->fmiBuffer.intBuffer[12] = comp->st.port;
    comp->fmiBuffer.intBuffer[13] = comp->st.stepCount;
    comp->fmiBuffer.realBuffer[15] = comp->st.x_1;
    comp->fmiBuffer.realBuffer[16] = comp->st.x_2;
    comp->fmiBuffer.realBuffer[17] = comp->st.x_3;
    comp->fmiBuffer.realBuffer[18] = comp->st.x_4;
    comp->fmiBuffer.realBuffer[19] = comp->st.y_1;
    comp->fmiBuffer.realBuffer[20] = comp->st.y_2;
    comp->fmiBuffer.realBuffer[21] = comp->st.y_3;
    comp->fmiBuffer.realBuffer[22] = comp->st.y_4;
    comp->fmiBuffer.intBuffer[23] = comp->st.nObstacles;
    comp->fmiBuffer.intBuffer[24] = comp->st.ox_1;
    comp->fmiBuffer.intBuffer[25] = comp->st.ox_2;
    comp->fmiBuffer.intBuffer[26] = comp->st.ox_3;
    comp->fmiBuffer.intBuffer[27] = comp->st.ox_4;
    comp->fmiBuffer.intBuffer[28] = comp->st.ox_5;
    comp->fmiBuffer.intBuffer[29] = comp->st.ox_6;
    comp->fmiBuffer.intBuffer[30] = comp->st.ox_7;
    comp->fmiBuffer.intBuffer[31] = comp->st.ox_8;
    comp->fmiBuffer.intBuffer[32] = comp->st.ox_9;
    comp->fmiBuffer.intBuffer[33] = comp->st.ox_10;
    comp->fmiBuffer.intBuffer[34] = comp->st.oy_1;
    comp->fmiBuffer.intBuffer[35] = comp->st.oy_2;
    comp->fmiBuffer.intBuffer[36] = comp->st.oy_3;
    comp->fmiBuffer.intBuffer[37] = comp->st.oy_4;
    comp->fmiBuffer.intBuffer[38] = comp->st.oy_5;
    comp->fmiBuffer.intBuffer[39] = comp->st.oy_6;
    comp->fmiBuffer.intBuffer[40] = comp->st.oy_7;
    comp->fmiBuffer.intBuffer[41] = comp->st.oy_8;
    comp->fmiBuffer.intBuffer[42] = comp->st.oy_9;
    comp->fmiBuffer.intBuffer[43] = comp->st.oy_10;

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
	
		comp->st.a1 = comp->fmiBuffer.realBuffer[1];
		comp->st.a2 = comp->fmiBuffer.realBuffer[2];
		comp->st.ertu_perc = comp->fmiBuffer.realBuffer[3];
		comp->st.eta = comp->fmiBuffer.realBuffer[4];
		comp->st.lambda = comp->fmiBuffer.realBuffer[5];
		comp->st.mapSize = comp->fmiBuffer.intBuffer[6];
		comp->st.max_ph = comp->fmiBuffer.realBuffer[7];
		comp->st.nRobots = comp->fmiBuffer.intBuffer[8];
		comp->st.phi = comp->fmiBuffer.realBuffer[9];
		comp->st.s_range = comp->fmiBuffer.intBuffer[10];
		comp->st.step_size = comp->fmiBuffer.realBuffer[11];
		comp->st.port = comp->fmiBuffer.intBuffer[12];
		comp->st.stepCount = comp->fmiBuffer.intBuffer[13];
		comp->st.nObstacles = comp->fmiBuffer.intBuffer[23];
		comp->st.ox_1 = comp->fmiBuffer.intBuffer[24];
		comp->st.ox_2 = comp->fmiBuffer.intBuffer[25];
		comp->st.ox_3 = comp->fmiBuffer.intBuffer[26];
		comp->st.ox_4 = comp->fmiBuffer.intBuffer[27];
		comp->st.ox_5 = comp->fmiBuffer.intBuffer[28];
		comp->st.ox_6 = comp->fmiBuffer.intBuffer[29];
		comp->st.ox_7 = comp->fmiBuffer.intBuffer[30];
		comp->st.ox_8 = comp->fmiBuffer.intBuffer[31] ;
		comp->st.ox_9 = comp->fmiBuffer.intBuffer[32];
		comp->st.ox_10 = comp->fmiBuffer.intBuffer[33];
		comp->st.oy_1 = comp->fmiBuffer.intBuffer[34];
		comp->st.oy_2 = comp->fmiBuffer.intBuffer[35];
		comp->st.oy_3 = comp->fmiBuffer.intBuffer[36];
		comp->st.oy_4 = comp->fmiBuffer.intBuffer[37];
		comp->st.oy_5 = comp->fmiBuffer.intBuffer[38];
		comp->st.oy_6 = comp->fmiBuffer.intBuffer[39];
		comp->st.oy_7 = comp->fmiBuffer.intBuffer[40];
		comp->st.oy_8 = comp->fmiBuffer.intBuffer[41];
		comp->st.oy_9 = comp->fmiBuffer.intBuffer[42];
		comp->st.oy_10 = comp->fmiBuffer.intBuffer[43];
		comp->st.x_1 = comp->fmiBuffer.realBuffer[15];
		comp->st.x_2 = comp->fmiBuffer.realBuffer[16];
		comp->st.x_3 = comp->fmiBuffer.realBuffer[17];
		comp->st.x_4 = comp->fmiBuffer.realBuffer[18];
		comp->st.y_1 = comp->fmiBuffer.realBuffer[19];
		comp->st.y_2 = comp->fmiBuffer.realBuffer[20];
		comp->st.y_3 = comp->fmiBuffer.realBuffer[21];
		comp->st.y_4 = comp->fmiBuffer.realBuffer[22];
		
		comp->fmiBuffer.realBuffer[44] = comp->st.eP;
		comp->fmiBuffer.realBuffer[45] = comp->st.sTime;
		comp->fmiBuffer.realBuffer[1] = comp->st.a1;
		comp->fmiBuffer.realBuffer[2] = comp->st.a2;
		comp->fmiBuffer.realBuffer[3] = comp->st.ertu_perc;
		comp->fmiBuffer.realBuffer[4] = comp->st.eta;
		comp->fmiBuffer.realBuffer[5] = comp->st.lambda;
		comp->fmiBuffer.intBuffer[6] = comp->st.mapSize;
		comp->fmiBuffer.realBuffer[7] = comp->st.max_ph;
		comp->fmiBuffer.intBuffer[8] = comp->st.nRobots;
		comp->fmiBuffer.realBuffer[9] = comp->st.phi;
		comp->fmiBuffer.intBuffer[10] = comp->st.s_range;
		comp->fmiBuffer.realBuffer[11] = comp->st.step_size;
		comp->fmiBuffer.intBuffer[12] = comp->st.port;
		comp->fmiBuffer.intBuffer[13] = comp->st.stepCount;
		comp->fmiBuffer.realBuffer[17] = comp->st.x_3;
		comp->fmiBuffer.realBuffer[18] = comp->st.x_4;
		comp->fmiBuffer.realBuffer[21] = comp->st.y_3;
		comp->fmiBuffer.realBuffer[22] = comp->st.y_4;
		comp->fmiBuffer.intBuffer[23] = comp->st.nObstacles;
		comp->fmiBuffer.intBuffer[24] = comp->st.ox_1;
		comp->fmiBuffer.intBuffer[25] = comp->st.ox_2;
		comp->fmiBuffer.intBuffer[26] = comp->st.ox_3;
		comp->fmiBuffer.intBuffer[27] = comp->st.ox_4;
		comp->fmiBuffer.intBuffer[28] = comp->st.ox_5;
		comp->fmiBuffer.intBuffer[29] = comp->st.ox_6;
		comp->fmiBuffer.intBuffer[30] = comp->st.ox_7;
		comp->fmiBuffer.intBuffer[31] = comp->st.ox_8;
		comp->fmiBuffer.intBuffer[32] = comp->st.ox_9;
		comp->fmiBuffer.intBuffer[33] = comp->st.ox_10;
		comp->fmiBuffer.intBuffer[34] = comp->st.oy_1;
		comp->fmiBuffer.intBuffer[35] = comp->st.oy_2;
		comp->fmiBuffer.intBuffer[36] = comp->st.oy_3;
		comp->fmiBuffer.intBuffer[37] = comp->st.oy_4;
		comp->fmiBuffer.intBuffer[38] = comp->st.oy_5;
		comp->fmiBuffer.intBuffer[39] = comp->st.oy_6;
		comp->fmiBuffer.intBuffer[40] = comp->st.oy_7;
		comp->fmiBuffer.intBuffer[41] = comp->st.oy_8;
		comp->fmiBuffer.intBuffer[42] = comp->st.oy_9;
		comp->fmiBuffer.intBuffer[43] = comp->st.oy_10;
		comp->first = 1;
	}
	
	comp->st.dummy = comp->fmiBuffer.intBuffer[14];
	
	tick(&comp->st);
	
	
	comp->fmiBuffer.realBuffer[15] = comp->st.x_1;
	comp->fmiBuffer.realBuffer[16] = comp->st.x_2;
	comp->fmiBuffer.realBuffer[19] = comp->st.y_1;
	comp->fmiBuffer.realBuffer[20] = comp->st.y_2;
	comp->fmiBuffer.realBuffer[44] = comp->st.eP;
	comp->fmiBuffer.realBuffer[45] = comp->st.sTime;
	
	if (comp->websocket_open == 1) {
		lws_service(comp->context, 0);
	}
}

/**
* Function used to convert the state into a string
*/
void stateToString(State st, char* str) {
	char* temp = (char*)malloc(1024);
	int i;
	
	strcpy(str, "(#");
	
	sprintf(temp, " mapSize := %d,", st.mapSize);
	strcat(str, temp);
	sprintf(temp, " nObstacles := %d,", st.nObstacles);
	strcat(str, temp);
	sprintf(temp, " explorationPercentage := %g,", st.eP);
	strcat(str, temp);
	for(i = 0; i < st.nObstacles; ++i) {
		sprintf(temp, " ox_%d := %d,", i + 1, ox[i]);
		strcat(str, temp);
		sprintf(temp, " oy_%d := %d,", i + 1, oy[i]);
		strcat(str, temp);
	}
	sprintf(temp, " nRobots := %d,", st.nRobots);
	strcat(str, temp);
	for(i = 0; i < st.nRobots; ++i) {
		sprintf(temp, " x_%d := %f,", i + 1, x[i]);
		strcat(str, temp);
	}
	for(i = 0; i < st.nRobots; ++i) {
		sprintf(temp, " y_%d := %f,", i + 1, y[i]);
		strcat(str, temp);
	}	
	//Remove the last char ','
	str[strlen(str)-1] = '\0';	
	strcat(str, " #);");

	free(temp);
}

void terminate(ModelInstance* comp) {
	
	int i;
	
	for(i = 0; i < comp->st.mapSize; ++i)
		free(map[i]);
	free(map);
	
	free(occupiedCells);
	free(x);
	free(y);
	free(ox);
	free(oy);
	
	close_websocket(comp);
	
}


/** 
 * List of supported protocols and callbacks 
 */
static struct lws_protocols protocols[] = {
	{
        "FMI",              // Name
        WebSocketCallback,  // Callback
        0,                  // Per_session_data_size
        0,                  // Rx_buffer_size
    },
    { NULL, NULL, 0, 0 }	// End of list
};

/**
 * Function used to initialize the websocket
 */
void create_websocket(ModelInstance* comp, int initial_port) {
	// Open websocket
    if (comp->websocket_open == 0) {
        comp->port = initial_port;
        comp->websocket_open = open_websocket(comp);
        if (comp->websocket_open == 0) {
            initial_port++; // Change port so that a new port can be tried at the next attempt
        } else {
            printf("WEBSOCKET OPENED\n");
        }
        printf("RETURNING PORT %i\n", comp->port);
    }
}

/**
 * Function used to open the websocket
 */
int open_websocket(ModelInstance* comp) {	
    const char *interface = NULL; // NULL means "all interfaces"
    lwsl_notice("libwebsockets test server - "
                "(C) Copyright 2010-2013 Andy Green <andy@warmcat.com> - "
                "licensed under LGPL2.1\n");			
                
    struct lws_context_creation_info info;
    memset(&info, 0, sizeof(info));
    info.port = comp->port;
    info.iface = interface;
    info.protocols = protocols;
    info.ssl_cert_filepath = NULL;
    info.ssl_private_key_filepath = NULL;
    info.gid = -1;
    info.uid = -1;
    info.options = 0;
    info.user = comp;    

    comp->context = lws_create_context(&info);

    if (comp->context == NULL) {
        printf("Libwebsocket init failed\n");
        return 0;
    }

    printf("Open websocket on port %i\n", comp->port);
    return 1;
}

/**
 * Callback function used to handle the received messages.
 */
static int WebSocketCallback(struct lws* wsi, enum lws_callback_reasons reason, void* user, void* in, size_t len) {
	struct lws_context* context = lws_get_context(wsi);
	ModelInstance* comp = (ModelInstance*)lws_context_user(context);
	
    // Callback
    switch (reason) {
		case LWS_CALLBACK_ESTABLISHED:
			printf("LWS_CALLBACK_ESTABLISHED\n");
			printf("**********************************************\n");
			printf("***             (FMI Protocol)             ***\n");
			printf("**********************************************\n");
			break;
		case LWS_CALLBACK_CLOSED:
			printf("CLIENT DISCONNECTED!\n\n");
			break;
		case LWS_CALLBACK_RECEIVE:
			printf("LWS_CALLBACK_RECEIVE\n");
			// 'len' is the length of the received message. It has some post padding.
			char* received_msg = (char*)malloc(len);
			memcpy(received_msg, (char*)in, len);
			messageHandler(comp, received_msg);
			free(received_msg);
			char* response = (char*)malloc(1024);
			stateToString(comp->st, response);
			memcpy(comp->lwssendstate + LWS_SEND_BUFFER_PRE_PADDING, response, strlen(response));
			lws_write(wsi, (unsigned char *)(comp->lwssendstate + LWS_SEND_BUFFER_PRE_PADDING), strlen(response), LWS_WRITE_TEXT);
			free(response);
			break;
		case LWS_CALLBACK_HTTP:
			printf("LWS_CALLBACK_HTTP\n");
			break;
		case LWS_CALLBACK_LOCK_POLL:
			printf("LWS_CALLBACK_LOCK_POLL\n");
			break;
		case LWS_CALLBACK_ADD_POLL_FD:
			printf("LWS_CALLBACK_ADD_POLL_FD\n");
			break;
		case LWS_CALLBACK_UNLOCK_POLL:
			printf("LWS_CALLBACK_UNLOCK_POLL\n");
			break;
		case LWS_CALLBACK_PROTOCOL_INIT:
			printf("LWS_CALLBACK_PROTOCOL_INIT\n");
			break;
		case LWS_CALLBACK_GET_THREAD_ID:
			printf("TIMEOUT\n");
			printf("LWS_CALLBACK_GET_THREAD_ID\n");
			break;
		case LWS_CALLBACK_WSI_DESTROY:
			printf("Timeout Happened %i\n", reason);
			break;
		default:
			printf("Unmanaged Callback Reason! %i\n", reason);
			break;
    }
    return 0;
}


/**
 * Function used to handle the received command
 */ 
void messageHandler(ModelInstance* comp, char* msg) {	
	if (strstr(msg, "refresh") == NULL) {
		
		if (strstr(msg, "click_tick") != NULL) {
			tick(&comp->st);
		}
		
	}	
}	

/**
 * Function used to close the websocket
 */
void close_websocket(ModelInstance* comp) {
    lws_context_destroy(comp->context);
    comp->websocket_open = 0;
    printf("Close websocket\n");
}

