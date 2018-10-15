#include <iostream>

#include "Matrix.h"

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