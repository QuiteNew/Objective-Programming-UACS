#include <iostream>

using namespace std;

class Vector
{
	double x, y, z;

public:
	Vector();
	Vector(double, double, double);
	void show();
	friend Vector operator+(Vector, Vector);
	friend Vector operator-(Vector, Vector);
	friend double operator*(Vector, Vector);
	friend Vector operator^(Vector, Vector);

};

Vector::Vector()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector::Vector(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector::show()
{
	cout << "(" << x << ", " << y << ", " << z << ")";
}

Vector operator+(Vector a, Vector b)
{
	Vector c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return c;
}

Vector operator-(Vector a, Vector b)
{
	Vector c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return c;
}

double operator*(Vector a, Vector b)
{
	double c;
	c = a.x*b.x + a.y*b.y + a.z*b.z;
	return c;
}

Vector operator^(Vector a, Vector b)
{
	Vector c;
	c.x = a.y*b.z - a.z*b.y;
	c.y = a.z*b.x - a.x*b.z;
	c.z = a.x*b.y - a.y*b.x;
	return c;
}




int main()
{
	double x, y, z;

	cout << endl;
	cout << "Enter the coordinates of vector a: ";
	cin >> x >> y >> z;
	Vector a(x, y, z);
	cout << "a = ";
	a.show();
	cout << endl;
	cout << "Enter the coordinates of vector b: ";
	cin >> x >> y >> z;
	Vector b(x, y, z);
	cout << "b = ";
	b.show();
	cout << endl;

	Vector c;
	double d;

	cout << endl;
	c = a+b;
	cout << "a+b = ";
	c.show();
	cout << endl;
	c = a-b;
	cout << "a-b = ";
	c.show();
	cout << endl;
	d = a*b;
	cout << "a*b = ";
	cout << d;
	cout << endl;
	c = a^b;
	cout << "a^b = ";
	c.show();
	cout << endl;


}
