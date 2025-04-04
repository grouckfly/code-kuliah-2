#include <iostream>

// Function to modify array elements using references
void modifyArray(int (&arr)[5], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] += 1; // Increment each element by 1
    }
}

int main() {
    int myArray[5] = {1, 2, 3, 4, 5};

    std::cout << "Before modification: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    modifyArray(myArray, 5); // Call the function to modify the array

    std::cout << "After modification: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}