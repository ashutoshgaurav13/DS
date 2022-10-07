#include <iostream>
using namespace std;

class mystack
{
public:
    struct Node
    {
        int data;
        Node *prev;
        Node *next;
        Node(int num)
        {
            data = num;
            prev = next = NULL;
        }
    };
    Node *head, *mid;
    int size;
    mystack()
    {
        head = mid = NULL;
        size = 0;
    }

    void push(int ele);
    void pop();
    void findMiddle();
    void deleteMiddle();
    void peek();
};
void mystack::findMiddle()
{
    if (size > 0)
        cout << mid->data << endl;
}
void mystack::peek()
{
    if (head == NULL)
    {
        cout << "stack Empty...\n";
        return;
    }
    else
    {
        cout << head->data << endl;
    }
}
void mystack::push(int ele)
{
    Node *temp = new Node(ele);
    if (head == NULL)
    {
        head = mid = temp;
        ++size;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
        ++size;
        if (size > 2)
        {
            if (size % 2 == 1)
                mid = mid->prev;
        }
    }
}
void mystack::pop()
{
    Node *temp = NULL;
    if (head == NULL)
    {
        cout << "Stack Underflow...\n";
        mid = NULL;
        return;
    }
    else
    {
        temp = head;
        head->next->prev = head->prev;
        head = head->next;
        delete temp;
        --size;
        if (size == 1 || size == 2)
            mid = head;
        else if (size > 2)
        {
            if (size % 2 == 0)
            {
                mid = mid->next;
            }
        }
    }
}
int main()
{
    mystack my;
    my.push(11);
    my.push(12);
    my.push(13);
    my.push(14);
    my.push(15);
    my.findMiddle();
    my.pop();
    my.findMiddle();
    my.pop();
    my.findMiddle();
    my.pop();
    my.findMiddle();
    my.pop();
    my.findMiddle();
    return 0;
}