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
bool Complex::operator==(Complex& a) { return((re == a.re) && (im == a.im)); }
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
	re = re * a.re - im * a.im;
	im = re * a.im + im * a.re;
	return *this;
}
Complex& Complex::operator/=(Complex& a)
{
	re = (re*a.re + im * a.im) / (a.re*a.re + a.im*a.im);
	im = (a.re *im - re * a.im) / (a.re*a.re + a.im*a.im);
	return *this;
}
double& Complex::get_Re()
{
	return re;
}
void Complex::put_Re(double value)
{
	re = value;
}
double& Complex::get_Im()
{
	return im;
}
void Complex::put_Im(double value)
{
	im = value;
}

Complex operator+(Complex& a, Complex& b)
{
	Complex c;
	c += a;
	c += b;
	return c;
}
Complex operator-(Complex& a, Complex& b)
{
	Complex c;
	c += a;
	c -= b;
	return c;
}
Complex operator*(Complex& a, Complex& b)
{
	Complex c;
	c.get_Re= a.get_Re * b.get_Re - a.get_Im * b.get_Im;
	c.get_Im= a.get_Re * b.get_Im + a.get_Im * b.get_Re;
	return c;
}
Complex operator/(Complex& a, Complex& b)
{
	Complex c;
	c.get_Re= (a.get_Re * b.get_Re + a.get_Im * b.get_Im) / (b.get_Re*b.get_Re + b.get_Im*b.get_Im);
	c.get_Im= (b.get_Re * a.get_Im - a.get_Re * b.get_Im) / (b.get_Re*b.get_Re + b.get_Im*b.get_Im);
	return c;
}

std::ostream& Complex::WriteTo(std::ostream& ostrm)
{
	ostrm << left << re << comma << right;
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

inline std::ostream& operator<<(std::ostream& ostrm, Complex& r)
{
	return r.WriteTo(ostrm);
}
inline std::iostream& operator>>(std::iostream& istrm, Complex& r)
{
	return r.ReadTo(istrm);
}

