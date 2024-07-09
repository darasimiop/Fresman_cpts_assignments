/*
* Programmer: Darsimi Ogunbinu-Peters
* Description: Lab 6
* Date: 2/23/23
*/
#include "header.hpp"
int main(void)
{
	Complex set1(10, sqrt(2)), set2(20, sqrt(5)), set3;
	Complex result1;
	Complex result2;
	Complex result3;
	Complex result4;


	set3 = set2;

	set1.setReal(5);
	set3.setReal(10);
	set3.setImg(sqrt(15));
 

	result1 = set3.add(set3);
	result2 = set1.add(set1);
	result3 = set3 + set3;
	result4 = set3 - set3;
	
	
	
	
	return 0;
}