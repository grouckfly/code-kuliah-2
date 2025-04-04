#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main()
{
    double *pvalue = NULL;
    if (!(pvalue = new double))
    {
        cout << "Error: out of memory." << endl;
        exit(1);
    }
    this_thread::sleep_for(chrono::milliseconds(50000));
    delete pvalue;
    return 0;
}