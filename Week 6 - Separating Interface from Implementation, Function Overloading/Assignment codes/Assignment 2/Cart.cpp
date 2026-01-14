#include <iostream>
#include <cmath>
using namespace std;

#include "Cart.h"
#include "Polar.h"

Cartesian::Cartesian()
{
	x = y = 0;
}

Cartesian::Cartesian(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Cartesian::getX()
{
	return x;
}

double Cartesian::getY()
{
	return y;
}

void Cartesian::print()
{
	cout << "(" << x << ", " << y << ")" << endl;
}

Cartesian Cartesian::toCart(Polar p)
{
	Cartesian c(p.getR() * cos(p.getF()), p.getR() * sin(p.getF()));

	return c;
}



