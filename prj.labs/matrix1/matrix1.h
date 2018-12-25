#ifndef MATRIX1_2018
#define MATRIX1_2018

class Matrix1
{
public:
  Matrix1() = default;
  Matrix1(int sizeRows, int sizeColums);
  Matrix1(Matrix1& matrix);
  ~Matrix1();
  int& At(int row, int col);
  int GetCountRows() const;
  int GetCountCols() const;
  void Clear();
  Matrix1& operator=(Matrix1& matrix);
private:
  int** matrix1_{ nullptr };
  int sizeRows_{ 0 };
  int sizeColums_{ 0 };
};



#endif // MATRIX1_2018