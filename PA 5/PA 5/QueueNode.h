#pragma once
#include "Data.h"

class QueueNode
{
public: // Member functions
	//default constructor
	QueueNode();
	//copy constructor
	QueueNode(QueueNode& copy);
	//overloaded constructor 
	QueueNode(const Data& newData);
	//destructor
	~QueueNode();
	//getter
	Data* getData();
	QueueNode* getNext();
	//setter
	void setData(Data* newData);
	void setNext(QueueNode* newNext);
	//getNext ptr 
	


private:
	Data* pData;    // The memory for Data will need to be allocated on 
	//                  the heap as well!
	QueueNode* pNext;
};