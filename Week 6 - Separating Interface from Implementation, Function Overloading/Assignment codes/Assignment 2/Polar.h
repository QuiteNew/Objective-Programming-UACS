class Cartesian;

class Polar
{
	double r, f;

public:
	double getR();
	double getF();
	Polar();
	Polar(double, double);
	void print();
	static Polar toPolar(Cartesian);
};
