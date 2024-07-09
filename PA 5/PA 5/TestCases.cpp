#include "TestCases.h"

bool testEmptyQueue()
{
	Data testData(1, 1, 1);
	Queue* q1 = new Queue();
	q1->enqeue(testData);
	if (q1->getLength() == 1)
	{
		return true;
	}
	else
	{
	return false;
	}
}

bool testNodeQueue()
{
	Data testData(1, 1, 1);
	Data testData1(2, 2, 2);

	Queue* q1 = new Queue();
	q1->enqeue(testData);
	q1->enqeue(testData1);
	if (q1->getLength() == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool test1NodeDequeue()
{
	Data testData(1, 1, 1);
	Queue* q1 = new Queue();
	q1->enqeue(testData);
	q1->dequeue();
	if (q1->isempty() == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool test2NodeDequeue()
{
	Data testData(1, 1, 1);
	Data testData1(2, 2, 2);
	Queue* q1 = new Queue();
	q1->enqeue(testData);
	q1->enqeue(testData1);
	q1->dequeue();

	if (q1->getLength() == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
