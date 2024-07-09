#include <stdlib.h>
#include <string.h>

typedef enum boolean
{
	False = 0, True = 1
}Bool;

typedef struct node
{
	double num;
	Node* pNext;
}Node;

typedef struct stack
{
	Node* pTop;
}Stack;

Bool isEMpty(Stack* pStack);
void push(Stack* pStack);
void pop(Stack pStack);
double peek(Stack* pStack);


#endif
