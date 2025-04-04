#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <chrono>
#include <thread>

struct Mahasiswa {
    std::string nama;
    int no_id;
    std::string jenis_kelamin;
    std::string kelas;
};

int main() {
    int jml_mhs;
    std::cout << "Masukkan jumlah mahasiswa: ";
    std::cin >> jml_mhs;

    // Validasi input
    if (jml_mhs <= 0) {
        std::cerr << "Jumlah mahasiswa tidak valid. Silakan masukkan nilai positif." << std::endl;
        return 1;
    }

    std::vector<Mahasiswa> mhs(jml_mhs);

    // Input data mahasiswa
    for (int i = 0; i < jml_mhs; i++) {
        std::cout << "Mahasiswa " << i + 1 << ":" << std::endl;
        std::cout << "Nama: ";
        std::cin.ignore(); // Ignore newline character yang tersisa di buffer input
        std::getline(std::cin, mhs[i].nama);
        std::cout << "No Id: ";
        std::cin >> mhs[i].no_id;
        std::cout << "Jenis Kelamin: ";
        std::cin.ignore(); // Ignore newline character yang tersisa di buffer input
        std::getline(std::cin, mhs[i].jenis_kelamin);
        std::cout << "Kelas: ";
        std::getline(std::cin, mhs[i].kelas);
        std::cout << std::endl;
    }

    // Tampilkan data mahasiswa
    for (int i = 0; i < jml_mhs; i++) {
        std::cout << "Mahasiswa " << i + 1 << ":" << std::endl;
        std::cout << "Nama: " << mhs[i].nama << std::endl;
        std::cout << "No Id: " << mhs[i].no_id << std::endl;
        std::cout << "Jenis Kelamin: " << mhs[i].jenis_kelamin << std::endl;
        std::cout << "Kelas: " << mhs[i].kelas << std::endl;
        std::cout << std::endl;
    }

    // Tunda eksekusi program
    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}