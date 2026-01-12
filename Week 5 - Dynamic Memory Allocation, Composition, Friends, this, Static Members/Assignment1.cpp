#include <iostream>
using namespace std;


class storekeeper;

class store {
	friend class storekeeper;
public:
	store(){
		numitems=0;
	}
	int show(){
		return numitems;
	}

private:
	int numitems;
};


class storekeeper {

public:
 void add_items(store &s){
	if(s.numitems>100)
		cout<<"No more room in the store\n";
	else
		s.numitems++;
	}

 void remove_items(store &s){
	if(s.numitems==0)
		cout<<"No more items in the store\n";
	else
		s.numitems--;
	}
};


void main(){

	store Store;
	storekeeper Storekeeper;

	Storekeeper.add_items(Store);
	cout<<"There are "<<Store.show()<<" items in the store\n";
	Storekeeper.remove_items(Store);
	Storekeeper.remove_items(Store);
	cout<<"There are "<<Store.show()<<" items in the store\n";
	Storekeeper.add_items(Store);
	cout<<"There are "<<Store.show()<<" items in the store\n";
	Storekeeper.add_items(Store);
	cout<<"There are "<<Store.show()<<" items in the store\n";
}
