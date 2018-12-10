//#include <iostream>
//#include "matrix.hpp"
//
//Matrix::Matrix(const int rowSize, const int columnSize)
//  : rowSize_(rowSize), columnSize_(columnSize)
//{
//  data_ = new int*[rowSize_];
//
//  for (int i(0); i < rowSize_; i++)
//  {
//    data_[i] = new int[columnSize_];
//
//    for (int j(0); j < columnSize_; j++)
//    {
//      data_[i][j] = 0;
//    }
//  }
//}
//
//Matrix::Matrix(const Matrix& obj)
//  : rowSize_(obj.rowSize_), columnSize_(obj.columnSize_)
//{
//  data_ = new int*[rowSize_];
//
//  for (int i(0); i < rowSize_; i++)
//  {
//    data_[i] = new int[columnSize_];
//
//    for (int j(0); j < columnSize_; j++)
//    {
//      data_[i][j] = obj.data_[i][j];
//    }
//  }
//}
//
//Matrix::~Matrix()
//{
//  delete[] data_;
//}
//
//int& Matrix::getElementAt(const int rowSize, const int columnSize)
//{
//  if (rowSize < 0)
//  {
//    throw std::exception("Size of row should not be negative");
//  }
//
//  if (columnSize < 0)
//  {
//    throw std::exception("Size of column should not be negative");
//  }
//
//  if (rowSize > rowSize_)
//  {
//    throw std::exception("Row size should be less than row size of matrix");
//  }
//
//  if (columnSize > columnSize_)
//  {
//    throw std::exception("Column size should be less than column size of matrix");
//  }
//
//  return data_[rowSize][columnSize];
//}
//
//int Matrix::getRowSize() const
//{
//  return rowSize_;
//}
//
//int Matrix::getColumnSize() const
//{
//  return columnSize_;
//}
//
//Matrix& Matrix::operator=(const Matrix& rhs)
//{
//  columnSize_ = rhs.columnSize_;
//  rowSize_ = rhs.rowSize_;
//
//  for (int i(0); i < rowSize_; i++)
//  {
//    data_[i] = new int[columnSize_];
//
//    for (int j(0); j < columnSize_; j++)
//    {
//      data_[i][j] = rhs.data_[i][j];
//    }
//  }
//
//  return *this;
//}



#include "matrix.h"

Matrix::Matrix(int sizeRows, int sizeColums)
	:matrix_(new int*[sizeRows])
	, sizeRows_(sizeRows)
	,sizeColums_(sizeColums)
{
	for (int i = 0; i < sizeRows; i++)
	{
		matrix_[i] = new int[sizeColums];
		for (int j = 0; j < sizeColums_; j++)
		{
			matrix_[i][j]=0;
		}
	}
}

Matrix::Matrix(Matrix& matrix)
	:Matrix(matrix.sizeRows_, matrix.sizeColums_)
{
	for (int i = 0; i < sizeRows_; i++)
	{
		for (int j = 0; j < sizeColums_; j++)
		{
			matrix_[i][j] = matrix.matrix_[i][j];
		}
	}
}
int& Matrix::GetElement(const int rows, const int colums) const
{
	if ((rows < 0) || (rows >= sizeRows_) || (colums < 0) || (colums >= sizeColums_)) throw "error";
	return matrix_[rows][colums];
}


Matrix::~Matrix()
{
	for (int i = 0; i < sizeRows_; i++)
	{
		delete[] matrix_[i];		
	}
	delete[] matrix_;
	matrix_ = nullptr;
}

int Matrix::GetCountRows() const
{
	return sizeRows_;
}
int Matrix::GetCountColums() const
{
	return sizeColums_;
}


