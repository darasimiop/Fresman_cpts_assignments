#include "DigitalMM.h"



void printMenu(FILE* infile, FILE* outfile, Node** pHead) {


	//the one's with the star infront of them have been completed to some degree.

	printf("\n*****Main Menu*****\n");
	printf("\n1.Load*	\n");
	printf("\n2.Store	\n");
	printf("\n3.Display* \n");
	printf("\n4.Insert  \n");
	printf("\n5.Delete  \n");
	printf("\n6.Edit    \n");
	printf("\n7.Store   \n");
	printf("\n8.Rate*    \n");
	printf("\n9.Play*    \n");
	printf("\n10.Shuffle  \n");
	printf("\n11.Exit Features *\n");

}



int getOption(void) {

	int option = 0;
	printf("\n>> ");
	scanf("%d", &option);
	return option;
}

int processOption(FILE* infile, Record* Songs) {

	int option = 0;


	do
	{
		printMenu();
		option = getOption();
	} while (option < LOAD || option > EXIT);

	return option;
}

void back(FILE* infile, Record* Songs, List* PlayList) {

	int option = 0;
	char response = '\0';
	printf("\n~~~~~~~~~ DO YOU WANT TO RETURN TO THE MENU ?~~~~~~~~~\n [Y- yes|N- no]\n >> ");
	scanf(" %c", &response);
	if (response == 'Y' || response == 'y') {
		system("cls");
		option = processOption(infile, Songs);
		executeOption(option, infile, Songs, PlayList);
	}
	else if (response == 'N' || response == 'n') {
		printf("\n~~~~~~~~END OF PROGRAM ~~~~~~~~\n\n");
		option = 0;
		//Exit should go here(not necessary)
	}
	else if (response != 'N' || response != 'n' && response == 'Y' || response == 'y')
	{
		response = '\0';
		option = 0;
		back(infile, Songs, PlayList);
	}
}

void sort_songs(Node** pHead, FILE* Infile)
{
	Node* cur = *pHead;
	Node* after;
	Node* before;
	Node* first = cur->pNext;
	int choice = 0;
	int store = 0;
	do
	{
		printf("How would you like to sort your music?\n");
		printf("1) Based on Artist (A-Z)\n");
		printf("2) Based on Album Title (A-Z)\n");
		printf("3) Based on Rating (1-5:Highest to Lowest)\n");
		printf("4) Based on Times Played (Largest-Smallest)\n");

		scanf("%d", &choice);
		//small menu to prompt user on how they want to sort their songs
	} while ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4));

	if (choice == 1) //This is to sort by artist
	{
		while (cur != NULL)
		{
			cur = cur->pNext;

			if (strcmp(cur->data.artist, cur->pNext->data.artist) < 0)
			{
				if (strchr(cur->data.artist, ','))
				{
					printf("\"%s\",%s,%s,%s,%d:%d,%d,%d\n", cur->data.artist, cur->data.albumTitle,
						cur->data.songTitle, cur->data.genre, cur->data.songLength.minute, cur->data.songLength.second,
						cur->data.timesPlayed, cur->data.songRating);

					fprintf(Infile, "\"%s\",%s,%s,%s,%d:%d,%d,%d\n", cur->data.artist, cur->data.albumTitle,
						cur->data.songTitle, cur->data.genre, cur->data.songLength.minute, cur->data.songLength.seconds,
						cur->data.timesPlayed, cur->data.songRating);
				}
				else
				{
					printf("%s,%s,%s,%s,%d:%d,%d,%d\n", cur->data.artist, cur->data.albumTitle,
						cur->data.songTitle, cur->data.genre, cur->data.songLength.minutes, cur->data.songLength.seconds,
						cur->data.timesPlayed, cur->data.songRating);

					fprintf(Infile, "%s,%s,%s,%s,%d:%d,%d,%d\n", cur->data.artist, cur->data.albumTitle,
						cur->data.songTitle, cur->data.genre, cur->data.songLength.minutes, cur->data.songLength.seconds,
						cur->data.timesPlayed, cur->data.songRating);
				}
			}
		}
	}
	if (choice == 2) // this is to sort by album title
	{
		while (cur != NULL)
		{
			cur = cur->pNext;

			if (strcmp(cur->data.albumTitle, cur->pNext->data.albumTitle) < 0)
			{
				if (strchr(cur->data.artist, ','))
				{
					printf("\"%s\",%s,%s,%s,%d:%d,%d,%d\n", cur->data.artist, cur->data.albumTitle,
						cur->data.songTitle, cur->data.genre, cur->data.songLength.minutes, cur->data.songLength.seconds,
						cur->data.timesPlayed, cur->data.songRating);
					fprintf(Infile, "\"%s\",%s,%s,%s,%d:%d,%d,%d\n", cur->data.artist, cur->data.albumTitle,
						cur->data.songTitle, cur->data.genre, cur->data.songLength.minutes, cur->data.songLength.seconds,
						cur->data.timesPlayed, cur->data.songRating);
				}
				else
				{
					printf("%s,%s,%s,%s,%d:%d,%d,%d\n", cur->data.artist, cur->data.albumTitle,
						cur->data.songTitle, cur->data.genre, cur->data.songLength.minutes, cur->data.songLength.seconds,
						cur->data.timesPlayed, cur->data.songRating);

					fprintf(Infile, "%s,%s,%s,%s,%d:%d,%d,%d\n", cur->data.artist, cur->data.albumTitle,
						cur->data.songTitle, cur->data.genre, cur->data.songLength.minutes, cur->data.songLength.seconds,
						cur->data.timesPlayed, cur->data.songRating);
				}
			}
		}
	}
	if (choice == 3) //this is to sort by songRating
	{
		while (cur != NULL)
		{
			cur = cur->pNext;
			if (cur->data.songRating <= cur->pNext->data.songRating)
			{
				if (strchr(cur->data.artist, ','))
				{
					printf("\"%s\",%s,%s,%s,%d:%d,%d,%d\n", cur->data.artist, cur->data.albumTitle,
						cur->data.songTitle, cur->data.genre, cur->data.songLength.minutes, cur->data.songLength.seconds,
						cur->data.timesPlayed, cur->data.songRating);

					fprintf(Infile, "\"%s\",%s,%s,%s,%d:%d,%d,%d\n", cur->data.artist, cur->data.albumTitle,
						cur->data.songTitle, cur->data.genre, cur->data.songLength.minutes, cur->data.songLength.seconds,
						cur->data.timesPlayed, cur->data.songRating);
				}
				else
				{
					printf("%s,%s,%s,%s,%d:%d,%d,%d\n", cur->data.artist, cur->data.albumTitle,
						cur->data.songTitle, cur->data.genre, cur->data.songLength.minutes, cur->data.songLength.seconds,
						cur->data.timesPlayed, cur->data.songRating);

					fprintf(Infile, "%s,%s,%s,%s,%d:%d,%d,%d\n", cur->data.artist, cur->data.albumTitle,
						cur->data.songTitle, cur->data.genre, cur->data.songLength.minutes, cur->data.songLength.seconds,
						cur->data.timesPlayed, cur->data.songRating);
				}
			}
		}
	}

	if (choice == 4) // this is to sort by times played
	{
		while (cur != NULL)
		{
			cur = cur->pNext;

			if (cur->data.timesPlayed >= cur->pNext->data.timesPlayed)
			{
				if (strchr(cur->data.artist, ','))
				{
					printf("\"%s\",%s,%s,%s,%d:%d,%d,%d\n", cur->data.artist, cur->data.albumTitle,
						cur->data.songTitle, cur->data.genre, cur->data.songLength.minutes, cur->data.songLength.seconds,
						cur->data.timesPlayed, cur->data.songRating);

					fprintf(Infile, "\"%s\",%s,%s,%s,%d:%d,%d,%d\n", cur->data.artist, cur->data.albumTitle,
						cur->data.songTitle, cur->data.genre, cur->data.songLength.minutes, cur->data.songLength.seconds,
						cur->data.timesPlayed, cur->data.songRating);
				}
				else
				{
					printf("%s,%s,%s,%s,%d:%d,%d,%d\n", cur->data.artist, cur->data.albumTitle,
						cur->data.songTitle, cur->data.genre, cur->data.songLength.minutes, cur->data.songLength.seconds,
						cur->data.timesPlayed, cur->data.songRating);

					fprintf(Infile, "%s,%s,%s,%s,%d:%d,%d,%d\n", cur->data.artist, cur->data.albumTitle,
						cur->data.songTitle, cur->data.genre, cur->data.songLength.minutes, cur->data.songLength.seconds,
						cur->data.timesPlayed, cur->data.songRating);
				}
			}

		}
	}
}



int executeOption(int option, FILE* infile, Record* Songs, List* PlayList) {

	int execution = 0;

	switch (option) {
	case LOAD:   system("pause"); system("cls"); execution = load(infile, *PlayList, Songs); back(infile, Songs, PlayList);
		break;

	case STORE:  system("pause");  system("cls"); printf("\n Inserting Current Record to the FILE\n"); execution = store(infile, Songs); back(infile, Songs, PlayList);
		break;

	case DISPLAY:  system("pause");  system("cls"); display(Songs); back(infile, Songs, PlayList);
		break;

	case INSERT:  system("pause"); system("cls"); printf("\n Inserting Current Record to the FILE\n"); execution = insertFront(PlayList, *Songs); back(infile, Songs, PlayList); //a change made here
		break;

	case DELETE:  system("pause"); system("cls"); printf("\n Deleting song from PlayList\n"); execution = deleteSong(Songs, PlayList); back(infile, Songs, PlayList);
		break;

	case EDIT:  system("pause"); system("cls"); printf("\n Editing PlayList\n"); execution = edit(Songs); back(infile, Songs, PlayList); // do this later edit(playlist, songs )
		break;

	case SORT:  system("pause"); system("cls"); printf("\n Sorting PlayList\n"); execution = insertInOrder(PlayList, Songs); back(infile, Songs, PlayList); // do this later edit(playlist, songs )
		break;

	case RATE:  system("pause"); system("cls"); printf("\n Rating song \n"); execution = rate(Songs); back(infile, Songs, PlayList); // do this later edit(playlist, songs )
		break;

	case PLAY:  system("pause"); system("cls"); execution = play(Songs); back(infile, Songs, PlayList); // do this later edit(playlist, songs )
		break;
	case SHUFFLE:  system("pause"); system("cls"); printf("\n Shuffling song from PlayList\n"); execution = shuffle(Songs); back(infile, Songs, PlayList); // do this later edit(playlist, songs )
		break;

	case EXIT:  system("pause"); system("cls"); printf("\n Exiting PlayList\n"); Exit(infile, Songs); // do this later edit(playlist, songs )
		break;
	}








}


int load(FILE* infile, List Playlist, Record* Songs) {


	//how to add insertFront in this ?

	int success = 0;

	char rowContent[100]; //dataparsing tool to access the file
	char lengthOfSong[10];
	int row_index = 0;


	while (!feof(infile) != NULL) {

		fgets(rowContent, 100, infile);

		strcpy(Songs[row_index].artist, strtok(rowContent, ","));
		strcpy(Songs[row_index].albumTitle, strtok(NULL, ","));
		strcpy(Songs[row_index].songTitle, strtok(NULL, ","));
		strcpy(Songs[row_index].genre, strtok(NULL, ","));
		strcpy(lengthOfSong, strtok(NULL, ",")); //stores length of song because it's a different struct
		Songs[row_index].timesPlayed = atoi(strtok(NULL, ","));
		Songs[row_index].songRating = atoi(strtok(NULL, "\n"));
		Songs[row_index].songLength.minutes = atoi(strtok(lengthOfSong, ":"));
		Songs[row_index].songLength.seconds = atoi(strtok(NULL, "\n"));


		//if you experience any difficulty comment this out.
		insertFront(&Playlist, *Songs);

		row_index++;

	}


	printf("\n\t\t\t************ Currently Loading the file ************ \n");
	//Sleep(3000); //2000milliseconds = 2 seconds
	timeDelay(5);

	printf("\n\t\t\t************ Done Loading File ************\n");
	system("pause");
	system("cls");




	return success;


}




int store(Node** pHead, FILE* Infile) {

	//The ?store? command writes the current records, in the dynamic doubly linked list, 
	//to the musicPlayList.csv file. 
	//The store will completely overwrite the previous contents in the file.
	// Open the file for writing
	Infile = fopen("musicPlayList.csv", "w");

	Node* cur = *pHead;
	while (cur->pNext != NULL)
	{
		cur = cur->pNext; // Continues for each of the nodes 
	}

	while (cur != NULL)
	{
		if (strchr(cur->data.artist, ','))
		{
			fprintf(Infile, "\"%s\",%s,%s,%s,%d:%d,%d,%d\n", cur->data.artist, cur->data.albumTitle,
				cur->data.songTitle, cur->data.genre, cur->data.songLength.minutes, cur->data.songLength.seconds,
				cur->data.timesPlayed, cur->data.songRating);
		}
		else
		{
			fprintf(Infile, "%s,%s,%s,%s,%d:%d,%d,%d\n", cur->data.artist, cur->data.albumTitle,
				cur->data.songTitle, cur->data.genre, cur->data.songLength.minutes, cur->data.songLength.seconds,
				cur->data.timesPlayed, cur->data.songRating);
		}
		// this stores all of the data if any of it has changed
		cur = cur->pPrev;
	}
	fclose(Infile);

}


void timeDelay(int Seconds) { //Code from geeksforgeeks.com / delay() in c

	int milliSeconds = 1000 * Seconds;

	clock_t startTime = clock();

	while (clock() < startTime + milliSeconds);


}

void display(Record* Songs) {

	int row_index = 0;

	printf("----------HERE IS YOUR PLAYLIST-------------");
	for (row_index = 0; row_index < 9; row_index++) {


		printf("\n->Artist:%s \n\t*Album Title:%s \n\t*Song Title:%s \n\t*Genre:%s \n\t*Duration of Song: {%d minutes :%d seconds} \n\t*Times played :%d \n\t*Song Rating:%d  \n end of line here \n",
			Songs[row_index].artist, Songs[row_index].albumTitle, Songs[row_index].songTitle, Songs[row_index].genre, Songs[row_index].songLength.minutes, Songs[row_index].songLength.seconds, Songs[row_index].timesPlayed, Songs[row_index].songRating);
	}

	system("pause");
	system("cls");



}



int edit(Node** pHead) {
	//The ?edit? command must allow the user to find a record in the list by artist.
	// If there are multiple records with the same artist, 
	//then your program must prompt the user which one to edit. 
	//The user may modify all of the attributes in the record.
	Node* cur = *pHead;
	int choice = 0;
	char artist_search[50];
	char new_field[50];
	int temp_int = 0;
	printf("Enter the artist to search(Case Sensitive): ");
	getchar();
	fgets(artist_search, 50, stdin);
	int len = strlen(artist_search);
	artist_search[len - 1] = '\0';
	//Gets the name of the artist

	while (cur != NULL & choice == 0)
	{
		cur = cur->pNext;
		if (strcmp(artist_search, cur->data.artist) == 0) //This compares the artist to a node in the linked list
		{
			do
			{
				printf("Is '%s' the song you want to edit?\n", cur->data.songTitle);
				printf("Enter 1 for yes, 2 for no: ");
				scanf(" %d", &choice);
			} while ((choice != 1) && (choice != 2)); //This is to confirm the user's choice

			if (choice == 1)
			{
				printf("1) Artist\n2) Album\n3) Title\n4) Genre\n5) Length\n6) Number of plays\n7) Rating\n");
				printf("Enter the field you wish to edit: ");
				scanf(" %d", &choice);
				//This allows the user to choose what aspect to edit

				switch (choice)
				{
				case 1://to change the artist
					printf("Enter the new artist: ");
					getchar();
					fgets(new_field, 50, stdin);
					strcpy(cur->data.artist, new_field);
					cur->data.artist[strlen(cur->data.artist) - 1] = '\0';
					//This changes the current arist to the new artist the user inputted

					printf("The new artist is %s\n", cur->data.artist);

					break;
				case 2://to change the album name
					printf("Enter the new album: ");
					getchar();
					fgets(new_field, 50, stdin);
					strcpy(cur->data.albumTitle, new_field);
					cur->data.albumTitle[strlen(cur->data.albumTitle) - 1] = '\0';
					//This changes the current album name to the new name the user inputted

					printf("The new album is %s\n", cur->data.albumTitle);

					break;
				case 3://to change song title
					printf("Enter the new title: ");
					getchar();
					fgets(new_field, 50, stdin);
					strcpy(cur->data.songTitle, new_field);
					cur->data.songTitle[strlen(cur->data.songTitle) - 1] = '\0';
					//This changes the current song title to the new title the user inputted

					printf("The new title is %s\n", cur->data.songTitle);

					break;
				case 4://to change the song genre
					printf("Enter the new genre: ");
					getchar();
					fgets(new_field, 50, stdin);
					strcpy(cur->data.genre, new_field);
					cur->data.genre[strlen(cur->data.genre) - 1] = '\0';
					//This changes the current genre to the new genre the user inputted

					printf("The new genre is %s\n", cur->data.genre);

					break;
				case 5://to change the song length
					printf("Enter the new number of minutes: ");
					scanf(" %d", &temp_int);
					cur->data.songLength.minutes = temp_int;
					//This changes the current time, in minutes, to the new time the user inputted

					printf("Enter the new number of seconds: ");
					scanf(" %d", &temp_int);
					cur->data.songLength.seconds = temp_int;
					//This changes the current time, in seconds, to the new time the user inputted

					break;
				case 6://to change the times a song has been played
					printf("Enter the new number of plays: ");
					scanf(" %d", &temp_int);
					cur->data.timesPlayed = temp_int;
					//This changes the current number of times a song has been played to what the user inputs

					break;
				case 7://to change the rating
					printf("Enter the new rating: ");
					scanf(" %d", &temp_int);
					cur->data.songRating = temp_int;
					//This changes the current rating to the new rating the user inputted

					break;
				}
				break;
			}
			else
			{
				edit_songs(&pHead);
			}
		}
		cur = cur->pNext;
		choice = 0;
		//This then sets the node back to the linked list




}


int rate(Record* Songs) {

	int row_index = 0, newSongRating = 0, success = 0;
	char response = '\0', secondResponse = '\0';
	while (row_index < 9) {
		printf("\n\t\tThe current rating for %s by %s is %d\n", Songs[row_index].songTitle, Songs[row_index].artist, Songs[row_index].songRating);
		printf("Do you want to make changes to this song? [Y|N]\n>>");
		scanf(" %c", &response);

		if (response == 'Y' || response == 'y') {
			printf("Rate %s by %s from [1 -5] \n 1-> Poor \t 2-> NotBad \t 3-> Fair \t 4-> Good \t 5-> Great \n>>", Songs[row_index].songTitle, Songs[row_index].artist);
			scanf("%d", &newSongRating);
			printf("You have Rated %s by %s a %d out of 5.\nAre you satisfied with this rating?\n>>", Songs[row_index].songTitle, Songs[row_index].artist, newSongRating);
			scanf(" %c", &secondResponse);

			if (secondResponse == 'Y' || secondResponse == 'y') {

				Songs[row_index].songRating = newSongRating;
				printf("\n\t\t\tYour rating has been saved...\n");
			}
			else if (secondResponse == 'N' || secondResponse == 'n') {

				system("pause");
				system("cls");
				rate(songs);
			}
			else if ((response != 'N' || response != 'n') && (response == 'Y' || response == 'y')) {

				printf("\nPlease choose a VALID option\n");
				response = '\0';
				system("pause");
				system("cls");
				rate(Songs);

			}

		}
		//end of first yes
		else if (response == 'N' || response == 'n') {

			row_index++;

		}
		else if ((response != 'N' || response != 'n') && (response == 'Y' || response == 'y'))
		{
			printf("\nPlease choose a VALID option\n");
			response = '\0';
			system("pause");
			system("cls");
			rate(Songs);
		}

		row_index++;
	}

	return success;




}


int play(Record* Songs) {

	int success = 0;
	int row_index = 0, respone = 0;


	//options


	printf("Which Song do you want to play?\n");
	while (row_index < 9) {
		printf("\n %d.| %s by %s \n", row_index + 1, Songs[row_index].songTitle, Songs[row_index].artist);


		row_index++;
	}
	printf("\n\n\n");
	printf(">> ");
	scanf("%d", &respone);



	if (respone == 1) {
		system("pause");
		system("cls");
		printf("\n\t\t\t\t\t\You are now listening to %s by %s\n\n", Songs[respone - 1].songTitle, Songs[respone - 1].artist);
		timeDelay(7);
		printf("\nDone playing %s ", Songs[respone - 1].songTitle);
	}
	else if (respone == 2) {

		system("pause");
		system("cls");
		printf("\n\t\t\t\t\t\You are now listening to %s by %s\n\n", Songs[respone - 1].songTitle, Songs[respone - 1].artist);
		timeDelay(7);
		printf("\nDone playing %s ", Songs[respone - 1].songTitle);

	}
	else if (respone == 3) {

		system("pause");
		system("cls");
		printf("\n\t\t\t\t\t\You are now listening to %s by %s\n\n", Songs[respone - 1].songTitle, Songs[respone - 1].artist);
		timeDelay(7);//Sleep(20000);
		printf("\nDone playing %s ", Songs[respone - 1].songTitle);

	}
	else if (respone == 4) {

		system("pause");
		system("cls");
		printf("\n\t\t\t\t\t\You are now listening to %s by %s\n\n", Songs[respone - 1].songTitle, Songs[respone - 1].artist);
		timeDelay(7);//Sleep(20000);
		printf("\nDone playing %s ", Songs[respone - 1].songTitle);

	}
	else if (respone == 5) {

		system("pause");
		system("cls");
		printf("\n\t\t\t\t\t\You are now listening to %s by %s\n\n", Songs[respone - 1].songTitle, Songs[respone - 1].artist);
		timeDelay(7);//Sleep(20000);
		printf("\nDone playing %s ", Songs[respone - 1].songTitle);

	}
	else if (respone == 6) {

		system("pause");
		system("cls");
		printf("\n\t\t\t\t\t\You are now listening to %s by %s\n\n", Songs[respone - 1].songTitle, Songs[respone - 1].artist);
		timeDelay(7);//Sleep(20000);
		printf("\nDone playing %s ", Songs[respone - 1].songTitle);

	}
	else if (respone == 7) {

		system("pause");
		system("cls");
		printf("\n\t\t\t\t\t\You are now listening to %s by %s\n\n", Songs[respone - 1].songTitle, Songs[respone - 1].artist);
		timeDelay(7);//Sleep(20000);
		printf("\nDone playing %s ", Songs[respone - 1].songTitle);

	}
	else if (respone == 8) {

		system("pause");
		system("cls");
		printf("\n\t\t\t\t\t\You are now listening to %s by %s\n\n", Songs[respone - 1].songTitle, Songs[respone - 1].artist);
		timeDelay(7);//Sleep(20000);
		printf("\nDone playing %s ", Songs[respone - 1].songTitle);

	}
	else if (respone == 9) {

		system("pause");
		system("cls");
		printf("\n\t\t\t\t\t\You are now listening to %s by %s\n\n", Songs[respone - 1].songTitle, Songs[respone - 1].artist);
		timeDelay(7);//Sleep(20000);
		printf("\nDone playing %s ", Songs[respone - 1].songTitle);

	}
	else
	{
		system("cls");
		play(Songs);
	}


	success = 1;
	return success;

}


void Exit(FILE* infile, Record* Songs) {

	//The ?exit? command saves the most recent list to the musicPlayList.csv file. 
	//This command will completely overwrite the previous contents in the file.
	//BASICALLY PRINTING ALL THE CONTENTS TO THE FILE.


	//int row_index = 0;
	//fprintf(infile, "\nedited musicPlaylist\n");
	////I'll do this later

 // Open the file in write mode
    infile = fopen("musicPlayList.csv", "w");

    // Print the header for the csv file
    fprintf(infile, "Artist,Album,Song Title,Genre,Duration (mm:ss),Times Played,Rating\n");

    // Loop through each song in the array and print its information to the file in csv format
    for (int i = 0; i < MAX_SONGS; i++) {
        fprintf(infile, "%s,%s,%s,%s,%02d:%02d,%d,%d\n",
            Songs[i].artist,
            Songs[i].albumTitle,
            Songs[i].songTitle,
            Songs[i].genre,
            Songs[i].songLength.minutes,
            Songs[i].songLength.seconds,
            Songs[i].timesPlayed,
            Songs[i].songRating);
    }

    // Close the file
    fclose(infile);



}


int insertFront(List* PlayList, Record Songs) {

	Node* newSongNode = makeNode(Songs);
	int success = 0, i = 0;


	if (newSongNode != NULL) {

		success = 1;


		if (PlayList->pHead == NULL) {
			PlayList->pHead = newSongNode;
			newSongNode->pNext = NULL;
		}
		else
		{
			newSongNode->pNext = PlayList->pHead; // this sets the exiting link of the new node to the start of the old node 
			PlayList->pHead = newSongNode; //Playlist->pHead is basically the previous node. and making the previous node's pHead attached to the pNext of the new node
			newSongNode->pPrev = newSongNode; //sets the second node's pPrev to pHead
			//newSongNode->pNext->pPrev = newSongNode; 
		}


		return success;
	}


}




int shuffle(Node** pHead) {
	int size = 0;
	int count = 0;
	int i = 0, j = 0;
	int success = 0;
	Node* cur = *pHead;
	//Variables to shuffle
	while (cur != NULL)
	{
		cur = cur->pNext;
		size++;
		//This goes thourgh each node in the link list and counts the amount of nodes there are in the list
	}

	int* space = malloc(sizeof(int) * size); // Allocates space

	while (count < size) // as long count is less than the size then it will loop
	{
		cur = *pHead; //reinitialize cur to phead once again
		while (TRUE) // While it equals something or has a value
		{
			j = rand() % size; //create a random number based on the size of the linked list
			success = 0; //not ready to shuffle and play
			for (i = 0; i <= count; i++) //iterate through the linked list
			{
				if (j == space[i]) // if the number is equal to the variable space that was allocated earlier
				{
					success = 0; // then do not proceed with shuffling and playing the song
					break;
				}
				else
				{
					success = 1; // if both values are not equal then we begin shuffling and playing the songs
				}
			}
			if (success == 1)
			{
				break; // when success equals to 1 then we are ready to break out of original while loop and being shuffling
			}
		}
		i = 0; // setting the i back to zero to reset the variable
		while (cur != NULL)//as long as cur has data
		{
			if (i == j) // if i(or 0) is equal to j then we print out the song that is currently playing and also play all songs until the end of the list
			{
				system("cls");
				printf("Artist: %s\nAlbum:%s\nSong:%s\nGenre:%s\nLength:%d:%d\n", cur->data.artist, cur->data.albulmTitle,
					cur->data.song_title, cur->data.genre, cur->data.length.minute, cur->data.length.second);
				//this prints the data of the current song playing

				cur->data.times_played++;
				//This adds 1 to the times a song has been played

				time_t change = time(NULL) + 7; //a variable such as int but instead its a variable in time
				while (change >= time(NULL));
				//this "plays" the song for 7 seconds and the while allows the time to actually pass in real time

				fflush(stdout);
				//Empty the buffer that goes out
				break;
				// After each song is played and i=1 the program will stop playing the songs since i does not equal j
			}
			cur = cur->pNext;
			i++;
			//move on to the next node and add 1 to i once everysong has been played
		}
		count++;
		//this count ensures the amount of songs played matches the number of songs in the linked list 
	}
	free(space);
	//After all is done we can free the memory





}


deleteSong(Node** pHead) {
	Node* cur = *pHead;
	Node* pPrev = NULL;
	char start[25];
	char target[25];

	printf("Enter a song to delete(Case Sensitive): ");
	//Allows the user to input a song they want to delete
	getchar();
	fgets(start, 25, stdin);
	int len = strlen(start);
	start[len - 1] = '\0';
	strcpy(target, start);
	//Gets the song from the .csv file

	while (cur != NULL)
	{
		cur = cur->pNext;
		if (strcmp(target, cur->data.song_title) == 0) //This to find the song the user wants to delete in the linked list
		{
			Node* temp = cur;
			temp->pNext->pPrev = temp->pPrev;
			temp->pPrev->pNext = temp->pNext;

			free(cur);

			printf("Successfully deleted %s\n", target);
			return;
			//This case is if the song is immediatley found and it is then deleted




}





Node* makeNode(Record Songs) {

	int success = 0;
	Node* newNode = malloc(sizeof(Node));


	if (newNode != NULL) {
		//remember to parse in file from the excel

		success = 1;

		strcpy((*newNode).data.artist, Songs.artist);
		strcpy((*newNode).data.albumTitle, Songs.albumTitle);
		strcpy((*newNode).data.songTitle, Songs.songTitle);
		strcpy((*newNode).data.genre, Songs.genre);
		newNode->data.songLength.minutes = Songs.songLength.minutes;
		newNode->data.songLength.seconds = Songs.songLength.seconds;
		newNode->data.timesPlayed = Songs.timesPlayed;
		newNode->data.songRating = Songs.songRating;




		newNode->pNext = NULL;
		newNode->pPrev = NULL;


	}

	return newNode;

}





