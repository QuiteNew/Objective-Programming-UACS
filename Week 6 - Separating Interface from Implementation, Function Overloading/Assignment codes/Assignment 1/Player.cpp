#include "Player.h"

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;


Player::Player()
{
}

Player::Player(char name[])
{
	strcpy(this->name, name);
	jersey = (rand() % 99) + 1;
}

void Player::score(int minute)
{
	cout << "Player #" << jersey << ", " << name << ", has scored a goal in the " << minute+1 << ". minute!" << endl;
}

int Player::getJersey()
{
	return jersey;
}

void Player::info()
{
	cout << "Player #" << jersey << ", " << name << endl;
}
