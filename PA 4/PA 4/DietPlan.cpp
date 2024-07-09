#include "DietPlan.h"
DietPlan::DietPlan(int goal, string pName, string pDate)
{
	planName = pName;
	planDate = pDate;
	goalCalories = goal;
}

DietPlan::DietPlan(DietPlan& copy)
{
	this->planName = copy.planName;
	this->planDate = copy.planDate;
	this->goalCalories = copy.goalCalories;
}

DietPlan::~DietPlan()
{
	cout << "Delete Diet Plan" << endl;
}

int DietPlan::getGoal()
{
	return goalCalories;
}

string DietPlan::getplanName()
{
	return planName;
}

string DietPlan::getplanDate()
{
	return planDate;
}

void DietPlan::setGoal(int newGoal)
{
	goalCalories = newGoal;
}
void DietPlan::setplanName(string newPlanName)
{
	planName = newPlanName;
}

void DietPlan::setplanDate(string newPlanDate)
{
	planDate = newPlanDate;
}

void DietPlan::editGoal()
{
	cout << "enter new goal: ";
	cin >> goalCalories;
}