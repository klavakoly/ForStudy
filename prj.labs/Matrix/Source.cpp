#include <iostream>

#include "matrix.h"

void CoutMatrix(Matrix& matr)
{
  using namespace std;
  for (int i = 0; i < matr.GetCountRows(); i++)
  {
    for (int j = 0; j < matr.GetCountColums(); j++)
    {
      cout << matr.GetElement(i, j) << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main()
{
  using namespace std;
  Matrix matr0(0, 0);
  cout << "Get matrix(0,0)" << endl;
  CoutMatrix(matr0);
  Matrix matr1(2, 2);
  cout << "Get matrix(3,3)" << endl;
  CoutMatrix(matr1);
  Matrix matr2(3,3);
  matr2.GetElement(0, 0) = 3;
  cout << "Test function GetElement(0,0) = 3 :" << matr2.GetElement(0, 0) << endl;
  Matrix matr3(matr2);
  cout << "Get matrix3 whch equale matrix2 :" << endl;
  cout << "Matrix2 :" << endl;
  CoutMatrix(matr2);
  cout << "Matrix3 :" << endl;
  CoutMatrix(matr3);
  cout << "Test function GetCountRows :" << endl;
  cout << "Matrix :" << endl;
  CoutMatrix(matr3);
  cout << "GetCountRows :" << matr3.GetCountRows() << endl;
  cout << "GetCountColums :" << matr3.GetCountColums() << endl;
  cout << endl;
  cout << "Test operator=. Matrix1 = Matrix2 :"<<endl;
  cout << "Matrix1 :" << endl;
  CoutMatrix(matr1);
  cout << "Matrix2 :" << endl;
  CoutMatrix(matr2);
  cout << "Matrix1 = Matrix2. Return Matrix1 :"<< endl;
  matr1 = matr2;
  
  CoutMatrix(matr1);
  return 0;
}