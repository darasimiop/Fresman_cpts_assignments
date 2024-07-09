#include "FitnessApplication.h"

FitnessApplication::FitnessApplication()
{
	//opening files here:
	this->dietInfile.open("inputDietFile.txt");
	this->exerciseInfile.open("inputExerciseFile.txt");
	this->dietOutfile.open("outputDietFile.txt");
	this->exerciseOutfile.open("outputExerciseFile.txt");



}

FitnessApplication::~FitnessApplication()
{
	this->dietInfile.close();
	this->exerciseInfile.close();
	this->dietOutfile.close();
	this->exerciseOutfile.close();
}

void FitnessApplication::runApp(void)
{
	bool state = true;
	int option = 0; //to select an option.

	while (state) {
		displayMenu();
		cin >> option;

		if (option == 1) { 
			loadWeeklyDietPlan(this->dietInfile, this->wDiets);
		}
		if (option == 2) {
			loadWeeklyExercisePlan(this->exerciseInfile, this->wExercise);
		}
		if (option == 3) {
			storeWeeklyDietPlan();
		}
		if (option == 4) {

		}
		if (option == 5) {

		}
		if (option == 6) {

		}
		if (option == 7) {

		}
		if (option == 8) {

		}
		if (option == 9) { //exit
			state = false;
		}
		






		system("cls");
	}
}

void FitnessApplication::loadDailyDietPlan(ifstream& infile, DietPlan& plan)
{
	string line;

	std::getline(infile, line);
	plan.setplanName(line);
	std::getline(infile, line);
	plan.setGoal(std::stoi(line));
	std::getline(infile, line);
	plan.setplanDate(line);
	std::getline(infile, line);

}

void FitnessApplication::loadDailyExercisePlan(ifstream& infile, ExercisePlan& plan)
{
	string line;

	std::getline(infile, line);
	plan.setplanName(line);
	std::getline(infile, line);
	plan.setGoal(std::stoi(line));
	std::getline(infile, line);
	plan.setplanDate(line);
	std::getline(infile, line);
}

void FitnessApplication::loadWeeklyDietPlan(ifstream& infile, DietPlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		loadDailyDietPlan(infile, weeklyPlan[i]);
	}
}

void FitnessApplication::loadWeeklyExercisePlan(ifstream& infile, ExercisePlan weeklyPlan[])
{
	for (int i = 0; i < 7; i++)
	{
		loadDailyExercisePlan(infile, weeklyPlan[i]);
	}
}

void FitnessApplication::displayMenu()
{
	cout << "1. Load weekly diet plan from file." << endl;
	cout << "2. Load weekly exercise plan from file. " << endl;
	cout << "3. Store weekly diet plan to file." << endl;
	cout << "4. Store weekly exercise plan to file." << endl;
	cout << "5. Display weekly diet plan to screen." << endl;
	cout << "6. Display weekly exercise plan to screen." << endl;
	cout << "7. Edit daily diet plan." << endl;
	cout << "8. Edit daily exercise plan." << endl;
	cout << "9. Exit." << endl;
	cout << ">> ";

}
