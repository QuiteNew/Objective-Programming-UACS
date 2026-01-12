#include <iostream>
using namespace std;

class Counter {
   friend void setX( Counter &, int ); 
public:
   Counter() { x = 0; }
   void print()  { cout << x << endl; }
private:
   int x;  
}; 


void setX( Counter &c, int val )
{
   c.x = val;  
}


int main()
{
   Counter counter;

   cout << "counter.x after instantiation: ";
   counter.print();
   cout << "counter.x after invoking the setX friend function: ";
   setX( counter, 8 );
   counter.print();
   return 0;
}
