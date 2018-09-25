#pragma once
#ifndef __RATIONA_H__
#define __RATIONA_H__
#include <ostream>
#include <iostream>
#include <sstream>
#include "DelHas.h"
#include "NOD.h"


class Rational
{
public:
	Rational();
	Rational(int num, int den);
	explicit Rational(int den);
	bool operator==(Rational& a) const;
	bool operator!=(Rational& a) const;
	Rational& operator*=(Rational& a);
	Rational& operator/=(Rational& a);
	Rational& operator+=(Rational& a);
	Rational& operator-=(Rational& a);
	Rational operator+(Rational& a);
	Rational operator-(Rational& a);
	Rational operator*(Rational& a);
	Rational operator/(Rational& a);
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);
	static const char slesh{ '/' };
private:
	int numerator = 0;
	int denominator = 0;
};


using namespace std;
inline std::ostream& operator<<(std::ostream&, const Rational&);
inline std::istream& operator>>(std::istream&, Rational&);

#endif // __RATIONA_H__
