#include "Complex.h"

Complex::Complex(double real)
	:Complex(real, 0.0)
{
};
Complex::Complex(double real, double imaginary)
{
	re=real;
	im=imaginary;
};
bool Complex::operator==(Complex& a) { return(((re - a.re) < 0.00001) && ((im - a.im) < 0.00001)); }
bool Complex::operator!=(Complex& a) { return(!operator==(a)); }
Complex& Complex::operator+=(Complex& a)
{
	re += a.re;
	im += a.im;
	return *this;
};
Complex& Complex::operator-=(Complex& a)
{
	re -= a.re;
	im -= a.im;
	return *this;
}
Complex& Complex::operator*=(Complex& a)
{
	Complex reThis = Complex(re);
	re = re * a.re - im * a.im;
	im =  reThis.re * a.im + im * a.re;
	return *this;
}
Complex& Complex::operator/=(Complex& a)
{
	re = (re*a.re + im * a.im) / (a.re*a.re + a.im*a.im);
	im = (a.re *im - re * a.im) / (a.re*a.re + a.im*a.im);
	return *this;
}


Complex operator+(Complex a, Complex b)
{
	Complex c;
	c += a;
	c += b;
	return c;
}
Complex operator-(Complex a, Complex b)
{
	Complex c;
	c += a;
	c -= b;
	return c;
}
Complex operator*(Complex a, Complex b)
{
	Complex c(a);
	c *= b;
	return c;

}
Complex operator/(Complex a, Complex b)
{
	Complex c(a);
	c /= b;
	return c;
}

std::ostream& Complex::WriteTo(std::ostream& ostrm)
{
	ostrm << left << re << comma << im << right;
	return ostrm;
}
std::iostream& Complex::ReadTo(std::iostream& istrm)
{
	char leftB{ 0 };
	char com{ 0 };
	char rightB{ 0 };
	double real{ 0.0 };
	double img{ 0.0 };
	istrm >> leftB >> real >> com >> img >> rightB;
	if ((leftB == left) && (com == comma) && (rightB == rightB))
	{
		re = real;
		im = img;
	}
	else
	{
		istrm.setstate(std::ios_base::failbit);
	}
	return istrm;
}


