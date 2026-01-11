#include <iostream>
using namespace std;


//definition of the class rectangle
class rectangle {
	double a, b;//data members
public:
	void set_a(double number);//declaration of set_a
	void set_b(double number);// declaration of set_b

	double get_a();//declaration of get_a
	double get_b();//declaration of get_b

	double perimeter();//declaration of perimetar
	double area();//declaration of plostina

};

// definition of set_a
void rectangle:: set_a(double number){
	a= number;
}

// definition of set_b
void rectangle:: set_b(double number){
	b= number;
}

// definition of get_a
double rectangle:: get_a(){
	return a;
}

// definition of get_b
double rectangle:: get_b(){
	return b;
}

// definition of perimeter
double rectangle::perimeter(){
	return 2*a+2*b;
}

// definition of area
double rectangle::area(){
	return a*b;
}

int main(){

	rectangle P;//create a rectangle object

	P.set_a(4);
	P.set_b(10);

	cout<<"a="<<P.get_a()<<endl;
	cout<<"b="<<P.get_b()<<endl;

	cout<<"The perimeter is "<<P.perimeter()<<endl;
	cout<<"The area is "<<P.area()<<endl;

}
