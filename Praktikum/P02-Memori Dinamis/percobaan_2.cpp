#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <chrono>
using namespace std;
int main()
{
    double *pvalue = NULL; // Pointer initialized with null
    pvalue = new double;   // Request memory for the variable
    *pvalue = 29494.99;    // Store value at allocated address
    cout << "Value of pvalue : " << *pvalue << endl;
    delete pvalue; // free up the memory.
    this_thread::sleep_for(chrono::milliseconds(50000));
    return 0;
}