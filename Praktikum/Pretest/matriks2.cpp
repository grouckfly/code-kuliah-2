#include <iostream>
#include <vector>
#include <stdexcept>

// Using directive is generally discouraged in header files, but for simplicity, we'll use it here
using namespace std;

// Type alias for a 2D vector of integers
typedef vector<vector<int> > Matrix;

// Function to multiply two matrices
Matrix multiplyMatrices(const Matrix& a, const Matrix& b) {
    int rowsA = a.size();
    int colsA = a[0].size();
    int colsB = b[0].size();

    // Check if matrices can be multiplied
    if (colsA != b.size()) {
        throw runtime_error("Matrices cannot be multiplied");
    }

    Matrix result(rowsA, vector<int>(colsB, 0));

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}

// Function to print a matrix
void printMatrix(const Matrix& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    try {
        Matrix a = {
            {1, 2},
            {3, 4}
        };

        Matrix b = {
            {5, 6},
            {7, 8}
        };

        Matrix result = multiplyMatrices(a, b);

        cout << "Hasil perkalian matriks:" << endl;
        printMatrix(result);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}