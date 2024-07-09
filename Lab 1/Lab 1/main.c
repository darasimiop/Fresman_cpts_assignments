/*****************************************************************************
**************
* Programmer: Darasimi Ogunbinu-Peters
* Class: CptS 122, Spring 2023; Lab Section 1
* Programming Assignment: Lab1Task2
* Date: January 18, 2023
* Description: Design, implement, compile, and test C solutions to the following 
problems
******************************************************************************
*************/

#include"Header.h"

int main(void) {
	//Task 2a
	char* word = "Mieri Ogunbinu-Peters";
	
	rec_reversestring(word);
	
	//Task 2b 
	char str[] = "This is a sample string";
	char* token;
	printf("The string is: %s\n", str);

	token = myStrTok(str, " ");
	while (token != NULL)
	{
		printf("Token: %s\n", token);
		token = myStrTok(NULL, " ");
	}
	
	
	
	return 0;
}