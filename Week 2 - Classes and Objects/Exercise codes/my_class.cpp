#include <iostream>
using namespace std;

//Definition of my_class
class my_class {
	int a;//data member a
public:
	void set_a(int b);
  //declaration for set_a
	int get_a();
  //declaration for get_a
};

//definition for set_a
void my_class:: set_a(int b){
	a=b;
}

// definition for get_a
int my_class:: get_a(){
	return a;
}

//main() function
int main(){

	my_class ob1, ob2;
   //create two objects of my_class

	ob1. set_a(4);
	ob2. set_a(10);
	cout<<ob1.get_a()<<endl;
	cout<<ob2.get_a()<<endl;

}
