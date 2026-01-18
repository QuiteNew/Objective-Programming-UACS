#ifndef ISSUEDBOOK_H
#define ISSUEDBOOK_H

#include "Book.h"

using namespace std;

class IssuedBook : public Book {
public:
    string borrowerName;

    IssuedBook(string t, int p, string b) : Book(t, p) {
        borrowerName = b;
    }

    void display() override {
        cout << "Issued Book: " << title << " (" << pages << " pages), Borrower: " << borrowerName << endl;
    }
};

#endif