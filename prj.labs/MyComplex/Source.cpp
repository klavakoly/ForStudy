#include <iostream>
#include <ostream>
#include "Complex.h"

using namespace std;
int main()
{
	Complex a1 = Complex(1.3, 3.4);
	Complex a2 = Complex(1.2, 3.1);
	Complex asum = Complex(2.5, 6.5);
	a1 += a2;
	cout << (a1 == asum) << " ( += )" << endl;
	a1 = Complex(1.3, 3.4);
	a1 = a1 + a2;
	cout << (a1 == asum) << " ( += )" << endl;
	system("pause");
}