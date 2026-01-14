#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#include "Tower.h"
#include "Attacker.h"



int main()
{
	srand(time(NULL));

	int attackLength, gateAttacked, gateDefended;
	int start, current, moment;
	Tower t;
	Attacker *aPtr;
	bool breached = false;

	start = time(NULL);
	current = time(NULL);
	cout << "Attackers incoming in " << endl << 3 << endl;
	while(current < (start + 3))
	{
		moment = time(NULL);
		if (moment != current)
		{

			cout << (2 - current + start) << endl;
			current = moment;
		}
	}
	cout << "IMPACT!" << endl;

	attackLength = rand() % 11 + 5;					// 15 seconds of attack time at most
	start = time(NULL);
	current = time(NULL);
	cout << "\nThe attack will last for " << attackLength << " seconds!" << endl << endl;
	while(current < (start + attackLength))
	{
		moment = time(NULL);
		if((moment != current) || (moment == start))
		{
			current = moment;

			gateAttacked = rand() % t.numGates;
			aPtr = new Attacker(gateAttacked);

			cout << "Which gate will you defend? ";
			cin >> gateDefended;
//			gateDefended = rand() % t.numGates;				// if a random gate is defended
			cout << "Defending gate " << gateDefended << "! " << endl;
			moment = time(NULL);

			if(((gateDefended % t.numGates) == gateAttacked) && (moment == current))
			{
				cout << "Gate " << gateAttacked << " has been secured! " << endl;
				delete aPtr;
			}
			else
			{
				t.gate[gateAttacked]--;
				cout << "GATE " << gateAttacked << " HAS BEEN HIT! Its new fortification value is " << t.gate[gateAttacked] << endl;
				if(t.gate[gateAttacked] == 0)
				{
					cout << "GATE " << gateAttacked << " HAS BEEN BREACHED!" << endl;
					breached = true;
					break;
				}
			}

			cout << endl;
		}
	}

	if(breached)
		cout << "\nThe attackers have overwhelmed the tower!" << endl;
	else
		cout << "\nThe tower has been successfully defended!" << endl;

	cout << "The tower gates have these final fortification values: " << endl;
	for(int i = 0; i < t.numGates; i++)
	{
		cout << "Gate " << i << ": " << t.gate[i] << endl;
	}

	cout << "The attackers have inflicted " << Attacker::numHits << " points of damage to your tower" << endl;

}
