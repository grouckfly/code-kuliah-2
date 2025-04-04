#include <iostream>

int main() {
    int a = 0, b = 1, next = 0;

    std::cout << "Fibonacci Hingga 300:" << std::endl;

    while (next <= 300) {
        std::cout << next << " ";
        a = b;
        b = next;
        next = a + b;
    }

    std::cout << std::endl;
    return 0;
}