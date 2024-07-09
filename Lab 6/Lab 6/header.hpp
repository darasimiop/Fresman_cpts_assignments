#include <iostream>
#include <math.h>

#define i sqrt(-1)

class Complex
{
public:
	Complex(); // constructor 

	Complex(double, double);

	~Complex(); //destructor 

	double getReal(); // feteches real number

	double getImg(); // feteches an imaginary number - getter

	void setReal(double); //setter

	void setImg(double); //setter for imaginary number

	Complex add(Complex rhs);







private:

	double realnumber;
	double imaginenumber;
};

Complex add(Complex lhs, Complex rhs);
Complex operator+ (const Complex &lhs, const Complex &rhs);
Complex operator- (const Complex& lhs, const Complex& rhs);
Complex subtract(Complex lhs, Complex rhs);
