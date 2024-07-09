/*****************************************************************************
**************
* Programmer: Darasimi Ogunbinu-Peters
* Class: CptS 122, Spring 2023; Lab Section 5
* Programming Assignment: Lab2
* Date: January 25, 2023
* Description: Design, implement, compile, and test C solutions to the following
problems
******************************************************************************
*************/
#include "header.h"

int main(void)
{
	FILE* ContactStream = fopen("contacts.txt", "r");
	FILE* OutputStream = fopen("ModContacts.txt", "w");

	int userchoice = 0;
	userchoice = processchoice();

	switch (userchoice)
	{
	case ADD:; insertContactInOrder(pHead, contactlist)
		break;

	case DELETE:;
		break;

	case EDIT:;
		break;

	case PRINT:;
		break;

	case STORE:;
		break;

	case LOAD:;
		break;

	}




	fclose(ContactStream);
	fclose(OutputStream);


	return 0;

}