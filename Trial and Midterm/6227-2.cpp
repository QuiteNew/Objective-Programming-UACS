#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

class Skier {
private:
    char name[50];
    int jersey;
    double gate[50];

public:
    Skier() {
        strcpy(name, "");
        jersey = 0;
        for (int i = 0; i < 50; i++) {
            gate[i] = 0.0;
        }
    }

    Skier(const char* skierName) {
        strncpy(name, skierName, 50);
        name[49] = '\0';
        jersey = rand() % 99 + 1;
        for (int i = 0; i < 50; i++) {
            gate[i] = (rand() % 100 + 1) / 10.0;
        }
    }

    double total() const {
        double sum = 0.0;
        for (int i = 0; i < 50; i++) {
            sum += gate[i];
        }
        return sum;
    }

    void info() const {
        cout << "Name: " << name << ", Jersey: " << jersey << ", Total Time: " << total() << " seconds" << endl;
    }
};

int main() {
    srand(time(0));

    Skier* skiers[10];

    for (int i = 0; i < 10; i++) {
        char skierName[50];
        cout << "Enter name for skier " << i + 1 << ": ";
        cin >> skierName;
        skiers[i] = new Skier(skierName);
    }

    cout << "\nSkier Info:\n";
    for (int i = 0; i < 10; i++) {
        skiers[i]->info();
    }

    Skier* winner = skiers[0];
    for (int i = 1; i < 10; i++) {
        if (skiers[i]->total() < winner->total()) {
            winner = skiers[i];
        }
    }

    cout << "\nWinner:\n";
    winner->info();

    for (int i = 0; i < 10; i++) {
        delete skiers[i];
    }

    return 0;
}