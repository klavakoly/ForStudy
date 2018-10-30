//написать программу для перегрузки стандартных операций для рациональных чисел
//класс рациональных чисел

#include <sstream>
#include <iostream>
#include <ostream>
#include "rationa.h"

using namespace std;

int main()
{ 
	
	try {
		cout << "Rational -4/0 = ";
		Rational a0 = Rational(-4, 0);
		cout << "Rational " << a0 << endl;
	} catch (const exception& e) {		
		cout << e.what()<<endl;
	}
	Rational a1 = Rational(-4, -2);
	cout << "Rational -4/-2 = " << a1 << endl;
	Rational a2 = Rational(4, -2);
	cout << "Rational 4/-2 = " << a2 << endl;
	Rational a3 = Rational(-4, 2);
	cout << "Rational -4/2 = " << a3 << endl;
	Rational a4 = Rational(4, 2);
	cout << "Rational 4/2 = " << a4 << endl;
	Rational a5 = Rational(2, -3);
	cout << "Didn't have NOD Rational 2/-3 = " << a5 << endl<<endl;

	Rational a = Rational(2, 3);
	Rational c = a;
	Rational b = Rational(-4, 7);
	Rational sum = Rational(2, 21);
	Rational sub = Rational(26, 21);
	Rational mul = Rational(-8, 21);
	Rational del = Rational(-7, 6);

	cout << "check operator ==" << endl;
	cout << "a = " << a << endl;
	cout << "c = " << c << endl;
	cout << "a == c -> " << (a == c) << endl<<endl;

	cout << "check operator !=" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "a == b -> " << (a == b) << endl << endl;

	cout << "check operator +=" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	a += b;
	cout << "a += b -> " << a << endl;
	cout << a << " = " << sum<<endl<<endl;

	cout << "check operator +" << endl;
	a = Rational(2, 3);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	a = a+ b;
	cout << "a = a + b -> " << a << endl;
	cout << a << " = " << sum << endl << endl;

	cout << "check operator -=" << endl;
	a = Rational(2, 3);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	a -= b;
	cout << "a -= b -> " << a << endl;
	cout << a << " = " << sub << endl << endl;
	
	cout << "check operator -" << endl;
	a = Rational(2, 3);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	a = a - b;
	cout << "a = a - b -> " << a << endl;
	cout << a << " = " << sub << endl << endl;

	cout << "check operator *=" << endl;
	a = Rational(2, 3);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	a *=  b;
	cout << "a *= b -> " << a << endl;
	cout << a << " = " << mul << endl << endl;

	cout << "check operator *" << endl;
	a = Rational(2, 3);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	a = a * b;
	cout << "a = a * b -> " << a << endl;
	cout << a << " = " << mul << endl << endl;
	
	cout << "check operator /=" << endl;
	a = Rational(2, 3);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	a /= b;
	cout << "a /= b -> " << a << endl;
	cout << a << " = " << del << endl << endl;

	cout << "check operator /" << endl;
	a = Rational(2, 3);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	a = a / b;
	cout << "a = a / b -> " << a << endl;
	cout << a << " = " << del << endl << endl;

}

