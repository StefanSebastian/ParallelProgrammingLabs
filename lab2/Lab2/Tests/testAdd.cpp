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

	TEST_CLASS(TestAdd)
	{
	public:

		TEST_METHOD(AddTwoIntMatrixes)
		{
			
			Logger::WriteMessage((std::string("Running 3x3 add int test")).c_str());
			MatrixGenerator mg = MatrixGenerator();

			Matrix<int> m1 = mg.getRandomIntMatrix(3, 3);
			Matrix<int> m2 = mg.getRandomIntMatrix(3, 3);
		

			Matrix<int> m3 = Matrix<int>(3, 3);
			double parT = ParallelCalculator<int>::calculate(m1, m2, m3, 3, MatrixOperations<int>::addition);

			Matrix<int> m4 = Matrix<int>(3, 3);
			double serialT = SerialMatrixOperations<int>::calculate(m1, m2, m4, MatrixOperations<int>::addition);

			Assert::IsTrue(m3 == m4);

			Logger::WriteMessage((std::to_string(parT) + " for 3 threads").c_str());
			Logger::WriteMessage((std::to_string(serialT) + " for serial operations").c_str());
		}

		TEST_METHOD(AddTwoComplexMatrixes)
		{
			Logger::WriteMessage((std::string("Running 3x3 add complex test")).c_str());
			MatrixGenerator mg = MatrixGenerator();
			Matrix<ComplexNumber> m1 = mg.getRandomComplexNumberMatrix(3, 3);
			Matrix<ComplexNumber> m2 = mg.getRandomComplexNumberMatrix(3, 3);
			Matrix<ComplexNumber> m3 = Matrix<ComplexNumber>(3, 3);
			double parT = ParallelCalculator<ComplexNumber>::calculate(m1, m2, m3, 3, MatrixOperations<ComplexNumber>::addition);

			Matrix<ComplexNumber> m4 = Matrix<ComplexNumber>(3, 3);
			double serialT = SerialMatrixOperations<ComplexNumber>::calculate(m1, m2, m4, MatrixOperations<ComplexNumber>::addition);

			Assert::IsTrue(m3 == m4);
			Logger::WriteMessage((std::to_string(parT) + " for 3 threads").c_str());
			Logger::WriteMessage((std::to_string(serialT) + " for serial operations").c_str());
		}

		TEST_METHOD(AddTwoInt3)
		{
			Logger::WriteMessage((std::string("Running 3x3 add int test")).c_str());
			MatrixGenerator mg = MatrixGenerator();

			std::vector<std::vector<int>> m1Values = { {1, 2, 3}, {1, 2, 3}, {1, 2, 3} };
			std::vector<std::vector<int>> m2Values = { { 1, 2, 3 },{ 1, 2, 3 },{ 1, 2, 3 } };

			Matrix<int> m1 = Matrix<int>(3, 3);
			m1.setData(m1Values);
			Matrix<int> m2 = Matrix<int>(3, 3);
			m2.setData(m2Values);

			std::vector<std::vector<int>> expectedValues = { {2,4,6}, {2,4,6}, {2,4,6} };
			Matrix<int> expected = Matrix<int>(3, 3);
			expected.setData(expectedValues);

			Matrix<int> m3 = Matrix<int>(3, 3);
			double parT = ParallelCalculator<int>::calculate(m1, m2, m3, 3, MatrixOperations<int>::addition);

			Matrix<int> m4 = Matrix<int>(3, 3);
			double serialT = SerialMatrixOperations<int>::calculate(m1, m2, m4, MatrixOperations<int>::addition);

			Assert::IsTrue(m3 == m4);
			Assert::IsTrue(m3 == expected);
			Assert::IsTrue(m4 == expected);

			Logger::WriteMessage((std::to_string(parT) + " for 3 threads").c_str());
			Logger::WriteMessage((std::to_string(serialT) + " for serial operations").c_str());
		}

		TEST_METHOD(AddTwoInt4)
		{
			Logger::WriteMessage((std::string("Running 2x4 add int test")).c_str());
			MatrixGenerator mg = MatrixGenerator();

			std::vector<std::vector<int>> m1Values = { { 1, 2, 3, 4 },{ -2, 2, 5, 3 } };
			std::vector<std::vector<int>> m2Values = { { 6, 2, 4, 0 },{ 1, 2, 5, 5 } };

			Matrix<int> m1 = Matrix<int>(2, 4);
			m1.setData(m1Values);
			Matrix<int> m2 = Matrix<int>(2, 4);
			m2.setData(m2Values);

			std::vector<std::vector<int>> expectedValues = { {7, 4, 7, 4}, {-1, 4, 10, 8} };
			Matrix<int> expected = Matrix<int>(2, 4);
			expected.setData(expectedValues);

			Matrix<int> m3 = Matrix<int>(2, 4);
			double parT = ParallelCalculator<int>::calculate(m1, m2, m3, 2, MatrixOperations<int>::addition);

			Matrix<int> m4 = Matrix<int>(2, 4);
			double serialT = SerialMatrixOperations<int>::calculate(m1, m2, m4, MatrixOperations<int>::addition);

			Assert::IsTrue(m3 == m4);
			Assert::IsTrue(m3 == expected);
			Assert::IsTrue(m4 == expected);

			Logger::WriteMessage((std::to_string(parT) + " for 2 threads").c_str());
			Logger::WriteMessage((std::to_string(serialT) + " for serial operations").c_str());
		}

		TEST_METHOD(AddTwoComplexMatrixes2) {
			Logger::WriteMessage((std::string("Running 2x2 add complex test")).c_str());
			MatrixGenerator mg = MatrixGenerator();

			std::vector<std::vector<ComplexNumber>> m1Values = { { ComplexNumber(1,1), ComplexNumber(1,-1) },{ ComplexNumber(2,2), ComplexNumber(4,4) } };
			std::vector<std::vector<ComplexNumber>> m2Values = { { ComplexNumber(2,2), ComplexNumber(3,3) },{ ComplexNumber(4,-4), ComplexNumber(2,-2) } };
			Matrix<ComplexNumber> m1 = Matrix<ComplexNumber>(2, 2);
			Matrix<ComplexNumber> m2 = Matrix<ComplexNumber>(2, 2);
			Matrix<ComplexNumber> m3 = Matrix<ComplexNumber>(2, 2);
			double parT = ParallelCalculator<ComplexNumber>::calculate(m1, m2, m3, 2, MatrixOperations<ComplexNumber>::addition);

			Matrix<ComplexNumber> m4 = Matrix<ComplexNumber>(2, 2);
			double serialT = SerialMatrixOperations<ComplexNumber>::calculate(m1, m2, m4, MatrixOperations<ComplexNumber>::addition);

			Assert::IsTrue(m3 == m4);

			std::vector<std::vector<ComplexNumber>> expectedValues = { { ComplexNumber(3,3), ComplexNumber(4,2) },{ ComplexNumber(6,-2), ComplexNumber(6,2) } };
			Matrix<ComplexNumber> expected = Matrix<ComplexNumber>(2, 2);
			Assert::IsTrue(m3 == expected);
			Assert::IsTrue(m4 == expected);

			Logger::WriteMessage((std::to_string(parT) + " for 2 threads").c_str());
			Logger::WriteMessage((std::to_string(serialT) + " for serial operations").c_str());
		}

		TEST_METHOD(AddTwoIntMatrixes2)
		{
			Logger::WriteMessage((std::string("Running 1000x1000 add int test")).c_str());
			MatrixGenerator mg = MatrixGenerator();
			Matrix<int> m1 = mg.getRandomIntMatrix(1000, 1000);
			Matrix<int> m2 = mg.getRandomIntMatrix(1000, 1000);
			Matrix<int> m3 = Matrix<int>(1000, 1000);
			double parT = ParallelCalculator<int>::calculate(m1, m2, m3, 4, MatrixOperations<int>::addition);

			Matrix<int> m4 = Matrix<int>(1000, 1000);
			double serialT = SerialMatrixOperations<int>::calculate(m1, m2, m4, MatrixOperations<int>::addition);

			Assert::IsTrue(m3 == m4);

			Logger::WriteMessage((std::to_string(parT) + " for 4 threads").c_str());
			Logger::WriteMessage((std::to_string(serialT) + " for serial operations").c_str());
		}
		
		TEST_METHOD(AddTwoComplexMatrixes3)
		{
			Logger::WriteMessage((std::string("Running 1000x1000 add complex test")).c_str());
			MatrixGenerator mg = MatrixGenerator();
			Matrix<ComplexNumber> m1 = mg.getRandomComplexNumberMatrix(1000, 1000);
			Matrix<ComplexNumber> m2 = mg.getRandomComplexNumberMatrix(1000, 1000);
			Matrix<ComplexNumber> m3 = Matrix<ComplexNumber>(1000, 1000);
			double parT = ParallelCalculator<ComplexNumber>::calculate(m1, m2, m3, 8, MatrixOperations<ComplexNumber>::addition);

			Matrix<ComplexNumber> m4 = Matrix<ComplexNumber>(1000, 1000);
			double serialT = SerialMatrixOperations<ComplexNumber>::calculate(m1, m2, m4, MatrixOperations<ComplexNumber>::addition);

			Assert::IsTrue(m3 == m4);

			Logger::WriteMessage((std::to_string(parT) + " for 8 threads").c_str());
			Logger::WriteMessage((std::to_string(serialT) + " for serial operations").c_str());
		}

	};
}