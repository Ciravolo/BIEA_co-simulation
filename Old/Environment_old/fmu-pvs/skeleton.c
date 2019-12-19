/*! \file skeleton.c
 * In this file there are the implementations
 * of the fuctions declared in fmu.h
 * along with the data needed.
 */
#include "fmu.h"
#include <string.h>

static int WebSocketCallback(struct lws*, enum lws_callback_reasons, void*, void*, size_t);

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

int connection = 0;

 /**
 * Function for the initialization of the model.
 * It calls the init function of the model and sets the output.
 * It initializes the semaphore and creates the websocket thread.
 * @param location is the directory where the fmu has been unzipped. Might be used in future version
 *
 */
void initialize(ModelInstance* comp, const char* location) {
    init(&comp->st);
    
    comp->fmiBuffer.realBuffer[101] = comp->st.dummy;
    
    comp->fmiBuffer.realBuffer[1] = comp->st.cell1_1;
    comp->fmiBuffer.realBuffer[2] = comp->st.cell1_10;
    comp->fmiBuffer.realBuffer[3] = comp->st.cell1_2;
    comp->fmiBuffer.realBuffer[4] = comp->st.cell1_3;
    comp->fmiBuffer.realBuffer[5] = comp->st.cell1_4;
    comp->fmiBuffer.realBuffer[6] = comp->st.cell1_5;
    comp->fmiBuffer.realBuffer[7] = comp->st.cell1_6;
    comp->fmiBuffer.realBuffer[8] = comp->st.cell1_7;
    comp->fmiBuffer.realBuffer[9] = comp->st.cell1_8;
    comp->fmiBuffer.realBuffer[10] = comp->st.cell1_9;
    comp->fmiBuffer.realBuffer[11] = comp->st.cell10_1;
    comp->fmiBuffer.realBuffer[12] = comp->st.cell10_10;
    comp->fmiBuffer.realBuffer[13] = comp->st.cell10_2;
    comp->fmiBuffer.realBuffer[14] = comp->st.cell10_3;
    comp->fmiBuffer.realBuffer[15] = comp->st.cell10_4;
    comp->fmiBuffer.realBuffer[16] = comp->st.cell10_5;
    comp->fmiBuffer.realBuffer[17] = comp->st.cell10_6;
    comp->fmiBuffer.realBuffer[18] = comp->st.cell10_7;
    comp->fmiBuffer.realBuffer[19] = comp->st.cell10_8;
    comp->fmiBuffer.realBuffer[20] = comp->st.cell10_9;
    comp->fmiBuffer.realBuffer[21] = comp->st.cell2_1;
    comp->fmiBuffer.realBuffer[22] = comp->st.cell2_10;
    comp->fmiBuffer.realBuffer[23] = comp->st.cell2_2;
    comp->fmiBuffer.realBuffer[24] = comp->st.cell2_3;
    comp->fmiBuffer.realBuffer[25] = comp->st.cell2_4;
    comp->fmiBuffer.realBuffer[26] = comp->st.cell2_5;
    comp->fmiBuffer.realBuffer[27] = comp->st.cell2_6;
    comp->fmiBuffer.realBuffer[28] = comp->st.cell2_7;
    comp->fmiBuffer.realBuffer[29] = comp->st.cell2_8;
    comp->fmiBuffer.realBuffer[30] = comp->st.cell2_9;
    comp->fmiBuffer.realBuffer[31] = comp->st.cell3_1;
    comp->fmiBuffer.realBuffer[32] = comp->st.cell3_10;
    comp->fmiBuffer.realBuffer[33] = comp->st.cell3_2;
    comp->fmiBuffer.realBuffer[34] = comp->st.cell3_3;
    comp->fmiBuffer.realBuffer[35] = comp->st.cell3_4;
    comp->fmiBuffer.realBuffer[36] = comp->st.cell3_5;
    comp->fmiBuffer.realBuffer[37] = comp->st.cell3_6;
    comp->fmiBuffer.realBuffer[38] = comp->st.cell3_7;
    comp->fmiBuffer.realBuffer[39] = comp->st.cell3_8;
    comp->fmiBuffer.realBuffer[40] = comp->st.cell3_9;
    comp->fmiBuffer.realBuffer[41] = comp->st.cell4_1;
    comp->fmiBuffer.realBuffer[42] = comp->st.cell4_10;
    comp->fmiBuffer.realBuffer[43] = comp->st.cell4_2;
    comp->fmiBuffer.realBuffer[44] = comp->st.cell4_3;
    comp->fmiBuffer.realBuffer[45] = comp->st.cell4_4;
    comp->fmiBuffer.realBuffer[46] = comp->st.cell4_5;
    comp->fmiBuffer.realBuffer[47] = comp->st.cell4_6;
    comp->fmiBuffer.realBuffer[48] = comp->st.cell4_7;
    comp->fmiBuffer.realBuffer[49] = comp->st.cell4_8;
    comp->fmiBuffer.realBuffer[50] = comp->st.cell4_9;
    comp->fmiBuffer.realBuffer[51] = comp->st.cell5_1;
    comp->fmiBuffer.realBuffer[52] = comp->st.cell5_10;
    comp->fmiBuffer.realBuffer[53] = comp->st.cell5_2;
    comp->fmiBuffer.realBuffer[54] = comp->st.cell5_3;
    comp->fmiBuffer.realBuffer[55] = comp->st.cell5_4;
    comp->fmiBuffer.realBuffer[56] = comp->st.cell5_5;
    comp->fmiBuffer.realBuffer[57] = comp->st.cell5_6;
    comp->fmiBuffer.realBuffer[58] = comp->st.cell5_7;
    comp->fmiBuffer.realBuffer[59] = comp->st.cell5_8;
    comp->fmiBuffer.realBuffer[60] = comp->st.cell5_9;
    comp->fmiBuffer.realBuffer[61] = comp->st.cell6_1;
    comp->fmiBuffer.realBuffer[62] = comp->st.cell6_10;
    comp->fmiBuffer.realBuffer[63] = comp->st.cell6_2;
    comp->fmiBuffer.realBuffer[64] = comp->st.cell6_3;
    comp->fmiBuffer.realBuffer[65] = comp->st.cell6_4;
    comp->fmiBuffer.realBuffer[66] = comp->st.cell6_5;
    comp->fmiBuffer.realBuffer[67] = comp->st.cell6_6;
    comp->fmiBuffer.realBuffer[68] = comp->st.cell6_7;
    comp->fmiBuffer.realBuffer[69] = comp->st.cell6_8;
    comp->fmiBuffer.realBuffer[70] = comp->st.cell6_9;
    comp->fmiBuffer.realBuffer[71] = comp->st.cell7_1;
    comp->fmiBuffer.realBuffer[72] = comp->st.cell7_10;
    comp->fmiBuffer.realBuffer[73] = comp->st.cell7_2;
    comp->fmiBuffer.realBuffer[74] = comp->st.cell7_3;
    comp->fmiBuffer.realBuffer[75] = comp->st.cell7_4;
    comp->fmiBuffer.realBuffer[76] = comp->st.cell7_5;
    comp->fmiBuffer.realBuffer[77] = comp->st.cell7_6;
    comp->fmiBuffer.realBuffer[78] = comp->st.cell7_7;
    comp->fmiBuffer.realBuffer[79] = comp->st.cell7_8;
    comp->fmiBuffer.realBuffer[80] = comp->st.cell7_9;
    comp->fmiBuffer.realBuffer[81] = comp->st.cell8_1;
    comp->fmiBuffer.realBuffer[82] = comp->st.cell8_10;
    comp->fmiBuffer.realBuffer[83] = comp->st.cell8_2;
    comp->fmiBuffer.realBuffer[84] = comp->st.cell8_3;
    comp->fmiBuffer.realBuffer[85] = comp->st.cell8_4;
    comp->fmiBuffer.realBuffer[86] = comp->st.cell8_5;
    comp->fmiBuffer.realBuffer[87] = comp->st.cell8_6;
    comp->fmiBuffer.realBuffer[88] = comp->st.cell8_7;
    comp->fmiBuffer.realBuffer[89] = comp->st.cell8_8;
    comp->fmiBuffer.realBuffer[90] = comp->st.cell8_9;
    comp->fmiBuffer.realBuffer[91] = comp->st.cell9_1;
    comp->fmiBuffer.realBuffer[92] = comp->st.cell9_10;
    comp->fmiBuffer.realBuffer[93] = comp->st.cell9_2;
    comp->fmiBuffer.realBuffer[94] = comp->st.cell9_3;
    comp->fmiBuffer.realBuffer[95] = comp->st.cell9_4;
    comp->fmiBuffer.realBuffer[96] = comp->st.cell9_5;
    comp->fmiBuffer.realBuffer[97] = comp->st.cell9_6;
    comp->fmiBuffer.realBuffer[98] = comp->st.cell9_7;
    comp->fmiBuffer.realBuffer[99] = comp->st.cell9_8;
    comp->fmiBuffer.realBuffer[100] = comp->st.cell9_9;
    comp->fmiBuffer.realBuffer[104] = comp->st.tickSize;
    comp->fmiBuffer.realBuffer[105] = comp->st.time;
    comp->fmiBuffer.intBuffer[102] = comp->st.port;
    comp->fmiBuffer.intBuffer[103] = comp->st.stepCount;

    comp->first = 0;
}

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
 * Function that performs a step of the simulation model.
 * At first the inputs of the are updated with the values fom the master algorithm.
 * Then the tick function is called inside the mutex, in order to guarantee mutual exlusion.
 * Finally the outputs of the model are forwarded to the master algorithm
 * @param action is the action to perform. Might be used in future version.
 */
void doStep(ModelInstance* comp, const char* action) {
	if(comp->first == 0) {
	
		comp->st.cell1_1 = comp->fmiBuffer.realBuffer[1];
		comp->st.cell1_10 = comp->fmiBuffer.realBuffer[2];
		comp->st.cell1_2 = comp->fmiBuffer.realBuffer[3];
		comp->st.cell1_3 = comp->fmiBuffer.realBuffer[4];
		comp->st.cell1_4 = comp->fmiBuffer.realBuffer[5];
		comp->st.cell1_5 = comp->fmiBuffer.realBuffer[6];
		comp->st.cell1_6 = comp->fmiBuffer.realBuffer[7];
		comp->st.cell1_7 = comp->fmiBuffer.realBuffer[8];
		comp->st.cell1_8 = comp->fmiBuffer.realBuffer[9];
		comp->st.cell1_9 = comp->fmiBuffer.realBuffer[10];
		comp->st.cell10_1 = comp->fmiBuffer.realBuffer[11];
		comp->st.cell10_10 = comp->fmiBuffer.realBuffer[12];
		comp->st.cell10_2 = comp->fmiBuffer.realBuffer[13];
		comp->st.cell10_3 = comp->fmiBuffer.realBuffer[14];
		comp->st.cell10_4 = comp->fmiBuffer.realBuffer[15];
		comp->st.cell10_5 = comp->fmiBuffer.realBuffer[16];
		comp->st.cell10_6 = comp->fmiBuffer.realBuffer[17];
		comp->st.cell10_7 = comp->fmiBuffer.realBuffer[18];
		comp->st.cell10_8 = comp->fmiBuffer.realBuffer[19];
		comp->st.cell10_9 = comp->fmiBuffer.realBuffer[20];
		comp->st.cell2_1 = comp->fmiBuffer.realBuffer[21];
		comp->st.cell2_10 = comp->fmiBuffer.realBuffer[22];
		comp->st.cell2_2 = comp->fmiBuffer.realBuffer[23];
		comp->st.cell2_3 = comp->fmiBuffer.realBuffer[24];
		comp->st.cell2_4 = comp->fmiBuffer.realBuffer[25];
		comp->st.cell2_5 = comp->fmiBuffer.realBuffer[26];
		comp->st.cell2_6 = comp->fmiBuffer.realBuffer[27];
		comp->st.cell2_7 = comp->fmiBuffer.realBuffer[28];
		comp->st.cell2_8 = comp->fmiBuffer.realBuffer[29];
		comp->st.cell2_9 = comp->fmiBuffer.realBuffer[30];
		comp->st.cell3_1 = comp->fmiBuffer.realBuffer[31];
		comp->st.cell3_10 = comp->fmiBuffer.realBuffer[32];
		comp->st.cell3_2 = comp->fmiBuffer.realBuffer[33];
		comp->st.cell3_3 = comp->fmiBuffer.realBuffer[34];
		comp->st.cell3_4 = comp->fmiBuffer.realBuffer[35];
		comp->st.cell3_5 = comp->fmiBuffer.realBuffer[36];
		comp->st.cell3_6 = comp->fmiBuffer.realBuffer[37];
		comp->st.cell3_7 = comp->fmiBuffer.realBuffer[38];
		comp->st.cell3_8 = comp->fmiBuffer.realBuffer[39];
		comp->st.cell3_9 = comp->fmiBuffer.realBuffer[40];
		comp->st.cell4_1 = comp->fmiBuffer.realBuffer[41];
		comp->st.cell4_10 = comp->fmiBuffer.realBuffer[42];
		comp->st.cell4_2 = comp->fmiBuffer.realBuffer[43];
		comp->st.cell4_3 = comp->fmiBuffer.realBuffer[44];
		comp->st.cell4_4 = comp->fmiBuffer.realBuffer[45];
		comp->st.cell4_5 = comp->fmiBuffer.realBuffer[46];
		comp->st.cell4_6 = comp->fmiBuffer.realBuffer[47];
		comp->st.cell4_7 = comp->fmiBuffer.realBuffer[48];
		comp->st.cell4_8 = comp->fmiBuffer.realBuffer[49];
		comp->st.cell4_9 = comp->fmiBuffer.realBuffer[50];
		comp->st.cell5_1 = comp->fmiBuffer.realBuffer[51];
		comp->st.cell5_10 = comp->fmiBuffer.realBuffer[52];
		comp->st.cell5_2 = comp->fmiBuffer.realBuffer[53];
		comp->st.cell5_3 = comp->fmiBuffer.realBuffer[54];
		comp->st.cell5_4 = comp->fmiBuffer.realBuffer[55];
		comp->st.cell5_5 = comp->fmiBuffer.realBuffer[56];
		comp->st.cell5_6 = comp->fmiBuffer.realBuffer[57];
		comp->st.cell5_7 = comp->fmiBuffer.realBuffer[58];
		comp->st.cell5_8 = comp->fmiBuffer.realBuffer[59];
		comp->st.cell5_9 = comp->fmiBuffer.realBuffer[60];
		comp->st.cell6_1 = comp->fmiBuffer.realBuffer[61];
		comp->st.cell6_10 = comp->fmiBuffer.realBuffer[62];
		comp->st.cell6_2 = comp->fmiBuffer.realBuffer[63];
		comp->st.cell6_3 = comp->fmiBuffer.realBuffer[64];
		comp->st.cell6_4 = comp->fmiBuffer.realBuffer[65];
		comp->st.cell6_5 = comp->fmiBuffer.realBuffer[66];
		comp->st.cell6_6 = comp->fmiBuffer.realBuffer[67];
		comp->st.cell6_7 = comp->fmiBuffer.realBuffer[68];
		comp->st.cell6_8 = comp->fmiBuffer.realBuffer[69];
		comp->st.cell6_9 = comp->fmiBuffer.realBuffer[70];
		comp->st.cell7_1 = comp->fmiBuffer.realBuffer[71];
		comp->st.cell7_10 = comp->fmiBuffer.realBuffer[72];
		comp->st.cell7_2 = comp->fmiBuffer.realBuffer[73];
		comp->st.cell7_3 = comp->fmiBuffer.realBuffer[74];
		comp->st.cell7_4 = comp->fmiBuffer.realBuffer[75];
		comp->st.cell7_5 = comp->fmiBuffer.realBuffer[76];
		comp->st.cell7_6 = comp->fmiBuffer.realBuffer[77];
		comp->st.cell7_7 = comp->fmiBuffer.realBuffer[78];
		comp->st.cell7_8 = comp->fmiBuffer.realBuffer[79];
		comp->st.cell7_9 = comp->fmiBuffer.realBuffer[80];
		comp->st.cell8_1 = comp->fmiBuffer.realBuffer[81];
		comp->st.cell8_10 = comp->fmiBuffer.realBuffer[82];
		comp->st.cell8_2 = comp->fmiBuffer.realBuffer[83];
		comp->st.cell8_3 = comp->fmiBuffer.realBuffer[84];
		comp->st.cell8_4 = comp->fmiBuffer.realBuffer[85];
		comp->st.cell8_5 = comp->fmiBuffer.realBuffer[86];
		comp->st.cell8_6 = comp->fmiBuffer.realBuffer[87];
		comp->st.cell8_7 = comp->fmiBuffer.realBuffer[88];
		comp->st.cell8_8 = comp->fmiBuffer.realBuffer[89];
		comp->st.cell8_9 = comp->fmiBuffer.realBuffer[90];
		comp->st.cell9_1 = comp->fmiBuffer.realBuffer[91];
		comp->st.cell9_10 = comp->fmiBuffer.realBuffer[92];
		comp->st.cell9_2 = comp->fmiBuffer.realBuffer[93];
		comp->st.cell9_3 = comp->fmiBuffer.realBuffer[94];
		comp->st.cell9_4 = comp->fmiBuffer.realBuffer[95];
		comp->st.cell9_5 = comp->fmiBuffer.realBuffer[96];
		comp->st.cell9_6 = comp->fmiBuffer.realBuffer[97];
		comp->st.cell9_7 = comp->fmiBuffer.realBuffer[98];
		comp->st.cell9_8 = comp->fmiBuffer.realBuffer[99];
		comp->st.cell9_9 = comp->fmiBuffer.realBuffer[100];
		comp->st.tickSize = comp->fmiBuffer.realBuffer[104];
		comp->st.time = comp->fmiBuffer.realBuffer[105];

		comp->first = 1;
	}
	
    /*comp->st.x_1 = comp->fmiBuffer.realBuffer[106];
    comp->st.x_2 = comp->fmiBuffer.realBuffer[107];
    comp->st.x_3 = comp->fmiBuffer.realBuffer[108];
    comp->st.x_4 = comp->fmiBuffer.realBuffer[109];
    comp->st.y_1 = comp->fmiBuffer.realBuffer[110];
    comp->st.y_2 = comp->fmiBuffer.realBuffer[111];
    comp->st.y_3 = comp->fmiBuffer.realBuffer[112];
    comp->st.y_4 = comp->fmiBuffer.realBuffer[113];*/
    
    //comp->fmiBuffer.realBuffer[1] = comp->st.cell1_1;
    //comp->fmiBuffer.realBuffer[2] = comp->st.cell1_10;
    //comp->fmiBuffer.realBuffer[3] = comp->st.cell1_2;
    //comp->fmiBuffer.realBuffer[4] = comp->st.cell1_3;
    //comp->fmiBuffer.realBuffer[5] = comp->st.cell1_4;
    //comp->fmiBuffer.realBuffer[6] = comp->st.cell1_5;
    //comp->fmiBuffer.realBuffer[7] = comp->st.cell1_6;
    //comp->fmiBuffer.realBuffer[8] = comp->st.cell1_7;
    //comp->fmiBuffer.realBuffer[9] = comp->st.cell1_8;
    //comp->fmiBuffer.realBuffer[10] = comp->st.cell1_9;
    //comp->fmiBuffer.realBuffer[11] = comp->st.cell10_1;
    //comp->fmiBuffer.realBuffer[12] = comp->st.cell10_10;
    //comp->fmiBuffer.realBuffer[13] = comp->st.cell10_2;
    //comp->fmiBuffer.realBuffer[14] = comp->st.cell10_3;
    //comp->fmiBuffer.realBuffer[15] = comp->st.cell10_4;
    //comp->fmiBuffer.realBuffer[16] = comp->st.cell10_5;
    //comp->fmiBuffer.realBuffer[17] = comp->st.cell10_6;
    //comp->fmiBuffer.realBuffer[18] = comp->st.cell10_7;
    //comp->fmiBuffer.realBuffer[19] = comp->st.cell10_8;
    //comp->fmiBuffer.realBuffer[20] = comp->st.cell10_9;
    //comp->fmiBuffer.realBuffer[21] = comp->st.cell2_1;
    //comp->fmiBuffer.realBuffer[22] = comp->st.cell2_10;
    //comp->fmiBuffer.realBuffer[23] = comp->st.cell2_2;
    //comp->fmiBuffer.realBuffer[24] = comp->st.cell2_3;
    //comp->fmiBuffer.realBuffer[25] = comp->st.cell2_4;
    //comp->fmiBuffer.realBuffer[26] = comp->st.cell2_5;
    //comp->fmiBuffer.realBuffer[27] = comp->st.cell2_6;
    //comp->fmiBuffer.realBuffer[28] = comp->st.cell2_7;
    //comp->fmiBuffer.realBuffer[29] = comp->st.cell2_8;
    //comp->fmiBuffer.realBuffer[30] = comp->st.cell2_9;
    //comp->fmiBuffer.realBuffer[31] = comp->st.cell3_1;
    //comp->fmiBuffer.realBuffer[32] = comp->st.cell3_10;
    //comp->fmiBuffer.realBuffer[33] = comp->st.cell3_2;
    //comp->fmiBuffer.realBuffer[34] = comp->st.cell3_3;
    //comp->fmiBuffer.realBuffer[35] = comp->st.cell3_4;
    //comp->fmiBuffer.realBuffer[36] = comp->st.cell3_5;
    //comp->fmiBuffer.realBuffer[37] = comp->st.cell3_6;
    //comp->fmiBuffer.realBuffer[38] = comp->st.cell3_7;
    //comp->fmiBuffer.realBuffer[39] = comp->st.cell3_8;
    //comp->fmiBuffer.realBuffer[40] = comp->st.cell3_9;
    //comp->fmiBuffer.realBuffer[41] = comp->st.cell4_1;
    //comp->fmiBuffer.realBuffer[42] = comp->st.cell4_10;
    //comp->fmiBuffer.realBuffer[43] = comp->st.cell4_2;
    //comp->fmiBuffer.realBuffer[44] = comp->st.cell4_3;
    //comp->fmiBuffer.realBuffer[45] = comp->st.cell4_4;
    //comp->fmiBuffer.realBuffer[46] = comp->st.cell4_5;
    //comp->fmiBuffer.realBuffer[47] = comp->st.cell4_6;
    //comp->fmiBuffer.realBuffer[48] = comp->st.cell4_7;
    //comp->fmiBuffer.realBuffer[49] = comp->st.cell4_8;
    //comp->fmiBuffer.realBuffer[50] = comp->st.cell4_9;
    //comp->fmiBuffer.realBuffer[51] = comp->st.cell5_1;
    //comp->fmiBuffer.realBuffer[52] = comp->st.cell5_10;
    //comp->fmiBuffer.realBuffer[53] = comp->st.cell5_2;
    //comp->fmiBuffer.realBuffer[54] = comp->st.cell5_3;
    //comp->fmiBuffer.realBuffer[55] = comp->st.cell5_4;
    //comp->fmiBuffer.realBuffer[56] = comp->st.cell5_5;
    //comp->fmiBuffer.realBuffer[57] = comp->st.cell5_6;
    //comp->fmiBuffer.realBuffer[58] = comp->st.cell5_7;
    //comp->fmiBuffer.realBuffer[59] = comp->st.cell5_8;
    //comp->fmiBuffer.realBuffer[60] = comp->st.cell5_9;
    //comp->fmiBuffer.realBuffer[61] = comp->st.cell6_1;
    //comp->fmiBuffer.realBuffer[62] = comp->st.cell6_10;
    //comp->fmiBuffer.realBuffer[63] = comp->st.cell6_2;
    //comp->fmiBuffer.realBuffer[64] = comp->st.cell6_3;
    //comp->fmiBuffer.realBuffer[65] = comp->st.cell6_4;
    //comp->fmiBuffer.realBuffer[66] = comp->st.cell6_5;
    //comp->fmiBuffer.realBuffer[67] = comp->st.cell6_6;
    //comp->fmiBuffer.realBuffer[68] = comp->st.cell6_7;
    //comp->fmiBuffer.realBuffer[69] = comp->st.cell6_8;
    //comp->fmiBuffer.realBuffer[70] = comp->st.cell6_9;
    //comp->fmiBuffer.realBuffer[71] = comp->st.cell7_1;
    //comp->fmiBuffer.realBuffer[72] = comp->st.cell7_10;
    //comp->fmiBuffer.realBuffer[73] = comp->st.cell7_2;
    //comp->fmiBuffer.realBuffer[74] = comp->st.cell7_3;
    //comp->fmiBuffer.realBuffer[75] = comp->st.cell7_4;
    //comp->fmiBuffer.realBuffer[76] = comp->st.cell7_5;
    //comp->fmiBuffer.realBuffer[77] = comp->st.cell7_6;
    //comp->fmiBuffer.realBuffer[78] = comp->st.cell7_7;
    //comp->fmiBuffer.realBuffer[79] = comp->st.cell7_8;
    //comp->fmiBuffer.realBuffer[80] = comp->st.cell7_9;
    //comp->fmiBuffer.realBuffer[81] = comp->st.cell8_1;
    //comp->fmiBuffer.realBuffer[82] = comp->st.cell8_10;
    //comp->fmiBuffer.realBuffer[83] = comp->st.cell8_2;
    //comp->fmiBuffer.realBuffer[84] = comp->st.cell8_3;
    //comp->fmiBuffer.realBuffer[85] = comp->st.cell8_4;
    //comp->fmiBuffer.realBuffer[86] = comp->st.cell8_5;
    //comp->fmiBuffer.realBuffer[87] = comp->st.cell8_6;
    //comp->fmiBuffer.realBuffer[88] = comp->st.cell8_7;
    //comp->fmiBuffer.realBuffer[89] = comp->st.cell8_8;
    //comp->fmiBuffer.realBuffer[90] = comp->st.cell8_9;
    //comp->fmiBuffer.realBuffer[91] = comp->st.cell9_1;
    //comp->fmiBuffer.realBuffer[92] = comp->st.cell9_10;
    //comp->fmiBuffer.realBuffer[93] = comp->st.cell9_2;
    //comp->fmiBuffer.realBuffer[94] = comp->st.cell9_3;
    //comp->fmiBuffer.realBuffer[95] = comp->st.cell9_4;
    //comp->fmiBuffer.realBuffer[96] = comp->st.cell9_5;
    //comp->fmiBuffer.realBuffer[97] = comp->st.cell9_6;
    //comp->fmiBuffer.realBuffer[98] = comp->st.cell9_7;
    //comp->fmiBuffer.realBuffer[99] = comp->st.cell9_8;
    //comp->fmiBuffer.realBuffer[100] = comp->st.cell9_9;
    //comp->fmiBuffer.realBuffer[104] = comp->st.tickSize;
    //comp->fmiBuffer.realBuffer[105] = comp->st.time;
    //comp->fmiBuffer.intBuffer[102] = comp->st.port;
    //comp->fmiBuffer.intBuffer[103] = comp->st.stepCount;

	if(comp->websocket_open == 1)
		lws_service(comp->context, 0);
	
    if (connection == 1) {
		lws_service(comp->context, 0);
		tick(&comp->st);
	}
	
	comp->fmiBuffer.realBuffer[101] = comp->st.dummy;
	
	/*printf("Time: %f\n", comp->fmiBuffer.realBuffer[105]);
	comp->fmiBuffer.realBuffer[105] += 0.01;
	comp->st.time = comp->fmiBuffer.realBuffer[105];*/
	
}

void terminate(ModelInstance* comp) {
	close_websocket(comp);
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
			connection = 1;
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
* Function used to convert the state into a string
*/
void stateToString(State st, char* str) {
	char* temp = (char*)malloc(1024);

	strcpy(str, "(#");
	
	/*sprintf(temp, " cell1_1 := %f,", st.cell1_1);
	strcat(str, temp);
	sprintf(temp, " cell1_10 := %f,", st.cell1_10);
	strcat(str, temp);
	sprintf(temp, " cell1_2 := %f,", st.cell1_2);
	strcat(str, temp);
	sprintf(temp, " cell1_3 := %f,", st.cell1_3);
	strcat(str, temp);
	sprintf(temp, " cell1_4 := %f,", st.cell1_4);
	strcat(str, temp);
	sprintf(temp, " cell1_5 := %f,", st.cell1_5);
	strcat(str, temp);
	sprintf(temp, " cell1_6 := %f,", st.cell1_6);
	strcat(str, temp);
	sprintf(temp, " cell1_7 := %f,", st.cell1_7);
	strcat(str, temp);
	sprintf(temp, " cell1_8 := %f,", st.cell1_8);
	strcat(str, temp);
	sprintf(temp, " cell1_9 := %f,", st.cell1_9);
	strcat(str, temp);
	sprintf(temp, " cell10_1 := %f,", st.cell10_1);
	strcat(str, temp);
	sprintf(temp, " cell10_10 := %f,", st.cell10_10);
	strcat(str, temp);
	sprintf(temp, " cell10_2 := %f,", st.cell10_2);
	strcat(str, temp);
	sprintf(temp, " cell10_3 := %f,", st.cell10_3);
	strcat(str, temp);
	sprintf(temp, " cell10_4 := %f,", st.cell10_4);
	strcat(str, temp);
	sprintf(temp, " cell10_5 := %f,", st.cell10_5);
	strcat(str, temp);
	sprintf(temp, " cell10_6 := %f,", st.cell10_6);
	strcat(str, temp);
	sprintf(temp, " cell10_7 := %f,", st.cell10_7);
	strcat(str, temp);
	sprintf(temp, " cell10_8 := %f,", st.cell10_8);
	strcat(str, temp);
	sprintf(temp, " cell10_9 := %f,", st.cell10_9);
	strcat(str, temp);
	sprintf(temp, " cell2_1 := %f,", st.cell2_1);
	strcat(str, temp);
	sprintf(temp, " cell2_10 := %f,", st.cell2_10);
	strcat(str, temp);
	sprintf(temp, " cell2_2 := %f,", st.cell2_2);
	strcat(str, temp);
	sprintf(temp, " cell2_3 := %f,", st.cell2_3);
	strcat(str, temp);
	sprintf(temp, " cell2_4 := %f,", st.cell2_4);
	strcat(str, temp);
	sprintf(temp, " cell2_5 := %f,", st.cell2_5);
	strcat(str, temp);
	sprintf(temp, " cell2_6 := %f,", st.cell2_6);
	strcat(str, temp);
	sprintf(temp, " cell2_7 := %f,", st.cell2_7);
	strcat(str, temp);
	sprintf(temp, " cell2_8 := %f,", st.cell2_8);
	strcat(str, temp);
	sprintf(temp, " cell2_9 := %f,", st.cell2_9);
	strcat(str, temp);
	sprintf(temp, " cell3_1 := %f,", st.cell3_1);
	strcat(str, temp);
	sprintf(temp, " cell3_10 := %f,", st.cell3_10);
	strcat(str, temp);
	sprintf(temp, " cell3_2 := %f,", st.cell3_2);
	strcat(str, temp);
	sprintf(temp, " cell3_3 := %f,", st.cell3_3);
	strcat(str, temp);
	sprintf(temp, " cell3_4 := %f,", st.cell3_4);
	strcat(str, temp);
	sprintf(temp, " cell3_5 := %f,", st.cell3_5);
	strcat(str, temp);
	sprintf(temp, " cell3_6 := %f,", st.cell3_6);
	strcat(str, temp);
	sprintf(temp, " cell3_7 := %f,", st.cell3_7);
	strcat(str, temp);
	sprintf(temp, " cell3_8 := %f,", st.cell3_8);
	strcat(str, temp);
	sprintf(temp, " cell3_9 := %f,", st.cell3_9);
	strcat(str, temp);
	sprintf(temp, " cell4_1 := %f,", st.cell4_1);
	strcat(str, temp);
	sprintf(temp, " cell4_10 := %f,", st.cell4_10);
	strcat(str, temp);
	sprintf(temp, " cell4_2 := %f,", st.cell4_2);
	strcat(str, temp);
	sprintf(temp, " cell4_3 := %f,", st.cell4_3);
	strcat(str, temp);
	sprintf(temp, " cell4_4 := %f,", st.cell4_4);
	strcat(str, temp);
	sprintf(temp, " cell4_5 := %f,", st.cell4_5);
	strcat(str, temp);
	sprintf(temp, " cell4_6 := %f,", st.cell4_6);
	strcat(str, temp);
	sprintf(temp, " cell4_7 := %f,", st.cell4_7);
	strcat(str, temp);
	sprintf(temp, " cell4_8 := %f,", st.cell4_8);
	strcat(str, temp);
	sprintf(temp, " cell4_9 := %f,", st.cell4_9);
	strcat(str, temp);
	sprintf(temp, " cell5_1 := %f,", st.cell5_1);
	strcat(str, temp);
	sprintf(temp, " cell5_10 := %f,", st.cell5_10);
	strcat(str, temp);
	sprintf(temp, " cell5_2 := %f,", st.cell5_2);
	strcat(str, temp);
	sprintf(temp, " cell5_3 := %f,", st.cell5_3);
	strcat(str, temp);
	sprintf(temp, " cell5_4 := %f,", st.cell5_4);
	strcat(str, temp);
	sprintf(temp, " cell5_5 := %f,", st.cell5_5);
	strcat(str, temp);
	sprintf(temp, " cell5_6 := %f,", st.cell5_6);
	strcat(str, temp);
	sprintf(temp, " cell5_7 := %f,", st.cell5_7);
	strcat(str, temp);
	sprintf(temp, " cell5_8 := %f,", st.cell5_8);
	strcat(str, temp);
	sprintf(temp, " cell5_9 := %f,", st.cell5_9);
	strcat(str, temp);
	sprintf(temp, " cell6_1 := %f,", st.cell6_1);
	strcat(str, temp);
	sprintf(temp, " cell6_10 := %f,", st.cell6_10);
	strcat(str, temp);
	sprintf(temp, " cell6_2 := %f,", st.cell6_2);
	strcat(str, temp);
	sprintf(temp, " cell6_3 := %f,", st.cell6_3);
	strcat(str, temp);
	sprintf(temp, " cell6_4 := %f,", st.cell6_4);
	strcat(str, temp);
	sprintf(temp, " cell6_5 := %f,", st.cell6_5);
	strcat(str, temp);
	sprintf(temp, " cell6_6 := %f,", st.cell6_6);
	strcat(str, temp);
	sprintf(temp, " cell6_7 := %f,", st.cell6_7);
	strcat(str, temp);
	sprintf(temp, " cell6_8 := %f,", st.cell6_8);
	strcat(str, temp);
	sprintf(temp, " cell6_9 := %f,", st.cell6_9);
	strcat(str, temp);
	sprintf(temp, " cell7_1 := %f,", st.cell7_1);
	strcat(str, temp);
	sprintf(temp, " cell7_10 := %f,", st.cell7_10);
	strcat(str, temp);
	sprintf(temp, " cell7_2 := %f,", st.cell7_2);
	strcat(str, temp);
	sprintf(temp, " cell7_3 := %f,", st.cell7_3);
	strcat(str, temp);
	sprintf(temp, " cell7_4 := %f,", st.cell7_4);
	strcat(str, temp);
	sprintf(temp, " cell7_5 := %f,", st.cell7_5);
	strcat(str, temp);
	sprintf(temp, " cell7_6 := %f,", st.cell7_6);
	strcat(str, temp);
	sprintf(temp, " cell7_7 := %f,", st.cell7_7);
	strcat(str, temp);
	sprintf(temp, " cell7_8 := %f,", st.cell7_8);
	strcat(str, temp);
	sprintf(temp, " cell7_9 := %f,", st.cell7_9);
	strcat(str, temp);
	sprintf(temp, " cell8_1 := %f,", st.cell8_1);
	strcat(str, temp);
	sprintf(temp, " cell8_10 := %f,", st.cell8_10);
	strcat(str, temp);
	sprintf(temp, " cell8_2 := %f,", st.cell8_2);
	strcat(str, temp);
	sprintf(temp, " cell8_3 := %f,", st.cell8_3);
	strcat(str, temp);
	sprintf(temp, " cell8_4 := %f,", st.cell8_4);
	strcat(str, temp);
	sprintf(temp, " cell8_5 := %f,", st.cell8_5);
	strcat(str, temp);
	sprintf(temp, " cell8_6 := %f,", st.cell8_6);
	strcat(str, temp);
	sprintf(temp, " cell8_7 := %f,", st.cell8_7);
	strcat(str, temp);
	sprintf(temp, " cell8_8 := %f,", st.cell8_8);
	strcat(str, temp);
	sprintf(temp, " cell8_9 := %f,", st.cell8_9);
	strcat(str, temp);
	sprintf(temp, " cell9_1 := %f,", st.cell9_1);
	strcat(str, temp);
	sprintf(temp, " cell9_10 := %f,", st.cell9_10);
	strcat(str, temp);
	sprintf(temp, " cell9_2 := %f,", st.cell9_2);
	strcat(str, temp);
	sprintf(temp, " cell9_3 := %f,", st.cell9_3);
	strcat(str, temp);
	sprintf(temp, " cell9_4 := %f,", st.cell9_4);
	strcat(str, temp);
	sprintf(temp, " cell9_5 := %f,", st.cell9_5);
	strcat(str, temp);
	sprintf(temp, " cell9_6 := %f,", st.cell9_6);
	strcat(str, temp);
	sprintf(temp, " cell9_7 := %f,", st.cell9_7);
	strcat(str, temp);
	sprintf(temp, " cell9_8 := %f,", st.cell9_8);
	strcat(str, temp);
	sprintf(temp, " cell9_9 := %f,", st.cell9_9);
	strcat(str, temp);
	sprintf(temp, " dummy := %f,", st.dummy);
	strcat(str, temp);
	sprintf(temp, " port := %d,", st.port);
	strcat(str, temp);
	sprintf(temp, " stepCount := %d,", st.stepCount);
	strcat(str, temp);
	sprintf(temp, " tickSize := %f,", st.tickSize);
	strcat(str, temp);
	sprintf(temp, " time := %f,", st.time);*/
	strcat(str, temp);
	sprintf(temp, " x_1 := %f,", st.x_1);
	strcat(str, temp);
	sprintf(temp, " x_2 := %f,", st.x_2);
	strcat(str, temp);
	sprintf(temp, " x_3 := %f,", st.x_3);
	strcat(str, temp);
	sprintf(temp, " x_4 := %f,", st.x_4);
	strcat(str, temp);
	sprintf(temp, " y_1 := %f,", st.y_1);
	strcat(str, temp);
	sprintf(temp, " y_2 := %f,", st.y_2);
	strcat(str, temp);
	sprintf(temp, " y_3 := %f,", st.y_3);
	strcat(str, temp);
	sprintf(temp, " y_4 := %f,", st.y_4);
	strcat(str, temp);
	//Remove the last char ','
	temp[strlen(str)-1] = '\0';
	strcat(str, " #);");

	free(temp);
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
