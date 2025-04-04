#include <iostream>
#include <assert.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int GetNth(Node *head, int index)
{
    Node *current = head;
    int count = 0;
    while (current != NULL)
    {
        if (count == index)
            return (current->data);
        count++;
        current = current->next;
    }
    assert(0);
}

int main()
{
    Node *head = NULL;
    push(&head, 14);
    push(&head, 56);
    push(&head, 29);
    push(&head, 69);
    push(&head, 33);
    cout << "Element at index 2 is " << GetNth(head, 2);
    return 0;
}