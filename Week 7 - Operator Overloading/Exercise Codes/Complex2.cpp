#include <iostream>
using namespace std;

class Complex
{
	double r, i;

public:
	Complex();
	Complex(double);
	Complex(double, double);
	void show();
	friend Complex operator+(Complex, Complex);
	friend Complex operator-(Complex, Complex);
	friend Complex operator*(Complex, Complex);
	friend Complex operator/(Complex, Complex);

	friend Complex operator+(Complex, double);
	friend Complex operator+(double, Complex);
	friend Complex operator-(Complex, double);
	friend Complex operator-(double, Complex);
	friend Complex operator*(Complex, double);
	friend Complex operator*(double, Complex);
	friend Complex operator/(Complex, double);
	friend Complex operator/(double, Complex);
};

Complex::Complex()
{
	r = 0;
	i = 0;
}

Complex::Complex(double r)
{
	this->r = r;
	i = 0;
}

Complex::Complex(double r, double i)
{
	this->r = r;
	this->i = i;
}

void Complex::show()
{
	cout << r << " + " << i << "*i";
}

Complex operator+(Complex a, Complex b)
{
	double real = a.r + b.r;
	double imag = a.i + b.i;
	Complex c(real, imag);
	return c;
}

Complex operator-(Complex a, Complex b)
{
	double real = a.r - b.r;
	double imag = a.i - b.i;
	Complex c(real, imag);
	return c;
}

Complex operator*(Complex a, Complex b)
{
	double real = a.r*b.r + a.i*b.i;
	double imag = a.r*b.i + a.i*b.r;
	Complex c(real, imag);
	return c;
}

Complex operator/(Complex a, Complex b)
{
	double d = b.r*b.r + b.i*b.i;
	double real = (a.r*b.r + a.i*b.i)/d;
	double imag = (a.i*b.r - a.r*b.i)/d;
	Complex c(real, imag);
	return c;
}



Complex operator+(Complex a, double b)
{
	Complex c(b);
	return a+c;
}

Complex operator+(double a, Complex b)
{
	Complex c(a);
	return c+b;
}

Complex operator-(Complex a, double b)
{
	Complex c(b);
	return a-c;
}

Complex operator-(double a, Complex b)
{
	Complex c(a);
	return c-b;
}
Complex operator*(Complex a, double b)
{
	Complex c(b);
	return a*c;
}

Complex operator*(double a, Complex b)
{
	Complex c(a);
	return c*b;
}
Complex operator/(Complex a, double b)
{
	Complex c(b);
	return a/c;
}

Complex operator/(double a, Complex b)
{
	Complex c(a);
	return c/b;
}



int main()
{
	double r, i;

	cout << "Enter the real and imaginary parts of the first Complex number: ";
	cin >> r >> i;
	Complex a(r, i);
	cout << "a = ";
	a.show();
	cout << endl;

	cout << "Enter the real and imaginary parts of the second Complex number: ";
	cin >> r >> i;
	Complex b(r, i);
	cout << "b = ";
	b.show();
	cout << endl;

	cout << endl;
	Complex c;
	c = a+b;
	cout << "a+b = ";
	c.show();
	cout << endl;
	c = a-b;
	cout << "a-b = ";
	c.show();
	cout << endl;
	c = a*b;
	cout << "a*b = ";
	c.show();
	cout << endl;
	c = a/b;
	cout << "a/b = ";
	c.show();

	cout << endl;
	double d;
	cout << "\nEnter a double number: ";
	cin >> d;
	cout << "d = " << d << endl << endl;
	c = a+d;
	cout << "a+d = ";
	c.show();
	cout << endl;
	c = a-d;
	cout << "a-d = ";
	c.show();
	cout << endl;
	c = a*d;
	cout << "a*d = ";
	c.show();
	cout << endl;
	c = a/d;
	cout << "a/d = ";
	c.show();
	cout << endl;

	cout << endl;
	c = d+b;
	cout << "d+b = ";
	c.show();
	cout << endl;
	c = d-b;
	cout << "d-b = ";
	c.show();
	cout << endl;
	c = d*b;
	cout << "d*b = ";
	c.show();
	cout << endl;
	c = d/b;
	cout << "d/b = ";
	c.show();
	cout << endl;
}
