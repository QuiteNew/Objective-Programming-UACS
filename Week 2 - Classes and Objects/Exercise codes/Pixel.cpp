#include <iostream>
using namespace std;


class Pixel {
public:
   int getx() { return x; }
   int gety() { return y; }
   void set ();
   void DrawPixel();
   void Copy(Pixel &);
private:
   int x, y;
};

void Pixel::set () {
	cout<<"x=";	cin>>x;      cout<<"y=";	cin>>y;
}

void Pixel::DrawPixel() {
	cout<<"(x,y)="<<x<<","<<y<<endl;
}

void Pixel::Copy(Pixel & Source) {
	x=Source.x;
	y=Source.y;
}

int main()
{
   Pixel p1,p2,p4[5];
   p1.set();
   cout << "Show the private members ";
   cout <<p1.getx()<<"  "<<p1.gety()<<endl;
   cout << "for p1";
   p1.DrawPixel();
   p2.Copy(p1);

   cout << "for p2";
   p2.DrawPixel();
   p4[2].set();

   cout << "for p4[2]";
   p4[2].DrawPixel();

   p4[1].Copy(p4[2]);

   cout << "for p4[1]";
   p4[1].DrawPixel();


}
