//#include <iostream>
//#include <vector>
//#include "matrix.hpp"
//
//using namespace std;
//
//void testConstructor(Matrix& matrix, int rowSize, int columnSize, int** data)
//{
//  bool result = (matrix.getRowSize() == rowSize) && (matrix.getColumnSize() == columnSize);
//
//  if (result)
//    cout << "Test constructor size with row size " << rowSize << " and column size " << columnSize << " passed" << endl;
//  else
//    cout << "Test constructor size with row size " << rowSize << " and column size " << columnSize << " failed" << endl;
//
//  bool result2 = true;
//  for (int i(0); i < rowSize; i++)
//  {
//    for (int j(0); j < columnSize; j++)
//    {
//      if (matrix.getElementAt(i, j))
//      {
//        result2 = false;
//      }
//    }
//  }
//
//  if (result2)
//    cout << "Test constructor data passed" << endl;
//  else
//    cout << "Test constructor data failed" << endl;
//}
//
//void testElementAt()
//{
//  Matrix matrix2(3, 3);
//  bool result = matrix2.getElementAt(2, 1) == 0;
//  if (result)
//    cout << "Test get element at (2, 1) passed" << endl;
//  else
//    cout << "Test get element at (2, 1) failed" << endl;
//}
//
//int main()
//{
//  Matrix matrix1;
//  testConstructor(matrix1, 0, 0, new int*[0]);
//
//  Matrix matrix2(3, 3);
//  int row1[3] = { 0, 0, 0 };
//  int row2[3] = { 0, 0, 0 };
//  int row3[3] = { 0, 0, 0 };
//  int* row1_ptr = row1;
//  int* row2_ptr = row2;
//  int* row3_ptr = row3;
//  int* matrix[3] = { row1_ptr, row2_ptr, row3_ptr };
//  int** matrix_ptr = matrix;
//  testConstructor(matrix2, 3, 3, matrix_ptr);
//
//  Matrix matrix3(matrix2);
//  testConstructor(matrix3, 3, 3, matrix_ptr);
//
//  testElementAt();
//
//  return 0;
//}

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
	Matrix matr0(0,0);
	cout << "Get matrix0 [0,0]"<<endl;
	CoutMatrix(matr0);
	Matrix matr1(3, 3);
	cout << "Get matrix1 [3,3]"<<endl;
	CoutMatrix(matr1);
	Matrix matr2(7, 10);
	matr2.GetElement(0, 0) = 3;
	cout << "Get matrix2 [7,10] where matrix[0,0]=3" << endl;
	CoutMatrix(matr2);
	Matrix matr3(matr2);
	cout << "Get matrix3 whch equale matrix2" << endl;
	CoutMatrix(matr3);
	return 0;
}