#include "ComplexNumber.h"
#include "MatrixOperations.h"
#include "MatrixGenerator.h"
#include "MatrixUtils.h"
#include "ParallelCalculator.h"
#include "SerialMatrixOperations.h"

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

void intMatrixes(int r1, int c1, int r2, int c2, int thr, string operation) {
	MatrixGenerator mg = MatrixGenerator();
	Matrix<int> m1 = mg.getRandomIntMatrix(r1, c1);
	Matrix<int> m2 = mg.getRandomIntMatrix(r2, c2);
	MatrixUtils::writeIntMatrix("mat1.txt", m1);
	MatrixUtils::writeIntMatrix("mat2.txt", m2);

	if (operation == "+") {
		Matrix<int> ser = Matrix<int>(r1, c1);
		Matrix<int> par = Matrix<int>(r1, c1);

		double parT  = ParallelCalculator<int>::calculate(m1, m2, par, thr, MatrixOperations<int>::addition);
		double serT = SerialMatrixOperations<int>::calculate(m1, m2, ser, MatrixOperations<int>::addition);

		MatrixUtils::writeIntMatrix("parallel.txt", par);
		MatrixUtils::writeIntMatrix("serial.txt", ser);

		if (ser == par) {
			cout << "Valid result" << std::endl;
		}

		cout << "Parallel time " + std::to_string(parT) + " for " + std::to_string(thr) + " threads" << std::endl;
		cout << "Serial time " + std::to_string(serT) << std::endl;

		//int fin; cin >> fin;
	}
	if (operation == "*") {
		Matrix<int> ser = Matrix<int>(r1, c2);
		Matrix<int> par = Matrix<int>(r1, c2);

		double parT = ParallelCalculator<int>::calculate(m1, m2, par, thr, MatrixOperations<int>::multiplication);
		double serT = SerialMatrixOperations<int>::calculate(m1, m2, ser, MatrixOperations<int>::multiplication);

		MatrixUtils::writeIntMatrix("parallel.txt", par);
		MatrixUtils::writeIntMatrix("serial.txt", ser);

		if (ser == par) {
			cout << "Valid result" << std::endl;
		}

		cout << "Parallel time " + std::to_string(parT) + " for " + std::to_string(thr) + " threads" << std::endl;
		cout << "Serial time " + std::to_string(serT) << std::endl;

		//int fin; cin >> fin;
	}
}

void complexMatrixes(int r1, int c1, int r2, int c2, int thr, string operation) {
	MatrixGenerator mg = MatrixGenerator();
	Matrix<ComplexNumber> m1 = mg.getRandomComplexNumberMatrix(r1, c1);
	Matrix<ComplexNumber> m2 = mg.getRandomComplexNumberMatrix(r2, c2);
	MatrixUtils::writeComplexNrMatrix("mat1.txt", m1);
	MatrixUtils::writeComplexNrMatrix("mat2.txt", m2);

	if (operation == "+") {
		Matrix<ComplexNumber> ser = Matrix<ComplexNumber>(r1, c1);
		Matrix<ComplexNumber> par = Matrix<ComplexNumber>(r1, c1);

		double parT = ParallelCalculator<ComplexNumber>::calculate(m1, m2, par, thr, MatrixOperations<ComplexNumber>::addition);
		double serT = SerialMatrixOperations<ComplexNumber>::calculate(m1, m2, ser, MatrixOperations<ComplexNumber>::addition);

		MatrixUtils::writeComplexNrMatrix("parallel.txt", par);
		MatrixUtils::writeComplexNrMatrix("serial.txt", ser);

		if (ser == par) {
			cout << "Valid result" << std::endl;
		}

		cout << "Parallel time " + std::to_string(parT) + " for " + std::to_string(thr) + " threads" << std::endl;
		cout << "Serial time " + std::to_string(serT) << std::endl;


		//int fin; cin >> fin;
	}
	if (operation == "*") {
		Matrix<ComplexNumber> ser = Matrix<ComplexNumber>(r1, c2);
		Matrix<ComplexNumber> par = Matrix<ComplexNumber>(r1, c2);

		double parT = ParallelCalculator<ComplexNumber>::calculate(m1, m2, par, thr, MatrixOperations<ComplexNumber>::multiplication);
		double serT = SerialMatrixOperations<ComplexNumber>::calculate(m1, m2, ser, MatrixOperations<ComplexNumber>::multiplication);

		MatrixUtils::writeComplexNrMatrix("parallel.txt", par);
		MatrixUtils::writeComplexNrMatrix("serial.txt", ser);

		if (ser == par) {
			cout << "Valid result" << std::endl;
		}

		cout << "Parallel time " + std::to_string(parT) + " for " + std::to_string(thr) + " threads" << std::endl;
		cout << "Serial time " + std::to_string(serT) << std::endl;


		//int fin; cin >> fin;
	}
}

void runSimulation() {
	cout << "Matrix type: int / complex" << std::endl;
	string type;
	cin >> type;
	cout << "Matrix 1 dimensions : " << std::endl;
	int rows1, cols1;
	cin >> rows1 >> cols1;

	cout << "Matrix 2 dimensions : " << std::endl;
	int rows2, cols2;
	cin >> rows2 >> cols2;

	cout << "Number of threads : " << std::endl;
	int threads;
	cin >> threads;

	cout << "Operation (+/*) : " << std::endl;
	string operation;
	cin >> operation;

	if (type == "int") {
		intMatrixes(rows1, cols1, rows2, cols2, threads, operation);
	}
	else {
		complexMatrixes(rows1, cols1, rows2, cols2, threads, operation);
	}

	cout << std::endl << "-------------------------------" << std::endl;
	
}

int main() {
	while (1) {
		runSimulation();
	}
}