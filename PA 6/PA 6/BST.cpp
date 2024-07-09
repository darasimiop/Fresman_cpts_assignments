#include "BST.h"
#include <iostream>

BST::BST(const std::string& file_name) :
    root_{ nullptr }
{
    // open the Morse table file
    std::ifstream file{ file_name };
    if (!file) {
        std::cerr << "Failed to open file " << file_name << std::endl;
        return;
    }

    // read the file line by line
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        // extract the character and morse code from the line
        char character = line[0];
        std::string morse_code = line.substr(1);

        // create a node for the character and morse code
        BSTNode* node = new BSTNode(character, morse_code);

        // insert the node into the tree
        insert(node);
    }

    // close the file
    file.close();
}

BST::~BST()
{
    // recursively destroy the tree
    destroy(root_);
}

void BST::insert(BSTNode* node)
{
    if (!root_) {
        // the tree is empty, make this node the root
        root_ = node;
    }
    else {
        // find the proper position to insert the node
        BSTNode* current = root_;
        while (true) {
            if (node->getCharacter() < current->getCharacter()) {
                if (!current->getLeftChild()) {
                    current->setLeftChild(node);
                    break;
                }
                else {
                    current = current->getLeftChild();
                }
            }
            else {
                if (!current->getRightChild()) {
                    current->setRightChild(node);
                    break;
                }
                else {
                    current = current->getRightChild();
                }
            }
        }
    }
}

void BST::print() const
{
    print(root_);
    std::cout << std::endl;
}

void BST::print(BSTNode* node) const
{
    if (node) {
        print(node->getLeftChild());
        std::cout << node->getCharacter() << node->getMorseCode() << " ";
        print(node->getRightChild());
    }
}

std::string BST::searchForChar(char character) const
{
    return search(this->root_, character);
}

std::string BST::search(BSTNode* node, char character) const
{
    if (!node) {
        // the character was not found
        return "Character not found";
    }
    else if (node->getCharacter() == character) 
    {
        return node->getMorseCode();
    }
    if (character < node->getCharacter())
    {
        return search(node->getLeftChild(), character);
    }
    if (character > node->getCharacter())
    {
        return search(node->getRightChild(), character); 
    }
}

void BST::destroy(BSTNode* node)
{
    if (node == nullptr) {
        return;
    }

    // recursively delete left and right subtrees
    destroy(node->getLeftChild());
    destroy(node->getRightChild());

    // delete the current node
    delete node;
}

std:: string BST::convertToMorse(std::string toMorse) {
    std::string result;
    for (char c : toMorse) {
        // Convert any lowercase characters to uppercase
        if (islower(c)) {
            c = toupper(c);
        }
        // Look up the character in the BST
        std::string morseCode = search(this->root_, c);
        // Append the Morse code to the result string
        if (morseCode != "Character not found") {
            result += morseCode + " ";
        }
    }
    return result;
    
}

    //takes string 
    //char by char itterates through string and checks tree
    //appends string to out string
