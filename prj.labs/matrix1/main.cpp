#include <ostream>
#include <iostream>
#include "matrix1.h"

int main()
{
  using namespace std;
  Matrix1 matrix1(3, 4);
  matrix1.At(1, 1) = 12;
  int a = matrix1.At(1, 1);
  cout << "Check conctructor(int, int). matrix1(3, 4). "<< endl<< "Return rows = " << matrix1.GetCountRows() << endl;
  cout << "Return cols = " << matrix1.GetCountCols() << endl<<endl;
  cout << "Check function At. matrix.At(1,1) = 12. " << endl;
  cout << "matrix.At(1, 1) return " << a<<endl<<endl;
  cout << a<<endl;
  Matrix1 matrix2(matrix1);
  cout << matrix2.At(1, 1)<<endl;
  cout << "Check conctructor(Matrix1&). matrix1(3, 4).  " << endl;
  cout << "Matrix matrix2(matrix1) return matrix2(1, 1) = " << matrix2.At(1, 1) << endl;
  cout << "matrix2 cols = " << matrix2.GetCountCols()<<endl;
  cout << "matrix2 rows = " << matrix2.GetCountRows() << endl<<endl;
  matrix1.At(1, 2) = 4;
  matrix1.At(2, 2) = 7;
  cout << "Check operator=. matrix1(1,1) = 12, matrix(1,2) = 4, matrix(2 , 2) = 7." << endl;
  cout << "matrix2 = matrix1 return matrix2:" << endl;
  matrix2 = matrix1;
  cout << "matrix2(1, 1) = " << matrix2.At(1, 1)<<endl;
  cout << "matrix2(1, 2) = " << matrix2.At(1, 2) << endl;
  cout << "matrix2(2, 2) = " << matrix2.At(2, 2) << endl;
  cout << "Chech function GetCoutRows. matrix1 rows=3." << endl;
  cout << "matrix1.GetCountRows return : " << matrix1.GetCountRows() << endl;
  cout << "Chech function GetCoutCols. matrix1 cols=4." << endl;
  cout << "matrix1.GetCountCols return : " << matrix1.GetCountCols() << endl;
}