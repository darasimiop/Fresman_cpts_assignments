#pragma once

#include <string>

class BSTNode {
public:
	//constructor
	BSTNode(char character, std::string morse_code);
	//getters
	char getCharacter() const;
std::string getMorseCode() const; 
BSTNode* getLeftChild() const;
BSTNode* getRightChild() const; 
//setters
void setLeftChild(BSTNode* left);
void setRightChild(BSTNode* right);

private:
	char character_;
	std::string morse_code_;
	BSTNode* left_child_;
	BSTNode* right_child_;
};