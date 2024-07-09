#pragma once
#include "DietPlan.h"
#include "ExercisePlan.h"

class FitnessApplication
{
public:

	FitnessApplication();
	~FitnessApplication();

	void runApp(void);

	void loadDailyDietPlan(ifstream& infile, DietPlan& plan);
	void loadDailyExercisePlan(ifstream& infile, ExercisePlan& plan);

	void loadWeeklyDietPlan(ifstream& infile, DietPlan weeklyPlan[]);
	void loadWeeklyExercisePlan(ifstream& infile, ExercisePlan weeklyPlan[]);

	void displayDailyPlan();

	void displayWeeklyPlan();

	void storeDailyDietPlan();
	void storeDailyExercisePlan();

	void storeWeeklyDietPlan();
	void storeWeeklyExercisePlan();

	void displayMenu();

private:
	DietPlan wDiets[7];
	ExercisePlan wExercise[7];
	std::ifstream dietInfile;
	std::ifstream exerciseInfile;

	std::ofstream dietOutfile;
	std::ofstream exerciseOutfile;


};

