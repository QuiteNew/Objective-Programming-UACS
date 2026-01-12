#include <iostream>
#include <string>
using namespace std;

class engineer; 

class mathematician
{
public:
	void show(engineer); //show e member function of mathematician
private:
	int index;
	char fullname[20];
};


class engineer
{
public:
	engineer(char s[20], int i)
	{
		strcpy(fullname, s);
		id=i;
	}
	friend void mathematician::show(engineer);
private:
	int id;
	char fullname[20];
};


void mathematician::show(engineer i)
{
	cout<<"Full name: "<<i.fullname<<" ID: "<<i.id<<endl;
}



void main()
{
	engineer I("Ivana Petrovska", 100);
	mathematician M;
	M.show(I);
}
