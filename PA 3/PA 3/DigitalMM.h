#ifndef DIGITAL_MUSIC_MANAGER
#define DIGITAL_MUSIC_MANAGER
#define _CRT_SECURE_NO_WARNINGS
#define MAX_SONGS 100


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>



//MACROS\\

#define LOAD    1
#define STORE   2
#define DISPLAY 3
#define INSERT  4
#define DELETE  5
#define EDIT    6
#define SORT    7
#define RATE    8
#define PLAY    9
#define SHUFFLE 10
#define EXIT    11
//#define PAUSE      system("pause")
//#define CLEARTEXT  system("cls")

						  //ENUM\\

typedef enum rating {

	POOR = 1, NOTBAD = 2, FAIR = 3, GOOD = 4, GREAT = 5

}Rating;


//STRUCTS\\

typedef struct duration {

	int minutes;
	int seconds;

}Duration;


typedef struct record {

	char artist[16]; //15bytes
	char albumTitle[30]; //15bytes
	char songTitle[15];  //15bytes
	char genre[15];      //15bytes
	Duration songLength;
	int timesPlayed;
	Rating songRating;


}Record;



typedef struct node {

	Record data;
	struct node* pNext;
	struct node* pPrev;
	struct node* data;

}Node;

typedef struct list {

	Node* pHead; //head pointer ... this is like the socket
}List;


//FUNCTION DEFINITIONS\\

/***********************************************************************************
 * Function: printMenu(void)                                                       *
 * Date Created:[Mon] 15th/02/2023                                                 *
 * Date Last Modified: 15th/ 02/2023.                                              *
 * Description:  Displays the   menu                                               *
																				   *
 * Input parameters: void                                                          *
 * Returns:void                                                                    *
 * Preconditions:  main() runs                                                     *
 * Postconditions: Prints out the menu contents                                    *
 ***********************************************************************************/
void printMenu(FILE* infile, FILE* outfile, Node** pHead);



//------
int getOption(void);
//------
int processOption(FILE* infile, Record* Songs);
//-----
int executeOption(int option, FILE* infile, Record* Songs, List* PlayList);
//-----
void back(FILE* infile, Record* Songs, List* PlayList);
//-----
int deleteSong(Node** pHead);

void timeDelay(int Seconds);


/***********************************************************************************
 * Function: load(FILE* infile, Record* Songs)                                     *
 * Date Created:[Mon] 15th/02/2023                                                 *
 * Date Last Modified: 15th/ 02/2023.                                              *
 * Description:                                                                    *
																				   *
 * Input parameters:                                                               *
 * Returns:                                                                        *
 * Preconditions:                                                                  *
 * Postconditions:                                                                 *
 ***********************************************************************************/
int load(FILE* infile, List PlayList, Record* Songs);

/***********************************************************************************
 * Function: store(Record* Songs)                                                  *
 * Date Created:[Mon] 15th/02/2023                                                 *
 * Date Last Modified: 15th/ 02/2023.                                              *
 * Description:                                                                    *
																				   *
 * Input parameters:                                                               *
 * Returns:                                                                        *
 * Preconditions:                                                                  *
 * Postconditions:                                                                 *
 ***********************************************************************************/
void store_songs(Node** pHead, FILE* Infile);//int store(FILE* infile, Record* Songs);

/***********************************************************************************
 * Function: display(Record* Songs)                                                *
 * Date Created:[Mon] 15th/02/2023                                                 *
 * Date Last Modified: 15th/ 02/2023.                                              *
 * Description:                                                                    *
																				   *
 * Input parameters:                                                               *
 * Returns:void                                                                    *
 * Preconditions:                                                                  *
 * Postconditions:                                                                 *
 ***********************************************************************************/
void display(Record* Songs);

//----
int insertFront(List* PlayList, Record Songs);
//---
int insertInOrder(List* Playlist, const Record* Songs);
//---
/***********************************************************************************
 * Function: edit(Record* Songs)                                                   *
 * Date Created:[Mon] 15th/02/2023                                                 *
 * Date Last Modified: 15th/ 02/2023.                                              *
 * Description:                                                                    *
																				   *
 * Input parameters:                                                               *
 * Returns:void                                                                    *
 * Preconditions:                                                                  *
 * Postconditions:                                                                 *
 ***********************************************************************************/
int edit(Node** pHead);

/***********************************************************************************
 * Function: rate(Record* Songs)                                                   *
 * Date Created:[Mon] 15th/02/2023                                                 *
 * Date Last Modified: 15th/ 02/2023.                                              *
 * Description:                                                                    *
																				   *
 * Input parameters:                                                               *
 * Returns:                                                                        *
 * Preconditions:                                                                  *
 * Postconditions:                                                                 *
 ***********************************************************************************/

int rate(Record* Songs);//put a star star

/***********************************************************************************
 * Function: play(Record* Songs)                                                   *
 * Date Created:[Mon] 15th/02/2023                                                *
 * Date Last Modified: 15th/ 02/2023.                                              *
 * Description:                                                                    *
																				   *
 * Input parameters:                                                               *
 * Returns:                                                                        *
 * Preconditions:                                                                  *
 * Postconditions:                                                                 *
 ***********************************************************************************/

int play(Record* Songs);

/***********************************************************************************
 * Function: exit(Record* Songs)                                                   *
 * Date Created:[Mon] 12th/02/2023                                                 *
 * Date Last Modified: 12th/ 02/2023.                                              *
 * Description:                                                                    *
																				   *
 * Input parameters:                                                               *
 * Returns:                                                                        *
 * Preconditions:                                                                  *
 * Postconditions:                                                                 *
 ***********************************************************************************/

void sort_songs(Node** pHead, FILE* Infile);
/*************************************************************
 * Function: sort_songs                                      *
                          *
 * Description: Allows the user to sort songs in a variety of ways
 * Input parameters: The Node and the data retreived from the .csv file
 * Returns:   N/a                                            *
 * Preconditions: N/a                                        *
 * Postconditions:  N/a                                      *
 *************************************************************/
void Exit(FILE* infile, Record* Songs);


//---
int shuffle(Node** pHead);


int initialisePlayList(List* PlayList, Record* Songs);

Node* makeNode(Record Songs);



#endif // !DIGITAL_MUSIC_MANAGER