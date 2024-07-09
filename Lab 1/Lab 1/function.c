#include"Header.h"
//Task 2a
void rec_reversestring(char *str)
{
	if (*str)
	{
		rec_reversestring(str + 1);
		
		printf("%c", *str);
	} 
}
 //Task 2b 
char* myStrTok(char* str, const char* delim)
{
    static char* saveptr;

    if (str != NULL)
    {
        saveptr = str;
    }

    if (saveptr == NULL)
    {
        return NULL;s
    }

    char* token = strtok_r(saveptr, delim, &saveptr);
    return token;
}