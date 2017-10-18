#include "ComplexNumber.h"

void ComplexNumber::setA(double _a)
{
	a = _a;
}

double ComplexNumber::getA()
{
	return a;
}

void ComplexNumber::setB(double _b)
{
	b = _b;
}

double ComplexNumber::getB()
{
	return b;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber & nr)
{
	ComplexNumber result;
	result.a = a + nr.a;
	result.b = b + nr.b;
	return result;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber & nr)
{
	ComplexNumber result;
	result.a = a * nr.a - b * nr.b;
	result.b = a * nr.b + b * nr.a;
	return result;
}

string ComplexNumber::toString()
{
	return to_string(a) + " " + to_string(b) + "i";
}
