#include "stdafx.h"
#include "CppUnitTest.h"

#include "Matrix.h"
#include "ComplexNumber.h"
#include "MatrixGenerator.h"
#include "ParallelCalculator.h"
#include "MatrixOperations.h"
#include "SerialMatrixOperations.h"
#include "MatrixUtils.h"

#include<iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace Tests
{

	TEST_CLASS(TestMultiply)
	{
	public:

		TEST_METHOD(MutiplyTwoIntMatrixes)
		{

			Logger::WriteMessage((std::string("Running 3x3 multiply int test")).c_str());
			MatrixGenerator mg = MatrixGenerator();

			Matrix<int> m1 = mg.getRandomIntMatrix(3, 3);
			Matrix<int> m2 = mg.getRandomIntMatrix(3, 3);


			Matrix<int> m3 = Matrix<int>(3, 3);
			double parT = ParallelCalculator<int>::calculate(m1, m2, m3, 3, MatrixOperations<int>::multiplication);

			Matrix<int> m4 = Matrix<int>(3, 3);
			double serialT = SerialMatrixOperations<int>::calculate(m1, m2, m4, MatrixOperations<int>::multiplication);

			Assert::IsTrue(m3 == m4);

			Logger::WriteMessage((std::to_string(parT) + " for 3 threads").c_str());
			Logger::WriteMessage((std::to_string(serialT) + " for serial operations").c_str());
		}

		TEST_METHOD(MultiplyTwoComplexMatrixes)
		{
			Logger::WriteMessage((std::string("Running 3x3 multiply complex test")).c_str());
			MatrixGenerator mg = MatrixGenerator();
			Matrix<ComplexNumber> m1 = mg.getRandomComplexNumberMatrix(3, 3);
			Matrix<ComplexNumber> m2 = mg.getRandomComplexNumberMatrix(3, 3);
			Matrix<ComplexNumber> m3 = Matrix<ComplexNumber>(3, 3);
			double parT = ParallelCalculator<ComplexNumber>::calculate(m1, m2, m3, 5, MatrixOperations<ComplexNumber>::multiplication);

			Matrix<ComplexNumber> m4 = Matrix<ComplexNumber>(3, 3);
			double serialT = SerialMatrixOperations<ComplexNumber>::calculate(m1, m2, m4, MatrixOperations<ComplexNumber>::multiplication);

			Assert::IsTrue(m3 == m4);

			Logger::WriteMessage((std::to_string(parT) + " for 5 threads").c_str());
			Logger::WriteMessage((std::to_string(serialT) + " for serial operations").c_str());
		}

		TEST_METHOD(MultiplyTwoInt2)
		{
			Logger::WriteMessage((std::string("Running 4x2 2x3 multiply int test")).c_str());
			MatrixGenerator mg = MatrixGenerator();

			std::vector<std::vector<int>> m1Values = { { 1, 2 },{ 2, 3 },{ 2, 3 }, {-1, -1} };
			std::vector<std::vector<int>> m2Values = { { 1, 2, 3 },{ 1, 2, 3 } };

			Matrix<int> m1 = Matrix<int>(4, 2);
			m1.setData(m1Values);
			Matrix<int> m2 = Matrix<int>(2, 3);
			m2.setData(m2Values);

			std::vector<std::vector<int>> expectedValues = { { 3,6,9 },{ 5,10,15 },{ 5,10,15 }, {-2,-4,-6} };
			Matrix<int> expected = Matrix<int>(4, 3);
			expected.setData(expectedValues);

			Matrix<int> m3 = Matrix<int>(4, 3);
			double parT = ParallelCalculator<int>::calculate(m1, m2, m3, 8, MatrixOperations<int>::multiplication);

			Matrix<int> m4 = Matrix<int>(4, 3);
			double serialT = SerialMatrixOperations<int>::calculate(m1, m2, m4, MatrixOperations<int>::multiplication);

			Assert::IsTrue(m3 == m4);
			Assert::IsTrue(m3 == expected);
			Assert::IsTrue(m4 == expected);

			Logger::WriteMessage((std::to_string(parT) + " for 8 threads").c_str());
			Logger::WriteMessage((std::to_string(serialT) + " for serial operations").c_str());
		}

		

		TEST_METHOD(MultiplyTwoComplexMatrixes2) {
			Logger::WriteMessage((std::string("Running 2x2 multiply complex test")).c_str());
			MatrixGenerator mg = MatrixGenerator();

			std::vector<std::vector<ComplexNumber>> m1Values = { { ComplexNumber(1,1), ComplexNumber(1,-1) },{ ComplexNumber(2,2), ComplexNumber(4,4) } };
			std::vector<std::vector<ComplexNumber>> m2Values = { { ComplexNumber(2,2), ComplexNumber(3,3) },{ ComplexNumber(4,-4), ComplexNumber(2,-2) } };
			Matrix<ComplexNumber> m1 = Matrix<ComplexNumber>(2, 2);
			Matrix<ComplexNumber> m2 = Matrix<ComplexNumber>(2, 2);
			Matrix<ComplexNumber> m3 = Matrix<ComplexNumber>(2, 2);
			double parT = ParallelCalculator<ComplexNumber>::calculate(m1, m2, m3, 2, MatrixOperations<ComplexNumber>::multiplication);

			Matrix<ComplexNumber> m4 = Matrix<ComplexNumber>(2, 2);
			double serialT = SerialMatrixOperations<ComplexNumber>::calculate(m1, m2, m4, MatrixOperations<ComplexNumber>::multiplication);

			Assert::IsTrue(m3 == m4);

			std::vector<std::vector<ComplexNumber>> expectedValues = { { ComplexNumber(0,-4), ComplexNumber(0,2) },{ ComplexNumber(32,8), ComplexNumber(16,12) } };
			Matrix<ComplexNumber> expected = Matrix<ComplexNumber>(2, 2);
			Assert::IsTrue(m3 == expected);
			Assert::IsTrue(m4 == expected);

			Logger::WriteMessage((std::to_string(parT) + " for 2 threads").c_str());
			Logger::WriteMessage((std::to_string(serialT) + " for serial operations").c_str());
		}

		TEST_METHOD(MultiplyTwoIntMatrixes3)
		{
			Logger::WriteMessage((std::string("Running 1000x1000 multiply int test")).c_str());
			MatrixGenerator mg = MatrixGenerator();
			Matrix<int> m1 = mg.getRandomIntMatrix(1000, 1000);
			Matrix<int> m2 = mg.getRandomIntMatrix(1000, 1000);
			Matrix<int> m3 = Matrix<int>(1000, 1000);
			double parT = ParallelCalculator<int>::calculate(m1, m2, m3, 4, MatrixOperations<int>::multiplication);

			Matrix<int> m4 = Matrix<int>(1000, 1000);
			double serialT = SerialMatrixOperations<int>::calculate(m1, m2, m4, MatrixOperations<int>::multiplication);

			Assert::IsTrue(m3 == m4);
			Logger::WriteMessage((std::to_string(parT) + " for 4 threads").c_str());
			Logger::WriteMessage((std::to_string(serialT) + " for serial operations").c_str());
		}

		TEST_METHOD(MultiplyTwoIntMatrixes4)
		{
			Logger::WriteMessage((std::string("Running 1000x1000 multiply int test")).c_str());
			MatrixGenerator mg = MatrixGenerator();
			Matrix<int> m1 = mg.getRandomIntMatrix(2000, 1000);
			Matrix<int> m2 = mg.getRandomIntMatrix(1000, 2000);
			Matrix<int> m3 = Matrix<int>(2000, 2000);
			double parT = ParallelCalculator<int>::calculate(m1, m2, m3, 6, MatrixOperations<int>::multiplication);

			Matrix<int> m4 = Matrix<int>(2000, 2000);
			double serialT = SerialMatrixOperations<int>::calculate(m1, m2, m4, MatrixOperations<int>::multiplication);

			Assert::IsTrue(m3 == m4);

			Logger::WriteMessage((std::to_string(parT) + " for 6 threads").c_str());
			Logger::WriteMessage((std::to_string(serialT) + " for serial operations").c_str());
		}

		TEST_METHOD(MultiplyTwoComplexMatrixes3)
		{
			Logger::WriteMessage((std::string("Running 1000x1000 multiply complex test")).c_str());
			MatrixGenerator mg = MatrixGenerator();
			Matrix<ComplexNumber> m1 = mg.getRandomComplexNumberMatrix(1000, 1000);
			Matrix<ComplexNumber> m2 = mg.getRandomComplexNumberMatrix(1000, 1000);
			Matrix<ComplexNumber> m3 = Matrix<ComplexNumber>(1000, 1000);
			double parT = ParallelCalculator<ComplexNumber>::calculate(m1, m2, m3, 10, MatrixOperations<ComplexNumber>::multiplication);

			Matrix<ComplexNumber> m4 = Matrix<ComplexNumber>(1000, 1000);
			double serialT = SerialMatrixOperations<ComplexNumber>::calculate(m1, m2, m4, MatrixOperations<ComplexNumber>::multiplication);

			Assert::IsTrue(m3 == m4);

			Logger::WriteMessage((std::to_string(parT) + " for 10 threads").c_str());
			Logger::WriteMessage((std::to_string(serialT) + " for serial operations").c_str());
		}

		void runIntSimulation(int nrTh, int r, int c) {
			Logger::WriteMessage(std::string("int data for " + std::to_string(nrTh) + " threads").c_str());
			Logger::WriteMessage((std::string("Running" + std::to_string(r) + "x" + std::to_string(c) + " multiply test")).c_str());
			MatrixGenerator mg = MatrixGenerator();

			Matrix<int> m1 = mg.getRandomIntMatrix(r, c);
			Matrix<int> m2 = mg.getRandomIntMatrix(r, c);


			Matrix<int> m3 = Matrix<int>(r, c);
			double parT = ParallelCalculator<int>::calculate(m1, m2, m3, nrTh, MatrixOperations<int>::multiplication);

			Matrix<int> m4 = Matrix<int>(r, c);
			double serialT = SerialMatrixOperations<int>::calculate(m1, m2, m4, MatrixOperations<int>::multiplication);

			Assert::IsTrue(m3 == m4);

			Logger::WriteMessage((std::to_string(parT) + " for " + std::to_string(nrTh) + " threads").c_str());
			Logger::WriteMessage((std::to_string(serialT) + " for serial operations").c_str());
			Logger::WriteMessage(std::string("---------------------------------------------").c_str());
		}

		TEST_METHOD(intSimulation)
		{
			for (int i = 2; i <= 8; i += 2) {
				runIntSimulation(i, 1000, 1000);
			}
		}

		void runComplexSimulation(int nrTh, int r, int c) {
			Logger::WriteMessage(std::string("complex number data for " + std::to_string(nrTh) + " threads").c_str());
			Logger::WriteMessage((std::string("Running" + std::to_string(r) + "x" + std::to_string(c) + " multiply test")).c_str());
			MatrixGenerator mg = MatrixGenerator();

			Matrix<ComplexNumber> m1 = mg.getRandomComplexNumberMatrix(r, c);
			Matrix<ComplexNumber> m2 = mg.getRandomComplexNumberMatrix(r, c);


			Matrix<ComplexNumber> m3 = Matrix<ComplexNumber>(r, c);
			double parT = ParallelCalculator<ComplexNumber>::calculate(m1, m2, m3, nrTh, MatrixOperations<ComplexNumber>::multiplication);

			Matrix<ComplexNumber> m4 = Matrix<ComplexNumber>(r, c);
			double serialT = SerialMatrixOperations<ComplexNumber>::calculate(m1, m2, m4, MatrixOperations<ComplexNumber>::multiplication);

			Assert::IsTrue(m3 == m4);

			Logger::WriteMessage((std::to_string(parT) + " for " + std::to_string(nrTh) + " threads").c_str());
			Logger::WriteMessage((std::to_string(serialT) + " for serial operations").c_str());
			Logger::WriteMessage(std::string("------------------------------------------------").c_str());
		}

		TEST_METHOD(complexSimulation)
		{
			for (int i = 2; i <= 8; i += 2) {
				runIntSimulation(i, 1000, 1000);
			}
		}

	};
}