#include "stack.hpp"

stack::stack(vector<string> newstackVector) {

	this->Absences = newstackVector;
}


//stack::stack(stack& existingstack) {
//
//	stack* newstack = new stack(existingstack.Absences);
//
//	int size = existingstack.Absences.size();
//	int index = 0;
//	for (index; index < size - 1; index++) {
//
//		this->Absences.push_back(existingstack.Absences[index-1]);
//	}
//	
//
//}

stack::~stack() {

}

bool stack::push(string newDate) {



	if (newDate != "") {

		if (isempty()) {

			this->Absences[0] = newDate;
			return true;
		}
		else {
			this->Absences.push_back(newDate);
		}
	}
	else {
		return false;
	}
}

//precondition: the stack isn't empty
bool stack::pop() {


	if (!isempty()) {
		this->Absences.pop_back();
		return true;
	}
	else {
		return false;
	}
}


void stack::peek() {

	if (!isempty()) {
		cout << "this is the first Date in the stack: " << this->Absences[0] << std::endl;
	}
	else {
		cout << "stack is empty" << std::endl;
	}
}


void stack::printstack() {

	int size = this->Absences.size();
	int index = 0;
	for (index; index < size - 1; index++) {

		cout << "Date: " << this->Absences[index] << std::endl;
	}
}


bool stack::isempty() {

	if (this->Absences[0] == "") {
		return true;
	}
	else {
		return false;
	}
}



void stack::deletestack() {

	int size = this->Absences.size();

	while (size != 0) {

		this->Absences.pop_back();
	}
}


int stack::getStackSize() {
	int size = this->Absences.size();
	return size;
}
