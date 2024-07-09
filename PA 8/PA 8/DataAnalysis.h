#pragma once
//Darasimi Ogunbinu-Peters
// PA 8 - Data Analysis via BST
// Comments in source file.

#include "BST.h"
#include <fstream>
#include <sstream>

class DataAnalysis
{
public:
	DataAnalysis() { ; }
	~DataAnalysis() { ; }
	void runAnalysis();
private:
	BST mTreesSold;
	BST mTreePurchased;
	std::fstream stream;
	std::fstream& openFile();
	void streamParse(std::istringstream& line, int& units, std::string& type, std::string& transaction);
	void fileParse(std::fstream& newStream);
	void chooseBST(std::string& transaction, std::string& type, int& units);
	void trends();
};