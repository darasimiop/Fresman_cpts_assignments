#include "ExercisePlan.h"

ExercisePlan::ExercisePlan(int goal, string pName, string pDate)
{
	planName = pName;
	planDate = pDate;
	goalSteps = goal;
}

ExercisePlan::ExercisePlan(ExercisePlan& copy)
{
	this->planName = copy.planName;
	this->planDate = copy.planDate;
	this->goalSteps = copy.goalSteps;
}

ExercisePlan::~ExercisePlan()
{
	cout << "Delete Diet Plan" << endl;
}

int ExercisePlan::getGoal()
{
	return goalSteps;
}

string ExercisePlan::getplanName()
{
	return planName;
}

string ExercisePlan::getplanDate()
{
	return planDate;
}

void ExercisePlan::setGoal(int newGoal)
{
	goalSteps = newGoal;
}
void ExercisePlan::setplanName(string newPlanName)
{
	planName = newPlanName;
}

void ExercisePlan::setplanDate(string newPlanDate)
{
	planDate = newPlanDate;
}

void ExercisePlan::editGoal()
{
	cout << "enter new goal: ";
	cin >> goalSteps;
}
