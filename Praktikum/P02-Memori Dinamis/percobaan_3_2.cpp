#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include <thread>
#include <chrono>

int main()
{
    int i, j;
    int ROW = 5;
    int COL = 8;
    int SIZE = ROW * COL;
    double *pvalue = new double[SIZE]; // Allocate memory for 1D array

    // Initialize and print the 1D array
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            pvalue[i * COL + j] = 0.1;
            printf("%.2f\t", pvalue[i * COL + j]);
        }
        printf("\n");
    }

    delete[] pvalue; // Free the allocated memory
    std::this_thread::sleep_for(std::chrono::milliseconds(50000));
    return 0;
}