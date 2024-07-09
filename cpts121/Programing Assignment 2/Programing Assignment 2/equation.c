#include "equation.h"

int calculate_series_resistance(int r1, int r2, int r3)
{
	return r1 + r2 +r3;
}
	double calculate_total_sales_tax(double sales_tax_rate, double item_cost)
	{
		return (sales_tax_rate * item_cost);
	}
	double calculate_volume_pyramid(double l, double w, double h)
	{
		
		return ((l * w * h) / 3);
	}
	double calculate_parallel_resistance(int r1, int r2, int r3)
	{
		return 1 / ((double)1 / r1 + (double)1 / r2 + (double)1 / r3);
	}

	char character_encoding(char plaintext_character, int shift_int) {
	return (plaintext_character - 'a') + ('A' - shift_int);
	}

	double calculate_distance(double x1, double x2, double y1, double y2)
	{
		return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
	}
	double calculate_general_equation(double x, double y, double z, int a)
	{

		return y = y / ((double)3 / 17) - z + x / (a % 2) + 3.14;
	}
