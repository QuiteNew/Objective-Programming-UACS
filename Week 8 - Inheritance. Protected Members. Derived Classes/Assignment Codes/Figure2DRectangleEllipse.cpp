#include <iostream>
#include <cmath>
using namespace std;

class Figure2D
{
protected:
	double width;
	double height;
	Figure2D();
	Figure2D(double);
	Figure2D(double, double);
	double circumference();
	double area();

public:
	double getWidth();
	double getHeight();
};

Figure2D::Figure2D()
{
	width = 0;
	height = 0;
}

Figure2D::Figure2D(double width)
{
	this->width = width;
	height = 0;
}

Figure2D::Figure2D(double width, double height)
{
	this->width = width;
	this->height = height;
}

double Figure2D::circumference()
{
	return -1;
}


double Figure2D::area()
{
	return (width * height);
}

double Figure2D::getWidth()
{
	return width;
}

double Figure2D::getHeight()
{
	return height;
}





class Rectangle : public Figure2D
{
public:
	Rectangle(double, double);
	double circumference();
	double area();
};

Rectangle::Rectangle(double width, double height) : Figure2D(width, height)
{
}

double Rectangle::circumference()
{
	return 2*(width + height);
}


double Rectangle::area()
{
	return this->Figure2D::area();
}





class Ellipse : private Figure2D
{
protected:
	double a, b;

public:
	Ellipse(double, double);
	double getA();
	double getB();
	double circumference();
	double area();
};

Ellipse::Ellipse(double width, double height)
{
	a = width / 2;
	b = height / 2;
}

double Ellipse::getA()
{
	return a;
}

double Ellipse::getB()
{
	return b;
}

double Ellipse::circumference()
{
	double A = 3.14 * (a+b);
	double B = 3 * ((a-b)/(a+b))*((a-b)/(a+b));
	double C = 10 + sqrt(4 - B);

	return (A * (1 + B/C));
}

double Ellipse::area()
{
	return (a * b * 3.14);
}





void main()
{
	double width, height;

	cout << "\nEnter the width and the height: ";
	cin >> width >> height;

	Rectangle r(width, height);
	cout << "\nCreating a rectangle from the given values with the following features: " << endl;
	cout << "Width:\t\t" << r.getWidth() << endl;
	cout << "Height:\t\t" << r.getHeight() << endl;
	cout << "Circumference:\t" << r.circumference() << endl;
	cout << "Area:\t\t" << r.area() << endl;

	Ellipse e(width, height);
	cout << "\nCreating an ellipse from the given values with the following features: " << endl;
	cout << "Major semiaxis:\t" << e.getA() << endl;
	cout << "Minor semiaxis:\t" << e.getB() << endl;
	cout << "Circumference:\t" << e.circumference() << endl;
	cout << "Area:\t\t" << e.area() << endl;
}