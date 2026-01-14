#include <iostream>
#include <cmath>
using namespace std;


class Fraction
{
	int num, den;

public:
	Fraction();
	Fraction(int, int);
	void show();
	double value();
	friend Fraction operator+(Fraction, Fraction);
	friend Fraction operator-(Fraction, Fraction);
	friend Fraction operator*(Fraction, Fraction);
	friend Fraction operator/(Fraction, Fraction);

};

Fraction::Fraction()
{
	this->num = 0;
	this->den = 1;
}


Fraction::Fraction(int num, int den)
{
	if(den < 0)
	{
		num *= -1;
		den *= -1;
	}

	this->num = num;
	this->den = den;
}

void Fraction::show()
{
	cout << num << "/" << den;
}

double Fraction::value()
{
	return ((double)num / (double)den);
}

Fraction operator+(Fraction a, Fraction b)
{
	Fraction f;
	f.num = a.num*b.den + b.num*a.den;
	f.den = a.den*b.den;
	if(f.den < 0)
	{
		f.num *= -1;
		f.den *= -1;
	}
	return f;
}

Fraction operator-(Fraction a, Fraction b)
{
	Fraction f;
	f.num = a.num*b.den - b.num*a.den;
	f.den = a.den*b.den;
	if(f.den < 0)
	{
		f.num *= -1;
		f.den *= -1;
	}
	return f;
}

Fraction operator*(Fraction a, Fraction b)
{
	Fraction f;
	f.num = a.num*b.num;
	f.den = a.den*b.den;
	if(f.den < 0)
	{
		f.num *= -1;
		f.den *= -1;
	}
	return f;
}

Fraction operator/(Fraction a, Fraction b)
{
	Fraction f;
	f.num = a.num*b.den;
	f.den = a.den*b.num;
	if(f.den < 0)
	{
		f.num *= -1;
		f.den *= -1;
	}
	return f;
}





int main()
{

	int num, den;

	cout << "\nEnter the numerator and denominator (both integer) of fraction a: ";
	cin >> num >> den;
	Fraction a(num, den);
	cout << "a = ";
	a.show();
	cout << "\tIts value is " << a.value() << endl;

	cout << "\nEnter the numerator and denominator (both integer) of fraction b: ";
	cin >> num >> den;
	Fraction b(num, den);
	cout << "b = ";
	b.show();
	cout << "\tIts value is " << b.value() << endl;

	cout << endl;
	Fraction c;

	c = a+b;
	cout << "a+b = ";
	c.show();
	cout << "\tIts value is " << c.value() << endl;
	c = a-b;
	cout << "a-b = ";
	c.show();
	cout << "\tIts value is " << c.value() << endl;
	c = a*b;
	cout << "a*b = ";
	c.show();
	cout << "\tIts value is " << c.value() << endl;
	c = a/b;
	cout << "a/b = ";
	c.show();
	cout << "\tIts value is " << c.value() << endl;

}

