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

void deleteNode(struct Node **head_ref, int position)
{
    if (*head_ref == NULL)
        return;
    struct Node *temp = *head_ref;
    if (position == 0)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
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

    // Add initial nodes
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);

    // Add 5 new nodes at random positions
    push(&head, 10); // Add to the front
    append(&head, 20); // Add to the end
    push(&head, 15); // Add to the front
    append(&head, 25); // Add to the end
    push(&head, 30); // Add to the front

    puts("Created Linked List with additional nodes: ");
    printList(head);

    // Delete 3 of the newly added nodes
    deleteNode(&head, 0); // Delete node at position 0 (30)
    deleteNode(&head, 5); // Delete node at position 5 (20)
    deleteNode(&head, 2); // Delete node at position 2 (15)

    puts("\nLinked List after Deletion of 3 nodes: ");
    printList(head);

    return 0;
}