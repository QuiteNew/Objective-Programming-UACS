#include <iostream>
#include <vector>
#include "Book.h"
#include "IssuedBook.h"

using namespace std;

const int MAX_PAGES_PER_DAY = 1000;

int main() {
    Book* b1 = new Book("C++ Programming", 500);
    Book* b2 = new Book("History of Mathematics", 300);
    Book* b3 = new Book("Data Structures", 450);

    Book* i1 = new IssuedBook("Clean Code", 350, "Alice");
    Book* i2 = new IssuedBook("Modern Physics", 400, "Bob");

    vector<Book*> library;
    library.push_back(b1);
    library.push_back(b2);
    library.push_back(b3);
    library.push_back(i1);
    library.push_back(i2);

    for (int i = 0; i < library.size(); i++) {
        cout << i << ") ";
        library[i]->display();
    }

    for (Book* item : library) {
        IssuedBook* issued = dynamic_cast<IssuedBook*>(item);
        if (issued) {
            cout << "Borrowed by " << issued->borrowerName << endl;
        }
    }

    cout << endl << "Issued books only:" << endl;
    for (Book* item : library) {
        if (dynamic_cast<IssuedBook*>(item)) {
            item->display();
        }
    }

    int totalPages = 0;
    int choice;

    while (true) {
        cout << "Select book index (-1 to stop): ";
        cin >> choice;

        if (choice == -1) break;

        if (choice >= 0 && choice < library.size()) {
            totalPages += library[choice]->pages;
            cout << "Total pages today: " << totalPages << endl;

            if (totalPages > MAX_PAGES_PER_DAY) {
                cout << "WARNING: Daily page limit exceeded" << endl;
            }
        }
    }

    for (Book* item : library) {
        delete item;
    }

    return 0;
}