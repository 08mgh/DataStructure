#include <iostream>
using namespace std;

class IntVector {
private:
    int data[100]; 
    int size;

public:
    IntVector() {
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool empty() {
        return size == 0;
    }

    int get(int index) {

    }

    int find(int value) {
    }

    void insert(int index, int value) {
    }

    int remove(int index) {
        return 0; 
    }

    void print() {
    }
};

int main() {
    IntVector v;

    v.insert(2, 25);
    v.insert(10, 99);

    cout << "remove(1) returns: " << v.remove(1) << endl; 
    cout << "remove(4) returns: " << v.remove(4) << endl;

    v.get(2);
    v.get(4);
    v.find(30);
    v.find(99);

    IntVector other;
    other.insert(1, 10);
    other.print();

    return 0;
}