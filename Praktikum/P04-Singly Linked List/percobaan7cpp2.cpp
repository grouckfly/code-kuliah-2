#include <iostream>
using namespace std;

struct Node
{
    int key;
    struct Node *next;
};

void push(struct Node **head_ref, int new_key)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->key = new_key;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

bool search(struct Node *head, int x)
{
    if (head == NULL)
        return false;
    if (head->key == x)
        return true;
    return search(head->next, x);
}

int main()
{
    struct Node *head = NULL;
    int x = 21;
    push(&head, 555);
    push(&head, 69);
    push(&head, 81);
    push(&head, 1);
    push(&head, 30);
    search(head, 81) ? cout << "Yes" : cout << "No";
    return 0;
}