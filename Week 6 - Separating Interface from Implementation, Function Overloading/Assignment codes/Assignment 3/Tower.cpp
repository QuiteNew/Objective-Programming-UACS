#include <iostream>
#include <cstdlib>
#include "Tower.h"
using namespace std;

Tower::Tower()
{
	numGates = (rand() % 4) + 4;
	gate = new int[numGates];
	cout << "Your tower has " << numGates << " gates, with the following fortification values: " << endl;
	for(int i = 0; i < numGates; i++)
	{
		gate[i] = (rand() % 10) + 1;
		cout << "Gate " << i << ": " << gate[i] << endl;
	}
}
