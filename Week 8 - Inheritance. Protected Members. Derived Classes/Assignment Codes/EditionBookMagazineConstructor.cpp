#include <iostream>
#include <string>
using namespace std;

class Edition {
public:
	void set_title(string);
	string get_title();
	Edition(string);

private:
	string title;
};

void Edition::set_title(string a)
{
		title=a;
}

string Edition::get_title()
{
		return title;
}

Edition::Edition(string t)
{
	set_title(t);
}



class Book : public Edition {
public:
	void set_author(string);
	string get_author();
	Book(string, string);

private:
	string author;
};

void Book::set_author(string a)
{
		author=a;
}

string Book::get_author()
{
		return author;
}

Book::Book(string t, string a) : Edition(t)
{
	set_author(a);
}



class Magazine : public Edition {
public:
	void set_copies(int);
	int get_copies();
	Magazine(string, int);

private:
	int copies;
};

void Magazine::set_copies(int a)
{
		copies=a;
}

int Magazine::get_copies()
{
		return copies;
}

Magazine::Magazine(string t, int c) : Edition(t)
{
	set_copies(c);
}


int main ()
{
	Book K("Thinking in C++", "Bruce Eckel");
	Magazine S("Kompletna", 20000);
	cout<<"The book has title "<<K.get_title()
		<<" and the author is "<<K.get_author()<<endl;
	cout<<"The magazine has title "<<S.get_title()
		<<" and number of copies "<<S.get_copies()<<endl;
}
