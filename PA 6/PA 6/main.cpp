#include "Run.h"

int main(void)
{
//create binary search tree
//load text file that has morse code into binary search tree
	BST testBST = BST("MorseTable.txt");

    // open the input file
    std::ifstream infile("convert.txt");
    if (!infile) {
        std::cerr << "Failed to open input file" << std::endl;
        return 1;
    }

    // read the input file line by line
    std::string line;
    while (std::getline(infile, line)) {
        // convert each character to Morse code using the binary search tree
        std::string morse = testBST.convertToMorse(line);

        // print the result
        std::cout << morse << std::endl;
    }

    // close the input file
    infile.close();

    return 0;
   
 
}
