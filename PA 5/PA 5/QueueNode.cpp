#include "QueueNode.h"

QueueNode::QueueNode()
{
	pData = new Data();
	pNext = nullptr;
}

QueueNode::QueueNode(const Data &newData)
{
	Data *D1 = new Data(newData); //creates a new data object
	this->pData = D1; //copies the whole object
	pNext = nullptr;
}

QueueNode::QueueNode(QueueNode& copy)
{
	pData = new Data(*copy.getData());
	pNext = copy.getNext();

}

QueueNode::~QueueNode()
{
	delete pData;
}

Data* QueueNode::getData()
{
	return pData;
}

QueueNode* QueueNode::getNext()
{
	return pNext;
}

void QueueNode::setData(Data* newData)
{
	pData = newData;
}

void QueueNode::setNext(QueueNode* newNext)
{
	pNext = newNext;
}
