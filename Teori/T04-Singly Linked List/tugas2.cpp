#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to push a node at the beginning
void push(Node*& head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Function to insert a node after a given node
void insertAfter(Node* prevNode, int data) {
    if (prevNode == nullptr) {
        cout << "Previous node cannot be null." << endl;
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to append a node at the end
void append(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to count the number of nodes in the linked list
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* head = nullptr;
    int numNodes, data, position, choice;

    cout << "Masukkan jumlah node: ";
    cin >> numNodes;

    for (int i = 1; i <= numNodes; i++) {
        cout << "Masukkan data untuk node ke-" << i << ": ";
        cin >> data;

        cout << "Tambahkan di (0) Selesai (1) Awal, (2) Tengah, (3) Akhir: ";
        cin >> choice;

        switch (choice) {
            case 1: // Tambahkan di awal
                push(head, data);
                break;
            case 2: // Tambahkan di tengah
                cout << "Masukkan posisi (0-based index) setelah node keberapa: ";
                cin >> position;
                {
                    Node* temp = head;
                    for (int j = 0; j < position && temp != nullptr; j++) {
                        temp = temp->next;
                    }
                    if (temp != nullptr) {
                        insertAfter(temp, data);
                    } else {
                        cout << "Posisi tidak valid!" << endl;
                    }
                }
                break;
            case 3: // Tambahkan di akhir
                append(head, data);
                break;
            case 0: // Selesai
                cout << "Selesai menambahkan node." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    }

    cout << "\nLinked List akhir: ";
    displayList(head);

    // Display the number of nodes in the linked list
    cout << "Jumlah node dalam linked list: " << countNodes(head) << endl;

    return 0;
}