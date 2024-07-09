#include "NodeBST.h"
//Constructor
BSTNode::BSTNode(char character, std::string morse_code) :
    character_{ character },
    morse_code_{ morse_code },
    left_child_{ nullptr },
    right_child_{ nullptr } {}

//Getters 
char BSTNode::getCharacter() const {
    return character_;
}

std::string BSTNode::getMorseCode() const {
    return morse_code_;
}

BSTNode* BSTNode::getLeftChild() const {
    return left_child_;
}

BSTNode* BSTNode::getRightChild() const {
    return right_child_;
}

//Setters
void BSTNode::setLeftChild(BSTNode* left) {
    left_child_ = left;
}

void BSTNode::setRightChild(BSTNode* right) {
    right_child_ = right;
}
