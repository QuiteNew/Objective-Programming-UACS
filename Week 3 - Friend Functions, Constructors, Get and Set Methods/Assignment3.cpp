#include <iostream>
#include <cmath>
using namespace std;

class Car
{
	int liters;
	double consumption;

public:
	Car();
	Car(int, double);
	~Car();
	double maxDistance();
};

Car::Car()
{
	liters = 40;
	consumption = 0.1;
	cout << "A car that has a fuel capacity of 40 liters and consumes 0.1 l/km is created" << endl;
}

Car::Car(int l, double c)
{
	liters = l;
	consumption = c;
	cout << "A car that has a fuel capacity of " << liters << " liters and consumes " << consumption << " l/km is created" << endl;
}

Car::~Car()
{
	cout << "A car that has a fuel capacity of " << liters << " liters and consumes " << consumption << " l/km is destroyed" << endl;
}

double Car::maxDistance()
{
	return liters/consumption;
}



int main()
{
	Car c1;
	cout << "This car can drive at most " << c1.maxDistance() << " kilometers on a single tank" << endl;

	Car c2(50, 0.2);
	cout << "This car can drive at most " << c2.maxDistance() << " kilometers on a single tank" << endl;

	Car *c3 = new Car(60, 0.25);
	cout << "This car can drive at most " << c3->maxDistance() << " kilometers on a single tank" << endl;

    return 0;
}
