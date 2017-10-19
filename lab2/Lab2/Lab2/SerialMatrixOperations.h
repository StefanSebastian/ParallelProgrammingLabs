#pragma once

#include "Matrix.h"
#include<functional>

template <class T>
class __declspec(dllexport) SerialMatrixOperations{
public:
	static void calculate(Matrix<T>& m1, Matrix<T>& m2, Matrix<T>& res,
		std::function<T(Matrix<T>&, Matrix<T>&, int, int)> operatorFunction);
};

template <class T>
inline void SerialMatrixOperations<T>::calculate(
	Matrix<T>& m1, 
	Matrix<T>& m2, 
	Matrix<T>& res, 
	std::function<T(Matrix<T>&, Matrix<T>&, int, int)> operatorFunction)
{

	// timestamp
	auto startTime = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < res.getRows(); i++) {
		for (int j = 0; j < res.getCols(); j++) {
			res.setElement(i, j, operatorFunction(m1, m2, i, j));
		}
	}

	// ending timestamp
	auto duration = std::chrono::high_resolution_clock::now() - startTime;
	double time = std::chrono::duration<double, std::milli>(duration).count();
	Logger::WriteMessage((std::to_string(time) + " serial").c_str());

}
