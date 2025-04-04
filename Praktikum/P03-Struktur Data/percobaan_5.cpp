#include <iostream>
#include <string>
#include <vector>

struct Fisik {
    std::string caraBergerak;
    struct {
        std::string mediaGerak;
        int jml;
    } gerak;
    std::string caraBerkembangbiak;
};

struct Makhluk {
    std::string nama;
    Fisik ph;
};

int main() {
    int jml;
    std::cout << "Masukkan jumlah makhluk: ";
    std::cin >> jml;

    std::vector<Makhluk> makhluk(jml);

    for (int i = 0; i < jml; i++) {
        std::cout << "Masukkan nama makhluk ke-" << i + 1 << ": ";
        std::cin.ignore();
        std::getline(std::cin, makhluk[i].nama);

        std::cout << "Masukkan cara bergeraknya: ";
        std::getline(std::cin, makhluk[i].ph.caraBergerak);

        std::cout << "Dengan media apa makhluk tersebut bergerak: ";
        std::getline(std::cin, makhluk[i].ph.gerak.mediaGerak);

        std::cout << "Berapa jumlah kaki/sirip/sayap makhluk tersebut: ";
        std::cin >> makhluk[i].ph.gerak.jml;
        std::cin.ignore();

        std::cout << "Dengan cara apa makhluk berkembangbiak: ";
        std::getline(std::cin, makhluk[i].ph.caraBerkembangbiak);

        std::cout << "\n";
    }

    std::cout << "\n\n";

    for (int i = 0; i < jml; i++) {
        std::cout << "Nama makhluk: " << makhluk[i].nama << "\n";
        std::cout << "Cara bergerak dengan " << makhluk[i].ph.caraBergerak << "\n";
        std::cout << "Media makhluk tersebut bergerak: " << makhluk[i].ph.gerak.mediaGerak << "\n";
        std::cout << "Jumlah kaki/sirip/sayap makhluk tersebut: " << makhluk[i].ph.gerak.jml << "\n";
        std::cout << "Cara makhluk berkembangbiak: " << makhluk[i].ph.caraBerkembangbiak << "\n";
        std::cout << "\n";
    }

    return 0;
}