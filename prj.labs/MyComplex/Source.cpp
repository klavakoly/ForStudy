#include <iostream>
#include <ostream>
#include "complex.h"

using namespace std;
int main()
{
	Complex a0;
	cout << "Complex() " << a0 << endl<<endl;
	Complex a1(2);
	cout << "Complex(a, 0) {2,0} -> " << a1 << endl<<endl;
	Complex a = Complex(1.3, 3.4);
	cout << "Complex(Complex) {1.3,3.4} -> " << a << endl << endl;
	
	Complex b = a;
	cout << "check operator =="<<endl;
	cout << "a = " << a << endl << "b = " << a1 << endl;
	cout << "a == b -> " << (b == a)<<endl<<endl;

	b = Complex(1.2, 3.1);
	cout << "check operator !=" << endl;
	cout << "a = " << a << endl << "b = " << a1 << endl;
	cout << "a == b -> " << (b == a) << endl << endl;
	
	 b = Complex(1.2, 3.1);
	Complex asum = Complex(2.5, 6.5);
	Complex asub = Complex(0.1, 0.3);
	Complex adel = Complex(1.3, 0.08);
	Complex amul = Complex(-5.5, 4);
	a += b;
	cout << "check operator +=" << endl;
	cout << "a=" << "{1.3,3.4}" << endl;
	cout << "b=" << b << endl;
	cout << "a += b -> " << a << endl;
	cout << a << "=" << asum << endl << endl;
	
	a = Complex(1.3, 3.4);
	a = a + b;
	cout << "check operator +" << endl;
	cout << "a=" << "{1.3,3.4}" << endl;
	cout << "b=" << b << endl;
	cout << "a = a + b -> " << a << endl;
	cout << a << "=" << asum << endl << endl;

	a = Complex(1.3, 3.4);
	a -=b;
	cout << "check operator -=" << endl;
	cout << "a=" << "{1.3,3.4}" << endl;
	cout << "b=" << b << endl;
	cout << "a -= b -> " << a << endl;
	cout << a << "=" << asub << endl << endl;
		
	a = Complex(1.3, 3.4);
	a =a- b;
	cout << "check operator -" << endl;
	cout << "a=" << "{1.3,3.4}" << endl;
	cout << "b=" << b << endl;
	cout << "a = a - b -> " << a << endl;
	cout << a << "=" << asub << endl << endl;

	a = Complex(0.5, 3);
	b = Complex(1, 2);
	a /=b;
	cout << "check operator /=" << endl;
	cout << "a=" << "{0.5, 3}" << endl;
	cout << "b=" << b << endl;
	cout << "a /= b -> " << a << endl;
	cout << a << "=" << adel << endl << endl;

	a = Complex(0.5, 3);
	a =a / b;
	cout << "check operator /" << endl;
	cout << "a=" << "{0.5, 3}" << endl;
	cout << "b=" << b << endl;
	cout << "a = a / b -> " << a << endl;
	cout << a << "=" << adel << endl << endl;

	a = Complex(0.5, 3);
	a *=  b;
	cout << "check operator *=" << endl;
	cout << "a=" << "{0.5, 3}" << endl;
	cout << "b=" << b << endl;
	cout << "a *= b -> " << a << endl;
	cout << a << "=" << amul << endl << endl;
		
	a = Complex(0.5, 3);
	a *= b;
	cout << "check operator *" << endl;
	cout << "a=" << "{0.5, 3}" << endl;
	cout << "b=" << b << endl;
	cout << "a = a * b -> " << a << endl;
	cout << a << "=" << amul << endl << endl;
}