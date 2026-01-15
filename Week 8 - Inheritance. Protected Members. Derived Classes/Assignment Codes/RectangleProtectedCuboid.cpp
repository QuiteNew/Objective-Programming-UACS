#include <iostream>
using namespace std;

class Rectangle
{
protected:
	double a, b;

public:
	Rectangle(double, double);
	double getA();
	double getB();
	double area();
};

Rectangle::Rectangle(double a, double b)
{
	this->a = a;
	this->b = b;
}

double Rectangle::getA()
{
	return a;
}

double Rectangle::getB()
{
	return b;
}

double Rectangle::area()
{
	return a*b;
}



class Cuboid : public Rectangle
{
protected:
	double c;

public:
	Cuboid(double, double, double);
	double getC();
	double area();
};

Cuboid::Cuboid(double a, double b, double c) : Rectangle(a, b)
{
	this->c = c;
}

double Cuboid::getC()
{
	return c;
}

double Cuboid::area()
{
	return (2*a*b + 2*b*c + 2*a*c);
}



void main()
{
	double a, b, c;

	cout << "Enter the three sides of the cuboid: ";
	cin >> a >> b >> c;

	Cuboid C(a, b, c);

	cout << "A cuboid with the following features has been entered: " << endl;
	cout << "Sides:\t\t" << C.getA() << "\t" << C.getB() << "\t" << C.getC() << endl;
	cout << "Base area:\t" << C.Rectangle::area() << endl;
	cout << "Total area:\t" << C.area() << endl;
}