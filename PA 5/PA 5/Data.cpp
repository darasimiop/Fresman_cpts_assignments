#include "Data.h"

Data::Data(int number, int service, int total)
{
	customerNumber = number;
	serviceTime = service;
	totalTime = total;
}

Data::Data(Data& copy)
{
	this->customerNumber = copy.getNumber();
	this->serviceTime = copy.getService();
	this->totalTime = copy.getTotal();
}

Data::Data(const Data& newData)
{
	this->customerNumber = newData.customerNumber;
	this->serviceTime = newData.serviceTime;
	this->totalTime = newData.totalTime;
}

Data::~Data()
{
	cout << "Delete Data" << endl;
}

int Data::getNumber()
{
	return customerNumber;
}

int Data::getService()
{
	return serviceTime;
}

int Data::getTotal()
{
	return totalTime;
}

void Data::setNumber(int newNumber)
{
	customerNumber = newNumber;
}

void Data::setService(int newService)
{
	serviceTime = newService;
}

void Data::setTotal(int newTotal)
{
	totalTime = newTotal;
}
