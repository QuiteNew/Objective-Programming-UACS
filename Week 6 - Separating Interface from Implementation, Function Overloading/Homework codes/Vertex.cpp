#include "Vertex.h"

Vertex::Vertex()
{
	x = 0;
	y = 0;
}

Vertex::Vertex(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Vertex::getX()
{
	return x;
}

double Vertex::getY()
{
	return y;
}

void Vertex::info()
{
	cout << "(" << x << ", " << y << ")" << endl;
}
