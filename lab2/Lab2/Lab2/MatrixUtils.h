#pragma once

#include"Matrix.h"
#include"ComplexNumber.h"

class __declspec(dllexport) MatrixUtils {
public:
	static std::string printIntMatrix(Matrix<int> m);
	static std::string printComplexMatrix(Matrix<ComplexNumber> m);
};