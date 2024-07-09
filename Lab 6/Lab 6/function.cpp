#include "header.hpp"
Complex::Complex()// default constructor
{
	realnumber = imaginenumber = 0.0;
}

Complex::Complex(double a, double b)
{
	a = realnumber;
	b = imaginenumber;
}

Complex::~Complex()// destructor
{

}

double Complex::getReal()
{
	return realnumber;
}

double Complex::getImg()
{
	return 0.0;
}

void Complex::setReal(double num)
{
	realnumber = num;
}

void Complex::setImg(double num)
{
	imaginenumber = num;
}

Complex Complex::add(Complex rhs)
{
	realnumber += rhs.getReal();

	return *this;
}

Complex add(Complex lhs, Complex rhs) 
{
	Complex result;

	result.setReal(lhs.getReal() + rhs.getReal());
	result.setImg(lhs.getImg() + rhs.getImg());

	return result;

}

Complex subtract(Complex lhs, Complex rhs)
{
	Complex result;

	result.setReal(lhs.getReal() - rhs.getReal());
	result.setImg(lhs.getImg() - rhs.getImg());

	return result;

}

Complex operator+ (const Complex& lhs, const Complex& rhs)
{
	return add(lhs, rhs);
}

Complex operator- (const Complex& lhs, const Complex& rhs)
{
	return subtract(lhs, rhs);
}