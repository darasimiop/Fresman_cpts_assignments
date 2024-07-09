#include "equation.h"

int main(void)
{
	int r1 = 0, r2 = 0, r3 = 0;
	printf("Enter R1: ");
	scanf("%d", &r1);
	printf("Enter R2: ");
	scanf("%d", &r2);
	printf("Enter R3: ");
	scanf("%d", &r3);	
	
	printf("Your series resistance is: %d\n", calculate_series_resistance(r1, r2, r3));
	
	double total_sales_tax = 0.0, sales_tax_rate = 0.0, item_cost = 0.0;
	printf("Enter sales_tax_rate: ");
	scanf("%lf", &sales_tax_rate);
	printf("Enter item_cost: ");
	scanf("%lf", &item_cost);
	printf("\ntotal sales tax is: %.2lf\n", calculate_total_sales_tax(sales_tax_rate, item_cost));
	
	
	double l = 0.0, w = 0.0, h = 0.0, volume_pyramid = 0.0;
    printf("Enter length: ");
	scanf("%lf", &l);
	printf("Enter width: ");
	scanf("%lf", &w);
	printf("Enter height: ");
	scanf("%lf", &h);
	printf("Your volume is: %.2lf\n", calculate_volume_pyramid(l, w, h));


	//Parallel Resistance
	printf("\nPlease enter three resistance values (all integers) for use in\n");
	scanf("%d%d%d", &r1, &r2, &r3);
	printf("Your Parallel resistance is: %.2lf", calculate_parallel_resistance(r1, r2, r3));
	
	char plaintext_character;
	int shift_int= 0;
	printf("\nPlease enter the plaintext character and shift key for use in a character encoding equation respectively: ");
	scanf(" %c%d", &plaintext_character, &shift_int);
	printf("Encoded Character %c \n", character_encoding(plaintext_character, shift_int));


	//calculate distance
	double x1, x2, y1, y2;
	printf("Please enter double x1, double y1, double x2, double y2\n");

	scanf("%lf%lf%lf%lf", &x1, &x2, &y1, &y2);
	printf("Distance Equation = : %.2lf\n", calculate_distance(x1, x2, y1, y2));


	double x = 0.0, y = 0.0, z = 0.0;
	int a = 0;
		printf("\nPlease enter x, y, and z (all floating_point values) and a (an integer value)\n");
		scanf("%lf%lf%lf%d", &x, &y, &z, &a);
		printf("general equation: y = y / (3/17) - z + x / (a %% 2) + PI  = %.2lf \n", calculate_general_equation(x, y, z, a));   


	return (0);


 }
