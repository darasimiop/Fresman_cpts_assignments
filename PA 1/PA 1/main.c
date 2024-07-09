#include "fitbit.h"

int main() {
	


	FILE* infile = fopen("FitbitData.csv", "r"),
	    *outfile = fopen("Results.csv", "w");
	FitbitData fitbitArray[MAXROWS]; //max rows = 1440 to represent max number of rows accepted by the array.

	int isdatafilled = fillData(infile, &fitbitArray);

	//paitent checker.
	int ispaiteintchecked = paitentChecker(&fitbitArray);
	// row modifier //checks for duplicate minute.
	int minuteVerifier = minutechecker(&fitbitArray);

	printStruct(&fitbitArray);


	//all calculations:
	double Calories = calculateCalories(&fitbitArray);//calories
	unsigned int floors = calculateFloors(&fitbitArray);//floors
	int steps = calculateSteps(&fitbitArray);//steps
	unsigned int heartRate = calculateHeartrate(&fitbitArray);//heartRate
	unsigned int maxStepsInAMinute = calculatemaxStepsInAMinute(&fitbitArray);//maxsteps
	unsigned int conseutivePoorSleepCounter = calculateconsecutivePoorSleepCounter(&fitbitArray);
	double Distance = calculateDistance(&fitbitArray);

	fprintf(outfile, "Header Line: Total Calories, Total Distance, Total FLoors, Total Steps, Avg Heartrate, Maz Steps, Sleep \n");
	fprintf(outfile, "        %lf KCAL, %lf Miles, %u Steps, %u BPM, %u Steps, %d Poor Consecutive Sleeping Periods \n", Calories, Distance, floors, steps, heartRate, maxStepsInAMinute, conseutivePoorSleepCounter);


	printSructToFile(outfile, &fitbitArray);

	fclose(infile);
	fclose(outfile);


	
	return 0;
}