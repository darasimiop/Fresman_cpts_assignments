#pragma once
#ifndef _StackNode_H
#define _StackNode_H
//Chat GPT helped me with most of this
template <typename T>
class stacknode {

public:
	//constructor(default)
	stacknode() {
		pData = nullptr;
		pNext = nullptr;
	};

	//copy constructor:(dynamically allocated)
	stacknode(stacknode& other) {
		if (other.data != nullptr) {

			this->pData = new T(*other.pData);
			this->pNext = nullptr;
		}
		
	};
	
	//destructor:
	~stacknode() {
		delete pData;
	};

	
	//getters:
	T data(void) const { //gets data
		return pData;
	};
	stacknode<T>* next(void) const { //gets next pointer
		return pData;
	};

	//setters:
	void setData(T newData) {
		this->pData = newData;
	}

	void setNextPointer(stacknode<T>* newNext) {
		this->pNext = newNext;
	}


private:
	T pData;
	stacknode<T>* pNext; //self referntial(pointer to itself)
};

#endif
