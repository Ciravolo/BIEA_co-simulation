#include "Environment.h"
/**
 * init function
 */
 
void init(State* st) { 
    
    int32_t i, j;
    
    st->nRobots = 4;
    st->a1 = 0.5; 
    st->a2 = 0.5; 
    st->ertu_perc = 0.0002; 
    st->eta = 0.9; 
    st->mapSize = 10; 
    st->max_ph = 2; 
    st->s_range = 1; 
    st->phi = 1;
    st->step_size = 0.1;
    st->lambda = 1;
    st->port = 8087;
    st->stepCount = 0;
    st->flag = 1;
    st->x_1 = 0.5f;
    st->x_2 = 9.5f;
    st->x_3 = 9.5f;
    st->x_4 = 0.5f;
    st->xDesired1 = 0.5f;
    st->xDesired2 = 9.5f;
    st->xDesired3 = 9.5f;
    st->xDesired4 = 0.5f;
    st->y_1 = 0.5f;
    st->y_2 = 0.5f;
    st->y_3 = 9.5f;
    st->y_4 = 9.5f;
    st->yDesired1 = 0.5f;
    st->yDesired2 = 0.5f;
    st->yDesired3 = 9.5f;
    st->yDesired4 = 9.5f;
    st->onDestination1Input = 0.0f;
    st->onDestination2Input = 0.0f;
    st->onDestination3Input = 0.0f;
    st->onDestination4Input = 0.0f;
    st->onDestinationOutput = 0.0f;
    
    map = (Cell**)malloc(st->mapSize*sizeof(Cell*));
    for(i = 0; i < st->mapSize; ++i)
		map[i] = (Cell*)malloc(st->mapSize*sizeof(Cell));
		
	x = (float64_t*)malloc(st->nRobots*sizeof(float64_t));
	y = (float64_t*)malloc(st->nRobots*sizeof(float64_t));
    
    epslon = unifRand();
	isInit = TRUE;
	Cell* occupiedCells[st->nRobots];
	
	//General initialization
	for(i = 0; i < st->mapSize; ++i) {
		for(j = 0; j < st->mapSize; ++j) {
			map[i][j].robot = FALSE;
			map[i][j].obstacle = FALSE;
			map[i][j].x = i + 1;
			map[i][j].y = j + 1;
		}
	}

	positions2Array(st);
	
	for(i = 0; i < st->nRobots; ++i) {
		occupiedCells[i] = findCellFromCoordinates(map, st, x[i], y[i]);
		updateContribution(map, st, occupiedCells[i]);
		occupiedCells[i]->robot = TRUE;
	}

	//Set obstacles
	map[2][0].obstacle = TRUE;
	map[3][0].obstacle = TRUE;
	map[1][8].obstacle = TRUE;
	map[4][3].obstacle = TRUE;
	map[4][4].obstacle = TRUE;
	map[6][7].obstacle = TRUE;
	map[7][7].obstacle = TRUE;
	map[7][8].obstacle = TRUE;
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
}

/**
 * Function to store the values in the arrays to the desired position variables 
 */
void array2Desired(State* st) {
	
	st->xDesired1 = x[0];
	st->xDesired2 = x[1];
	st->xDesired3 = x[2];
	st->xDesired4 = x[3];
	st->yDesired1 = y[0];
	st->yDesired2 = y[1];
	st->yDesired3 = y[2];
	st->yDesired4 = y[3];
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
 * Find neighbourhood
 */
float64_t findNeighbourhood(Cell** map, State* st, Cell* c) {

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
			pBest = pCurrent = 1;
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
			*x = (best->x) - 0.5;
			*y = (best->y) - 0.5;
			curr->robot = FALSE;
			neighbourhood[random].robot = TRUE;
		}
		// If the best neighbour is occupied and there aren't others free, the robot stops for one step
		else
		if((isOccupied(best) || hasObstacle(best)) && nSize == 0) {
			*x = *x;
			*y = *y;
		}
		else {
			*x = (best->x) - 0.5;
			*y = (best->y) - 0.5;
			curr->robot = FALSE;
			best->robot = TRUE;
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

		Cell* currentCells[st->nRobots];
		Cell* bestNeighbours[st->nRobots];
		float64_t sum;
		int32_t i;

		if(st->onDestination1Input == 1 && st->onDestination2Input == 1 && st->onDestination3Input == 1 && st->onDestination4Input == 1 && st->flag == 1) {

			positions2Array(st);
			
			for(i = 0; i < st->nRobots; ++i) {
				
				//Find the cell where robot is located
				currentCells[i] = findCellFromCoordinates(map, st, x[i], y[i]);
				//Find neighbourhood
				sum = findNeighbourhood(map, st, currentCells[i]);
				//Find the best neighbour
				bestNeighbours[i] = findBestNeighbour(map, st, currentCells[i], sum);
				//Move (best neighbour will be chosen if is not occupied or random chose among those in neighbourhood)
				move(map, st, currentCells[i], bestNeighbours[i], &x[i], &y[i]);
			}
			
			array2Desired(st);

			//Evaporation
			updatePheromone(map, st);
			
			//Update of the pheromone contributions given by all the robots
			for(i = 0; i < st->nRobots; ++i)
				updateContribution(map, st, bestNeighbours[i]);

			st->flag = 1 - st->flag;
			st->onDestinationOutput = 1;
		}
		else {
			//Evaporation
			updatePheromone(map, st);
			
			if(st->onDestination1Input == 1 && st->onDestination2Input == 1 && st->onDestination3Input == 1 && st->onDestination4Input == 1 && st->flag == 0) {
				st->flag = 1 - st->flag;
				st->onDestinationOutput = 0;
			}
		}
		
		return st;
}




