#include <iostream>
#include <cmath>
using namespace std;

#include "Cart.h"
#include "Polar.h"

int main()
{
	double a, b;
	Cartesian *cPtr = NULL;;
	Polar *pPtr = NULL;

	cout << "Enter two double values: ";
	cin >> a >> b;

	cout << "\nIf a Cartesian coordinate pair is created by those values:" << endl;
	cPtr = new Cartesian(a, b);
	cout << "Cartesian:\t";
	cPtr->print();
	pPtr = new Polar();
	*pPtr = Polar::toPolar(*cPtr);
	cout << "Polar:\t\t";
	pPtr->print();
	delete cPtr;
	delete pPtr;
	cPtr = NULL;
	pPtr = NULL;

	cout << "\nIf a Polar coordinate pair is created by those values:" << endl;
	pPtr = new Polar(a, b);
	cout << "Polar:\t\t";
	pPtr->print();
	cPtr = new Cartesian();
	*cPtr = Cartesian::toCart(*pPtr);
	cout << "Cartesian:\t";
	cPtr->print();
	delete cPtr;
	delete pPtr;
	cPtr = NULL;
	pPtr = NULL;
}
