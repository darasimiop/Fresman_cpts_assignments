#pragma once
/*
* =====================================================================================
*
*       Filename:  simulation.h
*
*    Description:  This contains function declarations for the program.
*
*        Version:  1.0
*        Created:  3/6/2023 6:37:00 PM
*       Revision:  none
*       Compiler:  c
*
*
*         Author:  Darasimi Ogunbinu-Peters, d.ogunbinu-peters@wsu.edu
*   Organization:  Washington State University
*
* =====================================================================================
*/



#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#pragma once

/*
The general program flow is as follows:

Generate a random number between 1 – 5 and 3 – 8 for express and normal lanes, respectively.
This represents the arrival time of the first customer into each lane. Set the variable for total time elapsed to 0.
As customers arrive into each line, randomly generate a service time for each. Start processing the customers in the lanes based on service time. Randomly generate the arrival time of the next customer into each line. Elapsed time should be updated by one unit.
As each minute elapses, a new customer may arrive and/or another customer may be done checking out. Display the appropriate messages as described above.
For every 10 minutes, print out the entire queue for each line
Repeat steps 2 through 4 for n minutes of simulation.


Hints: since this is a simulation one minute is really one unit of time. Thus, the incrementing of an integer variable could represent one minute of time elapsing.
*/

#include "Queue.h"

void ExpressLane(Queue expressQueue);
void NormalLane(Queue normalQueue);

void runExpress_LaneSimulation();
void runNormal_LaneSimulation();

void timeDelay(int Seconds);
void extraSpace(int lines);

void displayMenu(void);
void continueMenu(void);
void clearScreen(void);
int randomGenerator();
















