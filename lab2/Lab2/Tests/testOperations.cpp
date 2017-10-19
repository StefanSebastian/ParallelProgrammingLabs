#include "stdafx.h"
#include "CppUnitTest.h"

#include "Matrix.h"
#include "ComplexNumber.h"
#include "MatrixGenerator.h"
#include "ParallelCalculator.h"
#include "MatrixOperations.h"
#include "SerialMatrixOperations.h"

#include<iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace Tests
{


	TEST_CLASS(TestOperations)
	{
	public:

		TEST_METHOD(AddTwoIntMatrixes)
		{
			
			Logger::WriteMessage((std::string("Running 3x3 add int test")).c_str());
			MatrixGenerator mg = MatrixGenerator();
			Matrix<int> m1 = mg.getRandomIntMatrix(3, 3);
			Matrix<int> m2 = mg.getRandomIntMatrix(3, 3);
			Matrix<int> m3 = Matrix<int>(3, 3);
			ParallelCalculator<int>::calculate(m1, m2, m3, 3, MatrixOperations<int>::addition);

			Matrix<int> m4 = Matrix<int>(3, 3);
			SerialMatrixOperations<int>::calculate(m1, m2, m4, MatrixOperations<int>::addition);

			Assert::IsTrue(m3 == m4);
		}

		TEST_METHOD(AddTwoComplexMatrixes)
		{
			Logger::WriteMessage((std::string("Running 3x3 add complex test")).c_str());
			MatrixGenerator mg = MatrixGenerator();
			Matrix<ComplexNumber> m1 = mg.getRandomComplexNumberMatrix(3, 3);
			Matrix<ComplexNumber> m2 = mg.getRandomComplexNumberMatrix(3, 3);
			Matrix<ComplexNumber> m3 = Matrix<ComplexNumber>(3, 3);
			ParallelCalculator<ComplexNumber>::calculate(m1, m2, m3, 3, MatrixOperations<ComplexNumber>::addition);

			Matrix<ComplexNumber> m4 = Matrix<ComplexNumber>(3, 3);
			SerialMatrixOperations<ComplexNumber>::calculate(m1, m2, m4, MatrixOperations<ComplexNumber>::addition);

			Assert::IsTrue(m3 == m4);
		}

		TEST_METHOD(AddTwoIntMatrixes2)
		{
			Logger::WriteMessage((std::string("Running 1000x1000 add int test")).c_str());
			MatrixGenerator mg = MatrixGenerator();
			Matrix<int> m1 = mg.getRandomIntMatrix(1000, 1000);
			Matrix<int> m2 = mg.getRandomIntMatrix(1000, 1000);
			Matrix<int> m3 = Matrix<int>(1000, 1000);
			ParallelCalculator<int>::calculate(m1, m2, m3, 4, MatrixOperations<int>::addition);

			Matrix<int> m4 = Matrix<int>(1000, 1000);
			SerialMatrixOperations<int>::calculate(m1, m2, m4, MatrixOperations<int>::addition);

			Assert::IsTrue(m3 == m4);
		}
		


	};
}