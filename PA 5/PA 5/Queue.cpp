#include "Queue.h"

Queue::Queue()
{
	pHead = nullptr;
	pTail = nullptr;
}

Queue::Queue(Queue& copy)
{
	pHead = copy.getHead();
	pTail = copy.getTail();
}
void Queue::setHeadPtr(QueueNode* const newHead)
{
	this->pHead = newHead;
}
void Queue::setTailPtr(QueueNode* const newTail)
{
	this->pTail = newTail;
}

bool Queue::enqeue(Data const &newData)
{
	//QueueNode* pMem = new QueueNode(newData);
	QueueNode* pMem = new QueueNode(newData);
	if (pMem != NULL) {
		if (pHead == nullptr)
		{
			//pHead = pMem;
			//pTail = pMem;
			this->setHeadPtr(pMem);
			this->setTailPtr(pMem);

		}
		else
		{
			this->pTail->setNext(pMem);
			this->setTailPtr(pMem);

		}
		return true;
	}
	return false;
}

bool Queue::dequeue()
{
	QueueNode* pTemp = pHead;
	if (pHead == pTail)
	{
		pHead = nullptr;
		pTail = nullptr;
	}
	else
	{
		setHeadPtr(pHead->getNext());
	}
	delete pTemp;
	return true;
}

int Queue::getLength()
{
	QueueNode* pTemp = pHead;
	int count = 0;
	while (pTemp != nullptr)
	{
		pTemp = pTemp->getNext();
		count++;
			
	}
	return count;
}

bool Queue::isempty()
{
	if (pHead == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Queue::printQueue(QueueNode* Queue_P_Head, int n)
{
	QueueNode* pCur = Queue_P_Head;
	QueueNode* pPrev = nullptr;
	int i = 0;

	while (pCur != nullptr && (i < n)) {

		cout << "Customer " << pCur->getData()->getNumber() << " spent: " << pCur->getData()->getService() << " min(s) being attended too and waited for " << pCur->getData()->getService() << " min(s).";

		pPrev = pCur;
		pCur = pCur->getNext();
		i++;
		putchar('\n');
		putchar('\n');
	}

}

int Queue::randomGenerator()
{
	int roll = 0;
	roll = (rand() % 8) + 1;
	return roll;
}


Queue::~Queue()
{
	while (pTail != nullptr) {
		dequeue();
	}
}

QueueNode* Queue::getHead()
{
	return pHead;
}

QueueNode* Queue::getTail()
{
	return pTail;
}
