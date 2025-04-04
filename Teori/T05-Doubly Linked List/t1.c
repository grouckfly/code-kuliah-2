#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to count the total number of nodes in the list
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to insert a node at the end of the list
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("Total nodes after append: %d\n", countNodes(*head));
}

// Function to insert a node before a specific node
void insertAfter(Node** head, int target, int data) {
    Node* temp = *head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Target value %d not found in the list.\n", target);
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        *head = newNode;
    }
    temp->prev = newNode;
    printf("Total nodes after insert: %d\n", countNodes(*head));
}

// Function to display the list from the beginning
void displayForward(Node* head) {
    Node* temp = head;
    printf("List (Forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to display the list from the end
void displayBackward(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("List (Backward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Function to delete a node by value
void deleteNode(Node** head, int value) {
    Node* temp = *head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Value %d deleted from the list.\n", value);
}

// Function to search for a node by value
Node* searchNode(Node* head, int value) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            return temp;
        }
        temp = temp->next;
    }
    printf("Value %d not found in the list.\n", value);
    return NULL;
}

int main() {
    Node* head = NULL;

    // Adding nodes at the end
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);

    // Adding nodes at various positions
    insertAfter(&head, 10, 5);  // Insert 5 before 10
    insertAfter(&head, 20, 15); // Insert 15 before 20
    insertAfter(&head, 30, 25); // Insert 25 before 30

    // Adding more nodes at the end
    append(&head, 35);
    append(&head, 40);

    // Adding nodes at the front
    insertAfter(&head, 5, 1); // Insert 1 before 5

    // Adding a node in the middle
    insertAfter(&head, 25, 22); // Insert 22 before 25

    // Display the list after all insertions
    displayForward(head);
    displayBackward(head);

    // Deleting a few nodes
    deleteNode(&head, 1);  // Delete node with value 1
    deleteNode(&head, 22); // Delete node with value 22
    deleteNode(&head, 40); // Delete node with value 40

    // Display the list after deletions
    displayForward(head);
    displayBackward(head);

    // Test searchNode function
    Node* foundNode = searchNode(head, 15);
    if (foundNode != NULL) {
        printf("Node with value %d found at address %p.\n", foundNode->data, (void*)foundNode);
    }

    searchNode(head, 100); // Test with a value not in the list

    return 0;
}