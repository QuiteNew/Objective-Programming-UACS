#include <iostream>
using namespace std;

class Base
{
public:
	virtual void f()
	{
		cout <<"Base class f()"<<endl;
	}
};

class Derived : public Base
{
public:
	void f()
	{
		cout<<"Derived class f() - overriden Base f()"<<endl;
	}
};

int main()
{
	Base  x, y;
	Derived z;

//	x = new Base();
	x.f();

//	y = new Derived();
	y = z;
	y.f();
}
