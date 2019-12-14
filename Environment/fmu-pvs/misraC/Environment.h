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
 * operating modes
 */
typedef enum { X1 } Mode;

/**
 * state attributes
 */
typedef struct { 
    Mode mode;
    Mode previous_mode;
    
    int32_t nRobots;
    int32_t mapSize;
    int32_t port; 
    int32_t stepCount; 
    int32_t s_range; 
    int32_t flag; 
    float64_t a1; 
    float64_t a2; 
    float64_t ertu_perc; 
    float64_t eta;  
    float64_t max_ph; 
    float64_t phi;
    float64_t lambda;
    float64_t step_size;
    float64_t x_1; 
    float64_t x_2; 
    float64_t x_3; 
    float64_t x_4;
    float64_t xDesired1; 
    float64_t xDesired2; 
    float64_t xDesired3; 
    float64_t xDesired4; 
    float64_t y_1; 
    float64_t y_2;
    float64_t y_3; 
    float64_t y_4; 
    float64_t yDesired1; 
    float64_t yDesired2; 
    float64_t yDesired3; 
    float64_t yDesired4; 
    float64_t onDestinationOutput;
    float64_t onDestination1Input;
    float64_t onDestination2Input;
    float64_t onDestination3Input;
    float64_t onDestination4Input;
} State;

/**
 * matrix structure
 */
 typedef struct {
		 bool obstacle;
		 bool robot;
		 float64_t pheromone; //-- real matrix
		 int x;
		 int y;
 } Cell;

/**
 * Global variables
 */
Cell** map; 
float64_t* x;
float64_t* y;
Cell* neighbourhood;
int32_t nSize;
float64_t epslon;
bool isInit;

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
