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
    if (*head == NULL) {
        printf("The list is empty. Cannot delete value %d.\n", value);
        return;
    }
    Node* temp = *head;

    // Traverse the list to find the node with the given value
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    // If the node is not found
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    // Update the previous node's next pointer
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next; // Update head if the node to delete is the first node
    }

    // Update the next node's prev pointer
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // Free the memory of the node to delete
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

// Function to delete all nodes in the list
void clearList(Node** head) {
    Node* temp = *head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
    printf("All nodes have been deleted. The list is now empty.\n");
}

// Function to delete duplicate nodes in the list
void deleteDuplicates(Node** head) {
    if (*head == NULL) return;

    Node* current = *head;
    while (current != NULL) {
        Node* runner = current->next;
        while (runner != NULL) {
            if (runner->data == current->data) {
                Node* duplicate = runner;
                runner = runner->next;

                // Update the previous node's next pointer
                if (duplicate->prev != NULL) {
                    duplicate->prev->next = duplicate->next;
                }

                // Update the next node's prev pointer
                if (duplicate->next != NULL) {
                    duplicate->next->prev = duplicate->prev;
                }

                // Free the memory of the duplicate node
                free(duplicate);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

int main() {
    Node* head = NULL;

    // Adding 10 nodes with some duplicate values
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 20); // Duplicate
    append(&head, 40);
    append(&head, 50);
    append(&head, 30); // Duplicate
    append(&head, 60);
    append(&head, 70);
    append(&head, 10); // Duplicate

    printf("Initial list:\n");
    displayForward(head);

    // Deleting a node from the beginning
    deleteNode(&head, 10);
    printf("After deleting a node from the beginning (value 10):\n");
    displayForward(head);

    // Deleting a node from the middle
    deleteNode(&head, 30);
    printf("After deleting a node from the middle (value 30):\n");
    displayForward(head);

    // Deleting a node from the end
    deleteNode(&head, 70);
    printf("After deleting a node from the end (value 70):\n");
    displayForward(head);

    // Display the list backward for verification
    printf("Final list (Backward):\n");
    displayBackward(head);

    // Clear the entire list
    clearList(&head);

    return 0;
}