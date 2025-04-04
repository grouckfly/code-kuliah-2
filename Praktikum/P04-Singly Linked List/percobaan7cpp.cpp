#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *next;
};

void push(Node **head_ref, int new_key)
{
    Node *new_node = new Node();
    new_node->key = new_key;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

bool search(Node *head, int x)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->key == x)
            return true;
        current = current->next;
    }
    return false;
}

int main()
{
    Node *head = NULL;
    int x = 21;
    push(&head, 5);
    push(&head, 8);
    push(&head, 120);
    push(&head, 52);
    push(&head, 2);
    search(head, 10) ? cout << "Yes" : cout << "No";
    return 0;
}