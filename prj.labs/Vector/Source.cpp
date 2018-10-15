#include <iostream>
#include "Vector.h"


int main()
{
	using namespace std;
	Vector vector;
	cout << vector.GetSize() << " size of empty vector" << endl;
	Vector vector1(7);
	Vector vector3(vector1);
	int vector1Size = vector1.GetSize();
	cout << "Vector1 have size=7, metod GetSize return " << vector1Size << endl;
	for (int i = 0; i < vector1Size; i++)
	{
		vector1[i] = 1;
		cout << vector1[i] << " ";
	}
	cout << "  all 1" <<endl;
	vector3[0] = 3;
	cout << vector3[0] << " should return 3"<< endl;
}