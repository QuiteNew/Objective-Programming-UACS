#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;

#include "Player.cpp"

int main()
{
	srand(time(NULL));

	Player team1[5], team2[5], *p = NULL;
	int i, score1 = 0, score2 = 0;
	char name[50];

	cout << "\nEnter the players of Team 1:" << endl;
	for(i = 0; i < 5; i++)
	{
		cout << "Enter the name of player #" << i << ": ";
		cin.getline(name, 50);
		p = new Player(name);
		team1[i] = *p;
		delete p;
		p = NULL;
	}

	cout << "\nEnter the players of Team 2:" << endl;
	for(i = 0; i < 5; i++)
	{
		cout << "Enter the name of player #" << i << ": ";
		cin.getline(name, 50);
		p = new Player(name);
		team2[i] = *p;
		delete p;
		p = NULL;
	}

	cout << "\nHere are the lineups: " << endl;
	cout << "\nTeam1:" << endl;
	for(i = 0; i < 5; i++)
		team1[i].info();
	cout << "\nTeam2:" << endl;
	for(i = 0; i < 5; i++)
		team2[i].info();

	cout << "\nTHE MATCH BEGINS!" << endl;
	for(i = 0; i < 40; i++)
	{
		int scorer = rand() % 10;
		int chance = (rand() % 99) + 1;
		int scored = 0;

		switch(scorer)
		{
		case 0:	if(chance == team1[0].getJersey())
				{
					team1[0].score(i);
					scored = 1;
				}
		case 1:	if(chance == team1[1].getJersey())
				{
					team1[1].score(i);
					scored = 1;
				}
		case 2:	if(chance == team1[2].getJersey())
				{
					team1[2].score(i);
					scored = 1;
				}
		case 3:	if(chance == team1[3].getJersey())
				{
					team1[3].score(i);
					scored = 1;
				}
		case 4:	if(chance == team1[4].getJersey())
				{
					team1[4].score(i);
					scored = 1;
				}
		case 5:	if(chance == team2[0].getJersey())
				{
					team2[0].score(i);
					scored = 2;
				}
		case 6:	if(chance == team2[1].getJersey())
				{
					team2[1].score(i);
					scored = 2;
				}
		case 7:	if(chance == team2[2].getJersey())
				{
					team2[2].score(i);
					scored = 2;
				}
		case 8:	if(chance == team2[3].getJersey())
				{
					team2[3].score(i);
					scored = 2;
				}
		case 9:	if(chance == team2[4].getJersey())
				{
					team2[4].score(i);
					scored = 2;
				}
		}

		if(scored == 1)
			score1++;
		if(scored == 2)
			score2++;
		if(scored != 0)
			cout << "Current score:\tTeam1 : Team2\t" << score1 << " : " << score2 << endl;
	}

	cout << "\nThe match has ended with the following score:\tTeam1 : Team2\t " << score1 << " : " << score2 << endl;
	if(score1 > score2)
		cout << "TEAM 1 IS THE WINNER!" << endl;
	else if(score1 < score2)
		cout << "TEAM 2 IS THE WINNER!" << endl;
	else
		cout << "IT'S A DRAW!" << endl;
}
