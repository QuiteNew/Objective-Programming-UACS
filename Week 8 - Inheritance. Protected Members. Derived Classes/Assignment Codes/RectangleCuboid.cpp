#include <iostream>
using namespace std;

class Rectangle
{
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
	return (2 * this->Rectangle::area() + 2*getB()*c + 2*getA()*c);
}



int main()
{
	double a, b, c;

	cout << "Enter the three sides of a cuboid: ";
	cin >> a >> b >> c;

	Cuboid C(a, b, c);

	cout << "This is the cuboid that has been enetered: " << endl;
	cout << "Side a: " << C.getA() << "\tSide b: " << C.getB() << "\tSide c: " << C.getC() << endl;
	cout << "Area of the base: " << C.Rectangle::area() << endl;
	cout << "Area of the entire cuboid: " << C.area() << endl;
}