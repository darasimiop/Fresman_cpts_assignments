#pragma once
#include "QueueNode.h"

class Queue
{
public: // Member functions
	//default constructor 
	Queue();
	//copy constructor 
	Queue(Queue& copy);
	//destructor
	~Queue();
	//getter
	QueueNode* getHead();
	QueueNode* getTail();
	//setter
	void setHeadPtr(QueueNode* const newHead);
	void setTailPtr(QueueNode* const newTail);
	//enqueue
	bool enqeue(Data const &newData);
	bool dequeue();
	//gets length of queue
	int getLength();
	//isempty
	bool isempty();
	// printQueue()
	void printQueue(QueueNode* Queue_P_Head, int n);
	int randomGenerator();

private:
	QueueNode* pHead;
	QueueNode* pTail;
};