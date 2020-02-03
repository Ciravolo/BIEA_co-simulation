#ifndef _misraC_Environment_
#define _misraC_Environment_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "misraC_basic_types.h"

/**
 * state attributes
 */
typedef struct {
	
		int32_t nRobots;
		int32_t mapSize;
		int32_t nObstacles;
		int32_t port; 
		int32_t stepCount; 
		int32_t s_range;  
		int32_t dummy;
		float64_t a1; 
		float64_t a2; 
		float64_t ertu_perc; 
		float64_t eta;  
		float64_t max_ph; 
		float64_t phi;
		float64_t lambda;
		float64_t step_size;
		int32_t ox_1;
		int32_t ox_2;
		int32_t ox_3;
		int32_t ox_4;
		int32_t ox_5;
		int32_t ox_6;
		int32_t ox_7;
		int32_t ox_8;
		int32_t ox_9;
		int32_t ox_10;
		int32_t oy_1;
		int32_t oy_2;
		int32_t oy_3;
		int32_t oy_4;
		int32_t oy_5;
		int32_t oy_6;
		int32_t oy_7;
		int32_t oy_8;
		int32_t oy_9;
		int32_t oy_10;
		float64_t x_1;
		float64_t x_2;
		float64_t x_3;
		float64_t x_4;
		float64_t y_1;
		float64_t y_2;
		float64_t y_3;
		float64_t y_4;
		float64_t eP;
		float64_t sTime;
} State;

/**
 * matrix structure
 */
 typedef struct {
		 bool obstacle;
		 bool robot;
		 bool visited;
		 float64_t pheromone; //-- real matrix
		 float64_t contributions;
		 int x;
		 int y;
 } Cell;

/**
 * Global variables
 */
Cell** map; 
Cell** occupiedCells;
float64_t* x;
float64_t* y;
int32_t* ox;
int32_t* oy;
Cell* neighbourhood;
int32_t nSize;
int32_t nCells;
int32_t vCells;
float64_t epslon;
bool isInit1;
bool isInit2;
bool stop;

/**
 * init function
 */
void init(State* st);

/**
 * set the environment
 */ 
void setEnvironment(State* st);

/**
 * sais if there is an obstacle in the cell
 */
bool hasObstacle(Cell* c);

/**
 * sais if there is another robot in the cell
 */
bool isOccupied(Cell* c);

/**
 * Compute pheromone disseminated (eD is the euclideanDistance between the cell where the robot is and the cell
 * where the robot is disseminating the pheromone)
 */
float64_t pheromoneDisseminated(State* st, float64_t eD);

/**
 * Euclidean distance
 */
float64_t euclideanDistance(float64_t x1, float64_t x2, float64_t y1, float64_t y2);

/**
 * Return the cell where the robot is located
 */
Cell* findCellFromCoordinates(Cell** map, State* st, float64_t x, float64_t y);

/**
 * Find best neighbour
 */
float64_t findNeighbourhood(Cell** map, State* st, Cell* c);

/**
 * Find best neighbour
 */
Cell* findBestNeighbour(Cell** map, State* st, Cell* c, float64_t sum);

/**
 * Move the robot
 */
void move(Cell** map, State* st, Cell* curr, Cell* best, float64_t* x, float64_t* y);

/**
 * Update the contribution attribute to each cell where robot are moved and to each cell of the neighbourhoods
 */
void updateContribution(Cell** map, State* st, Cell* c);

/**
 * Update pheromone to each cell according to the evaporation law
 */
void updatePheromone(Cell** map, State* st);

/**
 * Uniform random number between 0 and 1
 */
float64_t unifRand();

/**
 * Function to obtain an array with all the robot position 
 */
void positions2Array(State* st);

/**
 * Function to store the values in the arrays to the desired position variables 
 */
void array2Desired(State* st);

/**
 * tick function 
 */
State* tick(State* st);

#endif
