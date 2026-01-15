#include <iostream>
#include <cmath>
using namespace std;

class Triangle
{
	double a, b, c;

public:
	Triangle(double, double, double);
	double getA();
	double getB();
	double getC();
	double baseArea();
};

Triangle::Triangle(double a, double b, double c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

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

double Triangle::baseArea()
{
	double s = (a+b+c)/2;
	return sqrt(s * (s-a) * (s-b) * (s-c));
}



class Pyramid : public Triangle
{
	double h;

public:
	Pyramid(double, double, double, double);
	double getH();
	double volume();
};

Pyramid::Pyramid(double a, double b, double c, double h) : Triangle(a, b, c)
{
	this->h = h;
}

double Pyramid::getH()
{
	return h;
}

double Pyramid::volume()
{
	return (baseArea() * h) / 3;
}



int main()
{
	double a, b, c, h;

	cout << "Enter the three sides of the base triangle and the height of the pyramid: " << endl;
	cout << "Side a: ";
	cin >> a;
	cout << "Side b: ";
	cin >> b;
	cout << "Side c: ";
	cin >> c;
	cout << "Height: ";
	cin >> h;

	Pyramid p(a, b, c, h);

	cout << "A pyramid with the following features has been entered: " << endl;
	cout << "Sides of the base triangle:\t" << p.getA() << "\t" << p.getB() << "\t" << p.getC() << endl;
	cout << "Height:\t\t\t\t" << p.getH() << endl;
	cout << "Volume:\t\t\t\t" << p.volume() << endl;

}