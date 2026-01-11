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
	int input, pts1 = 0, pts2 = 0;
	Player p1, p2;

	p1.setPts(pts1);
	p2.setPts(pts2);

	cout << "Keep entering integers. Enter -1 to stop entering." << endl;

	for(;;)		// infinite loop
	{
		cin >> input;

		if(input == -1)
			break;

		if(input % 2 != 0)
		{
			cout << "Player 1 has won a point!" << endl;
			pts1 = p1.getPts();
			pts1++;
			p1.setPts(pts1);
		}
		else
		{
			cout << "Player 2 has won a point!" << endl;
			pts2 = p2.getPts();
			pts2++;
			p2.setPts(pts2);
		}
	}

	cout << "Player 1 has got " << p1.getPts() << " points." << endl;
	cout << "Player 2 has got " << p2.getPts() << " points." << endl;
}
