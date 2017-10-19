#include "ComplexNumber.h"

ComplexNumber::ComplexNumber() :
	a {0},
	b {0}
{
}
 ComplexNumber::ComplexNumber(double a, double b) :
	a {a},
	b {b}
{
}

ComplexNumber::ComplexNumber(const ComplexNumber & nr) :
	a { nr.a },
	b { nr.b }
{
}

void ComplexNumber::setA(double a)
{
	this->a = a;
}

double ComplexNumber::getA() const
{
	return a;
}

void ComplexNumber::setB(double b)
{
	this->b = b;
}

double ComplexNumber::getB() const
{
	return b;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber & nr)
{
	return ComplexNumber(a + nr.a, b + nr.b);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber & nr)
{
	return ComplexNumber(a * nr.a - b * nr.b, a * nr.b + b * nr.a);
}

void ComplexNumber::operator=(const ComplexNumber & nr)
{
	this->a = nr.a;
	this->b = nr.b;
}

bool ComplexNumber::operator==(const ComplexNumber & nr) const
{
	return a == nr.getA() && b == nr.getB();
}

std::string ComplexNumber::toString()
{
	return std::to_string(a) + " " + std::to_string(b) + "i";
}