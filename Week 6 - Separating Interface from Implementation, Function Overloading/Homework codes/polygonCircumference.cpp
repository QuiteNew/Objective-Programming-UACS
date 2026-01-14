#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
#include "Vertex.cpp"



void main()
{
	srand(time(NULL));

	int numVertices, i;
	Vertex *vertex;
	double circ = 0;

	cout << "Enter the number of sides of the polygon (2 or less for random): ";
	cin >> numVertices;

	if(numVertices <= 2)
		numVertices = rand() % 8 + 3;

	vertex = new Vertex[numVertices];

	cout << "The polygon has " << numVertices << " vertices." << endl;
	for(i = 0; i < numVertices; i++)
	{
		double x, y;

		cout << "Enter coordinates x and y for vertex #" << i << ": ";
		cin >> x >> y;

		Vertex *p = new Vertex(x, y);
		vertex[i] = *p;
		delete p;
		p = NULL;
	}

	cout << "\nThe polygon with the following vertices has been entered: " << endl;
	for(i = 0; i < numVertices; i++)
	{
		cout << "Vertex #" << i << ": ";
		vertex[i].info();

		int j = i+1;
		if(i == numVertices-1)
			j = 0;

		
		double x = vertex[j].getX() - vertex[i].getX();
		double y = vertex[j].getY() - vertex[i].getY();
		circ += sqrt(x*x + y*y);
	}


	cout << "\nThe circumference of the polygon is " << circ << endl;
}