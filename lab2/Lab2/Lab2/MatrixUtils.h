#pragma once

#include"Matrix.h"
#include"ComplexNumber.h"

#include<fstream>

class __declspec(dllexport) MatrixUtils {
public:
	static std::string printIntMatrix(Matrix<int> m);
	static std::string printComplexMatrix(Matrix<ComplexNumber> m);
	static Matrix<int> readIntMatrix(std::string path);
	static Matrix<ComplexNumber> readComplexNrMatrix(std::string path);
	static void writeIntMatrix(std::string path, Matrix<int>& m);
	static void writeComplexNrMatrix(std::string path, Matrix<ComplexNumber>& m);
	static ComplexNumber parseComplexNumber(std::string number);
};