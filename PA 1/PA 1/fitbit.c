#include "fitbit.h"


int fillData(FILE* infile, FitbitData* fitbitArray) {

	int success = 0;
	char line[100]; //this is our parsing tool(i.e what we are using to read the file line by line.)

	int row = 0;
	

	int charIndex = 0;
	char temp_char = '\0';
	char temp_char2 = '\0';
	char temp_char3 = '\0';


	if (infile != NULL) { //checks if the file was read successfully

		printf("Successfully opened the file.../n");

		fgets(line, 100, infile); //gets first row
		fgets(line, 100, infile); //gets second row

		while (row < MAXROWS) {

			fgets(line, 100, infile);

			/*this is where validation(cleaning the file) of rows occur */

			int rowlength = strlen(line); //holds length of each line parsed.

			for (charIndex; charIndex < rowlength; charIndex++) {

				//this checks if the last column is empty.
				if (line[rowlength - 2] == ',' && line[rowlength - 1] == '\n') {

					line[rowlength - 1] = '~';
					line[rowlength] = '\n';
					line[rowlength] = '\0';
				}

				//checking for a double comma.
				if ((line[charIndex] == line[charIndex + 1]) && (line[charIndex] == ',')) {

					temp_char = line[charIndex];
					line[charIndex + 1] = '~';
					temp_char3 = line[rowlength - 1];

					for (int x = charIndex + 2; x < rowlength; x++) {

						temp_char2 = line[x];
						line[x] = temp_char;
						temp_char = temp_char2;
					}
				}

				if (line[rowlength] == '\0' && line[rowlength + 1] == ',') {

					line[rowlength] = '~';
					line[rowlength + 1] = '\0';
				}


				if (line[rowlength - 2] && line[rowlength - 1] == ',') {

					line[rowlength - 1] = ',';
					line[rowlength] = '~';
					line[rowlength + 1] = '\n';
					line[rowlength + 2] = '\0';
				}
				//end of line interaction 
			}


			//char
			strcpy(fitbitArray[row].patient, strtok(line, ","));
			//char
			strcpy(fitbitArray[row].minute, strtok(NULL, ","));
			//double
			fitbitArray[row].calories = atof(strtok(NULL, ",")); //atof() --> string to double
			//double
			fitbitArray[row].distance = atof(strtok(NULL, ",")); //atof() --> string to double
			//unsigned int
			fitbitArray[row].floors = atol(strtok(NULL, ",")); //atol() -> string to long(unsigned int)
			//unsinged int 
			fitbitArray[row].heartRate = atol(strtok(NULL, ",")); //atol() -> string to long(unsigned int)
			//unsinged int 
			fitbitArray[row].steps = atol(strtok(NULL, ",")); //atol() -> string to long(unsigned int) 
			//(int)sleeplevel
			(int)fitbitArray[row].sleepLevel = atoi(strtok(NULL, "\n")); //typecasted enum to an int.

			charIndex = 0;
			row++;
		}

		printf("\nIt works!");
		success = 1;
		

	}


	return success;
}


//checking through fitbitArray and making sure each row starts with the same paitent(i.e 12cx7)
int paitentChecker(FitbitData* fitbitArray){

	int row = 0, max_row = MAXROWS;
	int deletedRows = 0;

	char* paitent = fitbitArray[0].patient; 
	for (row; row < max_row; row++) {

		if (strcmp(paitent, fitbitArray[row].patient) != 0) {

			deletedRows++;
			for (row; row < max_row; row++) {

				fitbitArray[row] = fitbitArray[row + 1];
			}

		}
		
	}

	printf("\n%d Row(s) have been deleted: ", deletedRows);
	printf("for Patient \n");
	return deletedRows;

}

int minutechecker(FitbitData* fitbitArray){


	int row = 0, max_row = MAXROWS;
	int deletedRows = 0;

	
	for (row; row < max_row; row++) {

		if (strcmp(fitbitArray[row].minute, fitbitArray[row + 1].minute) != 0) {

			deletedRows++;
			for (row; row < max_row; row++) {

				fitbitArray[row] = fitbitArray[row + 1];
			}

		}

	}

	printf("\n%d Row(s) have been deleted: ", deletedRows);
	printf("for minutes. \n");
	return deletedRows;

	return 0;
}

double calculateDistance(FitbitData* fitbitArray)
{

	int row = 0;
	double totalDistance = 0;

	for (row; row < EDITEDROWS; row++) {
		totalDistance = totalDistance + fitbitArray[row].distance;
	}
	printf("\nTotal Distance: %.6lfMiles\n",totalDistance);
	return totalDistance;
	
}

double calculateCalories(FitbitData* fitbitArray)
{

	int row = 0;
	double totalCalories = 0;

	for (row; row < EDITEDROWS; row++) {
		totalCalories = totalCalories + fitbitArray[row].calories;
	}
	printf("\nTotal Calories: %.6lfCalories\n", totalCalories);
	return totalCalories;

}

unsigned int calculateFloors(FitbitData* fitbitArray)
{

	int row = 0;
	double totalFloors = 0;

	for (row; row < EDITEDROWS; row++) {
		totalFloors = totalFloors + fitbitArray[row].floors;
	}
	printf("\nTotal Floors: %.6lfFloors\n", totalFloors);
	return totalFloors;

}

int calculateSteps(FitbitData* fitbitArray)
{

	int row = 0;
	double totalSteps = 0;

	for (row; row < EDITEDROWS; row++) {
		totalSteps = totalSteps + fitbitArray[row].steps;
	}
	printf("\nTotal Steps: %.6lfSteps\n", totalSteps);
	return totalSteps;

}

unsigned int calculateHeartrate(FitbitData* fitbitArray)
{

	int row = 0;
	unsigned int totalHeartratePerMin = 0;
	int minutesINADay = 1440;

	for (row; row < EDITEDROWS; row++) {
		totalHeartratePerMin = (totalHeartratePerMin) / minutesINADay;
	}
	printf("\nAverage HeartRate: %u BPM\n", totalHeartratePerMin);
	return totalHeartratePerMin;

}

unsigned int calculatemaxStepsInAMinute(FitbitData* fitbitArray)
{

	int row = 0;
	unsigned int maxSteps = fitbitArray[row].steps;
	char timeOfSteps[10];

	for (row; row < EDITEDROWS; row++) {
		if (fitbitArray[row].steps > maxSteps); {
			maxSteps = fitbitArray[row].steps;
			//timeOfSteps = data[row].minute;
			strcpy(timeOfSteps, fitbitArray[row].minute);
		}
	}
	printf("The Maximum steps taken in A minute is:[ %u ] Steps at a time:[ %s ] \n", maxSteps);
	return maxSteps;

}

unsigned int calculateconsecutivePoorSleepCounter(FitbitData* fitbitArray)
{
	// looking for how many times it's at 0 consectively

	int row = 0;
	unsigned int poorSleepFrequency = 0, maxFrequency = 0;
	for (row; row < EDITEDROWS; row++)
	{
		if (fitbitArray[row].sleepLevel == 0) {
			if (fitbitArray[row].sleepLevel == fitbitArray[row + 1].sleepLevel) {
				poorSleepFrequency++;
			}
			else
			{
				if (poorSleepFrequency > maxFrequency) {
					maxFrequency = poorSleepFrequency;
				}
				poorSleepFrequency = 0;
			}
		}
	}
	printf("The Highest Frequency of Poor sleep is : %u consecutive times throughout the day\n", maxFrequency);
}

void printStruct(FitbitData* fitbitArray) {

	int row = 0;

	printf("--- Current FitbitData---");

	for (row; row < 1442; row++) {

		printf("\n|paitent: %s |minute: %s |calories : %lf |Distance: %lf |Floors: %u| HeartRate: %u| SleepLevel: %d| \n end of line here \n",
			fitbitArray[row].patient, fitbitArray[row].minute, fitbitArray[row].calories, fitbitArray[row].distance, fitbitArray[row].floors, fitbitArray[row].heartRate, fitbitArray[row].steps, fitbitArray[row].sleepLevel);

	}

}

void printSructToFile(FILE* outfile, FitbitData* fitbitArray){

	int row = 0;
	fprintf(outfile, "\n \nPaitent,Minute,Calories,Distance,Floors,Heart,Steps,SleepLevel\n");

	for (row; row < EDITEDROWS; row++) {

		fprintf(outfile, "%s,", fitbitArray[row].patient);
		fprintf(outfile, "%s,", fitbitArray[row].minute);
		fprintf(outfile, "%lf,", fitbitArray[row].calories);
		fprintf(outfile, "%lf,", fitbitArray[row].distance);
		fprintf(outfile, "%u,", fitbitArray[row].floors);
		fprintf(outfile, "%u,", fitbitArray[row].heartRate);
		fprintf(outfile, "%u,", fitbitArray[row].steps);
		fprintf(outfile, "%d,", fitbitArray[row].sleepLevel);
	}

}






