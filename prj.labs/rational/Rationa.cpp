#include "Rationa.h"
#include <stdexcept>
#include <math.h>


Rational::Rational() = default;
Rational::Rational(int num, int den)
	:numerator(num)
	, denominator(den)
{
	if (denominator == 0) throw std::invalid_argument("denuminator can't be 0!");
	delHas(numerator, denominator);
}
Rational::Rational(int den)
	: Rational(1, den)
{
}


bool Rational::operator==(Rational& a) const
{
	return (numerator == a.numerator) && (denominator == a.denominator);
}
bool Rational::operator!=(Rational& a) const { return !operator==(a); }
Rational& Rational::operator*=(Rational& a)
{
	numerator *= a.numerator;
	denominator *= a.denominator;
	delHas(numerator, denominator);
	return *this;
}
Rational& Rational::operator/=(Rational& a)
{
	numerator *= a.denominator;
	denominator *= a.numerator;
	delHas(numerator, denominator);
	return *this;
}
Rational& Rational::operator+=(Rational& a)
{
	int nod = NOD(denominator, a.denominator);
	numerator = numerator * (a.denominator / nod) + a.numerator*(denominator / nod);
	denominator = denominator * (a.denominator / nod);
	delHas(numerator, denominator);
	return *this;
}
Rational& Rational::operator-=(Rational& a)
{
	int nod = NOD(denominator, a.denominator);
	numerator = numerator * (a.denominator / nod) - a.numerator*(denominator / nod);
	denominator = denominator * (a.denominator / nod);
	delHas(numerator, denominator);
	return *this;
}
Rational Rational::operator+(Rational& a)
{
	Rational sum(*this);
	sum += a;
	return sum;
}
Rational Rational::operator-(Rational& a)
{
	Rational min(*this);
	min -= a;
	return min;
}
Rational Rational::operator*(Rational& a)
{
	Rational mul(*this);
	mul *= a;
	return mul;
}
Rational Rational::operator/(Rational& a)
{
	Rational red(*this);
	red /= a;
	return red;
}
std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
	ostrm << numerator << Rational::slesh << denominator;
	return ostrm;
}
std::istream& Rational::readFrom(std::istream& istrm)
{
	char slesh(0);
	int num(0);
	int den(1);

	istrm >> num >> slesh >> den;

	if (Rational::slesh == slesh)
	{
		numerator = num;//? нужо условие int?
		denominator = den;
	}
	else
	{
		istrm.setstate(std::ios_base::failbit);
	}

	return istrm;
}
int NOD(int a, int b)
{
	while (b != 0)//пока b не 0
	{
		if (abs(a) > abs(b))
		{
			a %= b;
			if (!a)
			{
				return b;
			}
		}
		else
		{
			b %= a;
			if (!b)
			{
				return (a>0) ? a : (-a);
			}
		}
	}
};
void delHas(int& a, int& b)
{
	int nod = NOD(a, b);
	if (nod)
	{
		a /= nod;
		b /= nod;
	}
};


