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

// Function to display the linked list in forward order
void displayListForward(Node* head) {
    Node* temp = head;
    cout << "Linked List (Forward): ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to display the linked list in reverse order using recursion
void displayListReverse(Node* head) {
    if (head == nullptr) {
        return;
    }
    displayListReverse(head->next);
    cout << head->data << " -> ";
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

// Function to search for a node in the linked list
void searchNode(Node* head, int key) {
    Node* temp = head;
    int position = 0;
    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "Data ditemukan pada posisi ke-" << position << endl;
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << "Data tidak ditemukan" << endl;
}

// Function to delete a node by value
void deleteNode(Node*& head, int key) {
    Node* temp = head;
    Node* prev = nullptr;

    // If the head node itself holds the key
    if (temp != nullptr && temp->data == key) {
        head = temp->next; // Change head
        delete temp;       // Free old head
        cout << "Node dengan nilai " << key << " dihapus." << endl;
        return;
    }

    // Search for the key to be deleted
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not present in the list
    if (temp == nullptr) {
        cout << "Data tidak ditemukan." << endl;
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    delete temp; // Free memory
    cout << "Node dengan nilai " << key << " dihapus." << endl;
}

// Function to delete a node by position
void deleteNodeAtPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "Linked list kosong." << endl;
        return;
    }

    Node* temp = head;

    // If the head node is to be deleted
    if (position == 0) {
        head = temp->next; // Change head
        delete temp;       // Free old head
        cout << "Node di posisi " << position << " dihapus." << endl;
        return;
    }

    // Find the previous node of the node to be deleted
    for (int i = 0; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }

    // If the position is invalid
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    // Node temp->next is the node to be deleted
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next; // Unlink the node
    delete nodeToDelete;             // Free memory
    cout << "Node di posisi " << position << " dihapus." << endl;
}

// Function to reverse the linked list
void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move prev to the current node
        current = next;       // Move to the next node
    }

    head = prev; // Update head to the new first node
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

    // Display the linked list in forward and reverse order
    displayListForward(head);
    cout << "Linked List (Reverse): ";
    displayListReverse(head);
    cout << "NULL" << endl;

    // Search for a node in the linked list
    int searchKey;
    cout << "Masukkan data yang ingin dicari: ";
    cin >> searchKey;
    searchNode(head, searchKey);

    // Allow the user to delete a node
    int deleteKey;
    cout << "Masukkan data yang ingin dihapus: ";
    cin >> deleteKey;
    deleteNode(head, deleteKey);

    // Display the linked list after deletion
    cout << "Linked List setelah penghapusan: ";
    displayList(head);

    // Allow the user to delete a node by position
    int deletePosition;
    cout << "Masukkan posisi yang ingin dihapus: ";
    cin >> deletePosition;
    deleteNodeAtPosition(head, deletePosition);

    // Display the linked list after deletion by position
    cout << "Linked List setelah penghapusan: ";
    displayList(head);

    // Reverse the linked list
    cout << "\nLinked List sebelum dibalik: ";
    displayList(head);
    reverseList(head);
    cout << "Linked List setelah dibalik: ";
    displayList(head);

    return 0;
}