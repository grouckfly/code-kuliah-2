#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <chrono>
using namespace std;
class Box
{
public:
    Box()
    {
        cout << "Constructor called!" << endl;
    }
    ~Box()
    {
        cout << "Destructor called!" << endl;
    }
};
int main()
{
    Box *myBoxArray = new Box[4];
    delete[] myBoxArray; // Delete array
    std::this_thread::sleep_for(std::chrono::milliseconds(50000));
    return 0;
}