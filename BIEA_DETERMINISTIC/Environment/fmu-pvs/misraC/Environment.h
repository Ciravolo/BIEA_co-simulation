#ifndef _misraC_Environment_
#define _misraC_Environment_

#include <assert.h>
#include <stdio.h>
#include <math.h>
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
    int32_t port; 
    int32_t stepCount; 
    int32_t s_range; 
    int32_t flag; 
    int32_t nObstacles;
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
    float64_t lx_1;
    float64_t lx_2;
    float64_t lx_3;
    float64_t lx_4;
    float64_t ly_1;
    float64_t ly_2;
    float64_t ly_3;
    float64_t ly_4;
    float64_t xDesired1; 
    float64_t xDesired2; 
    float64_t xDesired3; 
    float64_t xDesired4; 
    float64_t yDesired1; 
    float64_t yDesired2; 
    float64_t yDesired3; 
    float64_t yDesired4; 
    float64_t onDestinationOutput;
    float64_t onDestination1Input;
    float64_t onDestination2Input;
    float64_t onDestination3Input;
    float64_t onDestination4Input;
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
float64_t* xD;
float64_t* yD;
int32_t* oD;
int32_t* ox;
int32_t* oy;
int32_t nCells;
int32_t vCells;
Cell* neighbourhood;
int32_t nSize;
float64_t epslon;
bool isInit1, isInit2;
bool stop;

/**
 * init function
 */
void init(State* st);

/**
 * sais if there is an obstacle in the cell
 */
bool hasObstacle(Cell* c);

/**
 * sais if there is another robot in the cell
 */
bool isOccupied(Cell* c);

/**
 * Set the initial environment 
 */
void setEnvironment(State* st);

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
 * Find the denominator of the probability formula
 */
float64_t findSum(Cell** map, State* st, Cell* c);

/**
 * Find best neighbour
 */
Cell* findBestNeighbour(Cell** map, State* st, Cell* c, float64_t sum);

/**
 * Move the robot
 */
void move(Cell** map, State* st, Cell* curr, Cell* best, float64_t x, float64_t y, float64_t* xD, float64_t* yD);

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
 * Function to obtain an array with all the robots and obstacles positions 
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
