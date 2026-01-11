#include <iostream>
using namespace std;

class CreateAndDestroy
{
public:
   CreateAndDestroy( int );  // constructor
   ~CreateAndDestroy();      // destructor

private:
   int data;
}; // end class CreateAndDestroy

CreateAndDestroy::CreateAndDestroy( int value )
{
   data = value;
   cout << "Object " << data << " is created";
}

CreateAndDestroy::~CreateAndDestroy()
{
	cout << "Object " << data << " is destroyed" << endl;
}

void f();   // prototype

CreateAndDestroy first( 1 );  // global object



int main()
{
   cout << "   (global before main)" << endl;
   CreateAndDestroy second( 2 ); 		// local

   cout << "   (local in main)" << endl;
   static CreateAndDestroy third( 3 ); 		// local
   cout << "   (local static in main)" << endl;

   f();  				// call function to create objects
   CreateAndDestroy fourth( 4 );        		// local
   cout << "   (local in main)" << endl;
   return 0;
}

// Function to create objects
void f()
{
   CreateAndDestroy fifth( 5 );
   cout << "   (local in f() )" << endl;

   static CreateAndDestroy sixth( 6 );
   cout << "   (local static in f() )" << endl;

   CreateAndDestroy seventh( 7 );
   cout << "   (local in f() )" << endl;
} // end function create
