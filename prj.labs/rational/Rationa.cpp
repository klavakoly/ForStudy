#include "Rationa.h"

Rational::Rational() = default;
Rational::Rational(int num, int den)
	:numerator(num)
	, denominator(den)
{
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
inline std::ostream& operator<<(std::ostream& ostrm, const Rational& r)
{
	return r.writeTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Rational& r)
{
	return r.readFrom(istrm);
}
