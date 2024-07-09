#pragma once
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;
using std::vector;


class stack {

public:

	stack(vector<string> newstackVector = { "" });
	//stack(stack& existingstack);
	~stack();

	bool push(string newDate);
	bool pop();
	void peek();
	void printstack();
	int getStackSize();

	bool isempty();
	void deletestack();

private:
	vector<string> Absences;

};
