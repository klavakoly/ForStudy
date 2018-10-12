#pragma once
#include <sstream>
#include <ostream>


class Complex
{
	
public:
	Complex() = default;
	explicit Complex(double real);
	Complex(double real, double imaginary);
	bool operator==(Complex& a);
	bool operator!=(Complex& a);
	Complex& operator+=(Complex& a);
	Complex& operator-=(Complex& a);
	Complex& operator*=(Complex& a);
	Complex& operator/=(Complex& a);
	std::ostream& WriteTo(std::ostream& ostrm);
	std::iostream& ReadTo(std::iostream& istrm);

private:
	double re{0.0};
	double im{0.0};
	static const char left{ '{' };
	static const char comma{ ',' };
	static const char right{ '}' };

};

Complex operator+(Complex a, Complex b);
Complex operator-(Complex a, Complex b);
Complex operator*(Complex a, Complex b);
Complex operator/(Complex a, Complex b);
inline std::ostream& operator<<(std::ostream& ostrm, Complex& r)
{
	return r.WriteTo(ostrm);
}
inline std::iostream& operator>>(std::iostream& istrm, Complex& r)
{
	return r.ReadTo(istrm);
}