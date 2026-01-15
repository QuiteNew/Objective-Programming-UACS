#include <iostream>
using namespace std;
#include <string>

class Animal
{
public:
	string name;
	Animal(string);
	virtual string call();
};

Animal::Animal(string name)
{
	this->name = name;
}

string Animal::call()
{
	return "*none*";
}



class Lion : public Animal
{
public:
	Lion(string);
	string call();
};

Lion::Lion(string name) : Animal(name)
{
}

string Lion::call()
{
	return "ROAR";
}



class Frog : public Animal
{
public:
	Frog(string);
	string call();
};

Frog::Frog(string name) : Animal(name)
{
}

string Frog::call()
{
	return "CROAK";
}



class Dog : public Animal
{
public:
	Dog(string);
	string call();
};

Dog::Dog(string name) : Animal(name)
{
}

string Dog::call()
{
	return "ARF ARF";
}



class SaraMountainDog : public Dog
{
public:
	SaraMountainDog(string);
	string call();
	void features();
};

SaraMountainDog::SaraMountainDog(string name) : Dog(name)
{
}

string SaraMountainDog::call()
{
	return "WOOF WOOF";
}

void SaraMountainDog::features()
{
	cout << "The Sara Mountain Dog " << name << " is the champion of Macedonia for 2010" << endl;
}



int main()
{
	Animal *a;

	a = new Animal("Nessie");
	cout << "The sound of " << a->name << " is " << a->call() << endl;

	a = new Lion("Simba");
	cout << "The sound of " << a->name << " is " << a->call() << endl;

	a = new Frog("Kermit");
	cout << "The sound of " << a->name << " is " << a->call() << endl;

	a = new Dog("Rex");
	cout << "The sound of " << a->name << " is " << a->call() << endl;

	a = new SaraMountainDog("Sarko");
	cout << "The sound of " << a->name << " is " << a->call() << endl;
	((SaraMountainDog *)a)->features();
}
