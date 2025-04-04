#include <iostream>
using namespace std;

int main() {
    int baris, kolom;

    // Meminta pengguna memasukkan ukuran array
    cout << "Masukkan jumlah baris: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom: ";
    cin >> kolom;

    // 1. Alokasi memori untuk array baris (pointer ke pointer)
    int** array = new int*[baris];

    // 2. Alokasi memori untuk setiap baris (array 1 dimensi)
    for (int i = 0; i < baris; i++) {
        array[i] = new int[kolom];
    }

    // 3. Memasukkan nilai ke dalam array
    cout << "\nMasukkan elemen array:\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "Elemen [" << i << "][" << j << "]: ";
            cin >> array[i][j];
        }
    }

    // 4. Menampilkan isi array
    cout << "\nIsi Array:\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }

    // 5. Membebaskan memori (harus dilakukan untuk menghindari memory leak)
    for (int i = 0; i < baris; i++) {
        delete[] array[i]; // Menghapus setiap baris
    }
    delete[] array; // Menghapus array utama

    cout << "\nMemori berhasil dibebaskan!" << endl;
    return 0;
}