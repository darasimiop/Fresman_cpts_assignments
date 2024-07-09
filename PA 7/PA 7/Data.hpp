#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include"stack.hpp"
#include<time.h>
#include <string.h>
using std::cin;
using std::cout;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;


typedef struct fullName {

	string firstName;
	string lastName;

}FullName;


class Data {
public:
	Data();
	Data(string recNum, string idNum, FullName studentName, string email, string units, string prog, string level, string absences);
	Data(Data& copyData);
	~Data();

	string getRecordNumber() const;
	string getId() const;
	string getstudentFirstName() const;
	string getstudentLastName() const;
	string getEmail() const;
	string getUnits() const;
	string getProgram() const;
	string getLevel() const;
	int getAbsenceNum();
	stack getAbsenceStack();


	void setRecordNumber(string newRecordNum);
	void setId(string newId_Number);
	void setstudentFirstName(string newFullname);
	void setstudentLastName(string newFullname);
	void setEmail(string newEmail);
	void setUnits(string newUnits);
	void setProgram(string newProgram);
	void setLevel(string newLevel);
	void setAbsenceNum(int newAbsenceNum);
	void setAbsenceDate();


private:
	string recordNumber;
	string Id_Number;
	FullName studentName;
	string Email;
	string Units;
	string Program;
	string Level;
	int AbscenceNumber;
	stack Absences;

};
