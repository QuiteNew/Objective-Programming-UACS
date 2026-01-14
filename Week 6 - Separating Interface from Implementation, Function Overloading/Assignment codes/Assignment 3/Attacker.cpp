#include <iostream>
using namespace std;
#include "Attacker.h"

int Attacker::numHits = 0;

Attacker::Attacker()
{

}

Attacker::Attacker(int gate)
{
	this->gate = gate;
	cout << "Attacking gate " << gate << "!" << endl;
	numHits++;
}

Attacker::~Attacker()
{
	cout << "The attacker has been repelled!" << endl;
	numHits--;
}
