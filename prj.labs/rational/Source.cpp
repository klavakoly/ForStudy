//написать программу для перегрузки стандартных операций для рациональных чисел
//класс рациональных чисел

#include <sstream>
#include <iostream>
#include <ostream>
#include "Rational_Tests.h"
#include "DelHas.h"
#include "NOD.h"
#include "Rationa.h"






using namespace std;


int main()
{
	Rational a1 = Rational(3, 12);
	cout << a1 << endl;
	cout << Rational_Tests::Test1() << " ( == ) "<< endl;
	cout << Rational_Tests::Test2() << " ( != )" <<endl;
	cout << Rational_Tests::Test3() << " ( *= )"<< endl;
	cout << Rational_Tests::Test4() << " ( *  )"<< endl;
	cout << Rational_Tests::Test5() << " ( /= )" << endl;
	cout << Rational_Tests::Test6() << " ( /  )" << endl;
	cout << Rational_Tests::Test7() << " ( += )" << endl;
	cout << Rational_Tests::Test8() << " ( +  )" << endl;
	cout << Rational_Tests::Test9() << " ( -= )" << endl;
	cout << Rational_Tests::Test10() << " ( -  )" << endl;
	system("pause");
}

