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
using namespace std;

class Data
{
public: // Member functions
	//default constructor 
	Data(int number = 0, int service = 0, int total = 0);
	//Copy constructor
	Data(Data& copy);
	//overloaded constructor
	Data(const Data &newData);
	//destructor
	~Data();
	//getter
	int getNumber();
	int getService();
	int getTotal();
	//setter 
	void setNumber(int newNumber);
	void setService(int newService);
	void setTotal(int newTotal);
private:
	int customerNumber; // Unique identifier; starts at 1; after 24 hours 
	//should be reset to 1
	int serviceTime;   // Random time; varies between express and 
	//                        normal lanes; units in minutes
	int totalTime;     // totalTime = serviceTime + sum of 
	//                        serviceTimes of customers in line before this customer; units in minutes


}; // This memory needs to be allocated on the heap!