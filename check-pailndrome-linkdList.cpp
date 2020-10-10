#include <iostream>
#include <stack>
using namespace std;

void push(int);
void print();
bool cheeckPailndrome();
void reverse();

struct Node
{
    int data;
    Node *next;
    Node(int _data)
    {
        data = _data;
        next = NULL;
    }
};
Node *head = NULL;

void push(int item)
{
    Node *temp = new Node(item);
    temp->next = head;
    head = temp;
}

void print()
{
    Node *ptr = head;
    while (ptr)
    {
        cout << ptr->data << "|";
        ptr = ptr->next;
    }
    cout << endl;
}

bool checkPailndrome()
{
    if (!head)
        return true;
    Node *ptr = head;
    stack<int> s;
    while (ptr)
    {
        s.push(ptr->data);
        ptr = ptr->next;
    }
    ptr = head;
    while (ptr)
    {
        if (ptr->data != s.top())
            return false;
        ptr = ptr->next;
        s.pop();
    }
    return true;
}

void reverse()
{
}
int main()
{
    push(50);
    push(40);
    push(30);
    push(40);
    push(50);
    print();
    if ((checkPailndrome() == true))
        cout << "pailnDrome\n";
    else
    {
        cout << "not pailnDrome\n";
    }
}