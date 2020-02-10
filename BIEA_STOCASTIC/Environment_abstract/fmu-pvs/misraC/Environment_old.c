#include "Environment_old.h"

/**
 * init function
 */
void init(State* st) {
	
		st->nRobots = 4;
		st->a1 = 0.5f; 
		st->a2 = 0.5f; 
		st->ertu_perc = 0.002f; 
		st->eta = 0.9f; 
		st->mapSize = 10; 
		st->max_ph = 2; 
		st->s_range = 1; 
		st->phi = 1;
		st->step_size = 1.0f;
		st->lambda = 1;
		st->stepCount = 0;
		st->port = 8087;
		st->dummy = 0;
		st->nObstacles = 10;
		st->ox_1 = 3;
		st->ox_2 = 4;
		st->ox_3 = 2;
		st->ox_4 = 5;
		st->ox_5 = 5;
		st->ox_6 = 7;
		st->ox_7 = 8;
		st->ox_8 = 8;
		st->ox_9 = 0;
		st->ox_10 = 0;
		st->oy_1 = 1;	
		st->oy_2 = 1;
		st->oy_3 = 9;
		st->oy_4 = 4;
		st->oy_5 = 5;
		st->oy_6 = 8;
		st->oy_7 = 8;
		st->oy_8 = 9;
		st->oy_9 = 0;
		st->oy_10 = 0;	
		st->x_1 = 0.5f;
		st->x_2 = 9.5f;
		st->x_3 = 9.5f;
		st->x_4 = 0.5f;
		st->y_1 = 0.5f;
		st->y_2 = 0.5f;
		st->y_3 = 9.5f;
		st->y_4 = 9.5;
	    st->eP = 0.0f;
	    st->sTime = 0.0f;
		
		epslon = unifRand();
		isInit1 = TRUE;
		isInit2 = TRUE;
		stop = FALSE;
}

/**
 * set the environment
 */ 
void setEnvironment(State* st) {
	int32_t i, j;
	nCells = st->mapSize * st->mapSize;
	vCells = 0;
	
	map = (Cell**)malloc(st->mapSize*sizeof(Cell*));
	occupiedCells = (Cell**)malloc(st->nRobots*sizeof(Cell*));
	for(i = 0; i < st->mapSize; ++i)
		map[i] = (Cell*)malloc(st->mapSize*sizeof(Cell));
	
	x = (float64_t*)malloc(4*sizeof(float64_t));
	y = (float64_t*)malloc(4*sizeof(float64_t));
	ox = (int32_t*)malloc(10*sizeof(int32_t));
	oy = (int32_t*)malloc(10*sizeof(int32_t));
	
	positions2Array(st);
	
	//General initialization
	for(i = 0; i < st->mapSize; ++i) {
		for(j = 0; j < st->mapSize; ++j) {
			map[i][j].pheromone = 0;
			map[i][j].visited = 0;
			map[i][j].robot = FALSE;
			map[i][j].obstacle = FALSE;
			map[i][j].x = i + 1;
			map[i][j].y = j + 1;
		}
	}
	
	//Set occupied cells
	for(i = 0; i < st->nRobots; ++i) {
		occupiedCells[i] = findCellFromCoordinates(map, st, x[i], y[i]);
		updateContribution(map, st, occupiedCells[i]);
		occupiedCells[i]->robot = TRUE;
		occupiedCells[i]->visited = TRUE;
	}

	//Set obstacles
	for(i = 0; i < st->nObstacles; ++i) {
		if((ox[i] > 0) && (oy[i] > 0) && (ox[i] <= st->mapSize) && (oy[i] <= st->mapSize)) {
			map[ox[i] - 1][oy[i] - 1].obstacle = TRUE;
			--nCells;
		}
	}
	
	isInit2 = FALSE;	
	
	//Percentuale di esplorazione
	st->eP = ((double)st->nRobots / nCells) * 100;
	vCells = 0;
	//Exploration time
	st->sTime = st->stepCount * st->step_size;
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
 * Function to obtain an array with all the robot position 
 */
void positions2Array(State* st) {
	
	x[0] = st->x_1;
	x[1] = st->x_2;
	x[2] = st->x_3;
	x[3] = st->x_4;
	y[0] = st->y_1;
	y[1] = st->y_2;
	y[2] = st->y_3;
	y[3] = st->y_4;
	if(isInit1 == TRUE) {
		ox[0] = st->ox_1;
		ox[1] = st->ox_2;
		ox[2] = st->ox_3;
		ox[3] = st->ox_4;
		ox[4] = st->ox_5;
		ox[5] = st->ox_6;
		ox[6] = st->ox_7;
		ox[7] = st->ox_8;
		ox[8] = st->ox_9;
		ox[9] = st->ox_10;
		oy[0] = st->oy_1;
		oy[1] = st->oy_2;
		oy[2] = st->oy_3;
		oy[3] = st->oy_4;
		oy[4] = st->oy_5;
		oy[5] = st->oy_6;
		oy[6] = st->oy_7;
		oy[7] = st->oy_8;
		oy[8] = st->oy_9;
		oy[9] = st->oy_10;
		isInit1 = FALSE;
	}
}

/**
 * Function to store the values in the arrays to the desired position variables 
 */
void array2Desired(State* st) {
	
	st->x_1 = x[0];
	st->x_2 = x[1];
	st->x_3 = x[2];
	st->x_4 = x[3];
	st->y_1 = y[0];
	st->y_2 = y[1];
	st->y_3 = y[2];
	st->y_4 = y[3];
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
Cell* findCellFromCoordinates(Cell** map, State* st, float64_t x, float64_t y) {

		int32_t i, j;

		for(i = 0; i < st->mapSize; ++i) {
			for(j = 0; j < st->mapSize; ++j) {
				if((x >= i) && (x < i + 1) && (y >= j) && (y < j + 1))
					return &map[i][j];
			}
		}
		return 0;
}

/**
 * Find the denominator of the probability formula
 */
float64_t findSum(Cell** map, State* st, Cell* c) {

		float64_t sum = 0.0f;
		int32_t i, j;

		for(i = (c->x - st->s_range); i <= (c->x + st->s_range); ++i) {
			for(j = (c->y - st->s_range); j <= (c->y + st->s_range); ++j) {
				// Only the cells different from current and inside the map are considered
				if(i > 0 && j > 0 && i < st->mapSize + 1 && j < st->mapSize + 1 && !(i == c->x && j == c->y)) {
					// Denominator of the formula to compute the probability
					sum += pow(map[i-1][j-1].pheromone, st->phi) * pow(st->eta, st->lambda);
					// Number of neighbours in the neighbourhood
					if(!isOccupied(&map[i-1][j-1]) && !hasObstacle(&map[i-1][j-1]))
						++nSize;
				}
			}
		}
		// Allocation of the structure containing pointers to neighbours
		neighbourhood = (Cell*)malloc(sizeof(Cell)*nSize);
		nSize = 0;
		return sum;
}

/**
 * Find best neighbour
 */
Cell* findBestNeighbour(Cell** map, State* st, Cell* c, float64_t sum) {

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
			pBest = (pow(1000, st->phi) * pow(st->eta, st->lambda)) / sum;
			for(i = c->x - st->s_range; i <= c->x + st->s_range; ++i) {
				for(j = c->y - st->s_range; j <= c->y + st->s_range; ++j) {
					if(i > 0 && j > 0 && i < st->mapSize + 1 && j < st->mapSize + 1 && (i != c->x || j != c->y)) {
						// Probability is computed
						pCurrent = (pow(map[i-1][j-1].pheromone, st->phi) * pow(st->eta, st->lambda)) / sum;
						// If is smaller the previous, the best neighbour is updated
						if(pCurrent <= pBest) {
							pBest = pCurrent;
							bests[nBest] = &map[i-1][j-1];
							++nBest;
						}
						// Each neighbour not occupied is added to neighbourhood structure
						if(!isOccupied(&map[i-1][j-1]) && !hasObstacle(&map[i-1][j-1]))
							neighbourhood[nSize++] = map[i-1][j-1];
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
float64_t pheromoneDisseminated(State* st, float64_t eD) {
		return st->max_ph*exp(-eD/st->a1)+epslon/st->a2;
}

/**
 * Update the contribution attribute to each cell where robot are moved and to each cell of the neighbourhoods
 */
void updateContribution(Cell** map, State* st, Cell* c) {

		int32_t i, j;
		float64_t eD;

		// All the contributions that a robot give to the new pheromone value in some cells, are computed
		for(i = c->x - st->s_range; i <= c->x + st->s_range; ++i) {
			for(j = c->y - st->s_range; j <= c->y + st->s_range; ++j) {
				if(i > 0 && j > 0 && i < st->mapSize + 1 && j < st->mapSize + 1) {
					// The formula needs to know the euclidean distance among the current cell and that of the neighbour
					eD = euclideanDistance((c->x)-0.5, (map[i-1][j-1].x)-0.5, (c->y)-0.5, (map[i-1][j-1].y)-0.5);
					map[i-1][j-1].pheromone += pheromoneDisseminated(st, eD);
				}
			}
		}
}

/**
 * Update pheromone to each cell according to the evaporation law
 */
void updatePheromone(Cell** map, State* st) {
	
	int32_t i, j;
	
	//Evaporation
	for(i = 0; i < st->mapSize; ++i) {
		for(j = 0; j < st->mapSize; ++j) {
			map[i][j].pheromone -= st->ertu_perc * st->step_size * map[i][j].pheromone;
			if(map[i][j].pheromone < 0)
				map[i][j].pheromone = 0;
		}
	}
}

/**
 * Move the robot
 */
void move(Cell** map, State* st, Cell* curr, Cell* best, float64_t* x, float64_t* y) {

		int32_t random;

		// The best neighbour should be an obstacle or to be occupied by another robot. In both cases we choise another neighbour at random
		if((isOccupied(best) || hasObstacle(best)) && nSize != 0) {
			random = rand() / (RAND_MAX / nSize);
			best = &neighbourhood[random];
		}
		// If the best neighbour is occupied and there aren't others free, the robot stops for one step
		else
		if((isOccupied(best) || hasObstacle(best)) && nSize == 0) {
			best = curr;
		}
		
		*x = (best->x) - 0.5;
		*y = (best->y) - 0.5;
		curr->robot = FALSE;
		best->robot = TRUE;
		
		if(best->visited == FALSE) {
			best->visited = TRUE;
		}
		
		free(neighbourhood);
		nSize = 0;
}

/**
 * uniform random number between 0 and 1
 */
float64_t unifRand() {
    return rand() / (float64_t)RAND_MAX;
}

State* tick(State* st) {
	
		float64_t sum;
		int32_t i, j;
		
		if(isInit2 == TRUE)
			setEnvironment(st);
		
		Cell* currentCells[st->nRobots];
		Cell* bestNeighbours[st->nRobots];
		
		positions2Array(st);

		for(i = 0; i < st->nRobots; ++i) {
			//Find the cell where robot is located
			currentCells[i] = findCellFromCoordinates(map, st, x[i], y[i]);
			//Find the denominator of the probability formula
			sum = findSum(map, st, currentCells[i]);
			//Find the best neighbour
			bestNeighbours[i] = findBestNeighbour(map, st, currentCells[i], sum);
			//Move (best neighbour will be chosen if is not occupied or random chose among those in neighbourhood)
			move(map, st, currentCells[i], bestNeighbours[i], &x[i], &y[i]);
		}
		
		for(i = 0; i < st->mapSize; ++i) {
			for(j = 0; j < st->mapSize; ++j) {
				if(map[i][j].visited == TRUE)
					++vCells;
			}
		}

		array2Desired(st);
		
		//Evaporation
		updatePheromone(map, st);
			
		//Update of the pheromone contributions given by all the robots
		for(i = 0; i < st->nRobots; ++i)
			updateContribution(map, st, bestNeighbours[i]);

		//Increasing of the discrete simulation time
		++st->stepCount;
		
		if(stop == FALSE) {
			//Percentuale di esplorazione
			st->eP = ((double)vCells / nCells) * 100;
			vCells = 0;
			//Exploration time
			st->sTime = st->stepCount * st->step_size;
		}
		
		if(st->eP == 100)
			stop = TRUE;

		return st;
}
