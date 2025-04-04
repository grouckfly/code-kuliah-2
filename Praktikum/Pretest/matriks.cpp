#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

Matrix multiplyMatrices(const Matrix &a, const Matrix &b) {
    int rowsA = a.size();
    int colsA = a[0].size();
    int colsB = b[0].size();
    
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

void printMatrix(const Matrix &matrix) {
    for (const auto &row : matrix) {
        for (const auto &elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
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

    return 0;
}