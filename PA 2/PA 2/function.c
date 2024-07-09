#include "header.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Node* makeNode() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        return NULL;
    }
    return newNode;
}

int insertFront(Node** head, Node* newNode) {
    if (newNode == NULL) {
        return 0;
    }
    newNode->pNext = *head;
    *head = newNode;
    return 1;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("Title: %s, Artist: %s, Rating: %d\n", current->data.title, current->artist, current->rating);
        current = current->next;
    }
}

int load(struct Node** head) {
    FILE* fp = fopen("musicPlayList.csv", "r");
    if (fp == NULL) {
        return 0;
    }
    char title[100];
    char artist[100];
    int rating;
    while (fscanf(fp, "%[^,],%[^,],%d\n", title, artist, &rating) == 3) {
        struct Node* newNode = makeNode();
        strcpy(newNode->title, title);
        strcpy(newNode->artist, artist);
        newNode->rating = rating;
        if (!insertFront(head, newNode)) {
            return 0;
        }
    }
    fclose(fp);
    return 1;
}

int store(struct Node* head) {
    FILE* fp = fopen("musicPlayList.csv", "w");
    if (fp == NULL) {
        return 0;
    }
    struct Node* current = head;
    while (current != NULL) {
        fprintf(fp, "%s,%s,%d\n", current->title, current->artist, current->rating);
        current = current->next;
    }
    fclose(fp);
    return 1;
}

void display(struct Node* head) {
    printList(head);
}

struct Node* search(struct Node* head, char* artist) {
    struct Node* current = head;
    while (current != NULL) {
        if (strcmp(current->artist, artist) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void edit(struct Node* head) {
    char artist[100];
    printf("Enter the name of the artist: ");
    scanf("%s", artist);
    struct Node* node = search(head, artist);
    if (node == NULL) {
        printf("Artist not found.\n");
        return;
    }
    printf("Enter the new title: ");
    scanf("%s", node->title);

  
    void display() {
        printf("Displaying...\n");
    }

    void insert() {
        printf("Inserting...\n");
    }

    void delete() {
        printf("Deleting...\n");
    }

    void edit() {
        printf("Editing...\n");
    }

    void sort() {
        printf("Sorting...\n");
    }

    void rate() {
        printf("Rating...\n");
    }

    void play() {
        printf("Playing...\n");
    }

    void shuffle() {
        printf("Shuffling...\n");
    }