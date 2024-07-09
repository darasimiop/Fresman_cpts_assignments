#pragma once
#include <iostream>
#include"data.hpp"
using std::cin;
using std::cout;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;
using std::endl;


template<class T>
class Node {

public:

	Node(T record, Node<T>* pNext = nullptr);
	Node(Node<T>& existingNode);
	~Node();


	T getStudentRecord();
	Node<T>* getNextPtr() const;
	void setNextPtr(Node<T>* newNode);
	void setStudentRecord(T newStudentRecord);


private:
	T StudentRecord;
	Node<T>* NEXT_POINTER;
};

template<class T>
Node<T>::Node(T record, Node<T>* pNext) {

	this->StudentRecord = record;
	NEXT_POINTER = pNext;
}

template<class T>
Node<T>::Node(Node<T>& existingNode) {
	//dynamically allocated;

	Node<T>* BrandNewNode = new Node<T>(existingNode);
	BrandNewNode->StudentRecord.setRecordNumber(existingNode.StudentRecord.getRecordNumber());
	BrandNewNode->StudentRecord.setId(existingNode.StudentRecord.getId());
	BrandNewNode->StudentRecord.setstudentFirstName(existingNode.StudentRecord.getstudentFirstName());
	BrandNewNode->StudentRecord.setstudentLastName(existingNode.StudentRecord.getstudentLastName());
	BrandNewNode->StudentRecord.setEmail(existingNode.StudentRecord.getEmail());
	BrandNewNode->StudentRecord.setUnits(existingNode.StudentRecord.getUnits());
	BrandNewNode->StudentRecord.setProgram(existingNode.StudentRecord.getProgram());
	BrandNewNode->StudentRecord.setLevel(existingNode.StudentRecord.getLevel());
	BrandNewNode->setNextPtr(existingNode.getNextPtr());
}


template<class T>
Node<T>::~Node() {
	//gotta delete node
}


template<class T>
T Node<T>::getStudentRecord() {
	return this->StudentRecord;
}

template<class T>
Node<T>* Node<T>::getNextPtr() const {
	return this->NEXT_POINTER;
}

template<class T>
void Node<T>::setNextPtr(Node<T>* newNode) {
	NEXT_POINTER = newNode;
}


template<class T>
void Node<T>::setStudentRecord(T newStudentRecord) {
	this->StudentRecord.setRecordNumber(newStudentRecord.getRecordNumber());
	this->StudentRecord.setstudentFirstName(newStudentRecord.getstudentFirstName());
	this->StudentRecord.setstudentLastName(newStudentRecord.getstudentLastName());
	this->StudentRecord.setId(newStudentRecord.getId());
	this->StudentRecord.setEmail(newStudentRecord.getEmail());
	this->StudentRecord.setUnits(newStudentRecord.getUnits());
	this->StudentRecord.setProgram(newStudentRecord.getProgram());
	this->StudentRecord.setLevel(newStudentRecord.getLevel());
}
