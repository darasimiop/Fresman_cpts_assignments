#pragma once
#include "Queue.h"
class simulationApp
{
public:
	void testEmptyQue();
	void testSingleEnqueue();
	void testSingleDequeue();
	void testDoubleDequeue();
	void runAppFor24();
	void expressLaneFor24();
	void normalLaneFor24();
	void testPrintQueue(QueueNode* pHead);
	void testMenu();
};