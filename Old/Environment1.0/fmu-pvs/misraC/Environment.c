#include "Environment.h"
/**
 * init function
 */
 
void init(State* st) { 
    st->previous_mode = X1;
    st->mode = X1;
    st->cell1_1 = 0.0f;
    st->cell1_10 = 0.0f;
    st->cell1_2 = 0.0f;
    st->cell1_3 = 0.0f;
    st->cell1_4 = 0.0f;
    st->cell1_5 = 0.0f;
    st->cell1_6 = 0.0f;
    st->cell1_7 = 0.0f;
    st->cell1_8 = 0.0f;
    st->cell1_9 = 0.0f;
    st->cell10_1 = 0.0f;
    st->cell10_10 = 0.0f;
    st->cell10_2 = 0.0f;
    st->cell10_3 = 0.0f;
    st->cell10_4 = 0.0f;
    st->cell10_5 = 0.0f;
    st->cell10_6 = 0.0f;
    st->cell10_7 = 0.0f;
    st->cell10_8 = 0.0f;
    st->cell10_9 = 0.0f;
    st->cell2_1 = 0.0f;
    st->cell2_10 = 0.0f;
    st->cell2_2 = 0.0f;
    st->cell2_3 = 0.0f;
    st->cell2_4 = 0.0f;
    st->cell2_5 = 0.0f;
    st->cell2_6 = 0.0f;
    st->cell2_7 = 0.0f;
    st->cell2_8 = 0.0f;
    st->cell2_9 = 0.0f;
    st->cell3_1 = 0.0f;
    st->cell3_10 = 0.0f;
    st->cell3_2 = 0.0f;
    st->cell3_3 = 0.0f;
    st->cell3_4 = 0.0f;
    st->cell3_5 = 0.0f;
    st->cell3_6 = 0.0f;
    st->cell3_7 = 0.0f;
    st->cell3_8 = 0.0f;
    st->cell3_9 = 0.0f;
    st->cell4_1 = 0.0f;
    st->cell4_10 = 0.0f;
    st->cell4_2 = 0.0f;
    st->cell4_3 = 0.0f;
    st->cell4_4 = 0.0f;
    st->cell4_5 = 0.0f;
    st->cell4_6 = 0.0f;
    st->cell4_7 = 0.0f;
    st->cell4_8 = 0.0f;
    st->cell4_9 = 0.0f;
    st->cell5_1 = 0.0f;
    st->cell5_10 = 0.0f;
    st->cell5_2 = 0.0f;
    st->cell5_3 = 0.0f;
    st->cell5_4 = 0.0f;
    st->cell5_5 = 0.0f;
    st->cell5_6 = 0.0f;
    st->cell5_7 = 0.0f;
    st->cell5_8 = 0.0f;
    st->cell5_9 = 0.0f;
    st->cell6_1 = 0.0f;
    st->cell6_10 = 0.0f;
    st->cell6_2 = 0.0f;
    st->cell6_3 = 0.0f;
    st->cell6_4 = 0.0f;
    st->cell6_5 = 0.0f;
    st->cell6_6 = 0.0f;
    st->cell6_7 = 0.0f;
    st->cell6_8 = 0.0f;
    st->cell6_9 = 0.0f;
    st->cell7_1 = 0.0f;
    st->cell7_10 = 0.0f;
    st->cell7_2 = 0.0f;
    st->cell7_3 = 0.0f;
    st->cell7_4 = 0.0f;
    st->cell7_5 = 0.0f;
    st->cell7_6 = 0.0f;
    st->cell7_7 = 0.0f;
    st->cell7_8 = 0.0f;
    st->cell7_9 = 0.0f;
    st->cell8_1 = 0.0f;
    st->cell8_10 = 0.0f;
    st->cell8_2 = 0.0f;
    st->cell8_3 = 0.0f;
    st->cell8_4 = 0.0f;
    st->cell8_5 = 0.0f;
    st->cell8_6 = 0.0f;
    st->cell8_7 = 0.0f;
    st->cell8_8 = 0.0f;
    st->cell8_9 = 0.0f;
    st->cell9_1 = 0.0f;
    st->cell9_10 = 0.0f;
    st->cell9_2 = 0.0f;
    st->cell9_3 = 0.0f;
    st->cell9_4 = 0.0f;
    st->cell9_5 = 0.0f;
    st->cell9_6 = 0.0f;
    st->cell9_7 = 0.0f;
    st->cell9_8 = 0.0f;
    st->cell9_9 = 0.0f;
    st->port = 8087;
    st->stepCount = 0;
    st->flag = 1;
    st->tickSize = 0.01f;
    st->time = 0.0f;
    st->x_1 = 0.5f;
    st->x_2 = 9.5f;
    st->x_3 = 9.5f;
    st->x_4 = 0.5f;
    st->xDesired1 = 0.0f;
    st->xDesired2 = 0.0f;
    st->xDesired3 = 0.0f;
    st->xDesired4 = 0.0f;
    st->y_1 = 0.5f;
    st->y_2 = 0.5f;
    st->y_3 = 9.5f;
    st->y_4 = 9.5f;
    st->yDesired1 = 0.0f;
    st->yDesired2 = 0.0f;
    st->yDesired3 = 0.0f;
    st->yDesired4 = 0.0f;
    st->onDestination1 = 0.0f;
    st->onDestination2 = 0.0f;
    st->onDestination3 = 0.0f;
    st->onDestination4 = 0.0f;
    
    EPSLON = unifRand();
	isInit = TRUE;
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
    return (st->mode == X1);
}

/**
 * Translation function from State to State1
 */
void state2State1(State* st, State1* st1) {

		int32_t i, j;
		Cell* occupiedCells[ROBOTS];

    	st1->map[0][0].pheromone = st->cell1_1;
    	st1->map[0][1].pheromone =st->cell1_2;
    	st1->map[0][2].pheromone =st->cell1_3;
    	st1->map[0][3].pheromone =st->cell1_4;
    	st1->map[0][4].pheromone =st->cell1_5;
    	st1->map[0][5].pheromone =st->cell1_6;
    	st1->map[0][6].pheromone =st->cell1_7;
		st1->map[0][7].pheromone =st->cell1_8;
		st1->map[0][8].pheromone =st->cell1_9;
		st1->map[0][9].pheromone =st->cell1_10;
		st1->map[1][0].pheromone =st->cell2_1;
    	st1->map[1][1].pheromone =st->cell2_2;
    	st1->map[1][2].pheromone =st->cell2_3;
    	st1->map[1][3].pheromone =st->cell2_4;
    	st1->map[1][4].pheromone =st->cell2_5;
    	st1->map[1][5].pheromone =st->cell2_6;
    	st1->map[1][6].pheromone =st->cell2_7;
		st1->map[1][7].pheromone =st->cell2_8;
		st1->map[1][8].pheromone =st->cell2_9;
		st1->map[1][9].pheromone =st->cell2_10;
		st1->map[2][0].pheromone =st->cell3_1;
    	st1->map[2][1].pheromone =st->cell3_2;
    	st1->map[2][2].pheromone =st->cell3_3;
    	st1->map[2][3].pheromone =st->cell3_4;
    	st1->map[2][4].pheromone =st->cell3_5;
    	st1->map[2][5].pheromone =st->cell3_6;
    	st1->map[2][6].pheromone =st->cell3_7;
		st1->map[2][7].pheromone =st->cell3_8;
		st1->map[2][8].pheromone =st->cell3_9;
		st1->map[2][9].pheromone =st->cell3_10;
		st1->map[3][0].pheromone =st->cell4_1;
    	st1->map[3][1].pheromone =st->cell4_2;
    	st1->map[3][2].pheromone =st->cell4_3;
    	st1->map[3][3].pheromone =st->cell4_4;
    	st1->map[3][4].pheromone =st->cell4_5;
    	st1->map[3][5].pheromone =st->cell4_6;
    	st1->map[3][6].pheromone =st->cell4_7;
		st1->map[3][7].pheromone =st->cell4_8;
		st1->map[3][8].pheromone =st->cell4_9;
		st1->map[3][9].pheromone =st->cell4_10;
		st1->map[4][0].pheromone =st->cell5_1;
		st1->map[4][1].pheromone =st->cell5_2;
    	st1->map[4][2].pheromone =st->cell5_3;
    	st1->map[4][3].pheromone =st->cell5_4;
    	st1->map[4][4].pheromone =st->cell5_5;
    	st1->map[4][5].pheromone =st->cell5_6;
    	st1->map[4][6].pheromone =st->cell5_7;
		st1->map[4][7].pheromone =st->cell5_8;
		st1->map[4][8].pheromone =st->cell5_9;
		st1->map[4][9].pheromone =st->cell5_10;
		st1->map[5][0].pheromone =st->cell6_1;
    	st1->map[5][1].pheromone =st->cell6_2;
    	st1->map[5][2].pheromone =st->cell6_3;
    	st1->map[5][3].pheromone =st->cell6_4;
    	st1->map[5][4].pheromone =st->cell6_5;
    	st1->map[5][5].pheromone =st->cell6_6;
    	st1->map[5][6].pheromone =st->cell6_7;
		st1->map[5][7].pheromone =st->cell6_8;
		st1->map[5][8].pheromone =st->cell6_9;
		st1->map[5][9].pheromone =st->cell6_10;
		st1->map[6][0].pheromone =st->cell7_1;
    	st1->map[6][1].pheromone =st->cell7_2;
    	st1->map[6][2].pheromone =st->cell7_3;
    	st1->map[6][3].pheromone =st->cell7_4;
    	st1->map[6][4].pheromone =st->cell7_5;
    	st1->map[6][5].pheromone =st->cell7_6;
    	st1->map[6][6].pheromone =st->cell7_7;
		st1->map[6][7].pheromone =st->cell7_8;
		st1->map[6][8].pheromone =st->cell7_9;
		st1->map[6][9].pheromone =st->cell7_10;
		st1->map[7][0].pheromone =st->cell8_1;
    	st1->map[7][1].pheromone =st->cell8_2;
    	st1->map[7][2].pheromone =st->cell8_3;
    	st1->map[7][3].pheromone =st->cell8_4;
    	st1->map[7][4].pheromone =st->cell8_5;
    	st1->map[7][5].pheromone =st->cell8_6;
    	st1->map[7][6].pheromone =st->cell8_7;
		st1->map[7][7].pheromone =st->cell8_8;
		st1->map[7][8].pheromone =st->cell8_9;
		st1->map[7][9].pheromone =st->cell8_10;
		st1->map[8][0].pheromone =st->cell9_1;
    	st1->map[8][1].pheromone =st->cell9_2;
    	st1->map[8][2].pheromone =st->cell9_3;
    	st1->map[8][3].pheromone =st->cell9_4;
    	st1->map[8][4].pheromone =st->cell9_5;
    	st1->map[8][5].pheromone =st->cell9_6;
    	st1->map[8][6].pheromone =st->cell9_7;
		st1->map[8][7].pheromone =st->cell9_8;
		st1->map[8][8].pheromone =st->cell9_9;
		st1->map[8][9].pheromone =st->cell9_10;
		st1->map[9][0].pheromone =st->cell10_1;
    	st1->map[9][1].pheromone =st->cell10_2;
    	st1->map[9][2].pheromone =st->cell10_3;
    	st1->map[9][3].pheromone =st->cell10_4;
    	st1->map[9][4].pheromone =st->cell10_5;
    	st1->map[9][5].pheromone =st->cell10_6;
    	st1->map[9][6].pheromone =st->cell10_7;
		st1->map[9][7].pheromone =st->cell10_8;
		st1->map[9][8].pheromone =st->cell10_9;
		st1->map[9][9].pheromone =st->cell10_10;
		st1->x[0] = st->x_1;
		st1->x[1] = st->x_2;
		st1->x[2] = st->x_3;
		st1->x[3] = st->x_4;
		st1->y[0] = st->y_1;
		st1->y[1] = st->y_2;
		st1->y[2] = st->y_3;
		st1->y[3] = st->y_4;

		//General initialization
		for(i = 0; i < MAP_SIZE; ++i) {
			for(j = 0; j < MAP_SIZE; ++j) {
				st1->map[i][j].contributions = 0;
				st1->map[i][j].lastVisitTime = 0;
				st1->map[i][j].robot = FALSE;
				st1->map[i][j].obstacle = FALSE;
				st1->map[i][j].x = i + 1;
				st1->map[i][j].y = j + 1;
			}
		}

		//Set occupied currentCells
		for(i = 0; i < ROBOTS; ++i) {
			occupiedCells[i] = findCellFromCoordinates(st1, st1->x[i], st1->y[i]);
			if(isInit == TRUE) {
				updateContribution(st1, occupiedCells[i]);
				updatePheromone(st, st1, occupiedCells[i]);
				if(i == ROBOTS - 1) {
					isInit = FALSE;
				}
			}
			occupiedCells[i]->robot = TRUE;
		}

		//Set obstacles
		st1->map[2][0].obstacle = TRUE;
		st1->map[3][0].obstacle = TRUE;
		st1->map[1][8].obstacle = TRUE;
		st1->map[4][3].obstacle = TRUE;
		st1->map[4][4].obstacle = TRUE;
		st1->map[6][7].obstacle = TRUE;
		st1->map[7][7].obstacle = TRUE;
		st1->map[7][8].obstacle = TRUE;
}

/**
 * Translation function from State1 to State
 */
void state12State(State* st, State1* st1) {

		st->cell1_1 = st1->map[0][0].pheromone;
		st->cell1_2 = st1->map[0][1].pheromone;
		st->cell1_3 = st1->map[0][2].pheromone;
		st->cell1_4 = st1->map[0][3].pheromone;
		st->cell1_5 = st1->map[0][4].pheromone;
		st->cell1_6 = st1->map[0][5].pheromone;
		st->cell1_7 = st1->map[0][6].pheromone;
		st->cell1_8 = st1->map[0][7].pheromone;
		st->cell1_9 = st1->map[0][8].pheromone;
		st->cell1_10 = st1->map[0][9].pheromone;
		st->cell2_1 = st1->map[1][0].pheromone;
		st->cell2_2 = st1->map[1][1].pheromone;
		st->cell2_3 = st1->map[1][2].pheromone;
		st->cell2_4 = st1->map[1][3].pheromone;
		st->cell2_5 = st1->map[1][4].pheromone;
		st->cell2_6 = st1->map[1][5].pheromone;
		st->cell2_7 = st1->map[1][6].pheromone;
		st->cell2_8 = st1->map[1][7].pheromone;
		st->cell2_9 = st1->map[1][8].pheromone;
		st->cell2_10 = st1->map[1][9].pheromone;
		st->cell3_1 = st1->map[2][0].pheromone;
		st->cell3_2 = st1->map[2][1].pheromone;
		st->cell3_3 = st1->map[2][2].pheromone;
		st->cell3_4 = st1->map[2][3].pheromone;
		st->cell3_5 = st1->map[2][4].pheromone;
		st->cell3_6 = st1->map[2][5].pheromone;
		st->cell3_7 = st1->map[2][6].pheromone;
		st->cell3_8 = st1->map[2][7].pheromone;
		st->cell3_9 = st1->map[2][8].pheromone;
		st->cell3_10 = st1->map[2][9].pheromone;
		st->cell4_1 = st1->map[3][0].pheromone;
		st->cell4_2 = st1->map[3][1].pheromone;
		st->cell4_3 = st1->map[3][2].pheromone;
		st->cell4_4 = st1->map[3][3].pheromone;
		st->cell4_5 = st1->map[3][4].pheromone;
		st->cell4_6 = st1->map[3][5].pheromone;
		st->cell4_7 = st1->map[3][6].pheromone;
		st->cell4_8 = st1->map[3][7].pheromone;
		st->cell4_9 = st1->map[3][8].pheromone;
		st->cell4_10 = st1->map[3][9].pheromone;
		st->cell5_1 = st1->map[4][0].pheromone;
		st->cell5_2 = st1->map[4][1].pheromone;
		st->cell5_3 = st1->map[4][2].pheromone;
		st->cell5_4 = st1->map[4][3].pheromone;
		st->cell5_5 = st1->map[4][4].pheromone;
		st->cell5_6 = st1->map[4][5].pheromone;
		st->cell5_7 = st1->map[4][6].pheromone;
		st->cell5_8 = st1->map[4][7].pheromone;
		st->cell5_9 = st1->map[4][8].pheromone;
		st->cell5_10 = st1->map[4][9].pheromone;
		st->cell6_1 = st1->map[5][0].pheromone;
		st->cell6_2 = st1->map[5][1].pheromone;
		st->cell6_3 = st1->map[5][2].pheromone;
		st->cell6_4 = st1->map[5][3].pheromone;
		st->cell6_5 = st1->map[5][4].pheromone;
		st->cell6_6 = st1->map[5][5].pheromone;
		st->cell6_7 = st1->map[5][6].pheromone;
		st->cell6_8 = st1->map[5][7].pheromone;
		st->cell6_9 = st1->map[5][8].pheromone;
		st->cell6_10 = st1->map[5][9].pheromone;
		st->cell7_1 = st1->map[6][0].pheromone;
		st->cell7_2 = st1->map[6][1].pheromone;
		st->cell7_3 = st1->map[6][2].pheromone;
		st->cell7_4 = st1->map[6][3].pheromone;
		st->cell7_5 = st1->map[6][4].pheromone;
		st->cell7_6 = st1->map[6][5].pheromone;
		st->cell7_7 = st1->map[6][6].pheromone;
		st->cell7_8 = st1->map[6][7].pheromone;
		st->cell7_9 = st1->map[6][8].pheromone;
		st->cell7_10 = st1->map[6][9].pheromone;
		st->cell8_1 = st1->map[7][0].pheromone;
		st->cell8_2 = st1->map[7][1].pheromone;
		st->cell8_3 = st1->map[7][2].pheromone;
		st->cell8_4 = st1->map[7][3].pheromone;
		st->cell8_5 = st1->map[7][4].pheromone;
		st->cell8_6 = st1->map[7][5].pheromone;
		st->cell8_7 = st1->map[7][6].pheromone;
		st->cell8_8 = st1->map[7][7].pheromone;
		st->cell8_9 = st1->map[7][8].pheromone;
		st->cell8_10 = st1->map[7][9].pheromone;
		st->cell9_1 = st1->map[8][0].pheromone;
		st->cell9_2 = st1->map[8][1].pheromone;
		st->cell9_3 = st1->map[8][2].pheromone;
		st->cell9_4 = st1->map[8][3].pheromone;
		st->cell9_5 = st1->map[8][4].pheromone;
		st->cell9_6 = st1->map[8][5].pheromone;
		st->cell9_7 = st1->map[8][6].pheromone;
		st->cell9_8 = st1->map[8][7].pheromone;
		st->cell9_9 = st1->map[8][8].pheromone;
		st->cell9_10 = st1->map[8][9].pheromone;
		st->cell10_1 = st1->map[9][0].pheromone;
		st->cell10_2 = st1->map[9][1].pheromone;
		st->cell10_3 = st1->map[9][2].pheromone;
		st->cell10_4 = st1->map[9][3].pheromone;
		st->cell10_5 = st1->map[9][4].pheromone;
		st->cell10_6 = st1->map[9][5].pheromone;
		st->cell10_7 = st1->map[9][6].pheromone;
		st->cell10_8 = st1->map[9][7].pheromone;
		st->cell10_9 = st1->map[9][8].pheromone;
		st->cell10_10 = st1->map[9][9].pheromone;
		st->xDesired1 = st1->x[0];
		st->xDesired2 = st1->x[1];
		st->xDesired3 = st1->x[2];
		st->xDesired4 = st1->x[3];
		st->yDesired1 = st1->y[0];
		st->yDesired2 = st1->y[1];
		st->yDesired3 = st1->y[2];
		st->yDesired4 = st1->y[3];
}

//Print something to test

void printTest(State* st, State1* st1) {

		int i, j;

		//Stampo i valori dei feromoni nella matrice
		for(i = 0; i < MAP_SIZE; ++i) {
			for(j = 0; j < MAP_SIZE; ++j) {
				if(isOccupied(&st1->map[i][j])) {
					printf("Cella %i-%i: %.3g. Occupata.\n", i + 1, j + 1, st1->map[i][j].pheromone);
				}
				else
				if(hasObstacle(&st1->map[i][j]))
					printf("Cella %i-%i: %.3g. Ostacolo.\n", i + 1, j + 1, st1->map[i][j].pheromone);
				else
					printf("Cella %i-%i: %.3g.\n", i + 1, j + 1, st1->map[i][j].pheromone);
			}
		}

		//Stampo le posizioni dei robot
		for(i = 0; i < ROBOTS; ++i)
			printf("Coordinate del robot %d alla step %d: (%g-%g)\n", i+1, st->stepCount, st1->x[i], st1->y[i]);
}

/**
 * Sais if there is an obstacle in the cell
 */
bool hasObstacle(Cell* c) {
		return c->obstacle;
}

/**
 * Sais if there is another robot in the cell
 */
bool isOccupied(Cell* c) {
		return c->robot;
}

/**
 * Euclidean distance
 */
float64_t euclideanDistance(float64_t x1, float64_t x2, float64_t y1, float64_t y2) {
		return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

/**
 * Return the cell where the robot is located
 */
Cell* findCellFromCoordinates(State1* st1, int32_t x, int32_t y) {

		int32_t i, j;

		for(i = 0; i < MAP_SIZE; ++i) {
			for(j = 0; j < MAP_SIZE; ++j) {
				if((x >= i) && (x < i + 1) && (y >= j) && (y < j + 1))
					return &st1->map[i][j];
			}
		}
		return 0;
}

/**
 * Find neighbourhood
 */
float64_t findNeighbourhood(State1* st1, Cell* c) {

		float64_t sum = 0.0f;
		int32_t i, j;

		for(i = c->x - 1; i <= c->x + 1; ++i) {
			for(j = c->y - 1; j <= c->y + 1; ++j) {
				// Only the cells different from current and inside the map are considered
				if(i > 0 && j > 0 && i < MAP_SIZE + 1 && j < MAP_SIZE + 1 && !(i == c->x && j == c->y)) {
					// Denominator of the formula to compute the probability
					sum += pow(st1->map[i-1][j-1].pheromone, PHI) * pow(ETA, LAMBDA);
					// Number of neighbours in the neighbourhood
					if(!isOccupied(&st1->map[i-1][j-1]) && !hasObstacle(&st1->map[i-1][j-1]))
						++st1->nSize;
				}
			}
		}
		// Allocation of the structure containing pointers to neighbours
		st1->neighbourhood = (Cell*)malloc(sizeof(Cell)*(st1->nSize));
		st1->nSize = 0;
		return sum;
}

/**
 * Find best neighbour
 */
Cell* findBestNeighbour(State1* st1, Cell* c, float64_t sum) {

		Cell* bests[8];
		Cell* bestChosen;
		float64_t pBest;
		float64_t pCurrent;
		int32_t i, j, random, nBest = 0;

		// If sum is zero the algorithm stops
		if(sum == 0) {
			printf("Errore! Divisione per zero!\n");
				return 0;
		}
		else {
			pBest = pCurrent = 1;
			for(i = c->x - 1; i <= c->x + 1; ++i) {
				for(j = c->y - 1; j <= c->y + 1; ++j) {
					if(i > 0 && j > 0 && i < MAP_SIZE + 1 && j < MAP_SIZE + 1 && (i != c->x || j != c->y)) {
						// Probability is computed
						pCurrent = (pow(st1->map[i-1][j-1].pheromone, PHI) * pow(ETA, LAMBDA)) / sum;
						// If is smaller the previous, the best neighbour is updated
						if(pCurrent <= pBest) {
							pBest = pCurrent;
							bests[nBest] = &st1->map[i-1][j-1];
							++nBest;
						}
						// Each neighbour not occupied is added to neighbourhood structure
						if(!isOccupied(&st1->map[i-1][j-1]) && !hasObstacle(&st1->map[i-1][j-1]))
							st1->neighbourhood[(st1->nSize)++] = st1->map[i-1][j-1];
					}
				}
			}
			random = rand() / (RAND_MAX / nBest);
			bestChosen = bests[random]; 

			return bestChosen;
		}
}

/**
 * Compute pheromone disseminated (eD is the euclideanDistance between the cell where the robot is and the cell
 * where the robot is disseminating the pheromone)
 */
float64_t pheromoneDisseminated(float64_t eD) {
		return MAX_PH*exp(-eD/A1)+EPSLON/A2;
}

/**
 * Update the contribution attribute to each cell where robot are moved and to each cell of the neighbourhoods
 */
void updateContribution(State1* st1, Cell* c) {

		int32_t i, j;
		float64_t eD;

		// All the contributions that a robot give to the new pheromone value in some cells, are computed
		for(i = c->x - 1; i <= c->x + 1; ++i) {
			for(j = c->y - 1; j <= c->y + 1; ++j) {
				if(i > 0 && j > 0 && i < MAP_SIZE + 1 && j < MAP_SIZE + 1) {
					// The formula needs to know the euclidean distance among the current cell and that of the neighbour
					eD = euclideanDistance((c->x)-0.5, (st1->map[i-1][j-1].x)-0.5, (c->y)-0.5, (st1->map[i-1][j-1].y)-0.5);
					st1->map[i-1][j-1].contributions += pheromoneDisseminated(eD);
				}
			}
		}
}

/**
 * Find the rate of evaporation
 */
float64_t evaporationRate(State* st, Cell* c) {
		return ERTU_PERC*(st->stepCount - c->lastVisitTime);
}

void updatePheromone(State* st, State1* st1, Cell* c) {

		int32_t i, j;

		for(i = c->x - 1; i <= c->x + 1; ++i) {
			for(j = c->y - 1; j <= c->y + 1; ++j) {
				if(i > 0 && j > 0 && i < MAP_SIZE + 1 && j < MAP_SIZE + 1) {
					//printf(" arpCella %i-%i PRIMA: %g\n", i, j, st1->map[i-1][j-1].pheromone);
					// The new value of the pheromone is obtained subtracting to the current value, the part evaporated and summing the contributions
					// computed previously
					//printf("%g, %g, %g\n", st1->map[i-1][j-1].pheromone, evaporationRate(st, &st1->map[i-1][j-1])*st1->map[i-1][j-1].pheromone, st1->map[i-1][j-1].contributions);
					st1->map[i-1][j-1].pheromone = st1->map[i-1][j-1].pheromone - (evaporationRate(st, &st1->map[i-1][j-1])*st1->map[i-1][j-1].pheromone);
					// If the quantity evaporated is more than the current value, zero is considered
					if(st1->map[i-1][j-1].pheromone < 0)
						st1->map[i-1][j-1].pheromone = 0;
					st1->map[i-1][j-1].pheromone += st1->map[i-1][j-1].contributions;
					st1->map[i-1][j-1].lastVisitTime = st->stepCount;
					//printf(" arpCella %i-%i DOPO: %g\n", i, j, st1->map[i-1][j-1].pheromone);
				}
			}
		}
}

/**
 * Move the robot
 */
void move(State1* st1, Cell* curr, Cell* best, float64_t* x, float64_t* y) {

		int32_t random;

		// The best neighbour should be an obstacle or to be occupied by another robot. In both cases we choise another neighbour at random
		if((isOccupied(best) || hasObstacle(best)) && st1->nSize != 0) {
			random = rand() / (RAND_MAX / st1->nSize);
			*x = (st1->neighbourhood[random].x) - 0.5;
			*y = (st1->neighbourhood[random].y) - 0.5;
			curr->robot = FALSE;
			st1->neighbourhood[random].robot = TRUE;
		}
		// If the best neighbour is occupied and there aren't others free, the robot stops for one step
		else
		if((isOccupied(best) || hasObstacle(best)) && st1->nSize == 0) {
			*x = *x;
			*y = *y;
		}
		else {
			*x = (best->x) - 0.5;
			*y = (best->y) - 0.5;
			curr->robot = FALSE;
			best->robot = TRUE;
		}
		free(st1->neighbourhood);
		st1->nSize = 0;
}

/**
 * uniform random number between 0 and 1
 */
float64_t unifRand() {
    return rand() / (float64_t)RAND_MAX;
}

State* tick(State* st) {

		Cell* currentCells[ROBOTS];
		Cell* bestNeighbours[ROBOTS];
		float64_t sum;
		int32_t i;

		if(st->onDestination1 == 1 && st->onDestination2 == 1 && st->onDestination3 == 1 && st->onDestination4 == 1 && st->flag == 1) {
			//Translation from State to State1
			state2State1(st, &st1);

			for(i = 0; i < ROBOTS; ++i) {
				//Find the cell where robot is located
				currentCells[i] = findCellFromCoordinates(&st1, st1.x[i], st1.y[i]);
				//Find neighbourhood
				sum = findNeighbourhood(&st1, currentCells[i]);
				//Find the best neighbour
				bestNeighbours[i] = findBestNeighbour(&st1, currentCells[i], sum);
				//Move (best neighbour will be chosen if is not occupied or random chose among those in neighbourhood)
				move(&st1, currentCells[i], bestNeighbours[i], &st1.x[i], &st1.y[i]);
			}

			//Update of the pheromone contributions given by all the robots
			for(i = 0; i < ROBOTS; ++i)
				updateContribution(&st1, bestNeighbours[i]);

			//Update of the pheromone contributions given by all the robots
			for(i = 0; i < ROBOTS; ++i)
				updatePheromone(st, &st1, bestNeighbours[i]);

			//Increasing of the discrete simulation time
			++st->stepCount;
			
			//Translation from State1 to State
			state12State(st, &st1);
			
			printTest(st, &st1);
			st->flag = 1 - st->flag;
		}
		else
		if(st->onDestination1 == 1 && st->onDestination2 == 1 && st->onDestination3 == 1 && st->onDestination4 == 1 && st->flag == 0) {
			++st->stepCount;
			st->flag = 1 - st->flag;
		}
		else {
			//Increasing of the discrete simulation time
			++st->stepCount;
		}
		
		return st;
}




