#include "header.h"
int main(void)
{
	int menu_option = 0, rolls = 1, /*combo_number*/score_method = 0, score_card1[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0}, rounds = 0, die1 = 0, die2 = 0, die3 = 0, die4 = 0, die5 = 0, sum = 0, player1_score = 0, player2_score = 0, sum2 = 0, sum3 = 0, sum4 = 0;
	char roll_again = '/0';
	int dice[5] = { 0,0,0,0,0 }, freq_table[7] = { 0 }, score_card2[14] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	srand((unsigned int)time(NULL));

	do {
		do {
			printf("Welcome to Yahtzee! Select an option\n");
			print_menu(); //displays game menu
			scanf("%d", &menu_option);
		} while (menu_option < DISPLAY || menu_option > EXIT);
		
		switch (menu_option)
		{
		case 1:
			printf("Here are the rules. ");
			printf("The scorecard used for Yahtzee is composed of two sections.");
			printf("A upper section and a lower section.");
			printf("A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.\n");
			printf("The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\n");
			printf("If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.\n");
			printf("Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.\n");
			printf("If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus.\n ");
			system("pause");
			system("cls");
			break;
			do
			{
		case 2:
			printf("ready play 1!\n");
			system("pause");
			freq_table[1] = 0;
			freq_table[2] = 0; //resets frequency table
			freq_table[3] = 0;
			freq_table[4] = 0;
			freq_table[5] = 0;
			freq_table[6] = 0;
			rolls = 0;


			rolldice_array(dice, 5); //rolling dice
			system("pause");
			do {
				if (rolls < 2)
				{
					roll_again = '/0';
					printf("would you like to roll again? please enter Y/N: ");
					scanf(" %c", &roll_again);
					if (roll_again == 'y' || roll_again == 'Y')
					{
						rolldice_array(dice, 5);
						rolls++;
						if (rolls == 2)
						{
							roll_again = 'n';
						}
					}
					if (roll_again == 'n' || roll_again == 'N')
					{
						search_dice(dice, 5, freq_table, 7);

					}
				}

			} while (roll_again == 'y' || roll_again == 'Y' && rolls < 3);
			int pass = 0;
			do
			{
				do {
					score_method = 0;
					printf("\n Select which combonation you would like to use: \n");
					printf("1.) sum of 1's\n");
					printf("2.) sum of 2's\n");
					printf("3.) sum of 3's\n");
					printf("4.) sum of 4's\n");
					printf("5.) sum of 5's\n");
					printf("6.) sum of 6's\n");
					printf("7.) three of a kind\n");
					printf("8.) four of a kind\n");
					printf("9.) full house\n");
					printf("10.) small straight\n");
					printf("11.) large straight\n");
					printf("12.) YAHTZEE\n");
					printf("13.) chance\n");
					scanf("%d", &score_method);
					system("cls");
				} while (score_method == 0 || score_method > 13);


				switch (score_method)
				{
				case 1:
					pass = table1(freq_table, 7, pass, score_card1, 14);  //checking if combonation is possible and calculating points/ updatind score card
					break;
				case 2:
					pass = table2(freq_table, 7, pass, score_card1, 14);
					break;
				case 3:
					pass = table3(freq_table, 7, pass, score_card1, 14);
					break;
				case 4:
					pass = table4(freq_table, 7, pass, score_card1, 14);
					break;
				case 5:
					pass = table5(freq_table, 7, pass, score_card1, 14);
					break;
				case 6:
					pass = table6(freq_table, 7, pass, score_card1, 14);
					break;
				case7:
					pass = table7(freq_table, 7, pass, score_card1, 14);
					break;
				case 8:
					pass = table8(freq_table, 7, pass, score_card1, 14);
					break;
				case 9:
					pass = table9(freq_table, 7, pass, score_card1, 14);
					break;
				case 10:
					pass = table10(freq_table, 7, pass, score_card1, 14);
					break;
				case 11:
					pass = table11(freq_table, 7, pass, score_card1, 14);
					break;
				case 12:
					pass = table12(freq_table, 7, pass, score_card1, 14);
					break;
				case 13:
					pass = 1;
					for (int index = 0; index < 5; index++)
					{
						sum = sum + dice[index];
					}
					score_card1[13] = sum;
					break;
				default: printf("error with input please try again\n");
				}
			} while (pass == 0);

			printf("\ncurrent player 1 score card: \n");
			printf("1.) sum of 1's: %d\n", score_card1[1]);
			printf("2.) sum of 2's: %d\n", score_card1[2]);
			printf("3.) sum of 3's: %d\n", score_card1[3]);
			printf("4.) sum of 4's: %d\n", score_card1[4]);
			printf("5.) sum of 5's: %d\n", score_card1[5]);
			printf("6.) sum of 6's: %d\n", score_card1[6]);
			printf("7.) three of a kind: %d\n", score_card1[7]);
			printf("8.) four of a kind: %d\n", score_card1[8]);
			printf("9.) full house: %d\n", score_card1[9]);
			printf("10.) small straight: %d\n", score_card1[10]);
			printf("11.) large straight: %d\n", score_card1[11]);
			printf("12.) YAHTZEE: %d\n", score_card1[12]);
			printf("13.) chance: %d\n", score_card1[13]);

			system("pause");
			system("cls");


			printf("\n ready player 2 \n");
			system("pause");

			freq_table[1] = 0;
			freq_table[2] = 0; //resets frequency table
			freq_table[3] = 0;
			freq_table[4] = 0;
			freq_table[5] = 0;
			freq_table[6] = 0;
			rolls = 0;


			rolldice_array(dice, 5); //rolling dice
			system("pause");
			do {
				if (rolls < 2)
				{
					roll_again = '/0';
					printf("would you like to roll again? please enter Y/N: ");
					scanf(" %c", &roll_again);
					if (roll_again == 'y' || roll_again == 'Y')
					{
						rolldice_array(dice, 5);
						rolls++;
						if (rolls == 2)
						{
							roll_again = 'n';
						}
					}
					if (roll_again == 'n' || roll_again == 'N')
					{
						search_dice(dice, 5, freq_table, 7);

					}
				}

			} while (roll_again == 'y' || roll_again == 'Y' && rolls < 3);
			 pass = 0;
			do
			{
				do {
					score_method = 0;
					printf("\n Select which combonation you would like to use: \n");
					printf("1.) sum of 1's\n");
					printf("2.) sum of 2's\n");
					printf("3.) sum of 3's\n");
					printf("4.) sum of 4's\n");
					printf("5.) sum of 5's\n");
					printf("6.) sum of 6's\n");
					printf("7.) three of a kind\n");
					printf("8.) four of a kind\n");
					printf("9.) full house\n");
					printf("10.) small straight\n");
					printf("11.) large straight\n");
					printf("12.) YAHTZEE\n");
					printf("13.) chance\n");
					scanf("%d", &score_method);
					system("cls");
				} while (score_method == 0 || score_method > 13);


				switch (score_method)
				{
				case 1:
					pass = table1(freq_table, 7, pass, score_card2, 14);  //checking if combonation is possible and calculating points/ updatind score card
					break;
				case 2:
					pass = table2(freq_table, 7, pass, score_card2, 14);
					break;
				case 3:
					pass = table3(freq_table, 7, pass, score_card2, 14);
					break;
				case 4:
					pass = table4(freq_table, 7, pass, score_card2, 14);
					break;
				case 5:
					pass = table5(freq_table, 7, pass, score_card2, 14);
					break;
				case 6:
					pass = table6(freq_table, 7, pass, score_card2, 14);
					break;
				case 7:
					pass = table7(freq_table, 7, pass, score_card2, 14);
					break;
				case 8:
					pass = table8(freq_table, 7, pass, score_card2, 14);
					break;
				case 9:
					pass = table9(freq_table, 7, pass, score_card2, 14);
					break;
				case 10:
					pass = table10(freq_table, 7, pass, score_card2, 14);
					break;
				case 11:
					pass = table11(freq_table, 7, pass, score_card2, 14);
					break;
				case 12:
					pass = table12(freq_table, 7, pass, score_card2, 14);
					break;
				case 13:
					pass = 1;
					for (int index = 0; index < 5; index++)
					{
						sum3 = sum3 + dice[index];
					}
					score_card2[13] = sum3;
					break;
				default: printf("error with input please try again\n");
				}
			} while (pass == 0);

			printf("\ncurrent player 1 score card: \n");
			printf("1.) sum of 1's: %d\n", score_card2[1]);
			printf("2.) sum of 2's: %d\n", score_card2[2]);
			printf("3.) sum of 3's: %d\n", score_card2[3]);
			printf("4.) sum of 4's: %d\n", score_card2[4]);
			printf("5.) sum of 5's: %d\n", score_card2[5]);
			printf("6.) sum of 6's: %d\n", score_card2[6]);
			printf("7.) three of a kind: %d\n", score_card2[7]);
			printf("8.) four of a kind: %d\n", score_card2[8]);
			printf("9.) full house: %d\n", score_card2[9]);
			printf("10.) small straight: %d\n", score_card2[10]);
			printf("11.) large straight: %d\n", score_card2[11]);
			printf("12.) YAHTZEE: %d\n", score_card2[12]);
			printf("13.) chance: %d\n", score_card2[13]);
			score_method = 0;
			system("pause");
			system("cls");





			rounds++;
			}
			while (rounds < 14);
			for (int index = 0; index < 5; index++) //gets play 1 final score
			{
				sum2 = sum2 + score_card1[index];
			}
			sum2 = adjust_score(sum2);
			printf("\nplayer 1 final score: %d\n", sum2);

			for (int index = 0; index < 5; index++) //gets play 2 final score
			{
				sum4 = sum4 + score_card2[index];
			}
			sum4 = adjust_score(sum4);

			winner(sum2, sum4);   //decides winner
			printf("\nplayer 1 final score: %d\n", sum4);
			break;
		case 3:
			printf("Goodbye");
			break;
		default: printf("input error, try again \n");
			break;
		}
	
	} while (menu_option == PLAY || menu_option == DISPLAY);
	return 0;
}
