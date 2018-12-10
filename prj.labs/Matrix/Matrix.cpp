#include "matrix.h"

Matrix::Matrix(int sizeRows, int sizeColums)
  :matrix_(new int*[sizeRows])
  , sizeRows_(sizeRows)
  , sizeColums_(sizeColums)
{
  for (int i = 0; i < sizeRows; i++)
  {
    matrix_[i] = new int[sizeColums];
    for (int j = 0; j < sizeColums_; j++)
    {
      matrix_[i][j] = 0;
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
Matrix& Matrix::operator=(const Matrix& matrix)
{
  if (this != &matrix)
  {
    this->~Matrix();
    this->matrix_ = new int*[matrix.sizeRows_];
    for (int i = 0; i < matrix.sizeRows_; i++)
    {
      matrix_[i] = new int[matrix.sizeColums_];
      for (int j = 0; j < matrix.sizeColums_; j++)
      {
        matrix_[i][j] = matrix.matrix_[i][j];
      }
    }
    sizeRows_ = matrix.sizeRows_;
    sizeColums_ = matrix.sizeColums_;
  }
  return *this;
}


