#ifndef FITBIT_H // this is the start of guard code
#define FITBIT_H
#define MAXROWS 1444
#define EDITEDROWS 1442
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // we'll need access to standard I/O operations, including for files
#include <string.h> // we'll need to be able to process strings. we'll focus a lot on strtok () in this example
#include <stdlib.h> // atoi ()
typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;


int fillData(FILE* infile, FitbitData* fitbitArray);

int paitentChecker(FitbitData* fitbitArray);

int minutechecker(FitbitData* fitbitArray);

double calculateDistance(FitbitData* fitbitArray);

double calculateCalories(FitbitData* fitbitArray);

unsigned int calculateFloors(FitbitData* fitbitArray);

int calculateSteps(FitbitData* fitbitArray);

unsigned int calculateHeartrate(FitbitData* fitbitArray);

unsigned int calculatemaxStepsInAMinute(FitbitData* fitbitArray);

unsigned int calculateconsecutivePoorSleepCounter(FitbitData* fitbitArray);

void printStruct(FitbitData* fitbitArray);

void printSructToFile(FILE* outfile, FitbitData* fitbitArray);

#endif 