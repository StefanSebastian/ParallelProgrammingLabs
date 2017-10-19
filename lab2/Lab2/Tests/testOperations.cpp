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
			MatrixGenerator mg = MatrixGenerator();
			Matrix<int> m1 = mg.getRandomIntMatrix(3, 3);
			Matrix<int> m2 = mg.getRandomIntMatrix(3, 3);
			Matrix<int> m3 = Matrix<int>(3, 3);
			ParallelCalculator<int>::calculate(m1, m2, m3, 3, MatrixOperations<int>::addition);

			Matrix<int> m4 = Matrix<int>(3, 3);
			SerialMatrixOperations<int>::calculate(m1, m2, m4, MatrixOperations<int>::addition);

			Assert::IsTrue(m3 == m4);
		}

		


	};
}