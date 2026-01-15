#include <iostream>
using namespace std;
#include <cmath>

class Figure
{
public:
	virtual double area() = 0;
};

class Figure2D : public Figure
{
public:
	virtual double circumference() = 0;
};

class Figure3D : public Figure
{
public:
	virtual double volume() = 0;
};



class Circle : public Figure2D
{
	double r;

public:
	double getRadius();
	Circle(double);
	double circumference();
	double area();
};

double Circle::getRadius()
{
	return r;
}

Circle::Circle(double r)
{
	this->r = r;
}

double Circle::circumference()
{
	return 2*3.14*r;
}

double Circle::area()
{
	return r*r*3.14;
}




class Sphere : public Figure3D
{
	double r;

public:
	double getRadius();
	Sphere(double);
	double area();
	double volume();
};

double Sphere::getRadius()
{
	return r;
}

Sphere::Sphere(double r)
{
	this->r = r;
}

double Sphere::area()
{
	return 4*3.14*r*r;
}

double Sphere::volume()
{
	return (this->area() * r / 3);
}





int main()
{
	Figure *f;
	double r;

	cout << "\nEnter the r of the circle: ";
	cin >> r;
	f = new Circle(r);
	cout << "A circle with the following features has been input: " << endl;
	cout << "Radius:\t\t" << ((Circle *)f)->getRadius() << endl;
	cout << "Circumference:\t" << ((Circle *)f)->circumference() << endl;
	cout << "Area:\t\t" << f->area() << endl;
	delete f;
	f = NULL;

	cout << "\nEnter the r of the sphere: ";
	cin >> r;
	f = new Sphere(r);
	cout << "A sphere with the following features has been input: " << endl;
	cout << "Radius:\t\t" << ((Sphere *)f)->getRadius() << endl;
	cout << "Area:\t\t" << f->area() << endl;
	cout << "Volume:\t\t" << ((Sphere *)f)->volume() << endl;
	delete f;
	f = NULL;

}
