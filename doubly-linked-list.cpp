#include <iostream>
using namespace std;
struct Node;

void insert_end(Node **, int ele);
void insert_start(Node **, int ele);
void delete_start(Node **);
void delete_end(Node **);
void print(Node *);

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        prev = next = NULL;
    }
};
void delete_start(Node **head)
{
    Node *ptr = *head;
    ptr->next->prev = ptr->prev;
    *head = ptr->next;
    delete ptr;
}

void delete_end(Node **head)
{
    Node *ptr = *head;
    // Node *temp;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = ptr->next;
    delete ptr;
}
void print(Node *ptr)
{
    while (ptr)
    {
        cout << ptr->data << "|";
        ptr = ptr->next;
    }
    cout << endl;
}
void insert_start(Node **head, int ele)
{
    Node *ptr = *head;
    Node *temp = new Node(ele);
    if (ptr == NULL)
    {
        *head = temp;
    }
    else
    {
        ptr->prev = temp;
        temp->next = ptr;
        *head = temp;
    }
    // cout << "insert_start end...\n";
}

void insert_end(Node **head, int ele)
{
    Node *ptr = *head;
    Node *temp = new Node(ele);
    if (ptr == NULL)
    {
        *head = temp;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        temp->prev = ptr;
        ptr->next = temp;
    }

    // cout << "insert_end end here....\n";
}
int main()
{
    Node *head = NULL;
    Node *mid = NULL;
    insert_end(&head, 2);
    insert_end(&head, 3);
    insert_start(&head, 4);
    insert_end(&head, 5);
    insert_start(&head, 6);
    cout << "After insertion..\n";
    print(head);
    delete_start(&head);
    delete_end(&head);
    cout << "After deletion...\n";
    print(head);
    return 0;
}