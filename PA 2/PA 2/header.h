#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>  
#include<math.h>
#include <time.h>
#include<string.h>
#include<ctype.h>   

typedef struct duration {
    int minuete;
    int second;
}Duration;

typedef struct record {
    char artist[30];
    char album_title[30];
    char song_title[30];
    char genre[30];
    Duration length;
    int times_played;
    int rating;
}Record;

typedef struct node
{
    Record data;
    struct node* pNext;
    struct node* pPrev;
}Node;