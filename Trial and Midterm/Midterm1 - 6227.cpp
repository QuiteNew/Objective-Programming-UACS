#include <iostream>
using namespace std;

class Box {
private:
    double length, width, height;

public:
    Box(double l, double w, double h) : length(l), width(w), height(h) {}
    double volume() const {
        return length * width * height;
    }
    double surface() const {
        return 2 * (height * width) + 2 *(lenght* height) + 2* (width * length);
    }
};

int main() {
    int numBoxes;
    cin >> numBoxes;
    Box* boxes = new Box[numBoxes];

    for (int i = 0; i < numBoxes; i++) {
        double l, w, h;
        cin >> l >> w >> h;
        boxes[i] = Box(l, w, h);
    }

    for (int i = 0; i < numBoxes; i++) {
        cout << boxes[i].volume() << " " << boxes[i].surface() << endl;
    }

    delete[] boxes;

    return 0;
}

