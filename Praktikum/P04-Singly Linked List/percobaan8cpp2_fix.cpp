#include <iostream>
using namespace std;

// Definisi struktur node
struct Node {
    int data; // Data yang disimpan di node
    Node* next; // Pointer ke node berikutnya
};

// Fungsi rekursif untuk mendapatkan nilai data dari node ke-N
// head: pointer ke node pertama
// index: posisi node yang ingin diambil (dimulai dari 0)
int GetNth(Node* head, int index) {
    if (head == nullptr) {
        throw out_of_range("Index di luar jangkauan");
    }
    if (index == 0) {
        return head->data; // Mengembalikan data jika index adalah 0
    }
    return GetNth(head->next, index - 1); // Rekursi ke node berikutnya
}

// Fungsi untuk menambahkan node baru di awal linked list
// head: pointer ke pointer node pertama
// new_data: data baru yang akan ditambahkan
void push(Node** head, int new_data) {
    Node* new_node = new Node(); // Membuat node baru
    new_node->data = new_data; // Mengisi data pada node baru
    new_node->next = *head; // Menunjuk node pertama sebagai node berikutnya
    *head = new_node; // Mengubah head ke node baru
}

// Fungsi utama
int main() {
    Node* head = nullptr; // Inisialisasi linked list kosong
    
    // Menambahkan elemen ke linked list
    push(&head, 5); 
    push(&head, 92); 
    push(&head, 20); 
    push(&head, 190); 
    push(&head, 36); 
    
    try {
        int index = 5; // Indeks yang ingin dicari
        cout << "Elemen pada indeks " << index << " adalah " << GetNth(head, index) << endl;
    } catch (const out_of_range& e) {
        cout << e.what() << endl; // Menampilkan pesan kesalahan jika indeks di luar jangkauan
    }
    
    return 0;
}