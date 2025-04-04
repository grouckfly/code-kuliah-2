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
}

void append(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
 
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d : %p\n", node->data, (void *)node);
        node = node->next;
    }
}

int main()
{
    struct Node *head = NULL;

    // Adding nodes at the end
    append(&head, 6);
    append(&head, 4);

    // Adding nodes at the beginning
    push(&head, 7);
    push(&head, 1);

    // Adding nodes in the middle
    insertAfter(head->next, 8);
    insertAfter(head->next->next, 10);

    printf("\nCreated Linked list is:\n");
    printList(head);

    return 0;
}