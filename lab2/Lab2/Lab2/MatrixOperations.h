#pragma once

#include "Matrix.h"

/*
Defines a set of matrix operations
*/
template <class T>
class __declspec(dllexport) MatrixOperations {
public:
	static T addition(Matrix<T>& m1, Matrix<T>& m2, int i, int j);

	static T multiplication(Matrix<T>& m1, Matrix<T>& m2, int idx1, int idx2);
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
inline T MatrixOperations<T>::multiplication(Matrix<T>& m1, Matrix<T>& m2, int idx1, int idx2)
{
	if (m1.getCols() != m2.getRows()) {
		std::cout << "Invalid input";
		throw std::invalid_argument("The columns for the first matrix should match the rows for the second");
	}
	T product = T();
	for (int i = 0; i < m1.getCols(); i++) {
		product = product + m1.getElement(idx1, i) * m2.getElement(i, idx2);
	}
	return product;
}
