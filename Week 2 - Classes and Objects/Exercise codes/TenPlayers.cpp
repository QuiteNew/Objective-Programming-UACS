#include <iostream>
using namespace std;

class Player
{
	int pts;

public:
	int getPts();
	void setPts(int);
};

int Player::getPts()
{
	return pts;
}

void Player::setPts(int x)
{
	pts = x;
}

int main()
{
	int input, pts, max, maxind, digit, i;
	Player p[10];

	for(i = 0; i < 10; i++)
	{
		p[i].setPts(0);
	}

	cout << "Keep entering integers. Enter -1 to stop entering." << endl;

	for(;;)
	{
		cin >> input;

		if(input == -1)
			break;

		digit = input % 10;

		cout << "Player " << digit << " has won a point!" << endl;
		pts = p[digit].getPts();
		pts++;
		p[digit].setPts(pts);
	}

	cout << endl;
	max = p[0].getPts();
	maxind = 0;
	for(i = 0; i < 10; i++)
	{
		cout << "Player " << i << " has got " << p[i].getPts() << " points. " << endl;

		if(p[i].getPts() > max)
		{
			max = p[i].getPts();
			maxind = i;
		}
	}

	cout << "The winner is Player " << maxind << " with " << max << " points!" << endl;
}
