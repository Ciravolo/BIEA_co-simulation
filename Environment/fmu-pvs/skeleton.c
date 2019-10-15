/*! \file skeleton.c 
 * In this file there are the implementations
 * of the fuctions declared in fmu.h
 * along with the data needed.
 */
#include "fmu.h"
#include "misraC/Environment.h"


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
	printf("fine init\n");
    
    
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

    st.cell1_1 = fmiBuffer.realBuffer[1] ;
    st.cell1_10 = fmiBuffer.realBuffer[2] ;
    st.cell1_2 = fmiBuffer.realBuffer[3] ;
    st.cell1_3 = fmiBuffer.realBuffer[4] ;
    st.cell1_4 = fmiBuffer.realBuffer[5] ;
    st.cell1_5 = fmiBuffer.realBuffer[6] ;
    st.cell1_6 = fmiBuffer.realBuffer[7] ;
    st.cell1_7 = fmiBuffer.realBuffer[8] ;
    st.cell1_8 = fmiBuffer.realBuffer[9] ;
    st.cell1_9 = fmiBuffer.realBuffer[10] ;
    st.cell10_1 = fmiBuffer.realBuffer[11] ;
    st.cell10_10 = fmiBuffer.realBuffer[12] ;
    st.cell10_2 = fmiBuffer.realBuffer[13] ;
    st.cell10_3 = fmiBuffer.realBuffer[14] ;
    st.cell10_4 = fmiBuffer.realBuffer[15] ;
    st.cell10_5 = fmiBuffer.realBuffer[16] ;
    st.cell10_6 = fmiBuffer.realBuffer[17] ;
    st.cell10_7 = fmiBuffer.realBuffer[18] ;
    st.cell10_8 = fmiBuffer.realBuffer[19] ;
    st.cell10_9 = fmiBuffer.realBuffer[20] ;
    st.cell2_1 = fmiBuffer.realBuffer[21] ;
    st.cell2_10 = fmiBuffer.realBuffer[22] ;
    st.cell2_2 = fmiBuffer.realBuffer[23] ;
    st.cell2_3 = fmiBuffer.realBuffer[24] ;
    st.cell2_4 = fmiBuffer.realBuffer[25] ;
    st.cell2_5 = fmiBuffer.realBuffer[26] ;
    st.cell2_6 = fmiBuffer.realBuffer[27] ;
    st.cell2_7 = fmiBuffer.realBuffer[28] ;
    st.cell2_8 = fmiBuffer.realBuffer[29] ;
    st.cell2_9 = fmiBuffer.realBuffer[30] ;
    st.cell3_1 = fmiBuffer.realBuffer[31] ;
    st.cell3_10 = fmiBuffer.realBuffer[32] ;
    st.cell3_2 = fmiBuffer.realBuffer[33] ;
    st.cell3_3 = fmiBuffer.realBuffer[34] ;
    st.cell3_4 = fmiBuffer.realBuffer[35] ;
    st.cell3_5 = fmiBuffer.realBuffer[36] ;
    st.cell3_6 = fmiBuffer.realBuffer[37] ;
    st.cell3_7 = fmiBuffer.realBuffer[38] ;
    st.cell3_8 = fmiBuffer.realBuffer[39] ;
    st.cell3_9 = fmiBuffer.realBuffer[40] ;
    st.cell4_1 = fmiBuffer.realBuffer[41] ;
    st.cell4_10 = fmiBuffer.realBuffer[42] ;
    st.cell4_2 = fmiBuffer.realBuffer[43] ;
    st.cell4_3 = fmiBuffer.realBuffer[44] ;
    st.cell4_4 = fmiBuffer.realBuffer[45] ;
    st.cell4_5 = fmiBuffer.realBuffer[46] ;
    st.cell4_6 = fmiBuffer.realBuffer[47] ;
    st.cell4_7 = fmiBuffer.realBuffer[48] ;
    st.cell4_8 = fmiBuffer.realBuffer[49] ;
    st.cell4_9 = fmiBuffer.realBuffer[50] ;
    st.cell5_1 = fmiBuffer.realBuffer[51] ;
    st.cell5_10 = fmiBuffer.realBuffer[52] ;
    st.cell5_2 = fmiBuffer.realBuffer[53] ;
    st.cell5_3 = fmiBuffer.realBuffer[54] ;
    st.cell5_4 = fmiBuffer.realBuffer[55] ;
    st.cell5_5 = fmiBuffer.realBuffer[56] ;
    st.cell5_6 = fmiBuffer.realBuffer[57] ;
    st.cell5_7 = fmiBuffer.realBuffer[58] ;
    st.cell5_8 = fmiBuffer.realBuffer[59] ;
    st.cell5_9 = fmiBuffer.realBuffer[60] ;
    st.cell6_1 = fmiBuffer.realBuffer[61] ;
    st.cell6_10 = fmiBuffer.realBuffer[62] ;
    st.cell6_2 = fmiBuffer.realBuffer[63] ;
    st.cell6_3 = fmiBuffer.realBuffer[64] ;
    st.cell6_4 = fmiBuffer.realBuffer[65] ;
    st.cell6_5 = fmiBuffer.realBuffer[66] ;
    st.cell6_6 = fmiBuffer.realBuffer[67] ;
    st.cell6_7 = fmiBuffer.realBuffer[68] ;
    st.cell6_8 = fmiBuffer.realBuffer[69] ;
    st.cell6_9 = fmiBuffer.realBuffer[70] ;
    st.cell7_1 = fmiBuffer.realBuffer[71] ;
    st.cell7_10 = fmiBuffer.realBuffer[72] ;
    st.cell7_2 = fmiBuffer.realBuffer[73] ;
    st.cell7_3 = fmiBuffer.realBuffer[74] ;
    st.cell7_4 = fmiBuffer.realBuffer[75] ;
    st.cell7_5 = fmiBuffer.realBuffer[76] ;
    st.cell7_6 = fmiBuffer.realBuffer[77] ;
    st.cell7_7 = fmiBuffer.realBuffer[78] ;
    st.cell7_8 = fmiBuffer.realBuffer[79] ;
    st.cell7_9 = fmiBuffer.realBuffer[80] ;
    st.cell8_1 = fmiBuffer.realBuffer[81] ;
    st.cell8_10 = fmiBuffer.realBuffer[82] ;
    st.cell8_2 = fmiBuffer.realBuffer[83] ;
    st.cell8_3 = fmiBuffer.realBuffer[84] ;
    st.cell8_4 = fmiBuffer.realBuffer[85] ;
    st.cell8_5 = fmiBuffer.realBuffer[86] ;
    st.cell8_6 = fmiBuffer.realBuffer[87] ;
    st.cell8_7 = fmiBuffer.realBuffer[88] ;
    st.cell8_8 = fmiBuffer.realBuffer[89] ;
    st.cell8_9 = fmiBuffer.realBuffer[90] ;
    st.cell9_1 = fmiBuffer.realBuffer[91] ;
    st.cell9_10 = fmiBuffer.realBuffer[92] ;
    st.cell9_2 = fmiBuffer.realBuffer[93] ;
    st.cell9_3 = fmiBuffer.realBuffer[94] ;
    st.cell9_4 = fmiBuffer.realBuffer[95] ;
    st.cell9_5 = fmiBuffer.realBuffer[96] ;
    st.cell9_6 = fmiBuffer.realBuffer[97] ;
    st.cell9_7 = fmiBuffer.realBuffer[98] ;
    st.cell9_8 = fmiBuffer.realBuffer[99] ;
    st.cell9_9 = fmiBuffer.realBuffer[100] ;
    
    first = 1;
}
	
   /* st.x_1 = fmiBuffer.realBuffer[102];
    st.x_2 = fmiBuffer.realBuffer[103];
    st.x_3 = fmiBuffer.realBuffer[104];
    st.x_4 = fmiBuffer.realBuffer[105];
    st.y_1 = fmiBuffer.realBuffer[106];
    st.y_2 = fmiBuffer.realBuffer[107];
    st.y_3 = fmiBuffer.realBuffer[108];
    st.y_4 = fmiBuffer.realBuffer[109];*/
    tick(&st);
    
    
    /*
    fmiBuffer.realBuffer[1] = st.cell1_1;
    fmiBuffer.realBuffer[2] = st.cell1_10;
    fmiBuffer.realBuffer[3] = st.cell1_2;
    fmiBuffer.realBuffer[4] = st.cell1_3;
    fmiBuffer.realBuffer[5] = st.cell1_4;
    fmiBuffer.realBuffer[6] = st.cell1_5;
    fmiBuffer.realBuffer[7] = st.cell1_6;
    fmiBuffer.realBuffer[8] = st.cell1_7;
    fmiBuffer.realBuffer[9] = st.cell1_8;
    fmiBuffer.realBuffer[10] = st.cell1_9;
    fmiBuffer.realBuffer[11] = st.cell10_1;
    fmiBuffer.realBuffer[12] = st.cell10_10;
    fmiBuffer.realBuffer[13] = st.cell10_2;
    fmiBuffer.realBuffer[14] = st.cell10_3;
    fmiBuffer.realBuffer[15] = st.cell10_4;
    fmiBuffer.realBuffer[16] = st.cell10_5;
    fmiBuffer.realBuffer[17] = st.cell10_6;
    fmiBuffer.realBuffer[18] = st.cell10_7;
    fmiBuffer.realBuffer[19] = st.cell10_8;
    fmiBuffer.realBuffer[20] = st.cell10_9;
    fmiBuffer.realBuffer[21] = st.cell2_1;
    fmiBuffer.realBuffer[22] = st.cell2_10;
    fmiBuffer.realBuffer[23] = st.cell2_2;
    fmiBuffer.realBuffer[24] = st.cell2_3;
    fmiBuffer.realBuffer[25] = st.cell2_4;
    fmiBuffer.realBuffer[26] = st.cell2_5;
    fmiBuffer.realBuffer[27] = st.cell2_6;
    fmiBuffer.realBuffer[28] = st.cell2_7;
    fmiBuffer.realBuffer[29] = st.cell2_8;
    fmiBuffer.realBuffer[30] = st.cell2_9;
    fmiBuffer.realBuffer[31] = st.cell3_1;
    fmiBuffer.realBuffer[32] = st.cell3_10;
    fmiBuffer.realBuffer[33] = st.cell3_2;
    fmiBuffer.realBuffer[34] = st.cell3_3;
    fmiBuffer.realBuffer[35] = st.cell3_4;
    fmiBuffer.realBuffer[36] = st.cell3_5;
    fmiBuffer.realBuffer[37] = st.cell3_6;
    fmiBuffer.realBuffer[38] = st.cell3_7;
    fmiBuffer.realBuffer[39] = st.cell3_8;
    fmiBuffer.realBuffer[40] = st.cell3_9;
    fmiBuffer.realBuffer[41] = st.cell4_1;
    fmiBuffer.realBuffer[42] = st.cell4_10;
    fmiBuffer.realBuffer[43] = st.cell4_2;
    fmiBuffer.realBuffer[44] = st.cell4_3;
    fmiBuffer.realBuffer[45] = st.cell4_4;
    fmiBuffer.realBuffer[46] = st.cell4_5;
    fmiBuffer.realBuffer[47] = st.cell4_6;
    fmiBuffer.realBuffer[48] = st.cell4_7;
    fmiBuffer.realBuffer[49] = st.cell4_8;
    fmiBuffer.realBuffer[50] = st.cell4_9;
    fmiBuffer.realBuffer[51] = st.cell5_1;
    fmiBuffer.realBuffer[52] = st.cell5_10;
    fmiBuffer.realBuffer[53] = st.cell5_2;
    fmiBuffer.realBuffer[54] = st.cell5_3;
    fmiBuffer.realBuffer[55] = st.cell5_4;
    fmiBuffer.realBuffer[56] = st.cell5_5;
    fmiBuffer.realBuffer[57] = st.cell5_6;
    fmiBuffer.realBuffer[58] = st.cell5_7;
    fmiBuffer.realBuffer[59] = st.cell5_8;
    fmiBuffer.realBuffer[60] = st.cell5_9;
    fmiBuffer.realBuffer[61] = st.cell6_1;
    fmiBuffer.realBuffer[62] = st.cell6_10;
    fmiBuffer.realBuffer[63] = st.cell6_2;
    fmiBuffer.realBuffer[64] = st.cell6_3;
    fmiBuffer.realBuffer[65] = st.cell6_4;
    fmiBuffer.realBuffer[66] = st.cell6_5;
    fmiBuffer.realBuffer[67] = st.cell6_6;
    fmiBuffer.realBuffer[68] = st.cell6_7;
    fmiBuffer.realBuffer[69] = st.cell6_8;
    fmiBuffer.realBuffer[70] = st.cell6_9;
    fmiBuffer.realBuffer[71] = st.cell7_1;
    fmiBuffer.realBuffer[72] = st.cell7_10;
    fmiBuffer.realBuffer[73] = st.cell7_2;
    fmiBuffer.realBuffer[74] = st.cell7_3;
    fmiBuffer.realBuffer[75] = st.cell7_4;
    fmiBuffer.realBuffer[76] = st.cell7_5;
    fmiBuffer.realBuffer[77] = st.cell7_6;
    fmiBuffer.realBuffer[78] = st.cell7_7;
    fmiBuffer.realBuffer[79] = st.cell7_8;
    fmiBuffer.realBuffer[80] = st.cell7_9;
    fmiBuffer.realBuffer[81] = st.cell8_1;
    fmiBuffer.realBuffer[82] = st.cell8_10;
    fmiBuffer.realBuffer[83] = st.cell8_2;
    fmiBuffer.realBuffer[84] = st.cell8_3;
    fmiBuffer.realBuffer[85] = st.cell8_4;
    fmiBuffer.realBuffer[86] = st.cell8_5;
    fmiBuffer.realBuffer[87] = st.cell8_6;
    fmiBuffer.realBuffer[88] = st.cell8_7;
    fmiBuffer.realBuffer[89] = st.cell8_8;
    fmiBuffer.realBuffer[90] = st.cell8_9;
    fmiBuffer.realBuffer[91] = st.cell9_1;
    fmiBuffer.realBuffer[92] = st.cell9_10;
    fmiBuffer.realBuffer[93] = st.cell9_2;
    fmiBuffer.realBuffer[94] = st.cell9_3;
    fmiBuffer.realBuffer[95] = st.cell9_4;
    fmiBuffer.realBuffer[96] = st.cell9_5;
    fmiBuffer.realBuffer[97] = st.cell9_6;
    fmiBuffer.realBuffer[98] = st.cell9_7;
    fmiBuffer.realBuffer[99] = st.cell9_8;
    fmiBuffer.realBuffer[100] = st.cell9_9;
    fmiBuffer.intBuffer[101] = st.stepCount;*/
}

void terminate(){ }


