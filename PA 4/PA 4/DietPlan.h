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

class DietPlan
{
public:
	//default constructor 
	DietPlan(int goal = 0, string pName = "", string pDate = "");
	//copy constructor
	DietPlan(DietPlan& copy);
	//destructor:
	~DietPlan();
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
	int goalCalories;//represents maximum intake of claories in a day
	string planName;
	string planDate;
};

