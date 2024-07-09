#pragma once
#include <iostream>
#include "Node.hpp"
using std::cin;
using std::cout;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;



//SHOULD ONLY HAVE A HEAD POINTER:

//Should be a template:

template<class T>
class linkedlist {

public:

	linkedlist(Node<T>* phead = nullptr);
	linkedlist(linkedlist& existinglist);
	~linkedlist();



	bool insertatfront(Node<T>* studentrecord);

	bool isempty();
	void printlist();
	void deletelist();

	void setpHead(Node<T>* newpHead);
	Node<T>* getHeadptr()const;

	void generateReport()const;
	void generateSpecificReport(int input)const;


	void readClassList();
	void readMasterList();

	void storeMasterList();

	void markAbsences();

private:
	Node<T>* head_pointer;
};

template<class T>
linkedlist<T>::linkedlist(Node<T>* phead) {
	this->head_pointer = phead;
}


template<class T>
linkedlist<T>::linkedlist(linkedlist& existinglist) {


	linkedlist* newlist = new linkedlist(existinglist);
	newlist->head_pointer = existinglist.head_pointer;

	Node<T>* currentnode = existinglist.head_pointer;

	while (currentnode != nullptr) {

		currentnode = currentnode->getNextPtr();
		newlist->insertatfront(currentnode);
	}
}


template<class T>
linkedlist<T>::~linkedlist() {
	this->deletelist();
}


template<class T>

bool linkedlist<T>::insertatfront(Node<T>* studentrecord) {

	if (studentrecord != nullptr) {

		if (isempty()) {
			this->head_pointer = studentrecord;
			return true;
		}
		else {
			//if the list is not empty:
			Node<T>* pCur = this->head_pointer;
			this->head_pointer = studentrecord;
			studentrecord->setNextPtr(pCur);
			return true;
		}
	}
	else {

		return false;
	}

}

template<class T>
void linkedlist<T>::printlist() {

	Node<T>* pCur = this->head_pointer;
	while (pCur != nullptr) {

		cout << "First Name: " << pCur->getStudentRecord().getstudentFirstName() << std::endl;
		cout << "Last Name: " << pCur->getStudentRecord().getstudentLastName() << std::endl;
		cout << "Student ID: " << pCur->getStudentRecord().getId() << std::endl;
		cout << "Student Record Number: " << pCur->getStudentRecord().getRecordNumber() << std::endl;
		cout << "Student Email: " << pCur->getStudentRecord().getEmail() << std::endl;
		cout << "Student Units: " << pCur->getStudentRecord().getUnits() << std::endl;
		cout << "Student Level: " << pCur->getStudentRecord().getLevel() << std::endl;
		cout << "Student Major: " << pCur->getStudentRecord().getProgram() << std::endl;
		pCur = pCur->getNextPtr();

		cout << "\n";
	}

}


template<class T>
bool linkedlist<T>::isempty() {

	if (this->head_pointer == nullptr) {
		return true;
	}
	else {
		return false;
	}
}



template<class T>
void linkedlist<T>::deletelist() {

	Node<T>* pCur = this->head_pointer;

	while (pCur != nullptr) {
		Node<T>* pNext = pCur->getNextPtr();
		delete pCur;
		pCur = pNext;
	}

}

template<class T>
Node<T>* linkedlist<T>::getHeadptr() const {

	return this->head_pointer;

}

template<class T>
void linkedlist<T>::setpHead(Node<T>* newpHead) {
	this->head_pointer = newpHead;
}
template<class T>
void linkedlist<T>::generateReport()const {

	Node<Data>* pCur = this->head_pointer;
	for (int i = 0; i < 10; i++) {

		cout << i << "." << endl;
		cout << pCur->getStudentRecord().getRecordNumber() << ",";
		cout << pCur->getStudentRecord().getstudentFirstName() << " ";
		cout << pCur->getStudentRecord().getstudentLastName() << ",";
		cout << pCur->getStudentRecord().getEmail() << ",";
		cout << pCur->getStudentRecord().getProgram() << ",";
		cout << pCur->getStudentRecord().getUnits() << ",";
		cout << pCur->getStudentRecord().getLevel() << endl;

		if (pCur->getStudentRecord().getAbsenceNum() == 0) {
			cout << pCur->getStudentRecord().getAbsenceNum() << endl;
		}if (pCur->getStudentRecord().getAbsenceNum() != 0) {
			cout << pCur->getStudentRecord().getAbsenceNum() << ",";
			pCur->getStudentRecord().getAbsenceStack().peek();
		}
		pCur = pCur->getNextPtr();
	}
}

template<class T>
void linkedlist<T>::generateSpecificReport(int input) const {

	Node<Data>* pCur = this->head_pointer;
	for (int i = 0; i < 10; i++) {

		if (pCur->getStudentRecord().getAbsenceNum() >= input) {

			cout << i << "." << endl;
			cout << pCur->getStudentRecord().getRecordNumber() << ",";
			cout << pCur->getStudentRecord().getstudentFirstName() << " ";
			cout << pCur->getStudentRecord().getstudentLastName() << ",";
			cout << pCur->getStudentRecord().getEmail() << ",";
			cout << pCur->getStudentRecord().getProgram() << ",";
			cout << pCur->getStudentRecord().getUnits() << ",";
			cout << pCur->getStudentRecord().getLevel() << endl;

			if (pCur->getStudentRecord().getAbsenceNum() == 0) {
				cout << pCur->getStudentRecord().getAbsenceNum() << endl;
			}if (pCur->getStudentRecord().getAbsenceNum() != 0) {
				cout << pCur->getStudentRecord().getAbsenceNum() << ",";
				pCur->getStudentRecord().getAbsenceStack().peek();
			}

		}
		pCur = pCur->getNextPtr();
	}
}



template<class T>
void linkedlist<T>::readClassList() {

	char read[50];

	ifstream Sourcefile;
	Sourcefile.open("classList.csv");

	FullName studentName;
	string recNum, Id_num, email, units, program, level;

	recNum = Id_num = email = units = program = level = studentName.firstName = studentName.lastName = "";

	Data studentRecords[10];

	int index = 0;

	//use smth like fgets to take the title away
	Sourcefile.getline(read, 50, '\n');
	while (!Sourcefile.eof() && index != 11) {

		//reading from the file.
		Sourcefile.getline(read, 50, ','); //1
		recNum = read;


		Sourcefile.getline(read, 50, ','); //1111
		Id_num = read;

		Sourcefile.getline(read, 50, '"'); //,

		//reading in both names.
		Sourcefile.getline(read, 50, ','); //smith
		//do some gymnastics here.
		studentName.lastName = read;

		Sourcefile.getline(read, 50, '"'); //john
		//do some gymnastics here.
		studentName.firstName = read;

		Sourcefile.getline(read, 50, ','); //,
		Sourcefile.getline(read, 50, ','); //smithj@cpts122.edu
		email = read;

		Sourcefile.getline(read, 50, ','); //4
		units = read;

		Sourcefile.getline(read, 50, ','); //CS
		program = read;

		Sourcefile.getline(read, 50, '\n'); //Freshman
		level = read;

		studentRecords[index].setRecordNumber(recNum);
		studentRecords[index].setId(Id_num);
		studentRecords[index].setstudentFirstName(studentName.firstName);
		studentRecords[index].setstudentLastName(studentName.lastName);
		studentRecords[index].setEmail(email);
		studentRecords[index].setUnits(units);
		studentRecords[index].setProgram(program);
		studentRecords[index].setLevel(level);

		index++;
	}

	index = 0;

	while (index < 10) {

		Node<Data>* ptr = new Node<Data>(studentRecords[index]);

		this->insertatfront(ptr);

		index++;
	}
}


template<class T>
void linkedlist<T>::readMasterList() {

	char read[50];

	ifstream Sourcefile;
	Sourcefile.open("MasterList.csv");

	FullName studentName;
	string recNum, Id_num, email, units, program, level, absences;

	recNum = Id_num = email = units = program = level = studentName.firstName = studentName.lastName = absences = "";

	Data studentRecords[10];

	int index = 0;

	//use smth like fgets to take the title away
	Sourcefile.getline(read, 50, '\n');
	while (!Sourcefile.eof() && index != 11) {

		//reading from the file.
		Sourcefile.getline(read, 50, ','); //1
		recNum = read;


		Sourcefile.getline(read, 50, ','); //1111
		Id_num = read;

		Sourcefile.getline(read, 50, '"'); //,

		//reading in both names.
		Sourcefile.getline(read, 50, ','); //smith
		//do some gymnastics here.
		studentName.lastName = read;

		Sourcefile.getline(read, 50, '"'); //john
		//do some gymnastics here.
		studentName.firstName = read;

		Sourcefile.getline(read, 50, ','); //,
		Sourcefile.getline(read, 50, ','); //smithj@cpts122.edu
		email = read;

		Sourcefile.getline(read, 50, ','); //4
		units = read;

		Sourcefile.getline(read, 50, ','); //CS
		program = read;

		Sourcefile.getline(read, 50, ','); //Freshman
		level = read;

		Sourcefile.getline(read, 50, '\n'); //absence num
		absences = read;



		studentRecords[index].setRecordNumber(recNum);
		studentRecords[index].setId(Id_num);
		studentRecords[index].setstudentFirstName(studentName.firstName);
		studentRecords[index].setstudentLastName(studentName.lastName);
		studentRecords[index].setEmail(email);
		studentRecords[index].setUnits(units);
		studentRecords[index].setProgram(program);
		studentRecords[index].setLevel(level);

		studentRecords[index].setAbsenceNum(studentRecords[index].getAbsenceNum());

		index++;
	}

	index = 0;

	while (index < 10) {

		Node<Data>* ptr = new Node<Data>(studentRecords[index]);

		this->insertatfront(ptr);

		index++;
	}
}

template<class T>
void linkedlist<T>::storeMasterList() {

	ofstream output;
	output.open("MasterList.csv");
	Node<Data>* pCur = this->head_pointer;
	output << ",ID,Name,Email,Units,Program,Level,Absences" << endl;
	for (int i = 0; i < 10; i++) {
		output << pCur->getStudentRecord().getRecordNumber() << ',';
		output << pCur->getStudentRecord().getId() << ',';
		output << pCur->getStudentRecord().getstudentLastName() << " ";
		output << pCur->getStudentRecord().getstudentFirstName() << ',';
		output << pCur->getStudentRecord().getEmail() << ',';
		output << pCur->getStudentRecord().getUnits() << ',';
		output << pCur->getStudentRecord().getProgram() << ',';
		output << pCur->getStudentRecord().getLevel() << ',';
		if (pCur->getStudentRecord().getAbsenceNum() == 0) {
			output << pCur->getStudentRecord().getAbsenceNum() << endl;
		}
		else {
			output << pCur->getStudentRecord().getAbsenceNum() << ',';
			//pCur->getStudentRecord().getAbsenceStack().peek();
		}
		pCur = pCur->getNextPtr();

	}
}


template<class T>
void linkedlist<T>::markAbsences() {

	Node<Data>* pCur = this->head_pointer;
	int option = 0;
	for (int i = 0; i < 10; i++) {

		cout << "Name: " << pCur->getStudentRecord().getstudentFirstName() << " " << pCur->getStudentRecord().getstudentLastName() << "\nChoose [1 -> Present ] | [0-> Absent]\n>>";
		cin >> option;
		if (option == 0) {
			pCur->getStudentRecord().setAbsenceDate();
			cout << "This Student has been absent: " << pCur->getStudentRecord().getAbsenceStack().getStackSize() << " times\n";
			pCur->getStudentRecord().getAbsenceStack().printstack();
			cout << "\n";
			pCur = pCur->getNextPtr();
		}
		else {
			pCur = pCur->getNextPtr();
		}
	}

}