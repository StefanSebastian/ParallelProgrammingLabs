#pragma once

#include "Matrix.h"

/*
Defines a set of matrix operations
*/
template <class T>
class __declspec(dllexport) MatrixOperations {
public:
	static T addition(Matrix<T>& m1, Matrix<T>& m2, int i, int j);
};

template<class T>
inline T MatrixOperations<T>::addition(Matrix<T>& m1, Matrix<T>& m2, int i, int j)
{
	return m1.getElement(i, j) + m2.getElement(i, j);
}
