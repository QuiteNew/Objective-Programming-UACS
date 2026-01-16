#include <iostream>
#include <cmath>

#include "DenominatorZeroException.h"

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
    if (den == 0)
        throw DenominatorZeroException();
	this->num = num;
	this->den = den;
}

void Fraction::show()
{
	cout << num << "/" << den ;
}

double Fraction::value()
{
    if (den == 0 )
        throw DenominatorZeroException();

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
	if (f.den == 0)
        throw DenominatorZeroException("operator+");
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
	if (f.den == 0)
        throw DenominatorZeroException("operator-");

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
	if (f.den == 0)
        throw DenominatorZeroException("operator*");
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
	if (f.den == 0)
        throw DenominatorZeroException("operator/");
	return f;
}



int main()
{

	int num, den;

	cout << "\nEnter the numerator and denominator (both integer) of fraction a: ";
	cin >> num >> den;
	Fraction a;
    try {
        a = Fraction(num, den);
    } catch (DenominatorZeroException& dze) {
        cout << "Creating fraction a with denominator as zero! " << endl;
        cout << dze.what() << endl;
    }
	cout << "a = ";
	a.show();
	try {
        cout << "\tIts value is " << a.value() << endl;
    }
    catch ( DenominatorZeroException& dze) {
        cout << dze.what() << endl;
    }

	cout << "\nEnter the numerator and denominator (both integer) of fraction b: ";
	cin >> num >> den;
	Fraction b;
	try {
        b = Fraction(num, den);
    } catch (DenominatorZeroException& dze) {
        cout << "Creating fraction b with denominator as zero!" << endl;
        cout << dze.what() << endl;
    }
	cout << "b = ";
	b.show();
	try {
        cout << "\tIts value is " << b.value() << endl;
	} catch ( DenominatorZeroException& dze) {
        cout << dze.what() << endl;
    }


	cout << endl;
	Fraction c;
    try {
        c = a+b;
        cout << "a+b = ";
        c.show();
        cout << "\tIts value is " << c.value() << endl;
    }
    catch (const DenominatorZeroException denZerExc) {
        cout << denZerExc.what() << endl;
    }

    try {
        c = a-b;
        cout << "a-b = ";
        c.show();
        cout << "\tIts value is " << c.value() << endl;
    } catch (const DenominatorZeroException denZerExc) {
        cout << denZerExc.what() << endl;
    }

    try {
        c = a*b;
        cout << "a*b = ";
        c.show();
        cout << "\tIts value is " << c.value() << endl;
    } catch (const DenominatorZeroException denZerExc) {
        cout << denZerExc.what() << endl;
    }
    try {
        c = a/b;
        cout << "a/b = ";
        c.show();
        cout << "\tIts value is " << c.value() << endl;
    } catch (const DenominatorZeroException denZerExc) {
        cout << denZerExc.what() << endl;
    }

}

