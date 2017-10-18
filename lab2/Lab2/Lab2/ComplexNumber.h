#pragma once

#include<string>
using std::string;
using std::to_string;

class ComplexNumber {
private:
	double a;
	double b;
public:
	void setA(double _a);
	double getA();
	void setB(double _b);
	double getB();

	ComplexNumber operator+(const ComplexNumber& nr);
	ComplexNumber operator*(const ComplexNumber& nr);

	string toString();
};