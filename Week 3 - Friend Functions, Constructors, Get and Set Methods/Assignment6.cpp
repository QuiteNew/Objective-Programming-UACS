#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

class Polygon
{
public:
	double *side;
	int numSides;
	double circumference;
	Polygon();
	Polygon(int);
	Polygon(int, double);
	Polygon(double);
};

Polygon::Polygon()
{
	circumference = 0;
	numSides = rand() % 8 + 3;								// by default, from 3 to 10 at most
	side = new double[numSides];
	for(int i = 0; i < numSides; i++)
	{
		side[i] = ((double)rand() / RAND_MAX) * 10;			// by default, 10 is the longest side
		circumference += side[i];
	}
}

Polygon::Polygon(int numS)
{
	circumference = 0;
	numSides = rand() % (numS-2) + 3;
	side = new double[numSides];
	for(int i = 0; i < numSides; i++)
	{
		side[i] = ((double)rand() / RAND_MAX) * 10;			// by default, 10 is the longest side
		circumference += side[i];
	}
}

Polygon::Polygon(int numS, double maxSide)
{
	circumference = 0;
	numSides = rand() % (numS-2) + 3;
	side = new double[numSides];
	for(int i = 0; i < numSides; i++)
	{
		side[i] = ((double)rand() / RAND_MAX) * maxSide;
		circumference += side[i];
	}
}

Polygon::Polygon(double maxSide)
{
	circumference = 0;
	numSides = rand() % 8 + 3;								// by default, from 3 to 10 at most
	side = new double[numSides];
	for(int i = 0; i < numSides; i++)
	{
		side[i] = ((double)rand() / RAND_MAX) * maxSide;
		circumference += side[i];
	}
}



int main()
{
	int numPolygons, indMax, i, j;
	double maxCircumference;
	Polygon *p = NULL, *pPtr= NULL;

	srand(time(NULL));

	cout << "How many polygons will there be (0 for a random number)? ";
	cin >> numPolygons;

	if(numPolygons == 0)
		numPolygons = rand() % 10 + 1;							// there must be at least 1 and at most 10 polygons

	p = new Polygon[numPolygons];

	cout << "There will be " << numPolygons << " polygons" << endl << "----------------------------------------" << endl << endl;



	for(i = 0; i < numPolygons; i++)
	{
		cout << "\nPolygon " << i << ": " << endl;
		cout << "Enter the number of sides of the polygon (2 or less for a random number): ";
		int numSides;
		cin >> numSides;

		cout << "Enter the maximum length of a side (0 or less for a random number): ";
		double side;
		cin >> side;

		if(numSides < 3)
			if(side <= 0)
				pPtr = new Polygon();
			else
				pPtr = new Polygon(side);
		else
			if(side <= 0)
				pPtr = new Polygon(numSides);
			else
				pPtr = new Polygon(numSides, side);

		p[i] = *pPtr;
		delete pPtr;
		pPtr = NULL;
	}

	indMax = 0;
	maxCircumference = p[0].circumference;
	for(i = 0; i < numPolygons; i++)
	{
		cout << "\nPolygon " << i << " has " << p[i].numSides << " sides: " << endl;
		for(j = 0; j < p[i].numSides; j++)
		{
			cout << "Length of side " << j << ": " << p[i].side[j] << endl;
		}
		cout << "Its circumference is " << p[i].circumference << endl;

		if(p[i].circumference > maxCircumference)
		{
			maxCircumference = p[i].circumference;
			indMax = i;
		}
	}

	cout << "\nPolygon " << indMax << " has the greatest circumference of " << p[indMax].circumference << endl;

	return 0;
}
