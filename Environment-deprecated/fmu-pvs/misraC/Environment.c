#include "Environment.h"

/**
 * init function
 */
void init(State* st) {
			st->previous_mode = X1;
			st->mode = X1;
			st->stepCount = 0.0f;
    	st->cell1_1 = 0.0f;
    	st->cell1_2 = 0.0f;
    	st->cell1_3 = 0.0f;
    	st->cell1_4 = 0.0f;
    	st->cell1_5 = 0.0f;
    	st->cell1_6 = 0.0f;
    	st->cell1_7 = 0.0f;
    	st->cell1_8 = 0.0f;
    	st->cell1_9 = 0.0f;
			st->cell1_10 = 0.0f;
    	st->cell2_1 = 0.0f;
    	st->cell2_2 = 0.0f;
    	st->cell2_3 = 0.0f;
    	st->cell2_4 = 0.0f;
    	st->cell2_5 = 0.0f;
    	st->cell2_6 = 0.0f;
    	st->cell2_7 = 0.0f;
    	st->cell2_8 = 0.0f;
    	st->cell2_9 = 0.0f;
			st->cell2_10 = 0.0f;
    	st->cell3_1 = 0.0f;
    	st->cell3_2 = 0.0f;
    	st->cell3_3 = 0.0f;
    	st->cell3_4 = 0.0f;
    	st->cell3_5 = 0.0f;
    	st->cell3_6 = 0.0f;
    	st->cell3_7 = 0.0f;
    	st->cell3_8 = 0.0f;
    	st->cell3_9 = 0.0f;
			st->cell3_10 = 0.0f;
    	st->cell4_1 = 0.0f;
    	st->cell4_2 = 0.0f;
    	st->cell4_3 = 0.0f;
    	st->cell4_4 = 0.0f;
    	st->cell4_5 = 0.0f;
    	st->cell4_6 = 0.0f;
    	st->cell4_7 = 0.0f;
    	st->cell4_8 = 0.0f;
    	st->cell4_9 = 0.0f;
			st->cell4_10 = 0.0f;
    	st->cell5_1 = 0.0f;
    	st->cell5_2 = 0.0f;
    	st->cell5_3 = 0.0f;
    	st->cell5_4 = 0.0f;
    	st->cell5_5 = 0.0f;
    	st->cell5_6 = 0.0f;
    	st->cell5_7 = 0.0f;
    	st->cell5_8 = 0.0f;
    	st->cell5_9 = 0.0f;
			st->cell5_10 = 0.0f;
    	st->cell6_1 = 0.0f;
    	st->cell6_2 = 0.0f;
    	st->cell6_3 = 0.0f;
    	st->cell6_4 = 0.0f;
    	st->cell6_5 = 0.0f;
    	st->cell6_6 = 0.0f;
    	st->cell6_7 = 0.0f;
    	st->cell6_8 = 0.0f;
    	st->cell6_9 = 0.0f;
			st->cell6_10 = 0.0f;
    	st->cell7_1 = 0.0f;
    	st->cell7_2 = 0.0f;
    	st->cell7_3 = 0.0f;
    	st->cell7_4 = 0.0f;
    	st->cell7_5 = 0.0f;
    	st->cell7_6 = 0.0f;
    	st->cell7_7 = 0.0f;
    	st->cell7_8 = 0.0f;
    	st->cell7_9 = 0.0f;
			st->cell7_10 = 0.0f;
    	st->cell8_1 = 0.0f;
    	st->cell8_2 = 0.0f;
    	st->cell8_3 = 0.0f;
    	st->cell8_4 = 0.0f;
    	st->cell8_5 = 0.0f;
    	st->cell8_6 = 0.0f;
    	st->cell8_7 = 0.0f;
    	st->cell8_8 = 0.0f;
    	st->cell8_9 = 0.0f;
			st->cell8_10 = 0.0f;
    	st->cell9_1 = 0.0f;
    	st->cell9_2 = 0.0f;
    	st->cell9_3 = 0.0f;
    	st->cell9_4 = 0.0f;
    	st->cell9_5 = 0.0f;
    	st->cell9_6 = 0.0f;
    	st->cell9_7 = 0.0f;
    	st->cell9_8 = 0.0f;
    	st->cell9_9 = 0.0f;
			st->cell9_10 = 0.0f;
			st->cell10_1 = 0.0f;
    	st->cell10_2 = 0.0f;
    	st->cell10_3 = 0.0f;
    	st->cell10_4 = 0.0f;
    	st->cell10_5 = 0.0f;
    	st->cell10_6 = 0.0f;
    	st->cell10_7 = 0.0f;
    	st->cell10_8 = 0.0f;
    	st->cell10_9 = 0.0f;
			st->cell10_10 = 0.0f;
			st->x_1 = 0.0f;
	    st->x_2 = 0.0f;
	    st->x_3 = 0.0f;
	    st->x_4 = 0.0f;
	    st->y_1 = 0.0f;
	    st->y_2 = 0.0f;
	    st->y_3 = 0.0f;
	    st->y_4 = 0.0f;
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
 * print matrix
 */
void printTest(State1* st1) {

			int i, j;

			for(i = 0; i < 10; ++i) {
				for(j = 0; j < 10; ++j) {
					printf("Cella %i-%i: %f\n", i + 1, j + 1, st1->map[i][j].pheromone);
				}
			}

			printf("S_RANGE: %i\n", S_RANGE);
			printf("ERTU_PERC: %f\n", ERTU_PERC);
			printf("MAX_PH: %i\n", MAX_PH);
			printf("PHI: %i\n", PHI);
			printf("LAMBDA: %i\n", LAMBDA);
			printf("ETA: %f\n", ETA);
			printf("A1: %f\n", A1);
			printf("A2: %f\n", A2);
			printf("EPSLON: %f\n", EPSLON);
}

/**
 * sais if there is an obstacle in the cell
 */
bool hasObstacle(Cell* c) {
			return c->obstacle;
}

/**
 * sais if there is another robot in the cell
 */
bool isOccupied(Cell* c) {
			return c->robot;
}

/**
 * Euclidean distance
 */
float64_t euclideanDistance(int x1, int x2, int y1, int y2) {
			return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

/**
 * Compute pheromone disseminated (eD is the euclideanDistance between the cell where the robot is and the cell
 * where the robot is disseminating the pheromone)
 */
float64_t pheromoneDisseminated(float64_t eD) {
			return MAX_PH*exp(-eD/A1)-EPSLON/A2;
}

/**
 * Return the cell where the robot is located
 */
Cell* findCellFromCoordinates(State1* st1, int x, int y) {

			int i, j;

			for(i = 0; i < 10; ++i) {
				for(j = 0; j < 10; ++i) {
					if((x >= i) && (x < i + 1) && (y >= j) && (y < j + 1))
						return &st1->map[i][j];
				}
			}
			return 0;
}

/**
 * Find best neighbour
 */
Cell* findBestNeighbour(State1* st1, Cell* c) {

			Cell* best = &st1->map[c->x][c->y];
			float64_t pBest = 1, pCurrent = 0;
			float64_t sum = 0.0f;
			int i, j;

			for(i = c->x - 1; i <= c->x + 1; ++i) {
				for(j = c->y - 1; j <= c->y + 1; ++j) {
					if(i > 0 && j > 0 && i != c->x && j != c->y) {
						if(st1->map[i-1][j-1].pheromone < best->pheromone)
							sum += pow(st1->map[i-1][j-1].pheromone, PHI) * pow(ETA, LAMBDA);
					}
				}
			}

			for(i = c->x - 1; i <= c->x + 1; ++i) {
				for(j = c->y - 1; j <= c->y + 1; ++j) {
					if(i > 0 && j > 0 && i != c->x && j != c->y) {
						pCurrent = (pow(st1->map[i-1][j-1].pheromone, PHI) * pow(ETA, LAMBDA)) / sum;
						if(pCurrent < pBest && !isOccupied(&st1->map[i][j]) && !hasObstacle(&st1->map[i][j])) {
							pBest = pCurrent;
							best = &st1->map[i][j];
						}
					}
				}
			}

			return best;
}

/**
 * Find the rate of evaporation
 */
float64_t evaporationRate(State* st, Cell* c) {
			if(st->stepCount - c-> lastVisitTime < 0)
				return 0;
			else
				return ERTU_PERC*(st->stepCount - c-> lastVisitTime);
}

/**
 * Update the contribution attribute to each cell where robot are moved and to each cell of the neighbourhoods
 */
void updateContribution(State* st, State1* st1, Cell* c) {

			int i, j;
			float64_t eD;

			for(i = c->x - 1; i <= c->x + 1; ++i) {
				for(j = c->y - 1; j <= c->y + 1; ++j) {
					if(i > 0 && j > 0) {
						eD = euclideanDistance(c->x, c->y, st1->map[i-1][j-1].x, st1->map[i-1][j-1].y);
						st1->map[i-1][j-1].contributions += pheromoneDisseminated(eD);
						st1->map[i-1][j-1].lastVisitTime = st->stepCount;
					}
				}
			}
}

/**
 * translation function from State to State1
 */
void state2State1(State* st, State1* st1) {

			int i, j;

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

			for(i = 0; j < 10; ++i) {
				for(j = 0; j < 10; ++j) {
					st1->map[i][j].contributions = 0;
					st1->map[i][j].lastVisitTime = 0;
					st1->map[i][j].robot = FALSE;
					st1->map[i][j].obstacle = FALSE;
					st1->map[i][j].x = i + 1;
					st1->map[i][j].y = j + 1;
				}
			}
}

/**
 * translation function from State1 to State
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
}

/**
 * uniform random number between 0 and 1
 */
float64_t unifRand() {
    	return rand() / (float64_t)RAND_MAX;
}

State* tick(State* st) {

			Cell* currentCells[4];
			Cell* bestNeighbours[4];
			int i, j;

			//Translation from State to State1
			state2State1(st, &st1);

			//Find the cells where robots are located
			currentCells[0] = findCellFromCoordinates(&st1, st->x_1, st->y_1);
			currentCells[1] = findCellFromCoordinates(&st1, st->x_2, st->y_2);
			currentCells[2] = findCellFromCoordinates(&st1, st->x_3, st->y_3);
			currentCells[3] = findCellFromCoordinates(&st1, st->x_4, st->y_4);

			//Find the best neighbours to each robot which is not occupied by another one and where no obstacles //are located
			bestNeighbours[0] = findBestNeighbour(&st1, currentCells[0]);
			bestNeighbours[1] = findBestNeighbour(&st1, currentCells[1]);
			bestNeighbours[2] = findBestNeighbour(&st1, currentCells[2]);
			bestNeighbours[3] = findBestNeighbour(&st1, currentCells[3]);

			//Move robots
			st->x_1 = bestNeighbours[0]->x-0.5;
			st->y_1 = bestNeighbours[0]->y-0.5;
			st->x_2 = bestNeighbours[1]->x-0.5;
			st->y_2 = bestNeighbours[1]->y-0.5;
			st->x_3 = bestNeighbours[2]->x-0.5;
			st->y_3 = bestNeighbours[2]->y-0.5;
			st->x_4 = bestNeighbours[3]->x-0.5;
			st->y_4 = bestNeighbours[3]->y-0.5;

			//Update of the pheromone contributions given by all the robots
			for(i = 0; i < 4; ++i)
				updateContribution(st, &st1, bestNeighbours[i]);

			//Update of the pheromone attribute of all the cells in the MAX_PH
			for(i = 0; i < 10; ++i) {
				for(j = 0; j < 10; ++j) {
					st1.map[i][j].pheromone = st1.map[i][j].pheromone - evaporationRate(st, &st1.map[i][j]) + st1.map[i][j].contributions;
				}
			}

			//Increasing of the discrete simulation time
			++st->stepCount;

			state12State(st, &st1);
			//printTest(&st1);

	return st;
}
