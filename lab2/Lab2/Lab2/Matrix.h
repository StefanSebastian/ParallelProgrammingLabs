#pragma once

#include<vector>

/*
Generic matrix class
exported as dll
*/
template <class T>
class __declspec(dllexport) Matrix {
private:
	std::vector<std::vector<T>> data;
	int rows;
	int cols;
public:
	Matrix() = delete;
	Matrix(int rows, int cols);
	T getElement(int i, int j);
	void setElement(int i, int j, T element);
	int getRows();
	int getCols();

};

template<class T>
inline Matrix<T>::Matrix(int rows, int cols):
	rows{rows},
	cols{cols},
	data(rows, std::vector<T>(cols)) // rows elements of vector<T> type which has cols elements
{
}

template<class T>
inline  T Matrix<T>::getElement(int i, int j)
{
	return data[i][j];
}

template<class T>
inline  void Matrix<T>::setElement(int i, int j, T element)
{
	data[i][j] = element;
}

template<class T>
inline  int Matrix<T>::getRows()
{
	return rows;
}

template<class T>
inline  int Matrix<T>::getCols()
{
	return cols;
}
