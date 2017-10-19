#pragma once
#include<iostream>
#include<thread>
#include<chrono>
#include "Matrix.h"

template <class T>
class __declspec(dllexport) ParallelCalculator {
private:
	void worker(Matrix<T>& m1, Matrix<T>& m2, Matrix<T>& result, int start, int end,
		std::function<T(Matrix<T>&, Matrix<T>&, int, int)> operatorFunction);
public:
	Matrix<T> calculate(Matrix<T>& m1, Matrix<T>& m2, Matrix<T>& result, int nrThreads,
		std::function<T(Matrix<T>&, Matrix<T>&, int, int)> operatorFunction);
};

template<class T>
inline void ParallelCalculator<T>::calculate(
	Matrix<T>& m1,
	Matrix<T>& m2,
	Matrix<T>& result,
	int nrThreads,
	std::function<T(Matrix<T>&, Matrix<T>&, int, int)> operatorFunction)
{
	int rows = result.getRows();
	int cols = result.getCols();
	int len = rows * cols;
	if (nrThreads < 1 or nrThreads > len) {
		std::cout << "Invalid number of threads";
		return null;
	}

	// timestamp
	auto startTime = std::chrono::high_resolution_clock::now();

	// thread operations 
	int elemPerThread = len / nrThreads;
	int extraElems = len % nrThreads;
	int start = 0; int end = elemPerThread;

	std::thread[] threads = new std::thread[nrThreads];
	for (int i = 0; i < nrThreads; i++) {
		if (i < extraElems) {
			end++; // consider the extra elements
		}

		threads[i] = std::thread(worker, m1, m2, result, start, end);

		start = end;
		end += elemPerThread;
	}

	for (int i = 0; i < nrThreads; i++) {
		threads[i].join();
	}

	// ending timestamp
	auto endTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = endTime - startTime;
	std::cout << "Time for parallel operations " << diff.count() << " s\n";
}

template<class T>
inline void ParallelCalculator<T>::worker(
	Matrix<T>& m1, 
	Matrix<T>& m2, 
	Matrix<T>& result, 
	int start, 
	int end, 
	std::function<T(Matrix<T>&, Matrix<T>&, int, int)> operatorFunction)
{
	int cols = result.getCols();
	int startRow = start / cols;
	int startCol = start % cols;
	int endRow = end / cols;
	int endCol = end % cols;

	int i = startRow; int j = startCol;
	while (!(i == endRow && j == endCol)) {

		result.setElement(i, j, operatorFunction(m1, m2, i, j));

		if (j < cols - 1) {
			j++;
		}
		else {
			j = 0;
			i++;
		}
	}
}
