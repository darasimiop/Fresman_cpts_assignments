#include "header.h"
void print_menu()
{
	printf("1.Display rules \n");
	printf("2.Play game \n");
	printf("3.Exit \n");
}

void rolldice_array(int* dice, int size)
{
	for (int index = 0; index < size; index++)
	{
		dice[index] = rand() % 6 + 1;

	}
	printf("\nyou rolled!");
	printf("\ndice1: %d", dice[0]);
	printf(" dice2: %d", dice[1]);
	printf(" dice3: %d", dice[2]);
	printf(" dice4: %d", dice[3]);
	printf(" dice5: %d\n", dice[4]);
}
void search_dice(int* dice, int size, int* freq_table, int size1)
{
	for (int index = 0; index < size; index++)
	{
		if (dice[index] == 1)
		{
			freq_table[1] += 1;
		}
		if (dice[index] == 2)
		{
			freq_table[2] += 1;
		}
		if (dice[index] == 3)
		{
			freq_table[3] += 1;
		}
		if (dice[index] == 4)
		{
			freq_table[4] += 1;
		}
		if (dice[index] == 5)
		{
			freq_table[5] += 1;
		}
		if (dice[index] == 6)
		{
			freq_table[6] += 1;
		}
	}
	printf("\n time to pick your scoring method!\n");
	system("pause");
	system("cls");
	printf("\nyou rolled!");
	printf("\ndice 1: %d\n", dice[0]);
	printf("dice 2: %d\n", dice[1]);
	printf("dice 3: %d\n", dice[2]);
	printf("dice 4: %d\n", dice[3]);
	printf("dice 5: %d\n", dice[4]);

	printf("\n%d,", freq_table[1]);
	printf("%d,", freq_table[2]);
	printf("%d,", freq_table[3]);
	printf("%d,", freq_table[4]);
	printf("%d,", freq_table[5]);
	printf("\n%d,", freq_table[6]);

}

int table1(int freq_table[], int size, int pass, int score_card1[], int size1)
{
	for (int index = 0; index < size; index++)
	{
		if (freq_table[1] != 0)
		{
			pass = 1;
		}
		if (pass == 1)
		{
			score_card1[1] = freq_table[1] * 1;
		}
	}
	return pass;
}

int table2(int freq_table[], int size, int pass, int score_card1[], int size1)
{
	for (int index = 0; index < size; index++)
	{
		if (freq_table[2] != 0)
		{
			pass = 1;
		}
		if (pass == 1)
		{
			score_card1[2] = freq_table[2] * 2;
		}
	}
	return pass;
}

int table3(int freq_table[], int size, int pass, int score_card1[], int size1)
{
	for (int index = 0; index < size; index++)
	{
		if (freq_table[3] != 0)
		{
			pass = 1;
		}
		if (pass == 1)
		{
			score_card1[3] = freq_table[3] * 3;
		}
	}
	return pass;
}

int table4(int freq_table[], int size, int pass, int score_card1[], int size1)
{
	for (int index = 0; index < size; index++)
	{
		if (freq_table[4] != 0)
		{
			pass = 1;
		}
		if (pass == 1)
		{
			score_card1[4] = freq_table[4] * 4;
		}
	}
	return pass;
}

int table5(int freq_table[], int size, int pass, int score_card1[], int size1)
{
	for (int index = 0; index < size; index++)
	{
		if (freq_table[1] != 0)
		{
			pass = 1;
		}
		if (pass == 1)
		{
			score_card1[5] = freq_table[5] * 5;
		}
	}
	return pass;
}

int table6(int freq_table[], int size, int pass, int score_card1[], int size1)
{
	for (int index = 0; index < size; index++)
	{
		if (freq_table[6] != 0)
		{
			pass = 1;
		}
		if (pass == 1)
		{
			score_card1[6] = freq_table[6] * 6;
		}
	}
	return pass;
}

int table7(int freq_table[], int size, int pass, int score_card1[], int size1)
{
	int hold_index = 0; 

	if (freq_table[1] == 3)
	{
		pass = 1;
		hold_index = 1;
	}
	if (freq_table[2] == 3)
	{
		pass = 1;
		hold_index = 2;
	}
	if (freq_table[3] == 3)
	{
		pass = 1;
		hold_index = 3;
	}
	if (freq_table[4] == 3)
	{
		pass = 1;
		hold_index = 4;
	}
	if (freq_table[5] == 3)
	{
		pass = 1;
		hold_index = 5;
	}
	if (freq_table[6] == 3)
	{
		pass = 1;
		hold_index = 6;
	}
	if (pass == 1)
	{
		score_card1[7] = hold_index * 3;
	}
	return pass;
}


int table8(int freq_table[], int size, int pass, int score_card1[], int size1)
{
	int hold_index = 0;

	if (freq_table[1] == 4)
	{
		pass = 1;
		hold_index = 1;
	}
	if (freq_table[2] == 4)
	{
		pass = 1;
		hold_index = 2;
	}
	if (freq_table[3] == 4)
	{
		pass = 1;
		hold_index = 3;
	}
	if (freq_table[4] == 4)
	{
		pass = 1;
		hold_index = 4;
	}
	if (freq_table[5] == 4)
	{
		pass = 1;
		hold_index = 5;
	}
	if (freq_table[6] == 4)
	{
		pass = 1;
		hold_index = 6;
	}
	if (pass == 1)
	{
		score_card1[7] = hold_index * 4;
	}
	return pass;
}

int table9(int freq_table[], int size, int pass, int score_card1[], int size1)
{
	for (int index = 0; index < size; index++)
	{
		if (freq_table[index] == 3 && freq_table[index] == 2)
		{
			pass = 1;
			score_card1[9] = 25;
		}
	}
	return pass;
}

int table10(int freq_table[], int size, int pass, int score_card1[], int size1)
{
	int found = 0; 
	for (int index = 0; index < size; index++)
	{
		if (freq_table[index] == 1)
		{
			found++;
		}
		if (found > 3)
		{
			pass = 1;
			score_card1[10] = 30;
		}
	}
	return pass;
}

int table11(int freq_table[], int size, int pass, int score_card1[], int size1)
{
	int found = 0;
	for (int index = 0; index < size; index++)
	{
		if (freq_table[index] == 1)
		{
			found++;
		}
		if (found > 4)
		{
			pass = 1;
			score_card1[11] = 40;
		}
	}
	return pass;
}

int table12(int freq_table[], int size, int pass, int score_card1[], int size1)
{
	if (freq_table[1] == 5)
	{
		pass = 1;
	}
	if (freq_table[2] == 5)
	{
		pass = 1;
	}
	if (freq_table[3] == 5)
	{
		pass = 1;
	}
	if (freq_table[4] == 5)
	{
		pass = 1;
	}
	if (freq_table[5] == 5)
	{
		pass = 1;
	}
	if (freq_table[6] == 5)
	{
		pass = 1;
	}
	if (pass = 1)
	{
		score_card1[12] = 50;
		return pass;
	}
}

int adjust_score(int sum2)
{
	if (sum2 > 63);
	sum2 = sum2 + 35;
	return sum2;
}

int winner(int sum2, int sum4)
{
	if (sum2 > sum4)
	{
		printf("Player 1 wins!!!");
	}
	if (sum4 > sum2)
	{
		printf("Player 2 wins!!!");

	}
}



