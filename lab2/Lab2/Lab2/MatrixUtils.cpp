#include "MatrixUtils.h"

std::string MatrixUtils::printIntMatrix(Matrix<int> m)
{
	std::string res = "";
	for (int i = 0; i < m.getRows(); i++) {
		for (int j = 0; j < m.getCols(); j++) {
			res += m.getElement(i, j);
			res += " ";
		}
		res += "\n";
	}
	return res;
}

std::string MatrixUtils::printComplexMatrix(Matrix<ComplexNumber> m)
{
	std::string res = "";
	for (int i = 0; i < m.getRows(); i++) {
		for (int j = 0; j < m.getCols(); j++) {
			res += m.getElement(i, j).toString();
			res += " ";
		}
		res += "\n";
	}
	return res;
}
