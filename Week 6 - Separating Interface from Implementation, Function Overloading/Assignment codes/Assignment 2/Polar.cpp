#include <iostream>
#include <cmath>
using namespace std;

#include "Polar.h"
#include "Cart.h"

Polar::Polar()
{
	r = f = 0;
}

Polar::Polar(double r, double f)
{
	this->r = r;
	this->f = f;
}

double Polar::getR()
{
	return r;
}

double Polar::getF()
{
	return f;
}

void Polar::print()
{
	cout << "(" << r << ", " << f << ")" << endl;
}


Polar Polar::toPolar(Cartesian c)
{
	Polar p(sqrt(c.getX()*c.getX() + c.getY()*c.getY()), atan(c.getY()/c.getY()));

	return p;
}
