#include <iostream>
#include <cstring>

class MyClass {
private:
    char* data;

public:
    MyClass(const char* str) {
        // Allocate memory and copy the string
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Shallow copy constructor
    MyClass(const MyClass& other) {
        // Assign the pointer value
        data = other.data;
    }

    // Deep copy constructor
    MyClass deepCopy() {
        // Create a new instance and copy the string
        MyClass copy(data);
        return copy;
    }

    void printData() {
        std::cout << "Data: " << data << std::endl;
    }

    ~MyClass() {
        // Deallocate the memory
        delete[] data;
    }
};

int main() {
    MyClass original("Hello");

    // Shallow copy
    MyClass shallowCopy(original);

    // Deep copy
    MyClass deepCopy = original.deepCopy();

    // Modify the original and shallow copy
    original.printData();
    shallowCopy.printData();
    deepCopy.printData();

    original.printData();  // Original string is modified
    shallowCopy.printData();  // Shallow copy is also modified
    deepCopy.printData();  // Deep copy remains unchanged

    return 0;
}
