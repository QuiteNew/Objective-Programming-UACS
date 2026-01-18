#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

using namespace std;

class Book {
public:
    string title;
    int pages;

    Book(string t, int p) {
        title = t;
        pages = p;
    }

    virtual ~Book() {}

    virtual void display() {
        cout << "Book: " << title << " (" << pages << " pages)" << endl;
    }
};

#endif