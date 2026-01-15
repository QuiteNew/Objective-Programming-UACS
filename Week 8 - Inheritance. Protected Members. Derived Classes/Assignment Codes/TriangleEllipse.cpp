#include <iostream>
#include <cmath>
using namespace std;

class Triangle
{
protected:
	double a, b, c;

public:
	double getA();
	double getB();
	double getC();
	Triangle(double, double, double);
	double circumference();
	double area();
};

double Triangle::getA()
{
	return a;
}

double Triangle::getB()
{
	return b;
}

double Triangle::getC()
{
	return c;
}

Triangle::Triangle(double a, double b, double c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

double Triangle::circumference()
{
	return (a+b+c);
}

double Triangle::area()
{
	double s = (a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}



class Ellipse : private Triangle
{
private:
	double d1, d2, d;

protected:
	double a, b, e;

public:
	Ellipse(Triangle);
	double getA();
	double getB();
	double getE();
	double area();
};

Ellipse::Ellipse(Triangle t) : Triangle(t.getA(), t.getB(), t.getC())
{
	d1 = Triangle::a;
	d2 = Triangle::b;
	d = c;

	a = sqrt(d*(d1+d2))/2;
	b = sqrt((d1+d2-d)*(d1+d2+d))/2;
	e = d/(2*a);
}

double Ellipse::getA()
{
	return a;
}

double Ellipse::getB()
{
	return b;
}

double Ellipse::getE()
{
	return e;
}

double Ellipse::area()
{
	return a*b*3.14;
}



void main()
{
	double a, b, c;

	cout << "Enter three double values: ";
	cin >> a >> b >> c;


	if(((a+b) > c) && ((a+c) > b) && ((b+c) > a))
	{
		Triangle t(a, b, c);
		cout << "\nA TRIANGLE created from the three values would have the following features: " << endl;
		cout << "Sides:\t\t" << a << "\t" << b << "\t" << c << endl;
		cout << "Circumference:\t" << t.circumference() << endl;
		cout << "Area:\t\t" << t.area() << endl;

		Ellipse e(t);
		cout << "\nAn ELLIPSE created from the three values would have the following features: " << endl;
		cout << "Major semiaxis:\t" << e.getA() << endl;
		cout << "Minor semiaxis:\t" << e.getB() << endl;
		cout << "Eccentricity:\t" << e.getE() << endl;
		cout << "Area:\t\t" << e.area() << endl;
	}
	else
	{
		cout << "The three values don't satisfy the triangle inequalities." << endl;
		cout << "Therefore, neither a triangle nor an ellipse can be created out of them." << endl;
	}
}