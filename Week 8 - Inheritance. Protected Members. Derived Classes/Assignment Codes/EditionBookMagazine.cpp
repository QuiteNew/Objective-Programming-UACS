#include <iostream>
#include <string>
using namespace std;

class Edition {
public:
	void set_title(string);
	string get_title();

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



class Book : public Edition {
public:
	void set_author(string);
	string get_author();

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



class Magazine : public Edition {
public:
	void set_copies(int);
	int get_copies();

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





int main ()
{
	Book K;
	Magazine S;
	K.set_title("Thinking in C++");
	K.set_author("Bruce Eckel");
	S.set_title("Wired");
	S.set_copies(20000);
	cout<<"The title of the book is "<<K.get_title()
		<<" and the author is "<<K.get_author()<<endl;
	cout<<"The title of the magazine is "<<S.get_title()
		<<" and the number of copies "<<S.get_copies()<<endl;
}
