#include "Rational_Tests.h"

bool Rational_Tests::Test1()
{
	Rational a1 = Rational(2, 4);
	Rational a2 = Rational(1, 2);
	return (a1 == a2);

}
bool Rational_Tests::Test2()
{
	Rational a1 = Rational(2, 4);
	Rational a2 = Rational(3, 2);
	return (a1 != a2);

}
bool Rational_Tests::Test3()
{
	Rational a1 = Rational(2, 4);
	Rational a2 = Rational(3, 5);
	Rational a3 = Rational(3, 10);
	a1 *= a2;
	return (a1 == a3);
}
bool Rational_Tests::Test4()
{
	Rational a1 = Rational(2, 4);
	Rational a2 = Rational(3, 5);
	Rational a3 = Rational(3, 10);
	a1 = a1 * a2;
	return (a1 == a3);
}
bool Rational_Tests::Test5()
{
	Rational a1 = Rational(2, 3);
	Rational a2 = Rational(4, 7);
	Rational a3 = Rational(7, 6);
	a1 /= a2;
	return (a1 == a3);
}
bool Rational_Tests::Test6()
{
	Rational a1 = Rational(2, 3);
	Rational a2 = Rational(4, 7);
	Rational a3 = Rational(7, 6);
	a1 = a1 / a2;
	return (a1 == a3);
}
bool Rational_Tests::Test7()
{
	Rational a1 = Rational(5, 6);
	Rational a2 = Rational(4, 9);
	Rational a3 = Rational(23, 18);
	a1 += a2;
	return(a1 == a3);
}
bool Rational_Tests::Test8()
{
	Rational a1 = Rational(5, 6);
	Rational a2 = Rational(4, 9);
	Rational a3 = Rational(23, 18);
	a1 = a1 + a2;
	return(a1 == a3);
}
bool Rational_Tests::Test9()
{
	Rational a1 = Rational(5, 6);
	Rational a2 = Rational(4, 9);
	Rational a3 = Rational(7, 18);
	a1 -= a2;
	return(a1 == a3);
}
bool Rational_Tests::Test10()
{
	Rational a1 = Rational(5, 6);
	Rational a2 = Rational(4, 9);
	Rational a3 = Rational(7, 18);
	a1 = a1 - a2;
	return(a1 == a3);
}