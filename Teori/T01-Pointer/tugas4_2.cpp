#include <iostream>
#include <ctime>
using namespace std;

// Fungsi untuk mengembalikan array angka ganjil
int *getGanjil(){
    static int r[10];

    // Set seed untuk random number generator
    srand( (unsigned)time( NULL ) );

    // Loop untuk mengisi array dengan angka ganjil
    for (int i = 0; i < 10; ++i){
        // Menghasilkan angka random antara 1 dan 100
        int random = rand() % 100 + 1;

        // Jika angka random adalah ganjil, maka simpan ke array
        if (random % 2 != 0){
            r[i] = random;
        } else {
            // Jika angka random adalah genap, maka ulangi proses
            i--;
        }
    }

    return r;
}

// Fungsi main
int main(){
    // Pointer ke integer
    int *p;

    p = getGanjil();

    // Loop untuk mencetak array angka ganjil
    for (int i = 0; i < 10; i++){
        cout << "*(p + " << i << ") : ";
        cout << *(p + i) << endl;
    }

    return 0;
}