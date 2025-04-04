#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteNode(struct Node **head_ref, int key)
{

    struct Node *temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main()
{
    struct Node *head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    // Adding 5 new nodes
    push(&head, 10); // Add at the front
    push(&head, 20); // Add at the front
    struct Node *temp = head->next->next; // Insert after the third node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = 30;
    new_node->next = temp->next;
    temp->next = new_node;
    push(&head, 40); // Add at the front
    push(&head, 50); // Add at the front

    puts("Created Linked List with additional nodes: ");
    printList(head);

    // Deleting 3 nodes randomly
    deleteNode(&head, 10);
    deleteNode(&head, 30);
    deleteNode(&head, 50);

    puts("\nLinked List after Deletion of 3 nodes: ");
    printList(head);

    return 0;
}