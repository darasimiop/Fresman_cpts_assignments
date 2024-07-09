#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::ofstream;
using std::ifstream;
using std::ostream;
using std::endl;


class ExercisePlan
{
public:
	//default constructor 
	ExercisePlan(int goal = 0, string pName = "", string pDate = "");
	//copy constructor
	ExercisePlan(ExercisePlan& copy);
	//destructor:
	~ExercisePlan();
	//getter
	int getGoal();
	string getplanName();
	string getplanDate();
	//setter
	void setGoal(int newGoal);
	void setplanName(string newPlanName);
	void setplanDate(string newPlanDate);
	//editGoal propmpts user for new goal
	void editGoal();


private:
	int goalSteps;//represents maximum intake of claories in a day
	string planName;
	string planDate;
};

