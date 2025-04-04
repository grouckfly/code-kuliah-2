#include <iostream>

// Function to swap using pointers
void swapPointers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to swap using references
void swapReferences(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;

    std::cout << "Before swapping (using pointers): x = " << x << ", y = " << y << std::endl;
    swapPointers(&x, &y);
    std::cout << "After swapping (using pointers): x = " << x << ", y = " << y << std::endl;

    // Reset values
    x = 5; 
    y = 10;

    std::cout << "Before swapping (using references): x = " << x << ", y = " << y << std::endl;
    swapReferences(x, y);
    std::cout << "After swapping (using references): x = " << x << ", y = " << y << std::endl;

    return 0;
}