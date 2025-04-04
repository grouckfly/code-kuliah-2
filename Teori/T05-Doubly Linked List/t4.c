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

// Helper function for recursive reversal
void reverseRecursive(Node** startNode, Node** endNode, Node* current) {
    if (current == *endNode) {
        Node* temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        return;
    }

    Node* temp = current->prev;
    current->prev = current->next;
    current->next = temp;

    reverseRecursive(startNode, endNode, current->prev);
}

// Function to reverse a subset of the list from position start to end
void reverseSubset(Node** head, int start, int end) {
    if (*head == NULL || start >= end) {
        printf("Invalid range for reversing subset.\n");
        return;
    }

    Node* current = *head;
    Node* startNode = NULL;
    Node* endNode = NULL;
    int position = 1;

    // Locate the start and end nodes
    while (current != NULL && position <= end) {
        if (position == start) {
            startNode = current;
        }
        if (position == end) {
            endNode = current;
            break;
        }
        current = current->next;
        position++;
    }

    if (startNode == NULL || endNode == NULL) {
        printf("Invalid range for reversing subset.\n");
        return;
    }

    // Reverse the subset recursively
    reverseRecursive(&startNode, &endNode, startNode);

    // Adjust the connections to the rest of the list
    if (startNode->prev != NULL) {
        startNode->prev->next = endNode;
    } else {
        *head = endNode; // Update head if the subset starts at the first node
    }
    if (endNode->next != NULL) {
        endNode->next->prev = startNode;
    }

    printf("Subset from position %d to %d has been reversed.\n", start, end);
}

// Function to check if the doubly linked list is a palindrome
int isPalindrome(Node* head) {
    if (head == NULL) return 1; // An empty list is a palindrome

    Node* left = head;
    Node* right = head;

    // Move right pointer to the end of the list
    while (right->next != NULL) {
        right = right->next;
    }

    // Compare elements from both ends
    while (left != right && left->prev != right) {
        if (left->data != right->data) {
            return 0; // Not a palindrome
        }
        left = left->next;
        right = right->prev;
    }

    return 1; // The list is a palindrome
}

// Function to sort the doubly linked list in descending order
void sortDescending(Node** head) {
    if (*head == NULL) return;

    Node* i = *head;
    while (i != NULL) {
        Node* j = i->next;
        while (j != NULL) {
            if (i->data < j->data) {
                // Swap the data
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
    printf("The list has been sorted in descending order.\n");
}

// Function to split the doubly linked list into two halves
Node* split(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* secondHalf = slow->next;
    slow->next = NULL;
    if (secondHalf != NULL) {
        secondHalf->prev = NULL;
    }
    return secondHalf;
}

// Function to merge two sorted halves of the doubly linked list
Node* merge(Node* first, Node* second) {
    if (first == NULL) return second;
    if (second == NULL) return first;

    if (first->data > second->data) { // Descending order
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    } else {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

// Function to implement Merge Sort on the doubly linked list
Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* secondHalf = split(head);

    // Recursively sort both halves
    head = mergeSort(head);
    secondHalf = mergeSort(secondHalf);

    // Merge the sorted halves
    return merge(head, secondHalf);
}

// Wrapper function to sort the doubly linked list using Merge Sort
void sortDescendingMergeSort(Node** head) {
    *head = mergeSort(*head);
    printf("The list has been sorted in descending order using Merge Sort.\n");
}

// Function to check if the doubly linked list is sorted
int isSorted(Node* head) {
    if (head == NULL || head->next == NULL) {
        return 1; // An empty or single-node list is considered sorted
    }

    int ascending = 1, descending = 1;
    Node* temp = head;

    while (temp->next != NULL) {
        if (temp->data > temp->next->data) {
            ascending = 0;
        }
        if (temp->data < temp->next->data) {
            descending = 0;
        }
        temp = temp->next;
    }

    return ascending || descending;
}

// Function to partition the list for QuickSort
Node* partition(Node* low, Node* high) {
    int pivot = high->data;
    Node* i = low->prev;

    for (Node* j = low; j != high; j = j->next) {
        if (j->data >= pivot) { // Descending order
            i = (i == NULL) ? low : i->next;
            int temp = i->data;
            i->data = j->data;
            j->data = temp;
        }
    }
    i = (i == NULL) ? low : i->next;
    int temp = i->data;
    i->data = high->data;
    high->data = temp;
    return i;
}

// Recursive QuickSort function
void quickSort(Node* low, Node* high) {
    if (high != NULL && low != high && low != high->next) {
        Node* p = partition(low, high);
        quickSort(low, p->prev);
        quickSort(p->next, high);
    }
}

// Wrapper function for QuickSort
void sortDescendingQuickSort(Node** head) {
    if (*head == NULL) return;

    Node* tail = *head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    quickSort(*head, tail);
    printf("The list has been sorted in descending order using QuickSort.\n");
}

int main() {
    Node* head = NULL;

    // Step 1: Add at least 10 nodes with random values
    append(&head, 12);
    append(&head, 7);
    append(&head, 19);
    append(&head, 3);
    append(&head, 15);
    append(&head, 10);
    append(&head, 8);
    append(&head, 25);
    append(&head, 5);
    append(&head, 20);

    // Step 2: Print the DLL before sorting
    printf("DLL before sorting:\n");
    displayForward(head);

    // Step 3: Sort the DLL using MergeSort and print the result
    Node* mergeSortHead = head;
    sortDescendingMergeSort(&mergeSortHead);
    printf("DLL after sorting in descending order using MergeSort:\n");
    displayForward(mergeSortHead);

    // Step 4: Sort the DLL using QuickSort and print the result
    Node* quickSortHead = head;
    sortDescendingQuickSort(&quickSortHead);
    printf("DLL after sorting in descending order using QuickSort:\n");
    displayForward(quickSortHead);

    // Clear the list to free memory
    clearList(&head);

    return 0;
}