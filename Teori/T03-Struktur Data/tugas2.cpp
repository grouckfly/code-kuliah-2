#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <chrono>
#include <thread>
#include <fstream> // Tambahkan header untuk file handling

struct Mahasiswa {
    std::string nama;
    int no_id;
    std::string jenis_kelamin;
    std::string kelas;
};

// Fungsi untuk menyimpan data mahasiswa ke dalam file
void simpanDataMahasiswa(const std::vector<Mahasiswa>& mhs) {
    std::ofstream file("mahasiswa.txt");
    if (!file) {
        std::cerr << "Gagal membuka file untuk menulis data." << std::endl;
        return;
    }
    for (const auto& mahasiswa : mhs) {
        file << mahasiswa.nama << '\n'
             << mahasiswa.no_id << '\n'
             << mahasiswa.jenis_kelamin << '\n'
             << mahasiswa.kelas << '\n';
    }
}

// Fungsi untuk membaca data mahasiswa dari file
std::vector<Mahasiswa> bacaDataMahasiswa() {
    std::vector<Mahasiswa> mhs;
    std::ifstream file("mahasiswa.txt");
    if (!file) {
        std::cerr << "Gagal membuka file untuk membaca data." << std::endl;
        return mhs;
    }
    Mahasiswa mahasiswa;
    while (std::getline(file, mahasiswa.nama)) {
        file >> mahasiswa.no_id;
        file.ignore(); // Ignore newline character
        std::getline(file, mahasiswa.jenis_kelamin);
        std::getline(file, mahasiswa.kelas);
        mhs.push_back(mahasiswa);
    }
    return mhs;
}

void cariMahasiswa(const std::vector<Mahasiswa>& mhs, int no_id) {
    for (const auto& mahasiswa : mhs) {
        if (mahasiswa.no_id == no_id) {
            std::cout << "Mahasiswa ditemukan!" << std::endl;
            std::cout << "Nama: " << mahasiswa.nama << std::endl;
            std::cout << "No Id: " << mahasiswa.no_id << std::endl;
            std::cout << "Jenis Kelamin: " << mahasiswa.jenis_kelamin << std::endl;
            std::cout << "Kelas: " << mahasiswa.kelas << std::endl;
            return;
        }
    }
    std::cout << "Mahasiswa tidak ditemukan!" << std::endl;
}

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

    // Simpan data mahasiswa ke dalam file
    simpanDataMahasiswa(mhs);

    // Tampilkan data mahasiswa
    for (int i = 0; i < jml_mhs; i++) {
        std::cout << "Mahasiswa " << i + 1 << ":" << std::endl;
        std::cout << "Nama: " << mhs[i].nama << std::endl;
        std::cout << "No Id: " << mhs[i].no_id << std::endl;
        std::cout << "Jenis Kelamin: " << mhs[i].jenis_kelamin << std::endl;
        std::cout << "Kelas: " << mhs[i].kelas << std::endl;
        std::cout << std::endl;
    }

    // Baca data mahasiswa dari file
    std::vector<Mahasiswa> mhs_dari_file = bacaDataMahasiswa();

    // Tampilkan data mahasiswa yang dibaca dari file
    std::cout << "Data mahasiswa yang dibaca dari file:" << std::endl;
    for (const auto& mahasiswa : mhs_dari_file) {
        std::cout << "Nama: " << mahasiswa.nama << std::endl;
        std::cout << "No Id: " << mahasiswa.no_id << std::endl;
        std::cout << "Jenis Kelamin: " << mahasiswa.jenis_kelamin << std::endl;
        std::cout << "Kelas: " << mahasiswa.kelas << std::endl;
        std::cout << std::endl;
    }

    // Cari mahasiswa berdasarkan no_id
    int cari_no_id;
    std::cout << "Masukkan No Id mahasiswa yang ingin dicari: ";
    std::cin >> cari_no_id;
    cariMahasiswa(mhs, cari_no_id);

    return 0;
}