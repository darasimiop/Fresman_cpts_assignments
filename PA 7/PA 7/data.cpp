#include "data.hpp"
#include <string>

Data::Data() {

	this->recordNumber = "";
	this->Id_Number = "";
	this->studentName.firstName = "";
	this->studentName.lastName = "";
	this->Email = "";
	this->Units = "";
	this->Program = "";
	this->Level = "";
	this->AbscenceNumber = this->Absences.getStackSize();
}
Data::Data(string recNum, string idNum, FullName studentName, string email, string units, string prog, string level, string absences) {

	this->recordNumber = recNum;
	this->Id_Number = idNum;
	this->studentName.firstName = studentName.firstName;
	this->studentName.lastName = studentName.lastName;
	this->Email = email;
	this->Units = units;
	this->Program = prog;
	this->Level = level;
	this->AbscenceNumber = std::stoi(absences);
}

Data::Data(Data& copyData) {

	this->recordNumber = copyData.recordNumber;
	this->Id_Number = copyData.Id_Number;
	this->studentName.firstName = copyData.studentName.firstName;
	this->studentName.lastName = copyData.studentName.lastName;
	this->Email = copyData.Email;
	this->Units = copyData.Units;
	this->Program = copyData.Program;
	this->Level = copyData.Level;
	this->AbscenceNumber = copyData.AbscenceNumber;

}

Data::~Data() {

}

//GETTERS:

string Data::getRecordNumber() const {
	return this->recordNumber;
}


string Data::getId() const {
	return this->Id_Number;
}


string Data::getstudentFirstName() const {
	return this->studentName.firstName;
}


string Data::getstudentLastName() const {
	return this->studentName.lastName;
}


string Data::getEmail() const {
	return this->Email;
}


string Data::getUnits() const {
	return this->Units;
}


string Data::getProgram() const {
	return this->Program;
}


string Data::getLevel() const {
	return this->Level;
}

int Data::getAbsenceNum() {
	return AbscenceNumber;
}

stack Data::getAbsenceStack() {

	return this->Absences;
}


//SETTERS:

void Data::setRecordNumber(string newRecordNum) {
	this->recordNumber = newRecordNum;
}

void Data::setId(string newId_Number) {
	this->Id_Number = newId_Number;
}

void Data::setstudentFirstName(string newFirstName) {

	this->studentName.firstName = newFirstName;
}

void Data::setstudentLastName(string newLastName) {

	this->studentName.lastName = newLastName;
}


void Data::setEmail(string newEmail) {
	this->Email = newEmail;
}

void Data::setUnits(string newUnits) {

	this->Units = newUnits;
}

void Data::setProgram(string newProgram) {
	this->Program = newProgram;
}

void Data::setLevel(string newLevel) {

	this->Level = newLevel;
}

void Data::setAbsenceNum(int newAbsenceNum) {
	this->AbscenceNumber = newAbsenceNum;
}

void Data::setAbsenceDate() {

	time_t t = time(0);
	struct tm* now = localtime(&t);
	string today_sDate = std::to_string(now->tm_mon) + "/" + std::to_string(now->tm_mday) + "/" + std::to_string(now->tm_year + 1900);
	Absences.push(today_sDate);

	cout << "Present Date: " << today_sDate << std::endl;

	int num_absence = Absences.getStackSize();
	this->setAbsenceNum(num_absence);
}