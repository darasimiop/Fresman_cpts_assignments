#ifndef HEADER_H//guradcode for header

#define HEADER_H//guardcode for header
#define _CRT_SECURE_NO_WARNINGS//ignores 
#include <stdio.h> /* Header file for scanf, printf */
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
// values of display, play, and exit in the display menu 
#define DISPLAY 1 
#define PLAY 2
#define EXIT 3

void print_menu();//Prints menu

void rolldice_array(int* dice, int size);

void search_dice(int* dice, int size, int* freq_table, int size1);

int table1(int freq_table[], int size, int pass, int score_card1[], int size1);
int table2(int freq_table[], int size, int pass, int score_card1[], int size1);
int table3(int freq_table[], int size, int pass, int score_card1[], int size1);
int table4(int freq_table[], int size, int pass, int score_card1[], int size1);
int table5(int freq_table[], int size, int pass, int score_card1[], int size1);
int table6(int freq_table[], int size, int pass, int score_card1[], int size1);
int table7(int freq_table[], int size, int pass, int score_card1[], int size1);
int table8(int freq_table[], int size, int pass, int score_card1[], int size1);
int table9(int freq_table[], int size, int pass, int score_card1[], int size1);
int table10(int freq_table[], int size, int pass, int score_card1[], int size1);
int table11(int freq_table[], int size, int pass, int score_card1[], int size1);
int table12(int freq_table[], int size, int pass, int score_card1[], int size1);
int adjust_score(int sum2);
int winner(int sum2, int sum4);


#endif
