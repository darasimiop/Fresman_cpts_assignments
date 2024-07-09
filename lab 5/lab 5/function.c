#include "header.h"

Bool isEmpty(Stack* pStack)
{
	if (pStack->pTop == NULL)
	{
		return True;
	}
	else
	{
		return False;
	}
}

void push(Stack* pStack, double data)
{
	Node* pTemp = (Node*)malloc(sizeof(Node));

	if (pTemp != NULL)
	{
		pTemp->num = data;
		pTemp->pNext = NULL;
		if (isEmpty(pStack) == True)
		{
			pStack->pTop = pTemp;
		}
		else
		{
			pTemp->pNext = pStack->pTop;
			pStack->pTop = pTemp;
		}

		void pop(Stack* pStack)
		{
			Node* pTemp = pStack->pTop;

		}
	}
}