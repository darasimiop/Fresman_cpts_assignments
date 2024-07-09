#include "header.h"


void load();
void store();
void display();
void insert();
void delete();
void edit();
void sort();
void rate();
void play();
void shuffle();

int main() {
    int choice;

    while (1) {
        printf("\nMain Menu:\n");
        printf("(1)   Load\n");
        printf("(2)   Store\n");
        printf("(3)   Display\n");
        printf("(4)   Insert\n");
        printf("(5)   Delete\n");
        printf("(6)   Edit\n");
        printf("(7)   Sort\n");
        printf("(8)   Rate\n");
        printf("(9)   Play\n");
        printf("(10)  Shuffle\n");
        printf("(11)  Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            load();
            break;
        case 2:
            store();
            break;
        case 3:
            display();
            break;
        case 4:
            insert();
            break;
        case 5:
            delete();
            break;
        case 6:
            edit();
            break;
        case 7:
            sort();
            break;
        case 8:
            rate();
            break;
        case 9:
            play();
            break;
        case 10:
            shuffle();
            break;
        case 11:
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }

    return 0;
}

