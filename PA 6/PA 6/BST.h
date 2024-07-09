#pragma once
// Name: Darasimi Ogunbinu_Peters
#include "NodeBST.h"
#include <fstream>
#include <string>

class BST {
public:
	// cosntructor 
	BST(const std::string& file_name);

	// destructor 
	~BST();

	// print the tree
	void print() const;

	void print(BSTNode* node) const;

	//search for a character in the tree and retirn its morse code
	//if it's found. or an empty string if it's not found 
	std::string searchForChar(char character) const;

	//
	std::string convertToMorse(std::string toMorse);

	//insert a node onto the tree
	void insert(BSTNode* node);

private:
	//root node of the tree
	BSTNode* root_;

	

	//recursively search for a character in the tree
	std::string search(BSTNode* node, char character) const;

	//recursively destroy tree
	void destroy(BSTNode* node);

};

