//#pragma once
//#ifndef MATRIX_HPP
//#define MATRIX_HPP
//
//class Matrix
//{
//public:
//  Matrix() = default;
//  Matrix(const int rowSize, const int columnSize);
//  Matrix(const Matrix& obj);
//
//  ~Matrix();
//
//  int getRowSize() const;
//  int getColumnSize() const;
//
//  int& getElementAt(const int rowSize, const int columnSize);
//
//  Matrix& operator=(const Matrix& rhs);
//private:
//  int rowSize_{ 0 };
//  int columnSize_{ 0 };
//  int** data_{ nullptr };
//};
//
//#endif

#ifndef MATRIX_HPP
#define MATRIX_HPP
class Matrix
{
public:
	Matrix() = default;
	Matrix(int sizeRows, int sizeColums);
	Matrix( Matrix& matrix);
	int& GetElement(const int rows, const int colums) const;
	~Matrix();
	int GetCountRows() const;
	int GetCountColums() const;
private:
	int** matrix_{nullptr};
	int sizeRows_{ 0 };
	int sizeColums_{ 0 };
};
#endif //matrix_