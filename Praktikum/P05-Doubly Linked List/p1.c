#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

void insertAfter(struct Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void insertBefore(struct Node **head_ref, struct Node *next_node, int new_data)
{
    if (next_node == NULL)
    {
        printf("The given next node cannot be NULL\n");
        return;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = next_node->prev;
    new_node->next = next_node;
    if (next_node->prev != NULL)
        next_node->prev->next = new_node;
    else
        *head_ref = new_node;
    next_node->prev = new_node;
}

void append(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref; 
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
    return;
}

void printList(struct Node *node)
{
    struct Node *last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\nTraversal in reverse direction \n");
    while (last != NULL)
    {
        printf(" %d ", last->data);
        last = last->prev;
    }
}

void printAddresses(struct Node *node)
{
    printf("\nAddresses of nodes in the list:\n");
    while (node != NULL)
    {
        printf("Node with data %d: %p\n", node->data, (void *)node);
        node = node->next;
    }
}

int main()
{
    struct Node *head = NULL;

    // Adding nodes at various positions
    append(&head, 6); // Back
    push(&head, 7);   // Front
    push(&head, 1);   // Front
    append(&head, 4); // Back
    insertAfter(head->next, 8); // After a node
    insertBefore(&head, head->next, 5); // Before a node

    printf("Created DLL is: ");
    printList(head);

    // Print addresses of nodes
    printAddresses(head);

    return 0;
}