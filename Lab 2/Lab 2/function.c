#include "header.h"
//Task 1

Node* makeNode(Contact newData) // allocate space for a Node on the heap and intilaize it 
{
	Node* pMem = (Node*)malloc(sizeof(Node));

	if (pMem != NULL)
	{
		strcpy(pMem ->data.name, newData.name);
		strcpy(atoi(pMem->data.phone), newData.phone);
		strcpy(pMem->data.email, newData.email);
		strcpy(pMem->data.title, newData.title);
		
		return pMem;
	}
}

Boolean insertContactInOrder(Node** pList, Contact newData)
{
	Node* pCurrent = *pList,
		* pPrevious = NULL,
		* pMem = makeNode(newData);

	Boolean success;
	
	if (pMem != NULL)
	{
		success = TRUE;

		while (pCurrent != NULL && strcmp(pCurrent->data.name, newData.name) < 0)
		{
			pPrevious = pCurrent;
			pCurrent = pCurrent->pNext;
		}

		if (pPrevious == NULL)
		{
			pMem->pNext = *pList;
			*pList = pMem;
		}
		else
		{
			pMem->pNext = pCurrent;
			pPrevious->pNext = pMem;
		}
	}
}

Boolean deleteContact(Node** pList, Contact searchContact)
{
	Node* pTemp = *pList;
	Contact data = { "", "","","" };
	Boolean success;

	while (pTemp != NULL)
	{
		strcpy(data.name, pTemp->data.name);
		strcpy(atoi(data.phone), pTemp->data.phone);
		strcpy(data.email, pTemp->data.email);
		strcpy(data.title, pTemp->data.title);

		*pList = (*pList)->pNext;
		success = TRUE;
	}
	
	free(pTemp);

	return success;

}

int processchoice(void)
{
	int choice = 0;

	choice = scanf("%d", choice);

	return choice;
}

void contactmenu(void)
{
	printf("1.ADD\n");
	printf("2.Delete\n");
	printf("3.Edit\n");
	printf("4.Print\n");
	printf("5.Store\n");
	printf("6.Load\n");

}



