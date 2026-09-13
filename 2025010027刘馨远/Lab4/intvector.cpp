#include <iostream>

#define MAX_SIZE 100

class IntVector {
private:
    int data[MAX_SIZE];
    int size;

public:

    IntVector() {
        size = 0;
    }

    int getSize() const {
        return size;
    }

    bool empty() const {
        return size == 0;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i];
            if (i < size - 1) std::cout << " ";
        }
        std::cout << std::endl;
    }

    bool insert(int index, int value) {

        if (size == MAX_SIZE) return false;

        if (index < 0 || index > size) return false;

        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
        return true;
    }

    bool remove(int index, int& removed) {
        if (index < 0 || index >= size) return false;
        removed = data[index];
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        return true;
    }
};

int main() {
    IntVector v;

    v.insert(0, 10);
    v.insert(1, 20);
    v.insert(2, 30);
    v.insert(3, 40);

    std::cout << "初始: ";
    v.print();

    std::cout << "insert(2, 25) returns " << v.insert(2, 25) << std::endl;
    v.print();

    int removed;
    std::cout << "remove(1) returns " << v.remove(1, removed)
              << ", removed value is " << removed << std::endl;
    v.print();

    std::cout << "insert(10, 99) returns " << v.insert(10, 99) << std::endl;
    v.print();

    std::cout << "remove(4) returns " << v.remove(4, removed) << std::endl;
    v.print();

    return 0;
}