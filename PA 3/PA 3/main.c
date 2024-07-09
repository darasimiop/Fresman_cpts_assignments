#include "DigitalMM.h"
/*
Name: Darasimi Ogunbinu-Peters.
Date created: 12th |2| 2023 

Description: Write a C program that acts like a music organizational tool



*/


void main(void) {

	FILE* infile = fopen("musicPlayList.csv", "r+");
	int dataParsed = 0;
	List PlayList[10];
	Record Songs[9];  //struct for songs



	int preLoad = load(infile, *PlayList, Songs); //preLoading the file, to prevent putting the wrong data before performing any operation.
	int option = processOption(infile, Songs);
	int excution = executeOption(option, infile, &Songs, &PlayList);







	fclose(infile);
}