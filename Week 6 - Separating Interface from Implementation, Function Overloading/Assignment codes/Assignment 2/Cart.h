class Polar;

class Cartesian
{
	double x, y;

public:
	double getX();
	double getY();
	Cartesian();
	Cartesian(double, double);
	void print();
	static Cartesian toCart(Polar);
};
