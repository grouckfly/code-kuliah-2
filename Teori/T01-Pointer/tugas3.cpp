#include <iostream>
using namespace std;
const int MAX = 3;

int ptr_increment(){
    int var[MAX] = {10, 100, 200};
    int *ptr;
    // let us have array address in pointer.
    ptr = var;
    for (int i = 0; i < MAX; i++)
    {
        cout << "Address of var[" << i << "] = ";
        cout << ptr << endl;
        cout << "Value of var[" << i << "] = ";
        cout << *ptr << endl;
        // point to the next location
        ptr+=2;
    }
    return 0;
}

int ptr_decrement(){
    int var[MAX] = {10, 100, 200};
    int *ptr;
    // let us have array address in pointer.
    ptr = &var[MAX-1];
    for (int i = MAX; i > 0; i--)
    {
        cout << "Address of var[" << i << "] = ";
        cout << ptr << endl;
        cout << "Value of var[" << i << "] = ";
        cout << *ptr << endl;
        // point to the next location
        ptr-=2;
    }
    return 0;
}

int main()
{
    cout << "Pointer increment +2" << endl;
    ptr_increment();
    cout << endl;
    cout << "Pointer decrement -2" << endl;
    ptr_decrement();
    return 0;
}