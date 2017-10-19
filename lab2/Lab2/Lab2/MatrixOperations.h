#pragma once

#include "Matrix.h"

/*
Defines a set of matrix operations
*/
template <class T>
class __declspec(dllexport) MatrixOperations {
public:
	static T addition(Matrix<T>& m1, Matrix<T>& m2, int i, int j);

	static T multiplication(Matrix<T>& m1, Matrix<T>& m2, int i, int j);
};

template<class T>
inline T MatrixOperations<T>::addition(Matrix<T>& m1, Matrix<T>& m2, int i, int j)
{
	if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols()) {
		std::cout << "Invalid input";
		throw std::invalid_argument("Matrixes should have the same size");
	}
	return m1.getElement(i, j) + m2.getElement(i, j);
}

template<class T>
inline T MatrixOperations<T>::multiplication(Matrix<T>& m1, Matrix<T>& m2, int i, int j)
{
	return T(); // to do
}
