#include "matrix1.h"

Matrix1::Matrix1(int sizeRows, int sizeColums)
  :sizeRows_(sizeRows)
  , sizeColums_(sizeColums)
{
  matrix1_ = new int*[sizeRows_];
  for (int i = 0; i < sizeRows_; i++)
  {
    matrix1_[i] = new int[sizeColums_];
  }
}


Matrix1::Matrix1(Matrix1 & matrix)
  :sizeRows_(matrix.sizeRows_)
  , sizeColums_(matrix.sizeColums_)
{
  matrix1_ = new int*[sizeRows_];
  for (int i = 0; i < sizeRows_; i++)
  {
    matrix1_[i] = new int[sizeColums_];
  }
  for (int i = 0; i < sizeRows_; i++)
  {
    for (int j = 0; j < sizeColums_; j++)
    {
      matrix1_[i][j] = matrix.matrix1_[i][j];
    }
  }
}


Matrix1::~Matrix1()
{
  for (int i = 0; i < sizeRows_; i++)
  {
    delete[] matrix1_[i];
  }
  delete[] matrix1_;
}

int& Matrix1::At(int row, int col)
{
  return  matrix1_[row][col];
}


int Matrix1::GetCountRows() const
{
  return sizeRows_;
}

int Matrix1::GetCountCols() const
{
  return sizeColums_;
}

void Matrix1::Clear()
{
  this->~Matrix1();
}

Matrix1 & Matrix1::operator=(Matrix1 & matrix)
{

  if (this != &matrix)
  {
    if ((sizeColums_ < matrix.sizeColums_) && (sizeRows_ < matrix.sizeRows_))
    {
      Clear();
      for (int i = 0; i < matrix.sizeRows_; i++)
      {
        matrix1_ = new int*[matrix.sizeRows_];
        matrix1_[i] = new int[matrix.sizeColums_];
        for (int j = 0; j < matrix.sizeColums_; j++)
        {
          matrix1_[i][j] = matrix.matrix1_[i][j];
        }
      }
      sizeRows_ = matrix.sizeRows_;
      sizeColums_ = matrix.sizeColums_;
    }
    else
    {
      for (int i = 0; i < matrix.sizeRows_; i++)
      {
        for (int j = 0; j < matrix.sizeColums_; j++)
        {
          matrix1_[i][j] = matrix.matrix1_[i][j];
        }
      }
      sizeRows_ = matrix.sizeRows_;
      sizeColums_ = matrix.sizeColums_;
    }
  }
  return *this;
}



